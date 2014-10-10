#include "src/main_dialog.h"
#include "ui_main_dialog.h"
#include "topdialog.h"
#include "del_ins_messagedialog.h"
MainDialog::MainDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainDialog)
{
    ui->setupUi(this);
    ui->pushButton_close->setStyleSheet("background:rgba(0,0,0,0%)");
    ui->pushButton_close->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_close->setStyleSheet("QPushButton{border-image:url(:/images/quit.png)}QPushButton:hover:pressed{border-image:url(:/images/quit_p.png)}");

    ui->pushButton_options->setStyleSheet("background:rgba(0,0,0,0%)");
    ui->pushButton_options->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_options->setStyleSheet("QPushButton{border-image:url(:/images/option.png)}QPushButton:hover:pressed{border-image:url(:/images/option_p.png)}");

    ui->pushButton_list->setStyleSheet("background:rgba(0,0,0,0%)");
    ui->pushButton_list->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_list->setStyleSheet("QPushButton{border-image:url(:/images/top.png)}QPushButton:hover:pressed{border-image:url(:/images/top_p.png)}");

    ui->pushButton_start->setStyleSheet("background:rgba(0,0,0,0%)");
    ui->pushButton_start->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_start->setStyleSheet("QPushButton{border-image:url(:/images/start.png)}QPushButton:hover:pressed{border-image:url(:/images/start_p.png)}");
}

MainDialog::~MainDialog()
{
    delete ui;
}

void MainDialog::on_pushButton_close_clicked()
{
    this->close();
}

void MainDialog::on_pushButton_options_clicked()
{
    OptionDialog::OptionDialog(0);
    optiondialog.setWindowFlags(Qt::FramelessWindowHint);
    optiondialog.exec();
}

void MainDialog::on_pushButton_list_clicked()
{
    topdialog.setWindowFlags(Qt::FramelessWindowHint);
    topdialog.exec();
}

void MainDialog::on_pushButton_start_clicked()
{
    newgamedialog.setWindowFlags(Qt::FramelessWindowHint);
    newgamedialog.exec();
}
