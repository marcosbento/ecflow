/*
 * Copyright 2009- ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation
 * nor does it submit to any jurisdiction.
 */

#ifndef ecflow_viewer_UiLog_HPP
#define ecflow_viewer_UiLog_HPP

#include <sstream>
#include <string>
#include <vector>

#include <QStringList>
#include <boost/current_function.hpp>

class QModelIndex;
class QVariant;
class QPoint;
class QRegion;
class QRect;
class QDateTime;

class UiFunctionLog {
public:
    UiFunctionLog(const std::string& server, const std::string& funcName);
    explicit UiFunctionLog(const std::string& funcName);
    ~UiFunctionLog();

    std::string logEnter() const;
    std::string logLeave() const;

    static std::string formatFuncInfo(const std::string& funcName);

protected:
    void init();

    std::string serverName_;
    std::string funcName_;
};

class UiLog {
public:
    enum Type { INFO, WARN, ERROR, DBG };

    UiLog() = default;
    explicit UiLog(const std::string& server);
    ~UiLog();

    std::ostringstream& info();
    std::ostringstream& err();
    std::ostringstream& warn();
    std::ostringstream& dbg();

    static void enableTruncation();

    static std::string toString(int i) {
        std::stringstream ss;
        ss << i;
        return ss.str();
    }

protected:
    void output(const std::string& msg);
    void appendType(std::string& s, Type t) const;

    Type type_{INFO};
    std::ostringstream os_;
    std::string server_;

private:
    UiLog(const UiLog&)            = delete;
    UiLog& operator=(const UiLog&) = delete;
};

#define UI_FUNCTION_LOG UiFunctionLog __fclog(BOOST_CURRENT_FUNCTION);
#define UI_FN_DBG UiLog().dbg() << UiFunctionLog::formatFuncInfo(BOOST_CURRENT_FUNCTION);
#define UI_FN_INFO UiFunctionLog::formatFuncInfo(BOOST_CURRENT_FUNCTION)

// Overload ostringstream for various objects
std::ostream& operator<<(std::ostream&, const std::vector<std::string>&);

// Overload ostringstream for qt objects
std::ostream& operator<<(std::ostream&, const QString&);
std::ostream& operator<<(std::ostream&, const QModelIndex&);
std::ostream& operator<<(std::ostream&, const QVariant&);
std::ostream& operator<<(std::ostream&, const QStringList&);
std::ostream& operator<<(std::ostream&, const QRegion&);
std::ostream& operator<<(std::ostream&, const QRect&);
std::ostream& operator<<(std::ostream&, const QPoint&);
std::ostream& operator<<(std::ostream&, const QDateTime&);

#endif /* ecflow_viewer_UiLog_HPP */
