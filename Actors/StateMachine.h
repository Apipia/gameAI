//
// Created by anthony on 8/2/16.
//

#ifndef GAMEAI_STATEMACHINE_H
#define GAMEAI_STATEMACHINE_H

#include <cstdlib>
#include <cassert>
#include "State.h"

template <class entity_type>
class StateMachine
{
private:

    entity_type* owner;
    State<entity_type>* currentState;
    State<entity_type>* previousState;
    State<entity_type>* globalState;

public:
    StateMachine(<entity_type>* actor_owner) : owner(actor_owner),
                                               currentState(NULL),
                                               previousState(NULL),
                                               globalState(NULL)
    {}

    //setters
    void setCurrentState(entity_type* s)
    {
        currentState = s;
    }

    void setPreviousState(entity_type* s)
    {
        previousState = s;
    }

    void setGlobalState(entity_type* s)
    {
        globalState = s;
    }

    //Do the thing
    inline void update()const
    {
        //global thing
        if(globalState) globalState->Execute(owner);

        //state thing
        if(currentState) currentState->Execute(owner);
    }

    inline void changeState(State<entity_type>* newState)
    {
        assert(newState && "<StateMachine>::changeState>: invalid state");

        previousState = currentState;

        currentState->Exit(owner);

        currentState = newState;

        currentState->Enter(owner);
    }

    inline void revertToPreviousState()
    {
        changeState(previousState);
    }

    //accessors
    State<entity_type>* getCurrentState(){return currentState;}
    State<entity_type>* getPreviousState(){return previousState;}
    State<entity_type>* getGlobalState(){return globalState;}

    //current state equal to the type
    bool isInState(const State<entity_type>& st)const
    {
        return typeid(*currentState) == typeid(st);
    }
};


#endif //GAMEAI_STATEMACHINE_H
