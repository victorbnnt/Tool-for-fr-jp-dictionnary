#include <QApplication>
#include <stdio.h>
#include <string.h>
#include "MaFenetre.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

    MaFenetre MaFenetre;
    MaFenetre.show();

    return app.exec();
}

