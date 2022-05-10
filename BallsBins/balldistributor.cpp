#include "balldistributor.h"

using namespace std;
ballDistributor::ballDistributor(int n, benchmark* result, int benchmarkIndex, mersenneTwister* mersenne)
{
    //cout << "jestem w ballDistributor " << endl;
    int bins[n];// tab of bins
    int chosenBin;
    int chosenBin1;
    int chosenBin2;
    int chosenBin3;
    int thrownBalls = 0;
    int maxBalls = 1; //maximum number of balls
    bool firstCollision = false;
    int oneBall = 0; //number of bins which have minimum one ball
    int twoBalls = 0; //number of bins which have minimum two balls
    bool oneBallEvery = false;

    for( int i = 0; i < n; i++)
        bins[i] = 0;

    while(twoBalls != n)
    {
        //chosenBin = mersenne->MersenneTwister() % n ;
        chosenBin1 = mersenne->MersenneTwister() % n ;// generate numbers from 0 - n-1;
        chosenBin2 = mersenne->MersenneTwister() % n ;
        chosenBin3 = mersenne->MersenneTwister() % n ;

        if(bins[chosenBin1] > bins[chosenBin2])
            if(bins[chosenBin2] >= bins[chosenBin3])
               chosenBin = chosenBin3;
            else
                chosenBin = chosenBin2;
        else if(bins[chosenBin1] > bins[chosenBin3])
            chosenBin = chosenBin3;
        else chosenBin = chosenBin1;

        bins[chosenBin] += 1;
        thrownBalls += 1;
        //cout << "urna " << chosenBin << endl;

        if(firstCollision == false)
            if(bins[chosenBin] == 2)
            {
                //cout << "pierwsza kolizja " << endl;
                firstCollision = true;
                result->firstCollision[benchmarkIndex] = thrownBalls;
                //firstCollisionBallNumber = thrownBalls;
            }

        if(thrownBalls == n)
        {
            //cout << "wrzucono juz n " << n << endl;
            for( int i = 0; i < n; i++)
            {
                // number of empty bins after throwing n balls
                if(bins[i] == 0)
                    result->emptyUrns[benchmarkIndex] = result->emptyUrns[benchmarkIndex] + 1;
                // maximum of balls
                if(bins[i] > maxBalls)
                    maxBalls = bins[i];
            }
            result ->maxBalls[benchmarkIndex] = maxBalls;
        }

        if(bins[chosenBin] == 1)
            oneBall += 1;

        if(bins[chosenBin] == 2)
            twoBalls += 1;

        if(oneBallEvery == false)
        {
            if(oneBall == n)
             {   result ->oneBall[benchmarkIndex] = thrownBalls;
                //cout << "w kazdje jest minimum jedna " << endl;
                oneBallEvery = true;
            }
        }

        if(twoBalls == n)
        {
            result ->twoBall[benchmarkIndex] = thrownBalls;
            //cout << "w kazdje sa minimum dwie " << endl;
        }
    }
//cout << "wyszlam z while twoBalls " << endl;
    result ->twominusoneBall[benchmarkIndex] = (result ->twoBall[benchmarkIndex]) - (result ->oneBall[benchmarkIndex]);
}
