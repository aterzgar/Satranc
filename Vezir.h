// Arda Mavi - ardamavi.com

#ifndef VEZİR_H
#define VEZİR_H

#include "Tas.h"

class Vezir : public Tas{

    public:
        Vezir(takım, int, int);

    bool yolKntrl(vector<Tas*> , pair <int,  int>);

};

#endif