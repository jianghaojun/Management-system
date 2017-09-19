#include "ad_deletemenu_dialog.h"
#include "ui_ad_deletemenu_dialog.h"

ad_deletemenu_Dialog::ad_deletemenu_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ad_deletemenu_Dialog)
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

    ui->name_lineEdit->setStyleSheet("border:2px groove gray;"
                                  "border-radius:15px;"
                                  "padding:2px 4px;"
                                  "color:rgb(160,160,160);");

    ui->id_lineEdit->setStyleSheet("border:2px groove gray;"
                                   "border-radius:15px;"
                                   "padding:2px 4px;"
                                   "color:rgb(160,160,160);");

    ui->price_lineEdit->setStyleSheet("border:2px groove gray;"
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

ad_deletemenu_Dialog::~ad_deletemenu_Dialog()
{
    delete ui;
}

void ad_deletemenu_Dialog::dialogshow()
{
    this->show();
}

void ad_deletemenu_Dialog::on_back_pushButton_clicked()
{
    this->hide();
    emit administrator_widgetshow();
}

void ad_deletemenu_Dialog::deletepart(QMultiHash<QString, Food> &hash, QString food_type, int id, QString food_name, int food_price)
{
    if(search_food_id(hash, food_type, id))
    {
        Food f(food_name, id, food_price);
        hash.remove(food_type, f);
        QMessageBox::information(this, tr("删除成功"), tr("成功删除"), QMessageBox::Ok);
        ui->id_lineEdit->clear();
        ui->name_lineEdit->clear();
        ui->price_lineEdit->clear();
        //ui->textEdit->setText("结果：");
    }
    else
    {
        QMessageBox::warning(this, tr("删除失败"), tr("在该分类中不存在相同编号的菜品"), QMessageBox::Ok);
        ui->id_lineEdit->setFocus();
    }
}

void ad_deletemenu_Dialog::on_delete_pushButton_clicked()
{
    QString s1 = "Cold Dish";
    QString s2 = "Main Course";
    QString s3 = "Soup";

    extern QMultiHash <QString, Food> Menu_total;

    //ui->textEdit->clear();

    if(ui->id_lineEdit->text().isEmpty() || ui->name_lineEdit->text().isEmpty()
            || ui->price_lineEdit->text().isEmpty() || ui->comboBox->currentText() == "类别")
    {
        QMessageBox::information(this, tr("删除失败"), tr("请完整输入菜品信息（编号/菜名/价格/类别）"), QMessageBox::Ok);
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
