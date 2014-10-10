#ifndef MAIN_DIALOG_H
#define MAIN_DIALOG_H

#include <QDialog>
#include "src/optiondialog.h"
#include "src/newgamedialog.h"
#include "src/topdialog.h"
#include "src/qmessage_dialog.h"
#include "src/del_ins_messagedialog.h"

namespace Ui {
class MainDialog;
}

class MainDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit MainDialog(QWidget *parent = 0);
    ~MainDialog();


private slots:
    void on_pushButton_close_clicked();

    void on_pushButton_options_clicked();

    void on_pushButton_list_clicked();

    void on_pushButton_start_clicked();

private:
    Ui::MainDialog *ui;
    OptionDialog optiondialog;
    NewGameDialog newgamedialog;
    TopDialog topdialog;
    QMessageDialog qmessage_dialog;
//    Del_Ins_MessageDialog del_ins_messagedialog;
};

#endif // MAIN_DIALOG_H
