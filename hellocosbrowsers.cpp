//
// Created by Administrator on 2024/5/31.
//

// You may need to build the project (run Qt uic code generator) to get "ui_hellocosbrowsers.h" resolved

#include <QMessageBox>
#include "hellocosbrowsers.h"
#include "ui_hellocosbrowsers.h"



hellocosbrowsers::hellocosbrowsers(QWidget *parent) :
        QWidget(parent), ui(new Ui::hellocosbrowsers) {
    ui->setupUi(this);

    connect(ui->pushButton,&QPushButton::clicked, this,&hellocosbrowsers::showDialog);
}

hellocosbrowsers::~hellocosbrowsers() {
    delete ui;
}

void hellocosbrowsers::showDialog() {

    QMessageBox::information(this,QString::fromLocal8Bit("你好"),QString::fromLocal8Bit("你好，“我是对象浏览器”"));


}
