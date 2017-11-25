#include "houserepresenter.h"
#include "ui_houserepresenter.h"

#include <iostream>

#include <QGridLayout>
#include <QLabel>

#include "appliancewidget.h"

HouseRepresenter::HouseRepresenter(QWidget *parent, House* h) :
    QWidget(parent),
    ui(new Ui::HouseRepresenter)
{
    ui->setupUi(this);

    house = h;

    for(int i = 0; i < h->appliances.size(); i++)
    {
        ApplianceWidget* wid = new ApplianceWidget(this, h->appliances[i]);
        AWs.push_back(wid);
        ui->gridLayout_2->addWidget(wid, i / 3, i % 3);
    }
}

HouseRepresenter::~HouseRepresenter()
{
    delete ui;
}

void HouseRepresenter::tick(int t)
{
    for(int i = 0; i < AWs.size(); i++)
    {
        AWs[i]->tick(t);
    }

    ui->power->setText(QString::number(house->getPower()) + " W");
    ui->forced->setText(QString::number(house->getForced()) + " W");
}

