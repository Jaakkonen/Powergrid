#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <vector>

#include <QMainWindow>

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

    int t = 0;

protected:
    void timerEvent(QTimerEvent *event);
};

#endif // MAINWINDOW_H
