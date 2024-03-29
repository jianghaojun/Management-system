#include "ad_searchmenu_dialog.h"
#include "ui_ad_searchmenu_dialog.h"

ad_searchmenu_Dialog::ad_searchmenu_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ad_searchmenu_Dialog)
{
    ui->setupUi(this);
    ui->textEdit->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
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

    ui->textEdit->setStyleSheet("border:2px groove gray;"
                                  "border-radius:15px;"
                                  "padding:2px 4px;"
                                  "color:rgb(160,160,160);");

    ui->id_lineEdit->setStyleSheet("border:2px groove gray;"
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

    if(ui->id_lineEdit->text().isEmpty() || ui->comboBox->currentText() == "类别")
    {
        QMessageBox::information(this, tr("查询失败"), tr("请输入菜品编号并选择类别！"), QMessageBox::Ok);
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
