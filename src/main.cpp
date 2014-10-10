#include <QtGui/QApplication>
#include "src/main_dialog.h"
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainDialog w;
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GB18030"));
    w.setWindowFlags(Qt::FramelessWindowHint);
    w.show();
    
    return a.exec();
}
