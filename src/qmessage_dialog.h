#ifndef QMESSAGE_DIALOG_H
#define QMESSAGE_DIALOG_H

#include <QDialog>
#include <QString>
namespace Ui {
class QMessageDialog;
}

class QMessageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QMessageDialog(QWidget *parent = 0,QString strname="");
    ~QMessageDialog();

private:
    Ui::QMessageDialog *ui;
    QString str;

private slots:
    void window_close();
};

#endif // QMESSAGE_DIALOG_H
