#ifndef TOPDIALOG_H
#define TOPDIALOG_H

#include <QDialog>
#include <QListWidgetItem>
#include "del_ins_messagedialog.h"

namespace Ui {
class TopDialog;
}

class TopDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit TopDialog(QWidget *parent = 0);
    ~TopDialog();
    
private slots:
    void on_pushButton_insert_clicked();

    void on_pushButton_delete_clicked();

    void on_pushButton_clicked();

    void listWidget_item_click(QListWidgetItem *item);

    //void on_listWidget_itemClicked(QListWidgetItem *item);

    void receivesig(bool);

private:
    Ui::TopDialog *ui;
};

#endif // TOPDIALOG_H
