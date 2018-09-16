#include "BehaviorTree/BTNode.h"
#include "BehaviorTree/BTCompositeNode.h"
#include "BehaviorTree/BTBlackboard.h"

BTCompositeNode::BTCompositeNode()
    : m_children()
    , m_currentChildIndex(0)
    , m_initialized(false)
{}

BTCompositeNode::BTCompositeNode(BTInt32 childrenCount)
    : m_children(childrenCount)
    , m_currentChildIndex(0)
    , m_initialized(false)
{}

BTCompositeNode::~BTCompositeNode()
{}

BTNodeList BTCompositeNode::GetChildren()
{
    return m_children;
}

size_t BTCompositeNode::GetChildrenCount()
{
    return m_children.size();
}

BTInt32 BTCompositeNode::AddChild(BTNode* child)
{
    child->SetParent(this);
    m_children.push_back(child);
    return (BTInt32)m_children.size() - 1;
}

void BTCompositeNode::SetChild(BTNode* child, BTInt32 n)
{
    child->SetParent(this);
    m_children[n] = child;
}

BTNode* BTCompositeNode::GetChild(BTInt32 n)
{
    return m_children[n];
}

BTInt32 BTCompositeNode::GetCurrentChildIndex()
{
    return m_currentChildIndex;
}

void BTCompositeNode::SetCurrentChildIndex(BTInt32 n)
{
    m_currentChildIndex = n;
}


BTSequenceNode::BTSequenceNode()
    : BTCompositeNode()
{}

BTSequenceNode::BTSequenceNode(BTInt32 childrenCount)
    : BTCompositeNode(childrenCount)
{}

BTStatus BTSequenceNode::Execute(BTContext* ctx)
{
    if (!m_initialized) {
        OnInit();
        m_initialized = true;
    }

    while (true) {
        BTStatus s = m_children[m_currentChildIndex]->Execute(ctx);

        if (s != BTStatus::Success) {
            return s;
        } else {
            ++m_currentChildIndex;
            if (m_currentChildIndex == GetChildrenCount()) {
                m_currentChildIndex = 0;
                return BTStatus::Success;
            }
        }
    }
}


BTSelectorNode::BTSelectorNode()
    : BTCompositeNode()
{}

BTSelectorNode::BTSelectorNode(BTInt32 childrenCount)
    : BTCompositeNode(childrenCount)
{}

BTStatus BTSelectorNode::Execute(BTContext* ctx)
{
    if (!m_initialized) {
        OnInit();
        m_initialized = true;
    }

    while (true) {
        BTStatus s = m_children[m_currentChildIndex]->Execute(ctx);

        if (s != BTStatus::Failure) {
            return s;
        } else {
            ++m_currentChildIndex;
            if (m_currentChildIndex == GetChildrenCount()) {
                m_currentChildIndex = 0;
                return BTStatus::Failure;
            }
        }
    }
}
