//
// Created by anthony on 8/2/16.
//

#ifndef GAMEAI_GUARD_H
#define GAMEAI_GUARD_H

#include "../BaseGameEntity.h"
#include "../StateMachine.h"

class Guard : public BaseGameEntity
{
private:
    StateMachine<Guard>* stateMachine;

    //Other things the Guard will need to keep track of.
    //like Hunger, Location, etc.
    location_type location;

    int thirst;

    int fatigue;

    int arrows;

public:
    Guard(int id);

    int getThirst(){return thirst;}
    int getFatigue(){return fatigue;}
    int getArrows(){return arrows;}
    location_type getLocation(){return location;}

    void setThirst(int i){thirst = i;}
    void setFatigue(int i){fatigue = i;}
    void setArrows(int i){arrows = i;}
};
#endif //GAMEAI_GUARD_H
