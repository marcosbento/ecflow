//============================================================================
// Copyright 2009- ECMWF.
// This software is licensed under the terms of the Apache Licence version 2.0
// which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
// In applying this licence, ECMWF does not waive the privileges and immunities
// granted to it by virtue of its status as an intergovernmental organisation
// nor does it submit to any jurisdiction.
//============================================================================

#include "GenFileProvider.hpp"

#include "UiLog.hpp"
#include "VConfig.hpp"
#include "VReply.hpp"

#define UI_FILEPROVIDER_TASK_DEBUG__

GenFileProvider::GenFileProvider()
{
    fetchQueue_ = new FetchQueue(FetchQueue::RunAll, this);
    reply_ = new VReply();
}

GenFileProvider::~GenFileProvider()
{
    if (reply_) {
        delete reply_;
    }
}

void GenFileProvider::clear()
{
    reply_->reset();
}

void GenFileProvider::fetchFiles(const std::vector<std::string>& fPaths)
{
    reply_->reset();

    // Update the fetch tasks and process them.
    fetchQueue_->clear();
    fetchQueue_->setPolicy(FetchQueue::RunAll);
    Q_ASSERT(fetchQueue_->isEmpty());

    // we assume we have one task per path
    for (auto p: fPaths) {
        AbstractFetchTask* t=nullptr;
        if (VConfig::instance()->proxychainsUsed()) {
            t = makeFetchTask("transfer");
        } else {
            t = makeFetchTask("local");
        }
        Q_ASSERT(t);
        t->reset(p);
        fetchQueue_->add(t);
    }

    Q_ASSERT(fetchQueue_->size() == fPaths.size());

#ifdef UI_OUTPUTFILEPROVIDER_DEBUG__
    UiLog().dbg() << UI_FN_INFO << "queue=" << fetchQueue_;
#endif
    fetchQueue_->run();
}

void GenFileProvider::fetchFile(const std::string& fPath)
{
    // Update the fetch tasks and process them. The queue runs until any task can fetch
    // the logfile
    fetchQueue_->clear();
    fetchQueue_->setPolicy(FetchQueue::RunUntilFirstSucceeded);
    Q_ASSERT(fetchQueue_->isEmpty());
    AbstractFetchTask* t=nullptr;
    if (VConfig::instance()->proxychainsUsed()) {
        t = makeFetchTask("transfer");
    } else {
        t = makeFetchTask("local");
    }
    Q_ASSERT(t);
    t->setRunCondition(AbstractFetchTask::NoCondition);
    t->reset(fPath);
    fetchQueue_->add(t);

#ifdef UI_OUTPUTFILEPROVIDER_DEBUG__
    UiLog().dbg() << UI_FN_INFO << "queue=" << fetchQueue_;
#endif
    fetchQueue_->run();
}

void GenFileProvider::fetchQueueSucceeded()
{
    //owner_->infoReady(reply_);
    reply_->reset();
}

void GenFileProvider::fetchQueueFinished(const std::string& /*filePath*/, VNode* n)
{
    if (reply_->errorText().empty()) {
        reply_->setErrorText("Failed to fetch file!");
    }
    //owner_->infoFailed(reply_);
    reply_->reset();
}
