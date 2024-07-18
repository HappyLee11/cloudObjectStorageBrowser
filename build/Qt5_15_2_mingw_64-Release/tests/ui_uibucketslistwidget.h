/********************************************************************************
** Form generated from reading UI file 'uibucketslistwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UIBUCKETSLISTWIDGET_H
#define UI_UIBUCKETSLISTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "src/fend/uicom/uicomboline.h"

QT_BEGIN_NAMESPACE

class Ui_UiBucketsListWidget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    UiComboLine *lineEdit;
    QListView *listView;

    void setupUi(QWidget *UiBucketsListWidget)
    {
        if (UiBucketsListWidget->objectName().isEmpty())
            UiBucketsListWidget->setObjectName(QString::fromUtf8("UiBucketsListWidget"));
        UiBucketsListWidget->resize(220, 483);
        UiBucketsListWidget->setMinimumSize(QSize(220, 0));
        verticalLayout = new QVBoxLayout(UiBucketsListWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 10, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(UiBucketsListWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new UiComboLine(UiBucketsListWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        listView = new QListView(UiBucketsListWidget);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout->addWidget(listView);


        retranslateUi(UiBucketsListWidget);

        QMetaObject::connectSlotsByName(UiBucketsListWidget);
    } // setupUi

    void retranslateUi(QWidget *UiBucketsListWidget)
    {
        UiBucketsListWidget->setWindowTitle(QCoreApplication::translate("UiBucketsListWidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("UiBucketsListWidget", "\346\220\234\347\264\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UiBucketsListWidget: public Ui_UiBucketsListWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UIBUCKETSLISTWIDGET_H
