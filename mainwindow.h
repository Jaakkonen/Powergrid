#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <vector>

#include <QMainWindow>
#include <QLineSeries>

#include <QChart>
#include <QChartView>

#include "cluster.h"
#include "houserepresenter.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Cluster* cluster;
    std::vector<HouseRepresenter*> housereps;

    QtCharts::QLineSeries* series;
    QtCharts::QChart* chart;
    QtCharts::QChartView* chartView;

    int t = 0;

protected:
    void timerEvent(QTimerEvent *event);
};

#endif // MAINWINDOW_H
