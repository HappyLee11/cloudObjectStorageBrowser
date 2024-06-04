//
// Created by Administrator on 2024/5/31.
//

#ifndef CLOUDOBJECTSTORAGEBROWSER_HELLOCOSBROWSERS_H
#define CLOUDOBJECTSTORAGEBROWSER_HELLOCOSBROWSERS_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class hellocosbrowsers; }
QT_END_NAMESPACE

class hellocosbrowsers : public QWidget {
    Q_OBJECT

public:
    explicit hellocosbrowsers(QWidget *parent = nullptr);

    ~hellocosbrowsers() override;

private slots:
    void showDialog();

private:
    Ui::hellocosbrowsers *ui;
};


#endif //CLOUDOBJECTSTORAGEBROWSER_HELLOCOSBROWSERS_H
