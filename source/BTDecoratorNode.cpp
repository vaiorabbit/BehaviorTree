#include "BehaviorTree/BTNode.h"
#include "BehaviorTree/BTDecoratorNode.h"

BTNegateNode::BTNegateNode()
    : BTDecoratorNode()
{}

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
