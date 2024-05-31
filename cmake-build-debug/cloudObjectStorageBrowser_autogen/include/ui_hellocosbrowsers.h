/********************************************************************************
** Form generated from reading UI file 'hellocosbrowsers.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELLOCOSBROWSERS_H
#define UI_HELLOCOSBROWSERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_hellocosbrowsers
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *hellocosbrowsers)
    {
        if (hellocosbrowsers->objectName().isEmpty())
            hellocosbrowsers->setObjectName("hellocosbrowsers");
        hellocosbrowsers->resize(400, 300);
        pushButton = new QPushButton(hellocosbrowsers);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(80, 100, 231, 81));

        retranslateUi(hellocosbrowsers);

        QMetaObject::connectSlotsByName(hellocosbrowsers);
    } // setupUi

    void retranslateUi(QWidget *hellocosbrowsers)
    {
        hellocosbrowsers->setWindowTitle(QCoreApplication::translate("hellocosbrowsers", "hellocosbrowsers", nullptr));
        pushButton->setText(QCoreApplication::translate("hellocosbrowsers", "\344\275\240\345\245\275", nullptr));
    } // retranslateUi

};

namespace Ui {
    class hellocosbrowsers: public Ui_hellocosbrowsers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELLOCOSBROWSERS_H
