#ifndef HOUSEREPRESENTER_H
#define HOUSEREPRESENTER_H

#include <vector>

#include <QWidget>

#include "appliancewidget.h"
#include "house.h"

namespace Ui {
class HouseRepresenter;
}

class HouseRepresenter : public QWidget
{
    Q_OBJECT
    House* house;
    std::vector<ApplianceWidget*> AWs;

public:
    explicit HouseRepresenter(QWidget *parent = 0, House* h = 0);
    ~HouseRepresenter();


    void tick(int t);

private:
    Ui::HouseRepresenter *ui;
};

#endif // HOUSEREPRESENTER_H
