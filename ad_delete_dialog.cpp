#include "ad_delete_dialog.h"
#include "ui_ad_delete_dialog.h"

ad_delete_Dialog::ad_delete_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ad_delete_Dialog)
{
    ui->setupUi(this);
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
}

void ad_delete_Dialog::on_delete_pushButton_clicked()
{
    QString s1 = "顾客";
    QString s2 = "服务员";
    QString s3 = "厨师";
    QString s4 = "经理";
    QString s5 = "系统管理员";
    extern QHash <QString, QString> Customer;
    extern QHash <QString, QString> Employee;

    if(ui->pnlineEdit->text().isEmpty())
    {
        QMessageBox::information(this, tr("删除失败"), tr("请输入手机号！"), QMessageBox::Ok);
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
            deletepart(Employee, pn);
        }

        else if(ui->comboBox->currentText() == s3)    //厨师
        {
             deletepart(Employee, pn);
        }

        else if(ui->comboBox->currentText() == s4)    //经理
        {
             deletepart(Employee, pn);
        }

        else if(ui->comboBox->currentText() == s5)    //系统管理员
        {
             deletepart(Employee, pn);
        }
    }
}

