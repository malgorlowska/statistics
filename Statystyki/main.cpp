#include "mainwindow.h"
#include "analyzestatistics.h"

#include <QApplication>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QScatterSeries>
#include <QValueAxis>
#include <QLogValueAxis>
#include <QTextStream>
//#include <QCustomPlot>

QT_CHARTS_USE_NAMESPACE
int main(int argc, char *argv[])
{
    std::cout << "Poczatek main" << std::endl;
    QApplication a(argc, argv);
    analyzeStatistics analyze;
    analyzeStatistics analyze2;
    analyzeStatistics analyze3;
    std::cout << "Proboje otworzyc plik" << std::endl;
    if(!analyze.readFile("ballsbinsstatistics.txt"))
        std::cout << "Nie udalo sie otworzyc pliku!" << std::endl;
    if(!analyze2.readFile("ballsbinsstatistics2.txt"))
        std::cout << "Nie udalo sie otworzyc pliku!" << std::endl;
    if(!analyze3.readFile("ballsbinsstatistics3.txt"))
        std::cout << "Nie udalo sie otworzyc pliku!" << std::endl;

    std::cout << "Tworzę serię.." << std::endl;
    QLineSeries *seriesLine = new QLineSeries();
    QLineSeries *seriesLine2 = new QLineSeries();
    QLineSeries *seriesLine3 = new QLineSeries();
    seriesLine->append(1000, 0.001);
//seriesLine3->append(1000, 0.01);
    QScatterSeries *serieses[50];
    for( int i = 0; i < 100; i++)
    {
        //seriesLine->append(analyze.getterSampleSize(i), analyze.makeAverageFirstCollision(i));
        //seriesLine->append(analyze.getterSampleSize(i), analyze.makeAverageEmptyUrns(i));
        //seriesLine->append(analyze.getterSampleSize(i), analyze.makeAverageMaxBalls(i));
        //seriesLine->append(analyze.getterSampleSize(i), analyze.makeAverageOneBall(i));
        //seriesLine->append(analyze.getterSampleSize(i), analyze.makeAverageTwoBalls(i));
        //seriesLine->append(analyze.getterSampleSize(i), analyze.makeAverageTwoMinusOne(i));

        //seriesLine2->append(analyze2.getterSampleSize(i), analyze2.makeAverageFirstCollision(i));
        //seriesLine2->append(analyze2.getterSampleSize(i), analyze2.makeAverageEmptyUrns(i));
        //seriesLine2->append(analyze2.getterSampleSize(i), analyze2.makeAverageMaxBalls(i));
        //seriesLine2->append(analyze2.getterSampleSize(i), analyze2.makeAverageOneBall(i));
        //seriesLine2->append(analyze2.getterSampleSize(i), analyze2.makeAverageTwoBalls(i));
        //seriesLine2->append(analyze2.getterSampleSize(i), analyze2.makeAverageTwoMinusOne(i));

        //seriesLine3->append(analyze3.getterSampleSize(i), analyze3.makeAverageFirstCollision(i));
        //seriesLine3->append(analyze3.getterSampleSize(i), analyze3.makeAverageEmptyUrns(i));
        //seriesLine3->append(analyze3.getterSampleSize(i), analyze3.makeAverageMaxBalls(i));
        //seriesLine3->append(analyze3.getterSampleSize(i), analyze3.makeAverageOneBall(i));
        //seriesLine3->append(analyze3.getterSampleSize(i), analyze3.makeAverageTwoBalls(i));
        //seriesLine3->append(analyze3.getterSampleSize(i), analyze3.makeAverageTwoMinusOne(i));
    }

    /*for( int i = 0; i < 50; i++)
    {
        serieses[i] = new QScatterSeries();

        for(int j = 0; j < 100; j++)
        {
            //serieses[i]->append(analyze.getterSampleSize(j), analyze.getterFirstCollision(j,i));
            //serieses[i]->append(analyze.getterSampleSize(j), analyze.getterEmptyUrns(j,i));
            //serieses[i]->append(analyze.getterSampleSize(j), analyze.getterMaxBalls(j,i));
            //serieses[i]->append(analyze.getterSampleSize(j), analyze.getterOneBall(j,i));
            //serieses[i]->append(analyze.getterSampleSize(j), analyze.getterTwoBalls(j,i));
            //serieses[i]->append(analyze.getterSampleSize(j), analyze.getterTwoMinusOne(j,i));
        }
    }*/

    for( int i = 0; i < 100; i++)
    {
        //seriesLine->append(analyze.getterSampleSize(i), analyze.makeQuotientFirstCollisionToN(i));
        //seriesLine->append(analyze.getterSampleSize(i), analyze.makeQuotientEmptyUrnsToN(i));
        //seriesLine->append(analyze.getterSampleSize(i), analyze.makeQuotientMaxBallsToN(i));
        //seriesLine->append(analyze.getterSampleSize(i), analyze.makeQuotientOneBallToN(i));
        //seriesLine->append(analyze.getterSampleSize(i), analyze.makeQuotientTwoBallsToN(i));
        //seriesLine->append(analyze.getterSampleSize(i), analyze.makeQuotientTwoMinusOneToN(i));

        //seriesLine2->append(analyze2.getterSampleSize(i), analyze2.makeQuotientFirstCollisionToN(i));
        //seriesLine2->append(analyze2.getterSampleSize(i), analyze2.makeQuotientEmptyUrnsToN(i));
        //seriesLine2->append(analyze2.getterSampleSize(i), analyze2.makeQuotientMaxBallsToN(i));
        //seriesLine2->append(analyze2.getterSampleSize(i), analyze2.makeQuotientOneBallToN(i));
        //seriesLine2->append(analyze2.getterSampleSize(i), analyze2.makeQuotientTwoBallsToN(i));
        //seriesLine2->append(analyze2.getterSampleSize(i), analyze2.makeQuotientTwoMinusOneToN(i));

        //seriesLine3->append(analyze3.getterSampleSize(i), analyze3.makeQuotientFirstCollisionToN(i));
        //seriesLine3->append(analyze3.getterSampleSize(i), analyze3.makeQuotientEmptyUrnsToN(i));
        //seriesLine3->append(analyze3.getterSampleSize(i), analyze3.makeQuotientMaxBallsToN(i));
        //seriesLine3->append(analyze3.getterSampleSize(i), analyze3.makeQuotientOneBallToN(i));
        //seriesLine3->append(analyze3.getterSampleSize(i), analyze3.makeQuotientTwoBallsToN(i));
        //seriesLine3->append(analyze3.getterSampleSize(i), analyze3.makeQuotientTwoMinusOneToN(i));

        //seriesLine->append(analyze.getterSampleSize(i), analyze.makeQuotientFirstCollisionToSRoot(i));
        //seriesLine->append(analyze.getterSampleSize(i), analyze.makeQuotientMaxBallsToLog1(i));
        //seriesLine->append(analyze.getterSampleSize(i), analyze.makeQuotientMaxBallsToLog2(i));
        //seriesLine->append(analyze.getterSampleSize(i), analyze.makeQuotientOneBallToLog(i));
        //seriesLine->append(analyze.getterSampleSize(i), analyze.makeQuotientOneBallToN2(i));
        //seriesLine->append(analyze.getterSampleSize(i), analyze.makeQuotientTwoBallsToLog(i));
        //seriesLine->append(analyze.getterSampleSize(i), analyze.makeQuotientTwoBallsToN2(i));
        //seriesLine->append(analyze.getterSampleSize(i), analyze.makeQuotientTwoMinusOneToLog1(i));
        seriesLine->append(analyze.getterSampleSize(i), analyze.makeQuotientTwoMinusOneToLog2(i));

        //seriesLine2->append(analyze2.getterSampleSize(i), analyze2.makeQuotientFirstCollisionToSRoot(i));
        //seriesLine2->append(analyze2.getterSampleSize(i), analyze2.makeQuotientMaxBallsToLog1(i));
        //seriesLine2->append(analyze2.getterSampleSize(i), analyze2.makeQuotientMaxBallsToLog2(i));
        //seriesLine2->append(analyze2.getterSampleSize(i), analyze2.makeQuotientOneBallToLog(i));
        //seriesLine2->append(analyze2.getterSampleSize(i), analyze2.makeQuotientOneBallToN2(i));
        //seriesLine2->append(analyze2.getterSampleSize(i), analyze2.makeQuotientTwoBallsToLog(i));
        //seriesLine2->append(analyze2.getterSampleSize(i), analyze2.makeQuotientTwoBallsToN2(i));
        //seriesLine2->append(analyze2.getterSampleSize(i), analyze2.makeQuotientTwoMinusOneToLog1(i));
        seriesLine2->append(analyze2.getterSampleSize(i), analyze2.makeQuotientTwoMinusOneToLog2(i));

        //seriesLine3->append(analyze3.getterSampleSize(i), analyze3.makeQuotientFirstCollisionToSRoot(i));
        //seriesLine3->append(analyze3.getterSampleSize(i), analyze3.makeQuotientMaxBallsToLog1(i));
        //seriesLine3->append(analyze3.getterSampleSize(i), analyze3.makeQuotientMaxBallsToLog2(i));
        //seriesLine3->append(analyze3.getterSampleSize(i), analyze3.makeQuotientOneBallToLog(i));
        //seriesLine3->append(analyze3.getterSampleSize(i), analyze3.makeQuotientOneBallToN2(i));
        //seriesLine3->append(analyze3.getterSampleSize(i), analyze3.makeQuotientTwoBallsToLog(i));
        //seriesLine3->append(analyze3.getterSampleSize(i), analyze3.makeQuotientTwoBallsToN2(i));
        //seriesLine3->append(analyze3.getterSampleSize(i), analyze3.makeQuotientTwoMinusOneToLog1(i));
        seriesLine3->append(analyze3.getterSampleSize(i), analyze3.makeQuotientTwoMinusOneToLog2(i));
    }



    QChart *chart = new QChart();
    chart->setTitle("Minimum number of throws at which there is at least two balls minus one ball in each bin to n ln ln n");
    //chart->createDefaultAxes();
    QValueAxis *axisXI = new QValueAxis;
    QValueAxis *axisYI = new QValueAxis; //QLogValueAxis

    chart->addSeries(seriesLine);
    seriesLine->setName("d = 1");
    chart->addSeries(seriesLine2);
    seriesLine2->setName("d = 2");
    chart->addSeries(seriesLine3);
    seriesLine3->setName("d = 3");

    /*for( int i = 0; i < 50; i++)
    {
        serieses[i]->setMarkerSize(6.0);
        serieses[i]->setColor((Qt::blue));
        chart->addSeries(serieses[i]);
        chart->setAxisX(axisXI,serieses[i]);
        chart->setAxisY(axisYI,serieses[i]);
    }*/
    chart->setAxisX(axisXI,seriesLine);
    chart->setAxisY(axisYI,seriesLine);
    chart->setAxisX(axisXI,seriesLine3);
    chart->setAxisY(axisYI,seriesLine3);
    chart->setAxisX(axisXI,seriesLine2);
    chart->setAxisY(axisYI,seriesLine2);


//axisYI->setRange(0, 8000);


    axisXI->setTitleText("Sample size");
    axisYI->setTitleText("Minimum number of throws to n ln ln n");
    axisXI->setTickCount(10);
    chart->addAxis(axisXI, Qt::AlignBottom);
    axisYI->setTickCount(11);
    chart->addAxis(axisYI, Qt::AlignLeft);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    QMainWindow window;
    window.setCentralWidget(chartView);
    window.resize(400, 300);
    window.show();

    return a.exec();
}
