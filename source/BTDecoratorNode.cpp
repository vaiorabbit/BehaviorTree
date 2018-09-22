#include "BehaviorTree/BTNode.h"
#include "BehaviorTree/BTDecoratorNode.h"

BTStatus BTNegateNode::Execute(BTContext* ctx)
{
    if (!m_initialized) {
        OnInit();
        m_initialized = true;
    }

    BTStatus s = m_children[0]->Execute(ctx);

    if (s == BTStatus::Success) {
        return BTStatus::Failure;
    } else if (s == BTStatus::Failure) {
        return BTStatus::Success;
    } else {
        return BTStatus::Running;
    }
}

BTStatus BTRepeatNode::Execute(BTContext* ctx)
{
    if (!m_initialized) {
        OnInit();
        m_initialized = true;
    }

    BTStatus s = m_children[0]->Execute(ctx);
    if (s == BTStatus::Failure) {
        return s;
    } else if (++m_now == m_limit) {
        return BTStatus::Success;
    }

    return BTStatus::Running;
    }
