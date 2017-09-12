#include "administrator_widget.h"
#include "ui_administrator_widget.h"
#include "login_dialog.h"
#include "food.h"

Administrator_widget::Administrator_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Administrator_widget)
{
    ui->setupUi(this);
}

Administrator_widget::~Administrator_widget()
{
    delete ui;
}

void Administrator_widget::widgetshow()
{
    this->show();
}


void Administrator_widget::on_back_pushButton_clicked()
{
    this->hide();
    emit login_dialogshow();
}

void Administrator_widget::on_showC_pushButton_clicked()
{
    //设置账户显示
    int row1 = ui->Account_tableWidget->rowCount();               //清空原先的表格
    if(row1 != 0)
    {
        for(int i = row1; i >= 0; --i)
        {
            for(int j = 0; j < 3; ++j)
            {
                delete ui->Account_tableWidget->takeItem(i, j);   //删除用 new 申请的内存
            }
            ui->Account_tableWidget->removeRow(i);
        }
    }

    extern QHash <QString, QString> Customer;
    QHash<QString, QString>::const_iterator i = Customer.constBegin();

    while(i != Customer.constEnd())
    {
        int row = ui->Account_tableWidget->rowCount();
        QString type = "Customer";
        QString pn = i.key();
        QString pwd = i.value();

        ui->Account_tableWidget->insertRow(row);

        QTableWidgetItem *item0 = new QTableWidgetItem(type);
        item0->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->Account_tableWidget->setItem(row, 0, item0);

        QTableWidgetItem *item1 = new QTableWidgetItem(pn);
        item1->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->Account_tableWidget->setItem(row, 1, item1);

        QTableWidgetItem *item2 = new QTableWidgetItem(pwd);
        item2->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->Account_tableWidget->setItem(row, 2, item2);

        ++i;
    }
}

void Administrator_widget::on_showE_pushButton_clicked()
{
    //设置账户显示
    int row1 = ui->Account_tableWidget->rowCount();              //清空原先的表格
    if(row1 != 0)
    {
        for(int i = row1; i >= 0; --i)
        {
            for(int j = 0; j < 3; ++j)
            {
                delete ui->Account_tableWidget->takeItem(i, j);   //删除用 new 申请的内存
            }
            ui->Account_tableWidget->removeRow(i);
        }
    }

    extern QHash <QString, QString> Employee;
    QHash<QString, QString>::const_iterator i = Employee.constBegin();

    while(i != Employee.constEnd())
    {
        int row = ui->Account_tableWidget->rowCount();
        QString type = "Employee";
        QString pn = i.key();
        QString pwd = i.value();

        ui->Account_tableWidget->insertRow(row);

        QTableWidgetItem *item0 = new QTableWidgetItem(type);
        item0->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->Account_tableWidget->setItem(row, 0, item0);

        QTableWidgetItem *item1 = new QTableWidgetItem(pn);
        item1->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->Account_tableWidget->setItem(row, 1, item1);

        QTableWidgetItem *item2 = new QTableWidgetItem(pwd);
        item2->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->Account_tableWidget->setItem(row, 2, item2);

        ++i;
    }
}

void Administrator_widget::on_search_pushButton_clicked()
{
    emit ad_search_dialogshow();
}

void Administrator_widget::on_add_pushButton_clicked()
{
    emit ad_add_dialogshow();
}

void Administrator_widget::on_delete_pushButton_clicked()
{
    emit ad_delete_dialogshow();
}

void Administrator_widget::on_upload_pushButton_clicked()
{
    extern QHash <QString, QString> Customer;
    extern QHash <QString, QString> Employee;
    Customer_Upload(Customer);                 //数据回传函数
    Employee_Upload(Employee);
    QMessageBox::information(this, tr("上传成功"), tr("上传成功！"), QMessageBox::Ok);
}

void Administrator_widget::showmenu_part(QMultiHash<QString, Food> hash, QString food_type)
{
    QMultiHash <QString, Food>::iterator i = hash.find(food_type);
    while(i != hash.end() && i.key() == food_type)
    {
        Food f = i.value();
        int id = f.getID();
        QString Id = QString::number(id);       //将int类型转换成QString类型
        QString food_name = f.getName();
        int food_price = f.getPrice();
        QString Food_price = QString::number(food_price);

        int row = ui->Menu_tableWidget->rowCount();
        ui->Menu_tableWidget->insertRow(row);

        QTableWidgetItem *item0 = new QTableWidgetItem(food_type);
        item0->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->Menu_tableWidget->setItem(row, 0, item0);

        QTableWidgetItem *item1 = new QTableWidgetItem(Id);
        item1->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->Menu_tableWidget->setItem(row, 1, item1);

        QTableWidgetItem *item2 = new QTableWidgetItem(food_name);
        item2->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->Menu_tableWidget->setItem(row, 2, item2);

        QTableWidgetItem *item3 = new QTableWidgetItem(Food_price);
        item3->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->Menu_tableWidget->setItem(row, 3, item3);

        ++i;
    }
}

void Administrator_widget::on_showmenu_pushButton_clicked()
{
    //设置菜单显示
    QString s1 = "Cold Dish";
    QString s2 = "Main Course";
    QString s3 = "Soup";

    int row1 = ui->Menu_tableWidget->rowCount();                //清空原先的表格
    if(row1 != 0)
    {
        for(int i = row1; i >= 0; --i)
        {
            for(int j = 0; j < 4; ++j)
            {
                delete ui->Account_tableWidget->takeItem(i, j);   //删除用 new 申请的内存
            }
            ui->Menu_tableWidget->removeRow(i);
        }
    }

    extern QMultiHash <QString, Food> Menu_total;

    if(ui->comboBox->currentText() == s1)
    {
        showmenu_part(Menu_total, s1);
    }
    else if(ui->comboBox->currentText() == s2)
    {
        showmenu_part(Menu_total, s2);
    }
    else
    {
        showmenu_part(Menu_total, s3);
    }
}

void Administrator_widget::on_searchfood_pushButton_clicked()
{
    emit ad_searchmenu_dialogshow();
}

void Administrator_widget::on_addfood_pushButton_clicked()
{
    emit ad_searchmenu_dialogshow();
}

void Administrator_widget::on_deletefood_pushButton_clicked()
{
    emit ad_searchmenu_dialogshow();
}

void Administrator_widget::on_uploadfood_pushButton_clicked()
{
    extern QMultiHash<QString, Food> Menu_total;
    menu_upload(Menu_total);
    QMessageBox::information(this, tr("上传成功"), tr("上传成功！"), QMessageBox::Ok);
}
