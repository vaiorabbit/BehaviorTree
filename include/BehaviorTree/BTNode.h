#pragma once

#include "BTCommon.h"

class BTNode
{
public:

    BTNode();
    virtual ~BTNode();

    const BTNodeName& GetNodeName();
    void              SetNodeName(const BTNodeName& nodeName);

    BTNodeID GetID();
    void     SetID(BTNodeID id);

    BTCompositeNode* GetParent();
    void             SetParent(BTCompositeNode* parentNode);

    virtual void Reset() {}
    virtual void OnInit() {}
    virtual void OnTerm() {}
    virtual BTStatus Execute(BTContext* ctx) = 0;

private:

    BTNodeName       m_nodeName;
    BTNodeID         m_id;
    BTCompositeNode* m_parentNode;
};
