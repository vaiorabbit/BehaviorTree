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


class BTNegateNode : public BTDecoratorNode
{
public:

    BTNegateNode();
    virtual BTStatus Execute(BTContext* ctx) override;
};
