#include "BehaviorTree/BTNode.h"
#include "BehaviorTree/BTLeafNode.h"
#include "BehaviorTree/BTBlackboard.h"

BTStatus BTCallNode::Execute(BTContext* ctx)
{
    return m_fn ? m_fn(ctx) : BTStatus::Unknown;
}

void BTCallNode::SetCallbackFunction(BTCallbackFunction fn)
{
    m_fn = fn;
}

BTCallbackFunction BTCallNode::GetCallbackFunction()
{
    return m_fn;
}
