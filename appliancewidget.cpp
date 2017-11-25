#include "appliancewidget.h"
#include "ui_appliancewidget.h"

#include <QLabel>
#include <QPixmap>

ApplianceWidget::ApplianceWidget(QWidget *parent, Appliance* a) :
    QWidget(parent),
    ui(new Ui::ApplianceWidget)
{
    ui->setupUi(this);
    appliance = a;

    switch (appliance->getType()) {
    case TYPE_FRIDGE:
    {
        bg = "#0099ff";
        QPixmap ico(":/icons/jaakaappi.png");
        ui->icon->setPixmap(ico);
        break;
    }
    case TYPE_BLENDER:
    {
        bg = "#ff9900";
        QPixmap ico(":/icons/tehosekotin.png");
        ui->icon->setPixmap(ico);
        break;
    }
    case TYPE_HEATING:
    {
        bg = "#ff0000";
        QPixmap ico(":/icons/sahkolammitys.png");
        ui->icon->setPixmap(ico);
        break;
    }
    case TYPE_SAUNA:
    {
        bg = "#aaaaaa";
        QPixmap ico(":/icons/kiuas.png");
        ui->icon->setPixmap(ico);
        break;
    }
    case TYPE_WASH:
    {
        bg = "#0000aa";
        QPixmap ico(":/icons/pesukone.png");
        ui->icon->setPixmap(ico);
        break;
    }
    case TYPE_DISH:
    {
        bg = "#0000ff";
        QPixmap ico(":/icons/jaakaappi.png");
        ui->icon->setPixmap(ico);
        break;
    }
    case TYPE_TV:
    {
        bg = "#ff6666";
        QPixmap ico(":/icons/tv.png");
        ui->icon->setPixmap(ico);
        break;
    }
    case TYPE_PC:
    {
        bg = "#777777";
        QPixmap ico(":/icons/tietokone.png");
        ui->icon->setPixmap(ico);
        break;
    }
    case TYPE_LIGHT:
    {
        bg = "#ffff00";
        QPixmap ico(":/icons/valo.png");
        ui->icon->setPixmap(ico);
        break;
    }
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

    if(appliance->getPowerState() == POWER_QUEUED)
    {
        if(t % 20 < 10)
            this->setStyleSheet("* { background-color : " + bg + "; }");
        else
             this->setStyleSheet("* { background-color : transparent; }");
    }
}
