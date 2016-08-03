//
// Created by anthony on 8/2/16.
//

#ifndef GAMEAI_STATE_H
#define GAMEAI_STATE_H

template <class entity_type>
class State
{
public:

    virtual void Enter(entity_type*)=0;

    virtual void Execute(entity_type*)=0;

    virtual void Exit(entity_type*)=0;

    virtual ~State(){}
};
#endif //GAMEAI_STATE_H
