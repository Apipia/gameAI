//
// Created by anthony on 8/3/16.
//

#ifndef GAMEAI_GUARDOWNEDSTATES_H
#define GAMEAI_GUARDOWNEDSTATES_H

#include "../State.h"

class Guard;

class Patrol : public State<Guard>
{
private:

    Patrol(){}
    Patrol(const Patrol&);
    Patrol& operator=(const Patrol&);

public:

    static Patrol* Instance();

    virtual void Enter(Guard* guard);

    virtual void Execute(Guard* guard);

    virtual void Exit(Guard* guard);

};

class Resting : public State<Guard>
{
private:

    Resting(){}
    Resting(const Resting&);
    Resting& operator=(const Patrol&);

public:

    static Resting* Instance();

    virtual void Enter(Guard* guard);

    virtual void Execute(Guard* guard);

    virtual void Exit(Guard* guard);

};
#endif //GAMEAI_GUARDOWNEDSTATES_H
