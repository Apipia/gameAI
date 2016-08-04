//
// Created by anthony on 8/3/16.
//

#include <iostream>
#include "GuardOwnedStates.h"
#include "../location_type.h"
#include "Guard.h"
#include "../EntityNames.h"

//================PATROL:

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
    guard->setPatrolRounds(guard->ASSIGNED_PATROL_ROUNDS);
    std::cout << "\n" << getNameOfEntity(guard->ID()) << ": "
              << "Time to patrol!";

}

void Patrol::Execute(Guard *guard)
{
    std::cout << "\n" << getNameOfEntity(guard->ID()) << ": "
              << "On Patrol.";

    guard->incrementFatigue(10);
    guard->incrementThirst(8);
    guard->decrementPatrolRounds(1);

    if (guard->getPatrolRounds() >= 5)
    {
        if (guard->getThirst() >= 100)
            guard->changeState(Pub::Instance());
        else if (guard->getFatigue() >= 100)
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

//================RESTING:

void Resting::Enter(Guard *guard)
{
    if (guard->getLocation() != loc_barracks)
        guard->setLocation(loc_barracks);

    std::cout << "\n" << getNameOfEntity(guard->ID()) << ": "
                      << "I'm exhausted!";
}

void Resting::Execute(Guard *guard)
{
    std::cout << "\n" << getNameOfEntity(guard->ID()) << ": "
              << "Zzzz....";

    guard->decrementFatigue(20);

    if (guard->getFatigue() < 20)
        guard->changeState(Patrol::Instance());
}

void Resting::Exit(Guard *guard)
{
    std::cout << "\n" << getNameOfEntity(guard->ID()) << ": "
              << "All rested!";
}

//================ARCHERY:

void Archery::Enter(Guard *guard)
{
    std::cout << "\n" << getNameOfEntity(guard->ID()) << ": "
                    << "Reporting for Archery Practice.";

    if (guard->getLocation() != loc_archeryRange)
        guard->setLocation(loc_archeryRange);
}

void Archery::Execute(Guard *guard)
{
    if (guard->getArrows() <= 0)
    {
        std::cout << "\n" << getNameOfEntity(guard->ID()) << ": "
                  << "Getting arrows.";
        guard->setArrows(10);

    } else {
        std::cout << "\n" << getNameOfEntity(guard->ID()) << ": "
                  << "Knock... Pull... Release!";

        guard->decrementArrows(1);
        guard->incrementFatigue(5);
        guard->incrementThirst(8);

        if (guard->getFatigue() >= 100)
            guard->changeState(Resting::Instance());
        if (guard->getThirst() >= 100)
            guard->changeState(Pub::Instance());
    }
}

void Archery::Exit(Guard *guard)
{
    std::cout << "\n" << getNameOfEntity(guard->ID()) << ": "
              << "Archery Practice complete.";
}

//================PUB:

void Pub::Enter(Guard *guard)
{
    std::cout << "\n" << getNameOfEntity(guard->ID()) << ": "
              << "Time for a few rounds of drinks!";
    if (guard->getLocation() != loc_pub)
        guard->setLocation(loc_pub);
}

void Pub::Execute(Guard *guard)
{
    std::cout << "\n" << getNameOfEntity(guard->ID()) << ": "
              << "Delicious.";

    guard->decrementThirst(25);

    if (guard->getThirst() <= 25)
        guard->changeState(Archery::Instance());
}

void Pub::Exit(Guard *guard)
{
    std::cout << "\n" << getNameOfEntity(guard->ID()) << ": "
              << "Thirst quenched!";
}