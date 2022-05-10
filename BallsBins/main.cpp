#include "mersennetwister.h"
#include "benchmark.h"
#include "balldistributor.h"

#include <QCoreApplication>
#include <QApplication>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QValueAxis>
#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
QT_CHARTS_USE_NAMESPACE

using namespace std;
int main(int argc, char **argv)
{
    int repetitions = 50; // !!50
    string fileName;
    ofstream file;

    fileName = "ballsbinsstatistics3.txt";

    file.open(fileName);

    if(file.bad()) cout<<"Problem opening the file"<<endl;

    mersenneTwister* mersenne = new mersenneTwister();

    benchmark result(&file);

    file<<"Format: bins firstCollision emptyUrns maxBalls oneBall twoBalls twoBalls-oneBall"<<std::endl;
//cout << "zaraz powtorzenia " << endl;
    for(int i=0; i<repetitions; i++)
    {
        int n = 1000;

        int counter = 0;
        //cout << "zaraz while " << endl;
        do
        {
            //cout << "mamy " << n << " urn"<< endl;


            //clearing benchmark before next sample
            result.emptyUrns[counter] = 0;

            //balls and bins and measuring results
            result.sampleSize[counter] = n;
            //cout << "ballDistributor " << endl;
            ballDistributor(n, &result, counter, mersenne);


            n += 1000;
            counter++;

        }while(n != 101000);
        result.serialize();
        cout << "repetition " << i << endl;
    }

    file.close();
   return 0;
}

