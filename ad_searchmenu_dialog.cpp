#include "ad_searchmenu_dialog.h"
#include "ui_ad_searchmenu_dialog.h"

ad_searchmenu_Dialog::ad_searchmenu_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ad_searchmenu_Dialog)
{
    ui->setupUi(this);
}

ad_searchmenu_Dialog::~ad_searchmenu_Dialog()
{
    delete ui;
}

void ad_searchmenu_Dialog::dialogshow()
{
    this->show();
}

void ad_searchmenu_Dialog::on_back_pushButton_clicked()
{
    this->hide();
    emit administrator_widgetshow();
}

void ad_searchmenu_Dialog::searchpart(QMultiHash<QString, Food> hash, QString food_type, int id)
{
    if(search_food_id(hash, food_type, id))
    {
        QString food_name = search_food_name(hash, food_type, id);
        int food_price = search_food_price(hash, food_type, id);
        QString Food_price = QString::number(food_price);
        ui->textEdit->append("Name: " + food_name);
        ui->textEdit->append("Price: " + Food_price);
    }
    else
    {
        ui->textEdit->append("Not Found!");
    }
}

void ad_searchmenu_Dialog::on_search_pushButton_clicked()  //查询相应的菜品
{
    QString s1 = "Cold Dish";
    QString s2 = "Main Course";
    QString s3 = "Soup";

    extern QMultiHash <QString, Food> Menu_total;

    ui->textEdit->clear();

    if(ui->id_lineEdit->text().isEmpty())
    {
        QMessageBox::information(this, tr("查询失败"), tr("请输入菜品编号"), QMessageBox::Ok);
        ui->id_lineEdit->setFocus();
    }
    else
    {
        int id = ui->id_lineEdit->text().toInt();

        if(ui->comboBox->currentText() == s1)
        {
            searchpart(Menu_total, s1, id);
        }
        else if(ui->comboBox->currentText() == s2)
        {
            searchpart(Menu_total, s2, id);
        }
        else
        {
            searchpart(Menu_total, s3, id);
        }
    }
}

void ad_searchmenu_Dialog::addpart(QMultiHash<QString, Food> &hash, QString food_type, int id, QString food_name,int food_price)
{
    if(search_food(hash, id, food_name))
    {
        QMessageBox::information(this, tr("添加失败"), tr("菜品编号或名称重复"), QMessageBox::Ok);
        ui->id_lineEdit->setFocus();
    }
    else
    {
        Food f(food_name, id, food_price);
        hash.insert(food_type, f);
        QMessageBox::information(this, tr("添加成功"), tr("添加成功"), QMessageBox::Ok);
        ui->id_lineEdit->setFocus();
    }
}

void ad_searchmenu_Dialog::on_add_pushButton_clicked()
{
    QString s1 = "Cold Dish";
    QString s2 = "Main Course";
    QString s3 = "Soup";

    extern QMultiHash <QString, Food> Menu_total;

    ui->textEdit->clear();

    if(ui->id_lineEdit->text().isEmpty() || ui->name_lineEdit->text().isEmpty()
            || ui->price_lineEdit->text().isEmpty())
    {
        QMessageBox::information(this, tr("添加失败"), tr("请完整输入菜品信息（编号/菜名/价格）"), QMessageBox::Ok);
        ui->id_lineEdit->setFocus();
    }
    else
    {
        int id = ui->id_lineEdit->text().toInt();
        QString food_name = ui->name_lineEdit->text();
        int food_price = ui->price_lineEdit->text().toInt();

        if(ui->comboBox->currentText() == s1)
        {
            addpart(Menu_total, s1, id, food_name, food_price);
        }
        else if(ui->comboBox->currentText() == s2)
        {
            addpart(Menu_total, s2, id, food_name, food_price);
        }
        else
        {
            addpart(Menu_total, s3, id, food_name, food_price);
        }
    }
}


void ad_searchmenu_Dialog::deletepart(QMultiHash<QString, Food> &hash, QString food_type, int id, QString food_name, int food_price)
{
    if(search_food_id(hash, food_type, id))
    {
        Food f(food_name, id, food_price);
        hash.remove(food_type, f);
        QMessageBox::information(this, tr("删除成功"), tr("成功删除"), QMessageBox::Ok);
    }
    else
    {
        QMessageBox::information(this, tr("删除失败"), tr("在该分类中不存在相同编号的菜品"), QMessageBox::Ok);
        ui->id_lineEdit->setFocus();
    }
}

void ad_searchmenu_Dialog::on_delete_pushButton_clicked()
{
    QString s1 = "Cold Dish";
    QString s2 = "Main Course";
    QString s3 = "Soup";

    extern QMultiHash <QString, Food> Menu_total;

    ui->textEdit->clear();

    if(ui->id_lineEdit->text().isEmpty() || ui->name_lineEdit->text().isEmpty()
            || ui->price_lineEdit->text().isEmpty() )
    {
        QMessageBox::information(this, tr("删除失败"), tr("请完整输入菜品信息（编号/菜名/价格）"), QMessageBox::Ok);
        ui->id_lineEdit->setFocus();
    }
    else
    {
        int id = ui->id_lineEdit->text().toInt();
        QString food_name = ui->name_lineEdit->text();
        int food_price = ui->price_lineEdit->text().toInt();

        if(ui->comboBox->currentText() == s1)
        {
            deletepart(Menu_total, s1, id, food_name, food_price);
        }
        else if(ui->comboBox->currentText() == s2)
        {
            deletepart(Menu_total, s2, id, food_name, food_price);
        }
        else
        {
            deletepart(Menu_total, s3, id, food_name, food_price);
        }
    }
}
