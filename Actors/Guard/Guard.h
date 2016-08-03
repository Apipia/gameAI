//
// Created by anthony on 8/2/16.
//

#ifndef GAMEAI_GUARD_H
#define GAMEAI_GUARD_H


#include "../BaseGameEntity.h"
#include "../StateMachine.h"
#include "../location_type.h"
#include "GuardOwnedStates.h"

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

    int patrolRounds;

public:
    Guard(int id):location(loc_barracks),
                  thirst(0),
                  fatigue(0),
                  arrows(0),
                  BaseGameEntity(id)
    {
        //build the state machine, and toss this guard in there.
        stateMachine = new StateMachine<Guard>(this);
        stateMachine->setCurrentState(Resting::Instance());
    }

    ~Guard(){delete stateMachine;};

    int getPatrolRounds(){return patrolRounds;}
    int getThirst(){return thirst;}
    int getFatigue(){return fatigue;}
    int getArrows(){return arrows;}
    location_type getLocation(){return location;}

    void incrementFatigue(int i){fatigue += i;}
    void incrementThirst(int i){thirst += i;}
    void incrementArrows(int i){arrows += i;}
    void decrementPatrolRounds(int i){patrolRounds -= 1;}
    void setThirst(int i){thirst = i;}
    void setFatigue(int i){fatigue = i;}
    void setArrows(int i){arrows = i;}
    void setLocation(location_type p_location){location = p_location;}

    void changeState(State<Guard>* s)
    {
        stateMachine->changeState(s);
    }

};
#endif //GAMEAI_GUARD_H
