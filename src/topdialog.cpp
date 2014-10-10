#include "src/topdialog.h"
#include "ui_topdialog.h"
#include <QMessageBox>
#include <QDebug>
#include <QTextStream>
#include <QFile>
#include "qmessage_dialog.h"
#include "del_ins_messagedialog.h"

TopDialog::TopDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TopDialog)
{
    ui->setupUi(this);
    QFile file(":/style_sheet.qss");
    if(file.open(QFile::ReadOnly))
    {
        QTextStream filetext(&file);
        QString setstylesheet = filetext.readAll();
        ui->listWidget->setStyleSheet("QListWidget {font:bold; font-size:20px; color:yellow; background:rgba(0,0,0,0%); selection-color:#861a05; selection-background-color:gray; border-radius:8px; border:2px solid white;}");
        ui->pushButton->setStyleSheet(setstylesheet);
        ui->pushButton_delete->setStyleSheet(setstylesheet);
        ui->pushButton_insert->setStyleSheet(setstylesheet);
    }
    else
    {
        qDebug()<<"open file error";
    }
        ui->pushButton->setFocusPolicy(Qt::NoFocus);
        ui->pushButton_delete->setFocusPolicy(Qt::NoFocus);
        ui->pushButton_insert->setFocusPolicy(Qt::NoFocus);
        ui->label->setStyleSheet("QLabel {font:bold; font-size:20px; color:#8b0e0e;}");
        ui->label_2->setStyleSheet("QLabel {font:bold; font-size:20px; color:#8b0e0e;}");
        ui->lineEdit->setStyleSheet("QLineEdit {font:bold; font-size:20px; color:yellow; background:rgba(0,0,0,0%); border-radius:8px; border:2px solid white;}");
        ui->lineEdit_2->setStyleSheet("QLineEdit {font:bold; font-size:20px; color:yellow; background:rgba(0,0,0,0%); border-radius:8px; border:2px solid white;}");


        connect(ui->listWidget,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(listWidget_item_click(QListWidgetItem*)) );

        //connect(Del_Ins_MessageDialog,SIGNAL(sendsignal(bool)),this,SLOT(getslot(bool)));

       //connect(this, SIGNAL(on_pushButton_delete_clicked()), this, SLOT(on_delete()));
}

TopDialog::~TopDialog()
{
    delete ui;
}

void TopDialog::on_pushButton_insert_clicked()
{
    QString user = ui->lineEdit->text();
    QString score = ui->lineEdit_2->text();
    user += tr("最高纪录")+score+tr("分");
    ui->listWidget->addItem(new QListWidgetItem(QIcon(QObject::tr("")),user));
    if(ui->lineEdit->text().isEmpty())
    {
        QMessageDialog *dlg = new QMessageDialog(0, tr("用户名不能为空"));
        dlg->setWindowFlags(Qt::FramelessWindowHint);
        dlg->exec();
    }
}

void TopDialog::on_pushButton_delete_clicked()
{
    int index = ui->listWidget->currentIndex().row();
    if(index == -1)
    {
        QMessageDialog *a = new QMessageDialog(0,tr("未选中！"));
        a->setWindowFlags(Qt::FramelessWindowHint);
        a->exec();
    }
    //qDebug()<<"index = "<<index;
    //QMessageBox message(QMessageBox::NoIcon, tr("提示"), tr("确定删除？"), QMessageBox::Yes | QMessageBox::No, NULL);
    else
    {
      Del_Ins_MessageDialog *dlg = new Del_Ins_MessageDialog(0, tr("确认删除？"));
      dlg->setWindowFlags(Qt::FramelessWindowHint);
      connect(dlg, SIGNAL(sendsignal(bool)), this, SLOT(receivesig(bool)));
      dlg->exec();
    }
    //dlg->close();
}


void TopDialog::receivesig(bool a)
{
    if(a == 1)
    {
        int index = ui->listWidget->currentIndex().row();
        ui->listWidget->takeItem(index);
    }
}

void TopDialog::on_pushButton_clicked()
{
    this->close();
}

void TopDialog::listWidget_item_click(QListWidgetItem *item)
{
    QString str = item->text();
    qDebug()<<str;
}

/*void TopDialog::on_listWidget_itemClicked(QListWidgetItem *item)
{
    QString str = item->text();
    qDebug()<<str;
}*/
