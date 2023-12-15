/*
 * Copyright 2009- ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation
 * nor does it submit to any jurisdiction.
 */

#include "ecflow/client/UrlCmd.hpp"

#include <stdexcept>

#include "ecflow/node/Defs.hpp"
#include "ecflow/node/Node.hpp"

UrlCmd::UrlCmd(defs_ptr defs, const std::string& absNodePath) : defs_(defs), node_(nullptr) {
    if (!defs_.get()) {
        throw std::runtime_error("UrlCmd: The definition parameter is empty");
    }

    if (absNodePath.empty()) {
        throw std::runtime_error("UrlCmd: The node path parameter is empty");
    }

    node_ = defs_->findAbsNode(absNodePath).get();
    if (!node_) {
        std::string errorMsg = "UrlCmd: The node path parameter '";
        errorMsg += absNodePath;
        errorMsg += "' cannot be found.";
        throw std::runtime_error(errorMsg);
    }
}

std::string UrlCmd::getUrl() const {
    std::string url;
    node_->findParentUserVariableValue("ECF_URL_CMD", url);
    if (url.empty()) {
        std::string errorMsg = "UrlCmd: Could not find variable ECF_URL_CMD from node ";
        errorMsg += node_->absNodePath();
        throw std::runtime_error(errorMsg);
    }

    if (!node_->variableSubstitution(url)) {
        std::string errorMsg = "UrlCmd:: Variable substitution failed for ";
        errorMsg += url;
        throw std::runtime_error(errorMsg);
    }
    return url;
}

void UrlCmd::execute() const {
    // invoke as a system command, we don't use System::instance()
    // since this is on the client side. hence no need manage the spawned process
    system(getUrl().c_str());
}
