#include "radwindow.h"
#include <QString>
#include <string>
#include <QMessageBox>
#include <vector>
#include <sstream>
#include <QTextStream>
#include <QtCore/QCoreApplication>


using namespace std;

RadWindow::RadWindow() : QWidget()
{
    setFixedSize(870, 850);
    QString top = QString::fromUtf8("Nihonka - Sélection radical - 字形を選択");
    setWindowTitle(top);

    QFont maPolice("Meiryo",12,QFont::Bold,false);
    QFont maPolice_radical("Meiryo",12,QFont::Bold,false);
    QIcon monIcone(QCoreApplication::applicationDirPath() + "/nihon.png");

    // Construction du bouton close
    m_bouton_close_2 = new QPushButton("Quitter", this);
    m_bouton_close_2->setFont(maPolice);
    m_bouton_close_2->setCursor(Qt::PointingHandCursor);
    m_bouton_close_2->setIcon(monIcone);
    m_bouton_close_2->move(735,800);
    QObject::connect(m_bouton_close_2, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(m_bouton_close_2, SIGNAL(clicked()), this, SLOT(validate_radical()));
    QObject::connect(m_bouton_close_2, SIGNAL(clicked()), this, SLOT(emit_signal()));

    int j,k;
    k=1;
    j=0;
    string listeRadical[251]={"一","｜","丶","ノ","乙","亅","二","亠","人","亻","へ","儿","入","八","丷","冂","冖","冫","几","凵","刀","リ","力","勹","匕","匚","十","卜","卩","厂","厶","又","マ","九","ユ","乃","辶","口","囗","土","士","夂","夕","大","女","子","宀","寸","小","⺍","尢","尸","屮","山","川","巛","工","已","巾","干","幺","广","廴","廾","弋","弓","ヨ","彑","彡","彳","忄","扌","氵","犭","艹","⻏","⻖","也","亡","及","久","耂","心","戈","戸","手","支","攵","文","斗","斤","方","无","日","曰","月","木","欠","止","歹","殳","比","毛","氏","气","水","火","灬","爪","父","爻","爿","片","牛","犬","礻","王","元","井","勿","尤","五","屯","巴","毋","玄","瓦","甘","生","用","田","疋","疒","癶","白","皮","皿","目","矛","矢","石","示","禸","禾","穴","立","衤","世","巨","冊","母","罒","牙","瓜","竹","米","糸","缶","羊","羽","而","耒","耳","聿","肉","自","至","臼","舌","舟","艮","色","虍","虫","血","行","衣","西","臣","見","角","言","谷","豆","豕","豸","貝","赤","走","足","身","車","辛","辰","酉","釆","里","舛","麦","金","長","門","隶","隹","雨","青","非","奄","岡","免","斉","面","革","韭","音","頁","風","飛","食","首","香","品","馬","骨","高","髟","鬥","鬯","鬲","鬼","竜","韋","魚","鳥","鹵","鹿","麻","亀","黄","黒","黍","黹","無","歯","黽","鼎","鼓","鼠","鼻","齊","龠"};
    for (int i=0;i<251;i++) {
        QString radio = QString::fromStdString(listeRadical[i]);
        m_radical[i] = new QCheckBox(radio,this);
        m_radical[i]->setFont(maPolice_radical);
        m_radical[i]->move(10+70*j,50+(34*k));
        j++;
        if (j==12) {
            k++;
            j=0;
        }
    }
}

void RadWindow::validate_radical(){
    listToPrint="";
    for (int i=0;i<251;i++) {
        if (m_radical[i]->isChecked()) {
            stringstream istring;
            istring<<i+1;
            string st = istring.str();
            listToPrint=listToPrint+","+st;
        }
    }
    if (listToPrint!="") {
        listToPrint=listToPrint.substr(1);
    }
    stringRad=QString::fromStdString(listToPrint);
}

void RadWindow::emit_signal() {
    emit updateRadicalList();
}

QString RadWindow::getString(){
    return stringRad;
}
