#include "ad_search_dialog.h"
#include "ui_ad_search_dialog.h"
#include "account_list.h"

ad_search_Dialog::ad_search_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ad_search_Dialog)
{
    ui->setupUi(this);
    //样式表
    ui->search_pushButton->setStyleSheet("QPushButton"
                                       "{"
                                       "border:2px groove white;"
                                       "border-radius:15px;"
                                       "padding:2px 4px;"
                                       "color:rgb(255,255,255);"
                                       "background-color:rgb(0,147,221);"
                                       "}"
                                       "QPushButton:pressed"
                                       "{"
                                       "background-color:rgb(0,170,255);"
                                       "border-style:inset;"
                                       "}");

    ui->pnlineEdit->setStyleSheet("border:2px groove gray;"
                                  "border-radius:15px;"
                                  "padding:2px 4px;"
                                  "color:rgb(160,160,160);");

    ui->result_label->setStyleSheet("border:2px groove gray;"
                                   "border-radius:15px;"
                                   "padding:2px 4px;"
                                   "background-color:white;"
                                   "color:rgb(160,160,160);");

    ui->pwd_label->setStyleSheet("border:2px groove gray;"
                                  "border-radius:15px;"
                                  "padding:2px 4px;"
                                  "background-color:white;"
                                  "color:rgb(160,160,160);");

    ui->comboBox->setStyleSheet("QComboBox::drop-down"
                                "{"
                                "subcontrol-origin: padding;"
                                "subcontrol-position: top right;"
                                "width: 20px;"
                                "border-left-width: 1px;"
                                "border-left-color: darkgray;"
                                "border-left-style: solid; "
                                "border-top-right-radius: 15px;"
                                "border-bottom-right-radius: 15px;"
                                "}"
                                "QComboBox::down-arrow"
                                "{"
                                "image:url(:/image/images/arrow2.png);"
                                "}"
                                "QComboBox"
                                "{"
                                "border:2px groove gray;"
                                "border-radius:15px;"
                                "padding:2px 4px;"
                                "color:rgb(160,160,160);"
                                "}");

    ui->back_pushButton->setStyleSheet("QPushButton{"
                                       "border-style:hidden;"
                                       "color:rgb(0,147,221);}"
                                       ""
                                       "QPushButton:pressed{"
                                       "background-color:rgb(0,170,255);"
                                       "border-style:inset;}");
}

ad_search_Dialog::~ad_search_Dialog()
{
    delete ui;
}

void ad_search_Dialog::dialogshow()
{
    this->show();
}

void ad_search_Dialog::on_back_pushButton_clicked()
{
    this->hide();
    emit administrator_widgetshow();
}

void ad_search_Dialog::on_search_pushButton_clicked()
{
    QString s1 = "顾客";
    QString s2 = "服务员";
    QString s3 = "厨师";
    QString s4 = "经理";
    extern QHash <QString, QString> Customer;
    extern QVector <Waiter> Waiter_list;
    extern QVector <Chef> Chef_list;
    extern QHash <QString, QString> Manager;
    extern QHash <QString, QString> System_manager;

    if(ui->pnlineEdit->text().isEmpty() || ui->comboBox->currentText() == "身份")
    {
        QMessageBox::information(this, tr("查询失败"), tr("请输入手机号再查询并选择身份！"), QMessageBox::Ok);
        ui->pnlineEdit->setFocus();
    }
    else
    {
        QString pn = ui->pnlineEdit->text();
        if(ui->comboBox->currentText() == s1)        //顾客
        {
            searchpart(Customer, pn);
        }

        else if(ui->comboBox->currentText() == s2)        //服务员
        {
            searchpart(Waiter_list, pn);
        }

        else if(ui->comboBox->currentText() == s3)        //厨师
        {
            searchpart(Chef_list, pn);
        }

        else if(ui->comboBox->currentText() == s4)        //经理
        {
            searchpart(Manager, pn);
        }

        else                                             //系统管理员
        {
            searchpart(System_manager, pn);
        }
    }
}

void ad_search_Dialog::searchpart(QHash<QString, QString> hash, QString pn)
{
    if(search_account(hash, pn))
    {
        QString pwd = search_account_pwd(hash, pn);
        ui->result_label->setText("用户存在");
        ui->pwd_label->setText(pwd);
    }
    else
    {
        ui->result_label->clear();
        ui->pwd_label->clear();
        QMessageBox::information(this, tr("查询失败"), tr("用户不存在"), QMessageBox::Ok);
        ui->pnlineEdit->setFocus();
    }
}

void ad_search_Dialog::searchpart(QVector<Waiter> vector, QString pn)
{
    if(search_account(vector, pn))
    {
        QString pwd = search_account_pwd(vector, pn);
        ui->result_label->setText("用户存在");
        ui->pwd_label->setText(pwd);
    }
    else
    {
        ui->result_label->clear();
        ui->pwd_label->clear();
        QMessageBox::information(this, tr("查询失败"), tr("用户不存在"), QMessageBox::Ok);
        ui->pnlineEdit->setFocus();
    }
}

void ad_search_Dialog::searchpart(QVector<Chef> vector, QString pn)
{
    if(search_account(vector, pn))
    {
        QString pwd = search_account_pwd(vector, pn);
        ui->result_label->setText("用户存在");
        ui->pwd_label->setText(pwd);
    }
    else
    {
        ui->result_label->clear();
        ui->pwd_label->clear();
        QMessageBox::information(this, tr("查询失败"), tr("用户不存在"), QMessageBox::Ok);
        ui->pnlineEdit->setFocus();
    }
}
