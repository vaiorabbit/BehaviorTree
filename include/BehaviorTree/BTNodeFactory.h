#pragma once

#include "BTCommon.h"

class BTNodeFactory
{
public:

    BTNodeFactory()
        : m_createFuncs()
        {}

    template<typename BTDerivedNode>
    void RegisterType(const BTStr& name) {
        static_assert(std::is_base_of<BTNode, BTDerivedNode>::value, "BTNodeFactory::RegisterType : Failed to register this type");
        m_createFuncs[name] = &CreateNode<BTDerivedNode>;
    }

    void RegisterStandardNodeTypes() {
        RegisterType<BTSequenceNode>("BTSequenceNode");
        RegisterType<BTSelectorNode>("BTSelectorNode");
        RegisterType<BTIfElseNode>("BTIfElseNode");

        RegisterType<BTForceSuccessNode>("BTForceSuccessNode");
        RegisterType<BTForceFailureNode>("BTForceFailureNode");
        RegisterType<BTForceRunningNode>("BTForceRunningNode");
        RegisterType<BTNegateNode>("BTNegateNode");
        RegisterType<BTRepeatNode>("BTRepeatNode");

        RegisterType<BTSuccessNode>("BTSuccessNode");
        RegisterType<BTFailureNode>("BTFailureNode");
        RegisterType<BTRunningNode>("BTRunningNode");
        RegisterType<BTCallNode>("BTCallNode");
    }


    BTNode* Create(const BTStr& name) {
        auto it = m_createFuncs.find(name);
        return it != m_createFuncs.end() ? it->second() : nullptr;
    }

private:

    typedef BTNode* (*NodeCreateFunc)();
    typedef std::map<BTStr, NodeCreateFunc> NodeCreaFuncs;
    NodeCreaFuncs m_createFuncs;

    template<typename BTDerivedNode>
    static BTNode* CreateNode() {
        return new BTDerivedNode();
    }
};
