/*
 * Copyright 2009- ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation
 * nor does it submit to any jurisdiction.
 */

#ifndef aviso_ListenService_HPP
#define aviso_ListenService_HPP

#include <functional>

#include "aviso/ConfiguredListener.hpp"
#include "aviso/ListenerSchema.hpp"
#include "aviso/executor/PeriodicTaskExecutor.hpp"

namespace aviso {

class ListenService {
public:
    using address_t    = aviso::etcd::Address;
    using key_prefix_t = std::string;
    using listener_t   = aviso::ConfiguredListener;
    using revision_t   = int64_t;

    struct Entry
    {
        explicit Entry(listener_t listener) : listener_{std::move(listener)} {}
        explicit Entry(listener_t listener, revision_t revision) : listener_{std::move(listener)} {}

        const etcd::Address address() const { return listener_.address(); }
        std::string prefix() const { return listener_.prefix(); }
        std::string_view path() const { return listener_.path(); }
        const listener_t& listener() const { return listener_; }
        listener_t& listener() { return listener_; }

    private:
        listener_t listener_;
    };

    using storage_t            = std::vector<Entry>;
    using notify_callback_t    = std::function<void(const aviso::ConfiguredListener&, const aviso::Notification&)>;
    using subscribe_callback_t = std::function<std::vector<ListenRequest>()>;

    using schema_t = aviso::ListenerSchema;

    ListenService(schema_t schema, notify_callback_t notify, subscribe_callback_t subscribe)
        : schema_{schema},
          executor_{[this](const std::chrono::system_clock::time_point& now) { this->operator()(now); }},
          listeners_{},
          notify_{notify},
          subscribe_{subscribe} {};
    ListenService()                     = delete;
    ListenService(const ListenService&) = delete;
    ~ListenService() { stop(); }

    ListenService& operator=(const ListenService&) = delete;

    void start() {
        auto expiry = load_default_polling_interval();
        start(std::chrono::seconds{expiry});
    }
    void start(std::chrono::seconds expiry) { executor_.start(expiry); }

    void stop() { executor_.stop(); }
    void terminate() { executor_.stop(); }

    void operator()(const std::chrono::system_clock::time_point& now);

    void register_listener(const ListenRequest& request);
    void register_listener(const listener_t& listener);
    void unregister_listener(const std::string& unlisten_path);

private:
    static std::string load_cfg_location();
    static int load_default_polling_interval();

private:
    aviso::ListenerSchema schema_;
    aviso::PeriodicTaskExecutor<std::function<void(const std::chrono::system_clock::time_point& now)>> executor_;
    storage_t listeners_;

    notify_callback_t notify_;
    subscribe_callback_t subscribe_;
};

} // namespace aviso

#endif /* aviso_ListenService_HPP */
