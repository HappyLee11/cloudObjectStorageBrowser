#include <QCoreApplication>
#include <QDebug>
#include <QApplication>
#include "hellocosbrowsers.h"

int main(int argc, char *argv[]) {
    //QCoreApplication a(argc, argv);
    QApplication a(argc, argv);
    //qDebug() << "Hello World";
    //return QCoreApplication::exec();
    hellocosbrowsers h;
    h.show();
    return a.exec();

}
