#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    updateButtons(); // 잔여 금액에 따라 버튼 활성/비활성화
}

Widget::~Widget()
{
    delete ui;
}

void Widget::updateButtons() {
    ui->PbCoffee->setEnabled(money >= 100);
    ui->PbTee->setEnabled(money >= 150);
    ui->PbMilk->setEnabled(money >= 200);
}

void Widget:: changeMoney(int diff){
    money +=diff;
    ui->lcdNumber->display(money);
    updateButtons(); // 잔여 금액에 따라 버튼 활성/비활성화
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


void Widget::on_PbCoffee_clicked()
{
    if (money >= 100) {
        changeMoney(-100);
    } else {
        QMessageBox mb;
        mb.information(nullptr, "title", "Not enough money.");
    }
}

void Widget::on_PbTee_clicked()
{
    if (money >= 150) {
        changeMoney(-150);
    } else {
        QMessageBox mb;
        mb.information(nullptr, "title", "Not enough money.");
    }
}

void Widget::on_PbMilk_clicked()
{
    if (money >= 200) {
        changeMoney(-200);
    } else {
        QMessageBox mb;
        mb.information(nullptr, "title", "Not enough money.");
    }
}

void Widget::on_PbReset_clicked()
{
    if (money > 0) {
        int ret = QMessageBox::question(this, "Return Coins", "Do you want to return coins?", QMessageBox::Ok | QMessageBox::Cancel);

        if (ret == QMessageBox::Ok) {
            int coins = money;
            money = 0;
            ui->lcdNumber->display(money);

            QMessageBox mb;
            mb.information(nullptr, "Coins Returned", "Returned coins: " + QString::number(coins));
            updateButtons(); // 잔여 금액에 따라 버튼 활성/비활성화
        }
    }
}
