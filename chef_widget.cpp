#include "chef_widget.h"
#include "ui_chef_widget.h"

chef_widget::chef_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chef_widget)
{
    ui->setupUi(this);
}

chef_widget::~chef_widget()
{
    delete ui;
}

void chef_widget::widgetshow()
{
    this->show();
}

void chef_widget::on_back_pushButton_clicked()
{
    this->hide();
    emit login_dialogshow();
}
