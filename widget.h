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
    int money{0};

    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    void setUi(bool pbCoffee, bool pbTea, bool pbGongCha);
    void initButton();
    void changeMoney(int n);

private slots:
    void on_pb10_clicked();
    void on_pb50_clicked();
    void on_pb100_clicked();
    void on_pb500_clicked();
    void on_pbCoffee_clicked();
    void on_pbTea_clicked();
    void on_pbGongCha_clicked();
    void on_pbChange_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
