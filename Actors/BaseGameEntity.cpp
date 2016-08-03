//
// Created by anthony on 8/2/16.
//

#include <cassert>
#include "BaseGameEntity.h"

int BaseGameEntity::m_iNextValidID = 0;

//----------------------------- SetID -----------------------------------------
//
//  this must be called within each constructor to make sure the ID is set
//  correctly. It verifies that the value passed to the method is greater
//  or equal to the next valid ID, before setting the ID and incrementing
//  the next valid ID
//-----------------------------------------------------------------------------
void BaseGameEntity::setID(int val)
{
    assert((val >= m_iNextValidID) && "<BaseGameEntity::setID> Invalid ID");

    m_ID = val;

    m_iNextValidID = m_ID + 1;
}
