#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    money_ = 0;
    setControl();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::setControl(){
    ui->lcdNumber->display(money_);
    ui->coffee100->setEnabled(money_ >= 100);
    ui->tea150->setEnabled(money_ >= 150);
    ui->cola200->setEnabled(money_ >= 200);
}

void Widget::on_pb500_clicked()
{
    money_+=500;
    setControl();
}

void Widget::on_pb100_clicked()
{
    money_+=100;
    setControl();
}

void Widget::on_pb50_clicked()
{
    money_+=50;
    setControl();
}

void Widget::on_pb10_clicked()
{
    money_+=10;
    setControl();
}

void Widget::on_coffee100_clicked()
{
    money_-=100;
    setControl();
}

void Widget::on_tea150_clicked()
{
    money_-=150;
    setControl();
}

void Widget::on_cola200_clicked()
{
    money_-=200;
    setControl();
}

void Widget::on_reset_clicked()
{
    int m500=0, m100=0, m50=0, m10=0;
    while(money_!=0){
        if (money_>=500){
            money_-=500; m500++;
        }
        else if(money_>=100){
            money_-=100; m100++;
        }
        else if(money_>=50){
            money_-=50; m50++;
        }
        else{
            money_-=10; m10++;
        }
    }
    setControl();
    QString str;
    str.sprintf("500: %d\n100: %d\n50: %d\n10: %d",m500,m100,m50,m10);
    QMessageBox::information(this, "Charge", str, "OK");
}

