#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::setUi(bool Coffee, bool Tea, bool GongCha) {
    ui->pbCoffee->setEnabled(Coffee);
    ui->pbTea->setEnabled(Tea);
    ui->pbGongCha->setEnabled(GongCha);
}

void Widget::initButton() {
    setUi(false, false, false);
}

void Widget::changeMoney(int n) {
    if(money + n < 0) {
        return;
    }
    else {
        money += n;
        ui->lcdNumber->display(QString::number(money));

        if(money < 100) {
            setUi(false, false, false);
        }
        else if(money < 150) {
            setUi(true, false, false);
        }
        else if(money < 200) {
            setUi(true, true, false);
        }
        else {
            setUi(true, true, true);
        }
    }
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}

void Widget::on_pbGongCha_clicked()
{
    changeMoney(-200);
}

void Widget::on_pbChange_clicked()
{
    QMessageBox msg;
    int num;

    num = money/1000;
    if (num > 0) {
        msg.information(nullptr,"Change", "1000won : " + QString::number(num));
    }
    money %= 1000;

    num = money/500;
    if (num > 0) {
        msg.information(nullptr,"Change", "500won : " + QString::number(num));
    }
    money %= 500;

    num = money/100;
    if (num > 0) {
        msg.information(nullptr,"Change", "100won : " + QString::number(num));
    }
    money %= 100;

    num = money/50;
    if (num > 0) {
        msg.information(nullptr,"Change", "50won : " + QString::number(num));
    }
    money %= 50;

    num = money/10;
    if (num > 0) {
        msg.information(nullptr,"Change", "10won : " + QString::number(num));
    }
    money %= 10;

    ui->lcdNumber->display(QString::number(money));
    setUi(false, false, false);
}
