#ifndef ANALYZESTATISTICS_H
#define ANALYZESTATISTICS_H
#include <iostream>
#include <fstream>
#include <vector>

class analyzeStatistics
{

    std::string dataFormat;
    std::ofstream* file;
    std::string fName;

    int firstC[100][50];
    int emptyU[100][50];
    int maxB[100][50];
    int oneB[100][50];
    int twoB[100][50];
    int twoM[100][50];

    double sampleSize[100];
    double firstCollision[100];
    double emptyUrns[100];
    double maxBalls[100];
    double oneBall[100];
    double twoBalls[100];
    double twoMinusOne[100];

    double samplesCount[100];
    double quotientFirstCollisionToN[100];
    double quotientFirstCollisionToN2[100];
    double quotientEmptyUrnsToN[100];

public:
    analyzeStatistics();
    analyzeStatistics(std::string);

    bool readFile(std::string);

    double makeAverageFirstCollision(int);
    double makeAverageEmptyUrns(int);
    double makeAverageMaxBalls(int);
    double makeAverageOneBall(int);
    double makeAverageTwoBalls(int);
    double makeAverageTwoMinusOne(int);

    double makeQuotientFirstCollisionToN(int);
    double makeQuotientFirstCollisionToSRoot(int);
    double makeQuotientEmptyUrnsToN(int);
    double makeQuotientMaxBallsToN(int);
    double makeQuotientMaxBallsToLog1(int);
    double makeQuotientMaxBallsToLog2(int);
    double makeQuotientOneBallToN(int);
    double makeQuotientOneBallToLog(int);
    double makeQuotientOneBallToN2(int);
    double makeQuotientTwoBallsToN(int);
    double makeQuotientTwoBallsToLog(int);
    double makeQuotientTwoBallsToN2(int);
    double makeQuotientTwoMinusOneToN(int);
    double makeQuotientTwoMinusOneToLog1(int);
    double makeQuotientTwoMinusOneToLog2(int);
    double getterSampleSize(int);
    double getterFirstCollision(int,int);
    double getterEmptyUrns(int,int);
    double getterMaxBalls(int,int);
    double getterOneBall(int,int);
    double getterTwoBalls(int,int);
    double getterTwoMinusOne(int,int);

};

#endif // ANALYZESTATISTICS_H
