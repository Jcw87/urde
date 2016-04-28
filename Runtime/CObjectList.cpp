#include "CObjectList.hpp"

namespace urde
{

CObjectList::CObjectList(EGameObjectList listEnum)
: m_listEnum(listEnum)
{}

void CObjectList::AddObject(CEntity& entity)
{
    if (IsQualified())
    {
        if (m_lastId != -1)
            m_list[m_lastId].next = entity.GetUniqueId() & 0x3ff;
        TUniqueId prevLast = m_lastId;
        m_lastId = entity.GetUniqueId() & 0x3ff;
        SObjectListEntry& newEnt = m_list[m_lastId];
        newEnt.entity = &entity;
        newEnt.prev = prevLast;
        newEnt.next = -1;
        ++m_count;
    }
}

void CObjectList::RemoveObject(TUniqueId uid)
{
    uid = uid & 0x3ff;
    SObjectListEntry& ent = m_list[uid];
    if (!ent.entity || ent.entity->GetUniqueId() != uid)
        return;
    if (uid == m_lastId)
    {
        m_lastId = ent.prev;
        if (ent.prev != -1)
            m_list[ent.prev].next = -1;
    }
    else
    {
        if (ent.prev != -1)
            m_list[ent.prev].next = -1;
        m_list[ent.next].prev = -1;
    }
    ent.entity = nullptr;
    ent.prev = -1;
    ent.next = -1;
    --m_count;
}

const CEntity* CObjectList::GetObjectById(TUniqueId uid) const
{
    if (!uid)
        return nullptr;
    return m_list[uid & 0x3ff].entity;
}

CEntity* CObjectList::GetObjectById(TUniqueId uid)
{
    if (!uid)
        return nullptr;
    return m_list[uid & 0x3ff].entity;
}

bool CObjectList::IsQualified() {return true;}

}