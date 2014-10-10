#include "src/optiondialog.h"
#include "ui_optiondialog.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

OptionDialog::OptionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OptionDialog)
{
    ui->setupUi(this);
    ui->pushButton_back->setStyleSheet("background:rgba(0,0,0,0%);");
    ui->pushButton_back->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_back->setStyleSheet("QPushButton{border-image:url(:/images/back.png);font-size:24px;}QPushButton:hover:pressed{border-image:url(:/images/back_p.png);}");

    ui->pushButton_correct->setStyleSheet("background:rgba(0,0,0,0%);");
    ui->pushButton_correct->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_correct->setStyleSheet("QPushButton{border-image:url(:/images/correct.png);font-size:24px;}QPushButton:hover:pressed{border-image:url(:/images/correct_p.png);}");

    QFile file(":/style_sheet.qss");
    if(file.open(QFile::ReadOnly))
    {
        QTextStream filetext(&file);
        QString stylesheet = filetext.readAll();
        ui->checkBox_soundeffects->setStyleSheet("background:rgba(0,0,0,0%);");
        ui->checkBox_soundeffects->setStyleSheet(stylesheet);
        ui->checkBox_soundeffects->setFocusPolicy(Qt::NoFocus);

        ui->checkBox_inform->setStyleSheet(stylesheet);
        ui->checkBox_inform->setFocusPolicy(Qt::NoFocus);

        ui->radioButton_easy->setStyleSheet(stylesheet);
        ui->radioButton_easy->setFocusPolicy(Qt::NoFocus);

        ui->radioButton_middle->setStyleSheet(stylesheet);
        ui->radioButton_middle->setFocusPolicy(Qt::NoFocus);

        ui->radioButton_hard->setStyleSheet(stylesheet);
        ui->radioButton_hard->setFocusPolicy(Qt::NoFocus);
    }
    else
    {
        qDebug()<<"Open file error";
    }
}

OptionDialog::~OptionDialog()
{
    delete ui;
}

void OptionDialog::on_pushButton_back_clicked()
{
    close();
}

void OptionDialog::on_pushButton_correct_clicked()
{
    if(ui->radioButton_easy->isChecked())
    {
        qDebug()<<"easy difficulty";
    }
    else if(ui->radioButton_middle->isChecked())
    {
        qDebug()<<"medium difficulty";
    }
    else if(ui->radioButton_hard->isChecked())
    {
        qDebug()<<"hard difficulty";
    }
    else
    {
        qDebug()<<"nothing selected";
    }
    if(ui->checkBox_soundeffects->isChecked())
    {
        qDebug()<<"sound open";
    }
    else
    {
        qDebug()<<"sound close";
    }
    if(ui->checkBox_inform->isChecked())
    {
        qDebug()<<"message notif";
    }
    else
    {
        qDebug()<<"message notif close";
    }
    this->close();
}
