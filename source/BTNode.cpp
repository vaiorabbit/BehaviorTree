#include "BehaviorTree/BTNode.h"

BTNode::BTNode()
    : m_nodeName()
    , m_id(-1)
    , m_parentNode(nullptr)
{}

BTNode::~BTNode()
{}

const BTNodeName& BTNode::GetNodeName()
{
    return m_nodeName;
}

void BTNode::SetNodeName(const BTNodeName& nodeName)
{
    m_nodeName = nodeName;
}

BTNodeID BTNode::GetID()
{
    return m_id;
}

void BTNode::SetID(BTNodeID id)
{
    m_id = id;
}

BTCompositeNode* BTNode::GetParent()
{
    return m_parentNode;
}

void BTNode::SetParent(BTCompositeNode* parentNode)
{
    m_parentNode = parentNode;
}
