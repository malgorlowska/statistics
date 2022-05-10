#include "benchmark.h"
#include <iostream>

benchmark::benchmark()
{
    for(int i = 0; i < 100; i++)
    {
        sampleSize[i] = 0;
        firstCollision[i] = 0;
        emptyUrns[i] = 0;
        maxBalls[i] = 0;
        oneBall[i] = 0;
        twoBall[i] = 0;
        twominusoneBall[i] = 0;
    }
}

benchmark::benchmark(std::ofstream* f)
{
    file = f;
    for(int i = 0; i < 100; i++)
    {
        sampleSize[i] = 0;
        firstCollision[i] = 0;
        emptyUrns[i] = 0;
        maxBalls[i] = 0;
        oneBall[i] = 0;
        twoBall[i] = 0;
        twominusoneBall[i] = 0;
    }
}


void benchmark::serialize()
{

    for(int i=0; i<100; i++)
    {
    *file<<sampleSize[i]<<" "<<firstCollision[i]<<" "<<emptyUrns[i]<<" "<<maxBalls[i]<<" "<<oneBall[i]<<" "<<twoBall[i]<<" "<<twominusoneBall[i]<<std::endl;
    }
}

