#include <QCoreApplication>
#include <QDebug>
#include <QApplication>
#include "hellocosbrowsers.h"

int main(int argc, char *argv[]) {
    //QCoreApplication a(argc, argv);
    QApplication a(argc, argv);//每一个QTdou有一个这样的对象
    //qDebug() << "Hello World";
    //return QCoreApplication::exec();
    hellocosbrowsers h;
    h.show();
    return a.exec();//exec让程序进入事件循环，接受来自用户的事件

}
