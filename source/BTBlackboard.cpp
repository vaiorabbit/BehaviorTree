#include "BehaviorTree/BTBlackboard.h"

bool BTBlackboard::GetInt32(BTStr key, BTInt32& val)
{
    if (m_entries.find(key) != m_entries.end())
    {
        val = m_entries[key].value.valInt32;
        return true;
    }
    return false;
}

bool BTBlackboard::GetFloat32(BTStr key, BTFloat32& val)
{
    if (m_entries.find(key) != m_entries.end())
    {
        val = m_entries[key].value.valFloat32;
        return true;
    }
    return false;
}

bool BTBlackboard::GetBool(BTStr key, bool& val)
{
    if (m_entries.find(key) != m_entries.end())
    {
        val = m_entries[key].value.valBool;
        return true;
    }
    return false;
}

bool BTBlackboard::SetInt32(BTStr key, BTInt32 val)
{
    if (m_entries.find(key) != m_entries.end())
    {
        m_entries[key].value.valInt32 = val;
        return true;
    }
    return false;
}

bool BTBlackboard::SetFloat32(BTStr key, BTFloat32 val)
{
    if (m_entries.find(key) != m_entries.end())
    {
        m_entries[key].value.valFloat32 = val;
        return true;
    }
    return false;
}

bool BTBlackboard::SetBool(BTStr key, bool val)
{
    if (m_entries.find(key) != m_entries.end())
    {
        m_entries[key].value.valBool = val;
        return true;
    }
    return false;
}

bool BTBlackboard::AddInt32(BTStr key, BTInt32 val)
{
    if (m_entries.find(key) == m_entries.end())
    {
        m_entries[key].value.valInt32 += val;
        return true;
    }
    return false;
}

bool BTBlackboard::AddFloat32(BTStr key, BTFloat32 val)
{
    if (m_entries.find(key) == m_entries.end())
    {
        m_entries[key].value.valFloat32 += val;
        return true;
    }
    return false;
}
