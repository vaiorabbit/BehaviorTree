#pragma once

#include "BTCommon.h"
#include "BTNode.h"

class BTLeafNode : public BTNode
{
public:

    BTLeafNode();
    virtual ~BTLeafNode();
};


class BTSuccessNode : public BTLeafNode
{
public:
    virtual BTStatus Execute(BTContext* ctx) {
        return BTStatus::Success;
    }
};

class BTFailureNode : public BTLeafNode
{
public:
    virtual BTStatus Execute(BTContext* ctx) {
        return BTStatus::Failure;
    }
};

class BTRunningNode : public BTLeafNode
{
public:
    virtual BTStatus Execute(BTContext* ctx) {
        return BTStatus::Running;
    }
};

class BTCallNode : public BTLeafNode
{
public:
    virtual BTStatus Execute(BTContext* ctx) {
        return m_fn ? m_fn(ctx) : BTStatus::Unknown;
    }

    void SetCallbackFunction(BTCallbackFunction fn) {
        m_fn = fn;
    }

    BTCallbackFunction GetCallbackFunction() {
        return m_fn;
    }

protected:

    BTCallbackFunction m_fn;
};
