#ifndef DEL_INS_MESSAGEDIALOG_H
#define DEL_INS_MESSAGEDIALOG_H

#include <QDialog>
#include "topdialog.h"
#include "ui_topdialog.h"
namespace Ui {
class Del_Ins_MessageDialog;
}

class Del_Ins_MessageDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Del_Ins_MessageDialog(QWidget *parent = 0, QString question = "");
    ~Del_Ins_MessageDialog();
signals:
    void sendsignal(bool);

private slots:
    void pushButton_ok_clicked();

    void pushButton_No_clicked();

private:
    Ui::Del_Ins_MessageDialog *ui;

    QString ques;
};

#endif // DEL_INS_MESSAGEDIALOG_H
