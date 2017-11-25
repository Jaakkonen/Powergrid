#include "appliancewidget.h"
#include "ui_appliancewidget.h"

#include <QLabel>

ApplianceWidget::ApplianceWidget(QWidget *parent, Appliance* a) :
    QWidget(parent),
    ui(new Ui::ApplianceWidget)
{
    ui->setupUi(this);
    appliance = a;

    switch (appliance->getType()) {
    case TYPE_FRIDGE:
        bg = "#0099ff";
        ui->icon->setText("F");
        break;
    case TYPE_BLENDER:
        bg = "#ff9900";
        ui->icon->setText("B");
        break;
    case TYPE_HEATING:
        bg = "#ff0000";
        ui->icon->setText("H");
        break;
    case TYPE_SAUNA:
        bg = "#000000";
        ui->icon->setText("S");
        break;
    case TYPE_WASH:
        bg = "#0000aa";
        ui->icon->setText("W");
        break;
    case TYPE_DISH:
        bg = "#0000ff";
        ui->icon->setText("D");
        break;
    case TYPE_TV:
        bg = "#ff6666";
        ui->icon->setText("TV");
        break;
    case TYPE_PC:
        bg = "#999999";
        ui->icon->setText("PC");
        break;
    case TYPE_LIGHT:
        bg = "#ffff00";
        ui->icon->setText("L");
        break;
    default:
        break;
    }
}

ApplianceWidget::~ApplianceWidget()
{
    delete ui;
}

void ApplianceWidget::tick(int t)
{
    if(appliance->getPowerState() == POWER_FORCED_ON || appliance->getPowerState() == POWER_GRANTED_ON)
    {
        ui->power->setText(QString::number(appliance->getPower()) + " W");
        this->setStyleSheet("* { background-color : " + bg + "; }");
    }
    else
    {
        ui->power->setText(QString::number(0) + " W");
        this->setStyleSheet("* { background-color : transparent; }");
    }
}
