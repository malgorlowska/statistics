#ifndef BALLDISTRIBUTOR_H
#define BALLDISTRIBUTOR_H

#include "benchmark.h"
#include "mersennetwister.h"
#include <iostream>
class ballDistributor
{
public:
    ballDistributor(int, benchmark*, int, mersenneTwister*);
};

#endif // BALLDISTRIBUTOR_H
