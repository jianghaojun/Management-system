#ifndef CHEF_WIDGET_H
#define CHEF_WIDGET_H

#include <QWidget>

namespace Ui {
class chef_widget;
}

class chef_widget : public QWidget
{
    Q_OBJECT

public:
    explicit chef_widget(QWidget *parent = 0);
    ~chef_widget();

private:
    Ui::chef_widget *ui;

private slots:
    void widgetshow();                    //自己显示

    void on_back_pushButton_clicked();    //返回到登录界面
};

#endif // CHEF_WIDGET_H
