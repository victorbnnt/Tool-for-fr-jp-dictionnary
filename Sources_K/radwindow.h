#ifndef RADWINDOW_H
#define RADWINDOW_H

#include <QApplication>
#include <QtWidgets>
#include <QtGui>
#include <qpixmap.h>
#include <QCheckBox>

class RadWindow: public QWidget
{
    Q_OBJECT

    public:
    RadWindow();

    public slots:
    void validate_radical();
    void emit_signal();
    QString getString();

signals:
    void updateRadicalList();

    private:
    QPushButton *m_bouton_close_2;
    QCheckBox *m_radical[252];
    QString stringRad;
    std::string listToPrint;

};

#endif // RADWINDOW_H

