#ifndef NEWGAMEDIALOG_H
#define NEWGAMEDIALOG_H

#include <QDialog>

namespace Ui {
class NewGameDialog;
}

class NewGameDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit NewGameDialog(QWidget *parent = 0);
    ~NewGameDialog();
    
private slots:
    void on_pushButton_registerdone_clicked();

    void on_pushButton_get_back_clicked();

    int on_pushButton_fish_number_done_clicked();

    void on_pushButton_tab2_delete_clicked();

    void on_pushButton_tab2_commit_clicked();

private:
    Ui::NewGameDialog *ui;
};

#endif // NEWGAMEDIALOG_H
