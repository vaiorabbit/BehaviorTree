#pragma once

#include "BTCommon.h"
#include "BTNode.h"

class BTCompositeNode : public BTNode
{
public:

    BTCompositeNode();
    BTCompositeNode(BTInt32 childrenCount);
    virtual ~BTCompositeNode();

    bool Initialized() {
        return m_initialized;
    }
    virtual void Reset() override;

    BTNodeList GetChildren();
    size_t     GetChildrenCount();

    BTInt32 AddChild(BTNode* child);
    void    SetChild(BTNode* child, BTInt32 n);
    BTNode* GetChild(BTInt32 n);
    BTInt32 GetCurrentChildIndex();
    void    SetCurrentChildIndex(BTInt32 n);

protected:

    BTNodeList m_children;
    BTInt32    m_currentChildIndex;
    bool       m_initialized;
};


class BTSequenceNode : public BTCompositeNode
{
public:

    BTSequenceNode();
    BTSequenceNode(BTInt32 childrenCount);
    virtual BTStatus Execute(BTContext* ctx) override;
};

class BTSelectorNode : public BTCompositeNode
{
public:

    BTSelectorNode();
    BTSelectorNode(BTInt32 childrenCount);
    virtual BTStatus Execute(BTContext* ctx) override;
};

class BTIfElseNode : public BTCompositeNode
{
public:

    BTIfElseNode();
    virtual BTStatus Execute(BTContext* ctx) override;

    void SetConditionNode(BTNode* node);
    void SetIfNode(BTNode* node);
    void SetElseNode(BTNode* node);

private:
    BTIfElseNode(BTInt32 childrenCount) = delete;

};
