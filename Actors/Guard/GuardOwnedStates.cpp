//
// Created by anthony on 8/3/16.
//

#include <iostream>
#include "GuardOwnedStates.h"
#include "../location_type.h"
#include "Guard.h"
#include "../EntityNames.h"

//PATROL:

Patrol* Patrol::Instance()
{
    static Patrol instance;
    return &instance;
}

void Patrol::Enter(Guard* guard)
{
    if(guard->getLocation() != loc_patrolRoute)
    {
        guard->setLocation(loc_patrolRoute);
    }

    std::cout << "\n" << getNameOfEntity(guard->ID()) << ": "
              << "Time to patrol!";

}

void Patrol::Execute(Guard *guard)
{
    guard->incrementFatigue(1);
    guard->incrementThirst(1);
    guard->decrementPatrolRounds(1);

    if (guard->getPatrolRounds() >= 5)
    {
        if (guard->getThirst() >= 10)
            guard->changeState(Pub::Instance());
        else if (guard->getFatigue() >= 15)
            guard->changeState(Resting::Instance());
        else
            guard->changeState(Archery::Instance());
    }
}

void Patrol::Exit(Guard *guard)
{
    std::cout << "\n" << getNameOfEntity(guard->ID()) << ": "
                      << "Patrol complete.";
}

void Resting::Enter(Guard *guard)
{
    if (guard->getLocation() != loc_barracks)
        guard->setLocation(loc_barracks);

    std::cout << "\n" << getNameOfEntity(guard->ID()) << ": "
                      << "I'm exhausted!";
}

void Resting::Execute(Guard *guard)
{
    guard->de
}