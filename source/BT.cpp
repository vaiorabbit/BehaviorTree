#include "BehaviorTree/BTCommon.h"
#include "BehaviorTree/BTBlackboard.h"
#include "BehaviorTree/BTContext.h"
#include "BehaviorTree/BTNode.h"
#include "BehaviorTree/BTCompositeNode.h"
#include "BehaviorTree/BTDecoratorNode.h"
#include "BehaviorTree/BTLeafNode.h"
#include "BehaviorTree/BTNodeFactory.h"
#include "BehaviorTree/BT.h"

BehaviorTree::BehaviorTree()
    : m_rootNode(nullptr)
{}

BehaviorTree::~BehaviorTree()
{}

void BehaviorTree::SetRootNode(BTCompositeNode* root)
{
    m_rootNode = root;
}

BTCompositeNode* BehaviorTree::GetRootNode(BTCompositeNode* root)
{
    return m_rootNode;
}

BTContext& BehaviorTree::GetContext()
{
    return m_context;
}

BTStatus BehaviorTree::Run()
{
    m_rootNode->Reset();

    BTStatus status;
    do {
        status = m_rootNode->Execute(&m_context);
    } while (status == BTStatus::Running);

    return status;
}
