#include "src/gamedialog.h"
#include "ui_gamedialog.h"

GameDialog::GameDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameDialog)
{
    ui->setupUi(this);
    ui->pushButton_Game_Back->setStyleSheet("background:rgba(0,0,0,0%);");
    ui->pushButton_Game_Back->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_Game_Back->setStyleSheet("QPushButton{border-image:url(:/images/back.png);font-size:24px;}QPushButton:hover:pressed{border-image:url(:/images/back_p.png);}");

}

GameDialog::~GameDialog()
{
    delete ui;
}

void GameDialog::on_pushButton_Game_Back_clicked()
{
    this->close();
}
