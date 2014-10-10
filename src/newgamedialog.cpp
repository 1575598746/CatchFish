#include "src/newgamedialog.h"
#include "ui_newgamedialog.h"
#include "qmessage_dialog.h"
#include <QMessageBox>


NewGameDialog::NewGameDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewGameDialog)
{
    ui->setupUi(this);

    ui->pushButton_get_back->setStyleSheet("background:rgba(0,0,0,0%);");
    ui->pushButton_get_back->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_get_back->setStyleSheet("QPushButton{border-image:url(:/images/back.png);font-size:24px;}QPushButton:hover:pressed{border-image:url(:/images/back_p.png);}");

    ui->pushButton_registerdone->setStyleSheet("background:rgba(0,0,0,0%);");
    ui->pushButton_registerdone->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_registerdone->setStyleSheet("QPushButton{border-image:url(:/images/correct.png);font-size:24px;}QPushButton:hover:pressed{border-image:url(:/images/correct_p.png);}");

    ui->pushButton_fish_number_done->setStyleSheet("background:rgba(0,0,0,0%);");
    ui->pushButton_fish_number_done->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_fish_number_done->setStyleSheet("QPushButton{border-image:url(:/images/correct.png);font-size:24px;}QPushButton:hover:pressed{border-image:url(:/images/correct_p.png);}");

    ui->pushButton_tab2_delete->setStyleSheet("background:rgba(0,0,0,0%);");
    ui->pushButton_tab2_delete->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_tab2_delete->setStyleSheet("QPushButton{border-image:url(:/images/delete.png);font-size:24px;}QPushButton:hover:pressed{border-image:url(:/images/delete_p.png);}");

    ui->pushButton_tab2_commit->setStyleSheet("background:rgba(0,0,0,0%);");
    ui->pushButton_tab2_commit->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_tab2_commit->setStyleSheet("QPushButton{border-image:url(:/images/correct.png);font-size:24px;}QPushButton:hover:pressed{border-image:url(:/images/correct_p.png);}");


    ui->tabWidget->setFocusPolicy(Qt::NoFocus);
    ui->tabWidget->setStyleSheet(
                "QTabBar::tab{background:gray; color:yellow; padding:12px;}"
                "QTabBar::tab:selected{background:#0868f8;}"
                "QTabWidget::pane{border:1;}"
                "QWidget{background: rgba(0,0,0,0%);}");

    ui->label_name->setStyleSheet("QLabel {font:bold; font-size:20px; color:#8b0e0e;}");
    ui->label_code->setStyleSheet("QLabel {font:bold; font-size:20px; color:#8b0e0e;}");
    ui->label_codeconfirm->setStyleSheet("QLabel {font:bold; font-size:20px; color:#8b0e0e;}");

    ui->lineEdit_name->setStyleSheet("QLineEdit {font:bold; font-size:20px; color:white; border-radius:8px; border:2px solid white}");
    ui->lineEdit_code->setStyleSheet("QLineEdit {font:bold; font-size:20px; color:white; border-radius:8px; border:2px solid white}");
    ui->lineEdit_codeconfirm->setStyleSheet("QLineEdit {font:bold; font-size:20px; color:white; border-radius:8px; border:2px solid white}");

    ui->lineEdit_number1->setText("0");
    ui->lineEdit_number2->setText("0");
    ui->lineEdit_number3->setText("0");
    ui->lineEdit_number4->setText("0");
    //ui->lineEdit_fish_num->setText("0");



}

NewGameDialog::~NewGameDialog()
{
    delete ui;
}


void NewGameDialog::on_pushButton_registerdone_clicked()
{
    if(ui->lineEdit_name->text().isEmpty())
    {
        QMessageDialog *dlg = new QMessageDialog(0, tr("用户名不能为空"));
        dlg->setWindowFlags(Qt::FramelessWindowHint);
        dlg->exec();
        //QMessageBox::warning(NULL, tr("warning"), tr("用户名不能为空"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
                      /*出现warning图标*/                                /*yes获得焦点*/
        ui->lineEdit_name->setFocus();
        //qDebug("name is empty");
    }
    else if((ui->lineEdit_code->text().isEmpty())||(ui->lineEdit_code->text()!=ui->lineEdit_codeconfirm->text()))
    {
        ui->lineEdit_code->setFocus();
        qDebug("code is wrong");
        QMessageBox::critical(NULL, tr("错误"), tr("两次密码不匹配"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    }
    else
    {
        qDebug("code is correct");
        QString str = ui->lineEdit_name->text();
        int index = ui->comboBox_user->findText(str);//找到comboBox中包含str文本的选项，并返回选项的位置；
        //qDebug()<<"index ="<<index;
        if(index < 0)
        {
         QMessageBox::information(NULL, tr("信息"), tr("注册成功"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
         ui->comboBox_user->addItem(str);
         ui->tabWidget->setCurrentIndex(1);
        }
        else
        {
         QMessageBox::question(NULL, tr("question"), tr("已有此用户"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
         ui->comboBox_user->setCurrentIndex(index);//设置comboBox中的默认项；
         ui->tabWidget->setCurrentIndex(1);//设置tabWidget中的默认项；
        }
    }

}

void NewGameDialog::on_pushButton_get_back_clicked()
{
    this->close();
}

int NewGameDialog::on_pushButton_fish_number_done_clicked()
{
    int sum = ui->lineEdit_number1->text().toInt();
        sum += ui->lineEdit_number2->text().toInt();
        sum += ui->lineEdit_number3->text().toInt();
        sum += ui->lineEdit_number4->text().toInt();
        //QString str[4] = {ui->lineEdit_number1->text(),ui->lineEdit_number2->text(),ui->lineEdit_number3->text(),ui->lineEdit_number4->text()};
        //const char *a[4];
        //a[1] =
        //if(sum == 0)
        //{
           // QMessageDialog *dlg = new QMessageDialog(0, tr("鱼的数量不能为空"));
            //dlg->setWindowFlags(Qt::FramelessWindowHint);
            //dlg->exec();
        //}
        //QString str = QString::number(sum,10);
        //else
        //{
        ui->tabWidget->setCurrentIndex(1);
        //}
        return sum;
}

void NewGameDialog::on_pushButton_tab2_delete_clicked()
{
    int index = ui->comboBox_user->currentIndex();
    ui->comboBox_user->removeItem(index);
}

void NewGameDialog::on_pushButton_tab2_commit_clicked()
{
    /*if((ui->comboBox_user->Text=="")||(ui->lineEdit_tab2_secret->text().isEmpty()))
    {
        ui->lineEdit_tab2_secret->setFocus();
        qDebug("empty input");
    }*/
    int num = on_pushButton_fish_number_done_clicked();
    QString str = QString::number(num,10);
    ui->lineEdit_fish_num_tab2->setText(str);

    if((ui->comboBox_user->count()) == 0)
    {
        QMessageDialog *dlg = new QMessageDialog(0, tr("用户名不能为空"));
        dlg->setWindowFlags(Qt::FramelessWindowHint);
        dlg->exec();
    }
}
