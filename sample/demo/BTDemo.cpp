#include "BehaviorTree.h"

int main(int argc, char**argv)
{
    BTNodeFactory factory;

    factory.RegisterStandardNodeTypes();

    BTCompositeNode* bt_root = static_cast<BTSequenceNode*>(factory.Create("BTSequenceNode"));
    bt_root->AddChild((factory.Create("BTSuccessNode")));
    bt_root->AddChild((factory.Create("BTSuccessNode")));

    bt_root->Reset();

    BTContext ctx;
    bt_root->Execute(&ctx);

    return 0;
}
