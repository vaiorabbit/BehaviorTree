#pragma once

#include "BTCommon.h"
#include "BTCompositeNode.h"

class BTDecoratorNode : public BTCompositeNode
{
public:

    BTDecoratorNode() {};
    virtual ~BTDecoratorNode() {};

private:
    BTDecoratorNode(BTInt32 childrenCount) = delete;
};


class BTForceSuccessNode : public BTDecoratorNode
{
public:
    virtual BTStatus Execute(BTContext* ctx) {
        m_children[0]->Execute(ctx);
        return BTStatus::Success;
    }
};

class BTForceFailureNode : public BTDecoratorNode
{
public:
    virtual BTStatus Execute(BTContext* ctx) {
        m_children[0]->Execute(ctx);
        return BTStatus::Failure;
    }
};

class BTForceRunningNode : public BTDecoratorNode
{
public:
    virtual BTStatus Execute(BTContext* ctx) {
        m_children[0]->Execute(ctx);
        return BTStatus::Running;
    }
};

class BTNegateNode : public BTDecoratorNode
{
public:
    BTNegateNode()
        : BTDecoratorNode()
    {}

    virtual BTStatus Execute(BTContext* ctx) override;
};

class BTRepeatNode : public BTDecoratorNode
{
public:
    BTRepeatNode()
        : BTDecoratorNode()
    {}

    virtual BTStatus Execute(BTContext* ctx) override;

    virtual void OnInit() override {
        BTDecoratorNode::OnInit();
        m_now = 0;
    }

    void SetLimit(BTInt32 limit) {
        m_limit = limit;
    }

    BTInt32 GetLimit() {
        return m_limit;
    }

protected:

    BTInt32 m_limit;
    BTInt32 m_now;
};
