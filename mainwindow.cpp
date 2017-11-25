#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <cmath>
#include <iostream>

#include <QGridLayout>
#include <QLabel>

#include "houserepresenter.h"

#define HOUSES 50
#define MAXP 60000
#define OPT 0.6
#define SUB 0.8
#define DISPCHART 1000

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    cluster = new Cluster(HOUSES, MAXP, OPT, SUB);

    series0 = new QtCharts::QLineSeries();
    series1 = new QtCharts::QLineSeries();
    series2 = new QtCharts::QLineSeries();

    chart = new QtCharts::QChart();
        chart->legend()->hide();
        chart->addSeries(series0);
        chart->addSeries(series1);
        chart->addSeries(series2);
        chart->createDefaultAxes();
        chart->axisX()->setRange(0, DISPCHART);
        chart->axisY()->setRange(0, MAXP);
        chart->setTitle("Energy usage");

        //chart->update();

    chartView = new QtCharts::QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

    ui->setupUi(this);
    ui->horizontalLayout->addWidget(chartView);
    startTimer(50);

    for(int i = 0; i < HOUSES; i++)
    {
        HouseRepresenter* hr = new HouseRepresenter(this, cluster->houses[i]);
        ui->gridLayout->addWidget(hr, i / std::ceil(std::sqrt(HOUSES)), i % (int)std::ceil(std::sqrt(HOUSES)));
        housereps.push_back(hr);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    t++;
    cluster->tick();
    for(int i = 0; i < HOUSES; i++)
        housereps[i]->tick(t);

    ui->max->setText(QString::number(MAXP) + " W");
    ui->power->setText(QString::number(cluster->getPower()) + " W");
    ui->forced->setText(QString::number(cluster->getForced()) + " W");

    if(t > DISPCHART)
        chart->axisX()->setRange(t - DISPCHART, t);

    series0->append(t, cluster->getPower());
    series1->append(t, cluster->getPower(TYPE_HEATING));
    series2->append(t, cluster->getForced());
    chartView->update();
}
