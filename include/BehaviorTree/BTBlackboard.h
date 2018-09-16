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

    bool GetInt32(BTStr key, BTInt32& val)
    {
        if (m_entries.find(key) != m_entries.end())
        {
            val = m_entries[key].value.valInt32;
            return true;
        }
        return false;
    }

    bool GetFloat32(BTStr key, BTFloat32& val)
    {
        if (m_entries.find(key) != m_entries.end())
        {
            val = m_entries[key].value.valFloat32;
            return true;
        }
        return false;
    }

    bool GetBool(BTStr key, bool& val)
    {
        if (m_entries.find(key) != m_entries.end())
        {
            val = m_entries[key].value.valBool;
            return true;
        }
        return false;
    }

    bool SetInt32(BTStr key, BTInt32 val)
    {
        if (m_entries.find(key) != m_entries.end())
        {
            m_entries[key].value.valInt32 = val;
            return true;
        }
        return false;
    }

    bool SetFloat32(BTStr key, BTFloat32 val)
    {
        if (m_entries.find(key) != m_entries.end())
        {
            m_entries[key].value.valFloat32 = val;
            return true;
        }
        return false;
    }

    bool SetBool(BTStr key, bool val)
    {
        if (m_entries.find(key) != m_entries.end())
        {
            m_entries[key].value.valBool = val;
            return true;
        }
        return false;
    }

    bool AddInt32(BTStr key, BTInt32 val)
    {
        if (m_entries.find(key) == m_entries.end())
        {
            m_entries[key].value.valInt32 = val;
            return true;
        }
        return false;
    }

    bool AddFloat32(BTStr key, BTFloat32 val)
    {
        if (m_entries.find(key) == m_entries.end())
        {
            m_entries[key].value.valFloat32 = val;
            return true;
        }
        return false;
    }

    bool AddBool(BTStr key, bool val)
    {
        if (m_entries.find(key) == m_entries.end())
        {
            m_entries[key].value.valBool = val;
            return true;
        }
        return false;
    }

private:

    EntryTable m_entries;
};
