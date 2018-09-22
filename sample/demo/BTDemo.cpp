#include <iostream>
#include <memory>
#include "BehaviorTree.h"

BTStatus ConsoleOutput(BTContext* ctx)
{
    std::cout << "Console Output" << std::endl;
    return BTStatus::Success;
}

int main(int argc, char* argv[])
{
    BTNodeFactory factory;

    factory.RegisterStandardNodeTypes();

    auto bt_root = static_cast<BTSequenceNode*>(factory.Create("BTSequenceNode"));
    // bt_root->AddChild((factory.Create("BTSuccessNode")));
    // bt_root->AddChild((factory.Create("BTSuccessNode")));

    auto bt_repeater = static_cast<BTRepeatNode*>(factory.Create("BTRepeatNode"));
    bt_repeater->SetLimit(5);

    auto bt_caller = static_cast<BTCallNode*>(factory.Create("BTCallNode"));
    bt_caller->SetCallbackFunction(ConsoleOutput);
    bt_repeater->AddChild(bt_caller);
    bt_root->AddChild(bt_repeater);

    BehaviorTree bt;
    bt.SetRootNode(bt_root);
    bt.Run();

    return 0;
}
