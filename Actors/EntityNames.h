//
// Created by anthony on 8/2/16.
//

#ifndef GAMEAI_ENTITYNAMES_H
#define GAMEAI_ENTITYNAMES_H

#include <iostream>
#include <string>

enum
{
    ent_guard,
    ent_ninja
};

inline std::string getNameOfEntity(int n)
{
    switch(n)
    {
        case ent_guard:
            return "Guard";

        case ent_ninja:
            return "Ninja";

        default:
            return "Invalid ID";
    }

}
#endif //GAMEAI_ENTITYNAMES_H
