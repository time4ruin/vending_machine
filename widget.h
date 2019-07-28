#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    int money_;
    void setControl();

private slots:
    void on_pb500_clicked();

    void on_pb100_clicked();

    void on_pb50_clicked();

    void on_pb10_clicked();

    void on_coffee100_clicked();

    void on_tea150_clicked();

    void on_cola200_clicked();

    void on_reset_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H

