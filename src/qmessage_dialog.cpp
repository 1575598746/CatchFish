/*
Copyright 2011  Newsoft Institude of Information.
Author : Chunjun Zheng.
Content:
*/
#include "src/qmessage_dialog.h"
#include "ui_qmessage_dialog.h"
#include "src/del_ins_messagedialog.h"
#include <QFile>
#include <QTextStream>
QMessageDialog::QMessageDialog(QWidget *parent,QString strname) :
    QDialog(parent),
    ui(new Ui::QMessageDialog)
{
    ui->setupUi(this);
    QFile file(":/style_sheet.qss");
    if(file.open(QFile::ReadOnly))
    {
    QTextStream filetext(&file);
    QString stylesheet = filetext.readAll();
    ui->pushButton->setStyleSheet(stylesheet);
    }
    else
    {

    }
    ui->pushButton->setFocusPolicy(Qt::NoFocus);
    ui->label_2->setStyleSheet("QLabel {font: bold;font-size:20px;color:#8b0e0e;}");
    str=strname;
    ui->label_2->setText(str);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(window_close()));
}

QMessageDialog::~QMessageDialog()
{
    delete ui;
}
void QMessageDialog::window_close()
{
    this->close();
}

/*void QMessageDialog::on_pushButton_clicked()
{
    this->close();
}*/

