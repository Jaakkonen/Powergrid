#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <cmath>
#include <iostream>

#include <QGridLayout>

#include "houserepresenter.h"

#define HOUSES 50
#define MAXP 30000
#define OPT 0.6
#define SUB 0.8

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    cluster = new Cluster(HOUSES, MAXP, OPT, SUB);

    ui->setupUi(this);
    startTimer(1);

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
}
