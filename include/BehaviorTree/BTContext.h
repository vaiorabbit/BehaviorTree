#pragma once

#include "BTCommon.h"
#include "BTBlackboard.h"

class BTContext
{
public:

    BTContext()
        : m_blackboard()
        {}

    BTBlackboard& GetBlackboard() {
        return m_blackboard;
    }

private:

    BTBlackboard m_blackboard;
};
