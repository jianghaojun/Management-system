#include "ad_delete_dialog.h"
#include "ui_ad_delete_dialog.h"

ad_delete_Dialog::ad_delete_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ad_delete_Dialog)
{
    ui->setupUi(this);
    //样式表
    ui->delete_pushButton->setStyleSheet("QPushButton"
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

ad_delete_Dialog::~ad_delete_Dialog()
{
    delete ui;
}

void ad_delete_Dialog::dialogshow()
{
    this->show();
}

void ad_delete_Dialog::on_back_pushButton_clicked()
{
    this->hide();
    emit administrator_widgetshow();
}

void ad_delete_Dialog::on_delete_pushButton_clicked()
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
        QMessageBox::information(this, tr("删除失败"), tr("请输入手机号并选择身份！"), QMessageBox::Ok);
        ui->pnlineEdit->setFocus();
    }
    else
    {
        QString pn = ui->pnlineEdit->text();

        if(ui->comboBox->currentText() == s1)        //顾客
        {
            deletepart(Customer, pn);
        }
        else if(ui->comboBox->currentText() == s2)    //服务员
        {
            deletepart(Waiter_list, pn);
        }
        else if(ui->comboBox->currentText() == s3)    //厨师
        {
             deletepart(Chef_list, pn);
        }
        else if(ui->comboBox->currentText() == s4)    //经理
        {
             deletepart(Manager, pn);
        }
        else                                          //系统管理员
        {
             deletepart(System_manager, pn);
        }
    }
}

void ad_delete_Dialog::deletepart(QHash<QString, QString> &hash, QString pn)
{
    if(!search_account(hash, pn))
    {
        QMessageBox::information(this, tr("删除失败"), tr("用户不存在！"), QMessageBox::Ok);
    }
    else
    {
        hash.remove(pn);
        QMessageBox::information(this, tr("删除成功"), tr("删除成功！"), QMessageBox::Ok);
    }
    ui->pnlineEdit->clear();
}

void ad_delete_Dialog::deletepart(QVector<Waiter> &vector, QString pn)
{
    if(!search_account(vector, pn))
    {
        QMessageBox::information(this, tr("删除失败"), tr("用户不存在！"), QMessageBox::Ok);
    }
    else
    {
        for(int i = 0; i < vector.size(); ++i)
        {
            if(vector[i].get_Employee_pn() == pn)
            {
                vector.removeAt(i);
            }
        }
        QMessageBox::information(this, tr("删除成功"), tr("删除成功！"), QMessageBox::Ok);
    }
    ui->pnlineEdit->clear();
}

void ad_delete_Dialog::deletepart(QVector<Chef> &vector, QString pn)
{
    if(!search_account(vector, pn))
    {
        QMessageBox::information(this, tr("删除失败"), tr("用户不存在！"), QMessageBox::Ok);
    }
    else
    {
        for(int i = 0; i < vector.size(); ++i)
        {
            if(vector[i].get_Employee_pn() == pn)
            {
                vector.removeAt(i);
            }
        }
        QMessageBox::information(this, tr("删除成功"), tr("删除成功！"), QMessageBox::Ok);
    }
    ui->pnlineEdit->clear();
}

