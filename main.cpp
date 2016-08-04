#include <iostream>
#include <zconf.h>
#include "Actors/Guard/Guard.h"
#include "Actors/EntityNames.h"

int main() {

    Guard* guard = new Guard(ent_guard);
    for(int i = 0; i < 200; i++){
        guard->Update();
        usleep(2000000);
    }
    return 0;
}