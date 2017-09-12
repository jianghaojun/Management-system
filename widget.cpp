#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //设置tablewidget列宽自适应
    ui->mymenu_tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->menu_tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->evaluate_tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //用tablewidget来显示菜单
    extern QMultiHash <QString, Food> Menu_total;
    QMultiHash <QString, Food>::iterator i = Menu_total.begin();
    while(i != Menu_total.end())
    {
        Food f = i.value();
        QString food_type = i.key();
        int id = f.getID();
        QString Id = QString::number(id);       //将int类型转换成QString类型
        QString food_name = f.getName();
        int food_price = f.getPrice();
        QString Food_price = QString::number(food_price);

        int row = ui->menu_tableWidget->rowCount();
        ui->menu_tableWidget->insertRow(row);

        //设置tablewidget行高
        ui->menu_tableWidget->setRowHeight(row,75);

        QWidget *widget = new QWidget(ui->menu_tableWidget);
        QLabel *label = new QLabel;
        label->setPixmap(QPixmap(":/image/images/salad.png").scaled(50,50));
        QHBoxLayout *hLayout = new QHBoxLayout(widget);
        hLayout->addWidget(label);
        hLayout->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
        ui->menu_tableWidget->setCellWidget(row, 0, widget);

        QTableWidgetItem *item1 = new QTableWidgetItem(Id);
        item1->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->menu_tableWidget->setItem(row, 1, item1);

        QTableWidgetItem *item2 = new QTableWidgetItem(food_type);
        item2->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->menu_tableWidget->setItem(row, 2, item2);

        QTableWidgetItem *item3 = new QTableWidgetItem(food_name);
        item3->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->menu_tableWidget->setItem(row, 3, item3);

        QTableWidgetItem *item4 = new QTableWidgetItem(Food_price);
        item4->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->menu_tableWidget->setItem(row, 4, item4);

        QPushButton *add_button = new QPushButton(tr("点菜"));
        ui->menu_tableWidget->setCellWidget(row, 5, add_button);

        //给按钮添加一个属性"row"它的行号，以便在点击时能直接获取它所在的行
        add_button->setProperty("row", row);

        connect(add_button, SIGNAL(clicked()), this, SLOT(add_button_clicked()));

        ++i;
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::widgetshow()
{
    this->show();
}

void Widget::on_A1_pushButton_clicked()
{
    if(!ui->tablenumber_label->text().isEmpty())
    {
        QMessageBox::information(this, tr("上座失败"), tr("您已经选择了座位！"), QMessageBox::Ok);
    }
    else
    {
        QMessageBox::information(this, tr("上座成功"), tr("请就坐！"), QMessageBox::Ok);
        ui->tablenumber_label->setText("01");
        ui->tablenumber_label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->A1_label->setPixmap(QPixmap(":/image/images/full_table.png"));
        extern QVector <Table> Table_list;
        Table_list[0].setTableStatus(1);  // 0表示空闲，1表示有客人但没有服务员，2表示既有客人也有服务员
    }
}

void Widget::on_A2_pushButton_clicked()
{
    if(!ui->tablenumber_label->text().isEmpty())
    {
        QMessageBox::information(this, tr("上座失败"), tr("您已经选择了座位！"), QMessageBox::Ok);
    }
    else
    {
        QMessageBox::information(this, tr("上座成功"), tr("请就坐！"), QMessageBox::Ok);
        ui->tablenumber_label->setText("02");
        ui->tablenumber_label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->A2_label->setPixmap(QPixmap(":/image/images/full_table.png"));
        extern QVector <Table> Table_list;
        Table_list[1].setTableStatus(1);  // 0表示空闲，1表示有客人但没有服务员，2表示既有客人也有服务员
    }
}

void Widget::on_A3_pushButton_clicked()
{
    if(!ui->tablenumber_label->text().isEmpty())
    {
        QMessageBox::information(this, tr("上座失败"), tr("您已经选择了座位！"), QMessageBox::Ok);
    }
    else
    {
        QMessageBox::information(this, tr("上座成功"), tr("请就坐！"), QMessageBox::Ok);
        ui->tablenumber_label->setText("03");
        ui->tablenumber_label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->A3_label->setPixmap(QPixmap(":/image/images/full_table.png"));
        extern QVector <Table> Table_list;
        Table_list[2].setTableStatus(1);  // 0表示空闲，1表示有客人但没有服务员，2表示既有客人也有服务员
    }
}

void Widget::on_A4_pushButton_clicked()
{
    if(!ui->tablenumber_label->text().isEmpty())
    {
        QMessageBox::information(this, tr("上座失败"), tr("您已经选择了座位！"), QMessageBox::Ok);
    }
    else
    {
        QMessageBox::information(this, tr("上座成功"), tr("请就坐！"), QMessageBox::Ok);
        ui->tablenumber_label->setText("04");
        ui->tablenumber_label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->A4_label->setPixmap(QPixmap(":/image/images/full_table.png"));
        extern QVector <Table> Table_list;
        Table_list[3].setTableStatus(1);  // 0表示空闲，1表示有客人但没有服务员，2表示既有客人也有服务员
    }
}

void Widget::on_A5_pushButton_clicked()
{
    if(!ui->tablenumber_label->text().isEmpty())
    {
        QMessageBox::information(this, tr("上座失败"), tr("您已经选择了座位！"), QMessageBox::Ok);
    }
    else
    {
        QMessageBox::information(this, tr("上座成功"), tr("请就坐！"), QMessageBox::Ok);
        ui->tablenumber_label->setText("05");
        ui->tablenumber_label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->A5_label->setPixmap(QPixmap(":/image/images/full_table.png"));
        extern QVector <Table> Table_list;
        Table_list[4].setTableStatus(1);  // 0表示空闲，1表示有客人但没有服务员，2表示既有客人也有服务员
    }
}

void Widget::on_A6_pushButton_clicked()
{
    if(!ui->tablenumber_label->text().isEmpty())
    {
        QMessageBox::information(this, tr("上座失败"), tr("您已经选择了座位！"), QMessageBox::Ok);
    }
    else
    {
        QMessageBox::information(this, tr("上座成功"), tr("请就坐！"), QMessageBox::Ok);
        ui->tablenumber_label->setText("06");
        ui->tablenumber_label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->A6_label->setPixmap(QPixmap(":/image/images/full_table.png"));
        extern QVector <Table> Table_list;
        Table_list[5].setTableStatus(1);  // 0表示空闲，1表示有客人但没有服务员，2表示既有客人也有服务员
    }
}

void Widget::on_A7_pushButton_clicked()
{
    if(!ui->tablenumber_label->text().isEmpty())
    {
        QMessageBox::information(this, tr("上座失败"), tr("您已经选择了座位！"), QMessageBox::Ok);
    }
    else
    {
        QMessageBox::information(this, tr("上座成功"), tr("请就坐！"), QMessageBox::Ok);
        ui->tablenumber_label->setText("07");
        ui->tablenumber_label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->A7_label->setPixmap(QPixmap(":/image/images/full_table.png"));
        extern QVector <Table> Table_list;
        Table_list[6].setTableStatus(1);  // 0表示空闲，1表示有客人但没有服务员，2表示既有客人也有服务员
    }
}

void Widget::on_A8_pushButton_clicked()
{
    if(!ui->tablenumber_label->text().isEmpty())
    {
        QMessageBox::information(this, tr("上座失败"), tr("您已经选择了座位！"), QMessageBox::Ok);
    }
    else
    {
        QMessageBox::information(this, tr("上座成功"), tr("请就坐！"), QMessageBox::Ok);
        ui->tablenumber_label->setText("08");
        ui->tablenumber_label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->A8_label->setPixmap(QPixmap(":/image/images/full_table.png"));
        extern QVector <Table> Table_list;
        Table_list[7].setTableStatus(1);  // 0表示空闲，1表示有客人但没有服务员，2表示既有客人也有服务员
    }
}

void Widget::add_button_clicked()
{
    if(ui->tablenumber_label->text().isEmpty())
    {
        QMessageBox::information(this, tr("点菜失败"), tr("请先选择您的座位！"), QMessageBox::Ok);
    }
    else
    {
        //下面两行是获取所点击按钮所在的行数（在构造按钮时先给按钮设置一个property（“row”，row），即按钮所在的行数）
        QPushButton *btn = (QPushButton *) sender();
        int row = btn->property("row").toInt();

        int id = ui->menu_tableWidget->item(row, 1)->text().toInt();
        QString name = ui->menu_tableWidget->item(row, 3)->text();
        int price = ui->menu_tableWidget->item(row, 4)->text().toInt();
        int table_number = ui->tablenumber_label->text().toInt();

        extern QVector <Table> Table_list;
        Food f(name, id, price);

        Table_list[table_number-1].m.Menulist.push_back(f);

        int row1 = ui->mymenu_tableWidget->rowCount();               //清空原先的表格
        if(row1 != 0)
        {
            for(int i = row1; i >= 0; --i)
            {
                for(int j = 0; j < 3; ++j)
                {
                    delete ui->mymenu_tableWidget->takeItem(i, j);   //删除用 new 申请的内存
                }
                ui->mymenu_tableWidget->removeRow(i);
            }
        }

        for(int i = 0; i < Table_list[table_number-1].m.Menulist.size(); ++i)
        {
            int row = ui->mymenu_tableWidget->rowCount();
            Food f1 = Table_list[table_number-1].m.Menulist.at(i);
            QString name = f1.getName();
            QString price = QString::number(f1.getPrice());

            ui->mymenu_tableWidget->insertRow(row);
            ui->mymenu_tableWidget->setRowHeight(row,50);

            QTableWidgetItem *item0 = new QTableWidgetItem(name);
            item0->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            ui->mymenu_tableWidget->setItem(row, 0, item0);

            QTableWidgetItem *item1 = new QTableWidgetItem(price);
            item1->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            ui->mymenu_tableWidget->setItem(row, 1, item1);

            QPushButton *delete_button = new QPushButton(tr("删除"));
            ui->mymenu_tableWidget->setCellWidget(row, 2, delete_button);
            delete_button->setProperty("row", row);

            connect(delete_button, SIGNAL(clicked()), this, SLOT(delete_button_clicked()));
        }

        //用标签显示费用
        if(ui->tablenumber_label->text().isEmpty())
        {
            ui->fee_label->setText("￥:0");
        }
        else
        {
            QString fee = QString::number(Table_list[table_number-1].m.getSum());
            ui->fee_label->setText("￥:" + fee);
        }
    }

}

void Widget::delete_button_clicked()
{
    //下面两行是获取所点击按钮所在的行数（在构造按钮时先给按钮设置一个property（“row”，row），即按钮所在的行数）
    //QPushButton *btn = (QPushButton *) sender();
    //int row = btn->property("row").toInt();
    int row = ui->mymenu_tableWidget->currentRow();

    //删除行
    for(int i = 0; i < 3; ++i)
    {
        delete ui->mymenu_tableWidget->takeItem(row, i);   //删除用 new 申请的内存
    }
    ui->mymenu_tableWidget->removeRow(row);

    //删除菜单里对应的菜
    int table_number = ui->tablenumber_label->text().toInt();
    extern QVector <Table> Table_list;
    Table_list[table_number-1].m.Menulist.removeAt(row);

    //重新显示总价
    QString fee = QString::number(Table_list[table_number-1].m.getSum());
    ui->fee_label->setText("￥:" + fee);
}

void Widget::on_back_pushButton_clicked()
{
    this->hide();
    emit login_dialogshow();
    if(!ui->tablenumber_label->text().isEmpty())
    {
        int table_number = ui->tablenumber_label->text().toInt();

        //重置餐桌对应的菜单和空闲情况
        extern QVector <Table> Table_list;
        Table_list[table_number-1].m.Menulist.clear();
        Table_list[table_number-1].setTableStatus(0);  // 0表示空闲，1表示有客人但没有服务员，2表示既有客人也有服务员

        //重置餐桌空闲情况
        switch (table_number)
        {
        case(1):
            ui->A1_label->setPixmap(QPixmap(":/image/images/empty_table.png"));
            break;
        case(2):
            ui->A2_label->setPixmap(QPixmap(":/image/images/empty_table.png"));
            break;
        case(3):
            ui->A3_label->setPixmap(QPixmap(":/image/images/empty_table.png"));
            break;
        case(4):
            ui->A4_label->setPixmap(QPixmap(":/image/images/empty_table.png"));
            break;
        case(5):
            ui->A5_label->setPixmap(QPixmap(":/image/images/empty_table.png"));
            break;
        case(6):
            ui->A6_label->setPixmap(QPixmap(":/image/images/empty_table.png"));
            break;
        case(7):
            ui->A7_label->setPixmap(QPixmap(":/image/images/empty_table.png"));
            break;
        case(8):
            ui->A8_label->setPixmap(QPixmap(":/image/images/empty_table.png"));
            break;
        default:
            break;
        }
    }

    //清空标签的内容
    ui->tablenumber_label->setText("未选择座位");
    ui->fee_label->setText("￥:");

    //清空mymenu的表格
    int row = ui->mymenu_tableWidget->rowCount();
    if(row != 0)
    {
        for(int i = row; i >= 0; --i)
        {
            for(int j = 0; j < 3; ++j)
            {
                delete ui->mymenu_tableWidget->takeItem(i, j);   //删除用 new 申请的内存
            }
            ui->mymenu_tableWidget->removeRow(i);
        }
    }
}

void Widget::receive_customer_pn(QString pn)
{
    ui->welcome_label->setText("手机号为：" + pn);
}

void Widget::on_order_pushButton_clicked()
{
    QMessageBox *messagebox = new QMessageBox(this);
    messagebox->setWindowTitle("下单确认");
    messagebox->setText("客官确定要下单吗？");
    messagebox->setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    messagebox->setDefaultButton(QMessageBox::Cancel);
    int choice = messagebox->exec();
    if(choice == QMessageBox::Ok && !ui->tablenumber_label->text().isEmpty())
    {
        //如果确认下单则重置mymenu_tablewidget把删除按钮去除
        int row = ui->mymenu_tableWidget->rowCount();               //清空原先的表格
        if(row != 0)
        {
            for(int i = row; i >= 0; --i)
            {
                for(int j = 0; j < 3; ++j)
                {
                    delete ui->mymenu_tableWidget->takeItem(i, j);   //删除用 new 申请的内存
                }
                ui->mymenu_tableWidget->removeRow(i);
            }
        }
        ui->mymenu_tableWidget->removeColumn(2);

        int table_number = ui->tablenumber_label->text().toInt();

        extern QVector <Table> Table_list;

        for(int i = 0; i < Table_list[table_number-1].m.Menulist.size(); ++i)
        {
            int row = ui->mymenu_tableWidget->rowCount();
            Food f1 = Table_list[table_number-1].m.Menulist.at(i);
            QString name = f1.getName();
            QString price = QString::number(f1.getPrice());

            ui->mymenu_tableWidget->insertRow(row);
            ui->mymenu_tableWidget->setRowHeight(row,50);

            QTableWidgetItem *item0 = new QTableWidgetItem(name);
            item0->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            ui->mymenu_tableWidget->setItem(row, 0, item0);

            QTableWidgetItem *item1 = new QTableWidgetItem(price);
            item1->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            ui->mymenu_tableWidget->setItem(row, 1, item1);
        }
    }
    else
    {
        QMessageBox::information(this, tr("下单失败"), tr("请先选择座位！"), QMessageBox::Ok);
    }
}

void Widget::on_pay_pushButton_clicked()
{
    QString sum = ui->fee_label->text();
    QMessageBox *paymessage = new QMessageBox(this);
    paymessage->setIconPixmap(QPixmap(":/image/images/customer.png"));
    paymessage->setWindowTitle("买单确认");
    paymessage->setText("客官消费金额 " + sum);
    paymessage->setInformativeText("买单后请客官评价我们的菜品和服务员哦！");
    paymessage->setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    paymessage->setDefaultButton(QMessageBox::Ok);
    int choice = paymessage->exec();
    if(choice == QMessageBox::Ok)
    {
        //在evaluate_tablewidget内显示评价表
        int row = ui->evaluate_tableWidget->rowCount();

        ui->evaluate_tableWidget->insertRow(row);
        ui->evaluate_tableWidget->setRowHeight(row,50);

        QTableWidgetItem *item0 = new QTableWidgetItem("服务员");
        item0->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->evaluate_tableWidget->setItem(row, 0, item0);

        QDoubleSpinBox *waiterbox = new QDoubleSpinBox();
        waiterbox->setMaximum(5.0);
        waiterbox->setMinimum(0.0);
        waiterbox->setSingleStep(0.5);
        waiterbox->setValue(5.0);
        //QTableWidgetItem *item1 = new QTableWidgetItem();
        //item1->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->evaluate_tableWidget->setCellWidget(row, 1, waiterbox);

        int table_number = ui->tablenumber_label->text().toInt();

        extern QVector <Table> Table_list;

        for(int i = 0; i < Table_list[table_number-1].m.Menulist.size(); ++i)
        {
            int row = ui->evaluate_tableWidget->rowCount();
            Food f1 = Table_list[table_number-1].m.Menulist.at(i);
            QString name = f1.getName();
            //QString price = QString::number(f1.getPrice());

            ui->evaluate_tableWidget->insertRow(row);
            ui->evaluate_tableWidget->setRowHeight(row,50);

            QTableWidgetItem *item0 = new QTableWidgetItem(name);
            item0->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            ui->evaluate_tableWidget->setItem(row, 0, item0);

            QDoubleSpinBox *foodbox = new QDoubleSpinBox();
            foodbox->setMaximum(5.0);
            foodbox->setMinimum(0.0);
            foodbox->setSingleStep(0.5);
            foodbox->setValue(5.0);
            //QTableWidgetItem *item1 = new QTableWidgetItem();
            //item1->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            ui->evaluate_tableWidget->setCellWidget(row, 1, foodbox);
        }
    }
}
