#include "analyzestatistics.h"
#include <cmath>

analyzeStatistics::analyzeStatistics()
{
    for(int i=0; i<100; i++)
    {
        sampleSize[i] = 0;
        firstCollision[i] = 0;
        emptyUrns[i] = 0;
        maxBalls[i] = 0;
        oneBall[i] = 0;
        twoBalls[i] = 0;
        twoMinusOne[i] = 0;

        samplesCount[i] = 0;
        quotientFirstCollisionToN[i] = 0;
        quotientFirstCollisionToN2[i] = 0;
        quotientEmptyUrnsToN[i] = 0;
    }

}
analyzeStatistics::analyzeStatistics(std::string f)
{
    fName = f;
    readFile(fName);
    for(int i=0; i<10; i++)
    {
        sampleSize[i] = 0;
        firstCollision[i] = 0;
        emptyUrns[i] = 0;
        maxBalls[i] = 0;
        oneBall[i] = 0;
        twoBalls[i] = 0;
        twoMinusOne[i] = 0;

        samplesCount[i] = 0;
        quotientFirstCollisionToN[i] = 0;
        quotientFirstCollisionToN2[i] = 0;
        quotientEmptyUrnsToN[i] = 0;
    }

}

bool analyzeStatistics::readFile( std::string fileName )
{
    std::cout << "jestem w readfile" << std::endl;
    std::string linia;
    std::ifstream plik;
    plik.open( fileName.c_str() );
    std::cout << "probowalam otworzyc" << std::endl;
    if( !plik.good() )
    {
        std::cout << "plik not good" << std::endl;
         return false;
    }

    getline(plik,dataFormat);
    std::cout << dataFormat << std::endl;
    int index2 = -1;
    int index=0;

    while( true ) //pętla nieskończona
    {
        int a, b, c, d, e, f, g;

        plik >> a >> b >> c >> d >> e >> f >> g;
        //std::cout << a <<" "<< b<<" " << c<<" " << d<<" " << e<<" " << f<<" " << g<<" " << std::endl;
        if( !plik.fail() )
        {
            if(a == 1000)
                index2 += 1;


            //std::cout << "intex: "<<index<<" index2: "<<index2<<std::endl;

            index = a/1000-1; //TODO: refactor, no "magic numbers" - dependant on sample size
            sampleSize[index] = a;
            firstCollision[index] += b;
            firstC[index][index2] = b;
            emptyUrns[index] += c;
            emptyU[index][index2] = c;
            maxBalls[index] += d;
            maxB[index][index2] = d;
            oneBall[index] += e;
            oneB[index][index2] = e;
            twoBalls[index] += f;
            twoB[index][index2] = f;
            twoMinusOne[index] += g;
            twoM[index][index2] = g;

            samplesCount[index] ++;
        }
        else
             break; //zakończ wczytywanie danych - wystąpił jakiś błąd (np. nie ma więcej danych w pliku)

    }

   // std::cout << sampleSize[0] <<" "<< timeCount[0] <<" "<< comparisonsCount[0] <<" "<< swapsCount[0] <<std::endl;
    plik.close();
    return true;
}

double analyzeStatistics::makeAverageFirstCollision(int n)
{
    std::cout <<"SampleSize: "<<sampleSize[n]<<" FirstCollision: "<<firstCollision[n]<<" samples: "<<samplesCount[n]<< " average: " <<firstCollision[n]/samplesCount[n]<<std::endl;
    return firstCollision[n]/samplesCount[n];
}

double analyzeStatistics::makeAverageEmptyUrns(int n)
{
    std::cout <<"SampleSize: "<<sampleSize[n]<<" emptyUrns: "<<emptyUrns[n]<<" samples: "<<samplesCount[n]<< " average: " <<emptyUrns[n]/samplesCount[n]<<std::endl;
    return emptyUrns[n]/samplesCount[n];
}

double analyzeStatistics::makeAverageMaxBalls(int n)
{
    return maxBalls[n]/samplesCount[n];
}

double analyzeStatistics::makeAverageOneBall(int n)
{
    return oneBall[n]/samplesCount[n];
}
double analyzeStatistics::makeAverageTwoBalls(int n)
{
    return twoBalls[n]/samplesCount[n];
}
double analyzeStatistics::makeAverageTwoMinusOne(int n)
{
    return twoMinusOne[n]/samplesCount[n];
}


double analyzeStatistics::makeQuotientFirstCollisionToN(int n)
{
    return (firstCollision[n]/samplesCount[n])/sampleSize[n];
}

double analyzeStatistics::makeQuotientFirstCollisionToSRoot(int n)
{
  //  std::cout << swapsCount[n]<<" "<<samplesCount[n]<<" "<<sampleSize[n]<<" "<<(swapsCount[n]/samplesCount[n])/sampleSize[n]<<std::endl;
    return (firstCollision[n]/samplesCount[n])/sqrt(sampleSize[n]); // przez pierwiastek!!!
}
double analyzeStatistics::makeQuotientEmptyUrnsToN(int n)
{
  //  std::cout << swapsCount[n]<<" "<<samplesCount[n]<<" "<<sampleSize[n]<<" "<<(swapsCount[n]/samplesCount[n])/sampleSize[n]<<std::endl;
    return (emptyUrns[n]/samplesCount[n])/sampleSize[n];
}
double analyzeStatistics::makeQuotientMaxBallsToN(int n)
{
    return (maxBalls[n]/samplesCount[n])/sampleSize[n];
}
double analyzeStatistics::makeQuotientMaxBallsToLog1(int n)
{
    return (maxBalls[n]/samplesCount[n])/(log(sampleSize[n])/log(log(sampleSize[n])));
}
double analyzeStatistics::makeQuotientMaxBallsToLog2(int n)
{
    return (maxBalls[n]/samplesCount[n])/(log(log(sampleSize[n])));
}
double analyzeStatistics::makeQuotientOneBallToN(int n)
{
    return (oneBall[n]/samplesCount[n])/sampleSize[n];
}
double analyzeStatistics::makeQuotientOneBallToLog(int n)
{
    return (oneBall[n]/samplesCount[n])/(sampleSize[n]*log(sampleSize[n]));
}
double analyzeStatistics::makeQuotientOneBallToN2(int n)
{
    return (oneBall[n]/samplesCount[n])/(sampleSize[n]*sampleSize[n]);
}
double analyzeStatistics::makeQuotientTwoBallsToN(int n)
{
    return (twoBalls[n]/samplesCount[n])/sampleSize[n];
}
double analyzeStatistics::makeQuotientTwoBallsToLog(int n)
{
    return (twoBalls[n]/samplesCount[n])/(sampleSize[n]*log(sampleSize[n]));
}
double analyzeStatistics::makeQuotientTwoBallsToN2(int n)
{
    return (twoBalls[n]/samplesCount[n])/(sampleSize[n]*sampleSize[n]);
}
double analyzeStatistics::makeQuotientTwoMinusOneToN(int n)
{
    return (twoMinusOne[n]/samplesCount[n])/sampleSize[n];
}
double analyzeStatistics::makeQuotientTwoMinusOneToLog1(int n)
{
 return (twoMinusOne[n]/samplesCount[n])/(sampleSize[n]*log(sampleSize[n]));
}
double analyzeStatistics::makeQuotientTwoMinusOneToLog2(int n)
{
 return (twoMinusOne[n]/samplesCount[n])/(sampleSize[n]*log(log(sampleSize[n])));
}



double analyzeStatistics::getterSampleSize(int n)
{
    return sampleSize[n];
}
double analyzeStatistics::getterFirstCollision(int n, int k)
{
    return firstC[n][k];
}
double analyzeStatistics::getterEmptyUrns(int n, int k)
{
    return emptyU[n][k];
}
double analyzeStatistics::getterMaxBalls(int n, int k)
{
    return maxB[n][k];
}
double analyzeStatistics::getterOneBall(int n, int k)
{
    return oneB[n][k];
}
double analyzeStatistics::getterTwoBalls(int n, int k)
{
    return twoB[n][k];
}
double analyzeStatistics::getterTwoMinusOne(int n, int k)
{
    return twoM[n][k];
}
