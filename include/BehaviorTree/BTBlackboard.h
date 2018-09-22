#pragma once

#include "BTCommon.h"
#include <map>

struct BTBlackboardEntry
{
    enum Type : BTInt32 {
        eTypeInt32,
        eTypeFloat32,
        eTypeBool
    };

    typedef union {
        BTInt32 valInt32;
        BTFloat32 valFloat32;
        bool valBool;
    } Value;

    enum Type  type;
    Value value;
};

class BTBlackboard
{
public:
    typedef std::map<BTStr, BTBlackboardEntry> EntryTable;

    BTBlackboard()
        : m_entries()
        {}

    bool GetInt32(BTStr key, BTInt32& val);
    bool GetFloat32(BTStr key, BTFloat32& val);
    bool GetBool(BTStr key, bool& val);

    bool SetInt32(BTStr key, BTInt32 val);
    bool SetFloat32(BTStr key, BTFloat32 val);
    bool SetBool(BTStr key, bool val);

    bool AddInt32(BTStr key, BTInt32 val);
    bool AddFloat32(BTStr key, BTFloat32 val);

private:

    EntryTable m_entries;
};
