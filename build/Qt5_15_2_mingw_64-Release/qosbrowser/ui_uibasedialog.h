/********************************************************************************
** Form generated from reading UI file 'uibasedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UIBASEDIALOG_H
#define UI_UIBASEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "src/fend/uicom/uipushbutton.h"

QT_BEGIN_NAMESPACE

class Ui_UiBaseDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QFrame *frameTitle;
    QHBoxLayout *horizontalLayout;
    QLabel *labelLogo;
    QLabel *labelTitle;
    UiPushButton *btnClose;
    QFrame *line;
    QWidget *widgetBody;

    void setupUi(QDialog *UiBaseDialog)
    {
        if (UiBaseDialog->objectName().isEmpty())
            UiBaseDialog->setObjectName(QString::fromUtf8("UiBaseDialog"));
        UiBaseDialog->resize(429, 472);
        UiBaseDialog->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_2 = new QVBoxLayout(UiBaseDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(9, 0, 9, 9);
        frameTitle = new QFrame(UiBaseDialog);
        frameTitle->setObjectName(QString::fromUtf8("frameTitle"));
        frameTitle->setFrameShape(QFrame::StyledPanel);
        frameTitle->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frameTitle);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        labelLogo = new QLabel(frameTitle);
        labelLogo->setObjectName(QString::fromUtf8("labelLogo"));
        labelLogo->setMinimumSize(QSize(0, 0));
        labelLogo->setMaximumSize(QSize(32, 32));

        horizontalLayout->addWidget(labelLogo);

        labelTitle = new QLabel(frameTitle);
        labelTitle->setObjectName(QString::fromUtf8("labelTitle"));
        QFont font;
        font.setBold(false);
        labelTitle->setFont(font);

        horizontalLayout->addWidget(labelTitle);

        btnClose = new UiPushButton(frameTitle);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnClose->sizePolicy().hasHeightForWidth());
        btnClose->setSizePolicy(sizePolicy);
        btnClose->setMinimumSize(QSize(0, 0));

        horizontalLayout->addWidget(btnClose);

        horizontalLayout->setStretch(1, 1);

        verticalLayout_2->addWidget(frameTitle);

        line = new QFrame(UiBaseDialog);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);

        widgetBody = new QWidget(UiBaseDialog);
        widgetBody->setObjectName(QString::fromUtf8("widgetBody"));

        verticalLayout_2->addWidget(widgetBody);

        verticalLayout_2->setStretch(2, 1);

        retranslateUi(UiBaseDialog);

        QMetaObject::connectSlotsByName(UiBaseDialog);
    } // setupUi

    void retranslateUi(QDialog *UiBaseDialog)
    {
        UiBaseDialog->setWindowTitle(QCoreApplication::translate("UiBaseDialog", "\347\231\273\345\275\225", nullptr));
        labelLogo->setText(QString());
        labelTitle->setText(QCoreApplication::translate("UiBaseDialog", "\350\257\267\345\241\253\345\206\231\346\240\207\351\242\230", nullptr));
        btnClose->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class UiBaseDialog: public Ui_UiBaseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UIBASEDIALOG_H
