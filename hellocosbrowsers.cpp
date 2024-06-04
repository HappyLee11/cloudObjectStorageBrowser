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

    setStyleSheet("QWidget{font-size:24pt;}");

    QIcon icon;
    icon.addFile("image/lotusLeaf.png");
    setWindowIcon(icon);
}



hellocosbrowsers::~hellocosbrowsers() {
    delete ui;
}

void hellocosbrowsers::showDialog() {
//tr() 用于国际化和本地化，它自动处理 UTF-8 编码的源文件，是 Qt 推荐的方式来处理 UI 中的文本
    QMessageBox::information(this, tr("你好"), QStringLiteral("你好，“我是对象浏览器”"));
}

