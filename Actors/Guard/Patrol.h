//
// Created by anthony on 8/2/16.
//

#ifndef GAMEAI_PATROL_H
#define GAMEAI_PATROL_H

#include <iostream>
#include "../State.h"
#include "Guard.h"
#include "../EntityNames.h"

class Patrol : public State<Guard>
{
private:
    Patrol(){}

public:

    virtual void Enter(Guard* guard)
    {
        std::cout << "\n" << getNameOfEntity(guard->ID()) << ": "
                  << "Time to go on patrol";
    }

    virtual void Execute(Guard* guard)
    {
        std::cout << "\n" << getNameOfEntity(guard->ID()) << ": "
                  << "Man this is boring...";
        guard->setLocation(loc_patrolRoute);
    }
};
#endif //GAMEAI_PATROL_H
