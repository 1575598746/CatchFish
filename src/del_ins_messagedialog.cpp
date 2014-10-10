#include "src/del_ins_messagedialog.h"
#include "ui_del_ins_messagedialog.h"
#include <QFile>
#include <QTextStream>
#include "src/qmessage_dialog.h"
#include "src/topdialog.h"
//#include "ui_topdialog.h"

Del_Ins_MessageDialog::Del_Ins_MessageDialog(QWidget *parent, QString question) :
    QDialog(parent),
    ui(new Ui::Del_Ins_MessageDialog)
{
    ui->setupUi(this);
    QFile file(":/style_sheet.qss");
    if(file.open(QFile::ReadOnly))
    {
    QTextStream filetext(&file);
    QString stylesheet = filetext.readAll();
    ui->pushButton_no->setStyleSheet(stylesheet);
    ui->pushButton_yes->setStyleSheet(stylesheet);
    }
    else
    {

    }
    ui->pushButton_no->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_yes->setFocusPolicy(Qt::NoFocus);
    ui->label_question->setStyleSheet("QLabel {font: bold;font-size:20px;color:#8b0e0e;}");
    ques = question;
    ui->label_question->setText(ques);

    connect(ui->pushButton_yes, SIGNAL(clicked()), this, SLOT(pushButton_ok_clicked()));
    connect(ui->pushButton_no, SIGNAL(clicked()), this, SLOT(pushButton_No_clicked()));
}

Del_Ins_MessageDialog::~Del_Ins_MessageDialog()
{
    delete ui;
}

void Del_Ins_MessageDialog::pushButton_ok_clicked()
{
    emit sendsignal(1);
    QMessageDialog *dlg = new QMessageDialog(0, tr("ÒÑÉ¾³ý"));
    dlg->setWindowFlags(Qt::FramelessWindowHint);
    dlg->exec();
    this->close();
}


void Del_Ins_MessageDialog::pushButton_No_clicked()
{
    emit sendsignal(0);
    this->close();
}

