#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <string>
#include <fstream>

class benchmark
{
public:
    int sampleSize[100];
    int firstCollision[100];
    int emptyUrns[100];
    int maxBalls[100];
    int oneBall[100];
    int twoBall[100];
    int twominusoneBall[100];
    std::ofstream* file;

    benchmark();
    benchmark(std::ofstream*);
    void serialize();
};

#endif // BENCHMARK_H
