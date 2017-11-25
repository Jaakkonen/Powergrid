#ifndef APPLIANCEWIDGET_H
#define APPLIANCEWIDGET_H

#include <QWidget>

#include "appliance.h"

namespace Ui {
class ApplianceWidget;
}

class ApplianceWidget : public QWidget
{
    Q_OBJECT
    Appliance* appliance;
    QString bg;


public:
    explicit ApplianceWidget(QWidget *parent = 0, Appliance* a = 0);
    ~ApplianceWidget();

    void tick(int t);

private:
    Ui::ApplianceWidget *ui;
};

#endif // APPLIANCEWIDGET_H
