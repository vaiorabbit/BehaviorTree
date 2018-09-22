#pragma once

#include "BTCommon.h"

class BehaviorTree
{
public:

    BehaviorTree();
    virtual ~BehaviorTree();

    void SetRootNode(BTCompositeNode* root);
    BTCompositeNode* GetRootNode(BTCompositeNode* root);

    BTContext& GetContext();

    BTStatus Run();

protected:

    BTCompositeNode* m_rootNode;
    BTContext        m_context;
};
