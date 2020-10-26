#ifndef DEF_MAFENETRE
#define DEF_MAFENETRE

#include <QApplication>
#include <QtWidgets>
#include <QtGui>
#include <qpixmap.h>
#include "radwindow.h"

class in_out {public: QString reste; QString hira;};
class in_out RomaToHira(class in_out);
QString LoOp(char *);

class MaFenetre : public QWidget
{
    Q_OBJECT

    public:
    MaFenetre();

    public slots:
    void CreationKanji();
    void SousClasse1();
    void SousClasse2();
    void SousCategorie1();
    void SousCategorie2();
    void ouvrirDialogue();
    void kanji_cree();
    void Selectpath();
    void openRadSelection();
    void updateRadicalList();

    private:
    QPushButton *m_boutonDialogue;
    QPushButton *m_bouton_close;
    QPushButton *m_bouton_num;
    QPushButton *m_bouton_path;
    QPushButton *m_bouton_rad;
    RadWindow *radwindow;

        //path
    QLineEdit *m_input_Path;
    QLabel *m_Path;
        //numero
    QLineEdit *m_input_num;
    QLabel *m_num;
        //Kanji
    QLineEdit *m_input_kanji;
    QLabel *m_kanji;
        //nombre traits
    QLineEdit *m_input_trait;
    QLabel *m_trait;
        //numero clé
    QLineEdit *m_input_key;
    QLabel *m_key;
        //numero clé
    QLineEdit *m_input_radicaux;
    QLabel *m_radicaux;
        //romaji 1
    QLineEdit *m_input_roma1;
    QLabel *m_roma1;
        //romaji 2
    QLineEdit *m_input_roma2;
    QLabel *m_roma2;
        //romaji 3
    QLineEdit *m_input_roma3;
    QLabel *m_roma3;
        //romaji 4
    QLineEdit *m_input_roma4;
    QLabel *m_roma4;
        //romaji 5
    QLineEdit *m_input_roma5;
    QLabel *m_roma5;
        //ON maj 1
    QLineEdit *m_input_ONm1;
    QLabel *m_ONm1;
        //ON maj 2
    QLineEdit *m_input_ONm2;
    QLabel *m_ONm2;
        //ON maj 3
    QLineEdit *m_input_ONm3;
    QLabel *m_ONm3;
        //ON maj 4
    QLineEdit *m_input_ONm4;
    QLabel *m_ONm4;
        //ON maj 5
    QLineEdit *m_input_ONm5;
    QLabel *m_ONm5;
        //Onyomi 1
    QLineEdit *m_input_ONy1;
    QLabel *m_ONy1;
        //Onyomi 2
    QLineEdit *m_input_ONy2;
    QLabel *m_ONy2;
        //Onyomi 3
    QLineEdit *m_input_ONy3;
    QLabel *m_ONy3;
        //Onyomi 4
    QLineEdit *m_input_ONy4;
    QLabel *m_ONy4;
        //Onyomi 5
    QLineEdit *m_input_ONy5;
    QLabel *m_ONy5;

        //fr1
    QLineEdit *m_input_fr1;
    QLabel *m_fr1;
        //fr2
    QLineEdit *m_input_fr2;
    QLabel *m_fr2;
       //fr3
    QLineEdit *m_input_fr3;
    QLabel *m_fr3;
       //fr4
    QLineEdit *m_input_fr4;
    QLabel *m_fr4;
        //fr5
    QLineEdit *m_input_fr5;
    QLabel *m_fr5;
        //fr6
    QLineEdit *m_input_fr6;
    QLabel *m_fr6;
        //fr7
    QLineEdit *m_input_fr7;
    QLabel *m_fr7;
        //fr8
    QLineEdit *m_input_fr8;
    QLabel *m_fr8;

        //Classe 1
     QComboBox *m_classe1;
     QLabel *m_classe1_txt;
        //Sous Classe 1
     QComboBox *m_sclasse1;
     QLabel *m_sclasse1_txt;

        //Classe 2
     QComboBox *m_classe2;
     QLabel *m_classe2_txt;
       //Sous Classe 2
     QComboBox *m_sclasse2;
     QLabel *m_sclasse2_txt;

        //Categorie 1
     QComboBox *m_cat1;
     QLabel *m_cat1_txt;
        //Sous Categorie 1
     QComboBox *m_scat1;
     QLabel *m_scat1_txt;

        //Categorie 2
     QComboBox *m_cat2;
     QLabel *m_cat2_txt;
        //Sous Categorie 2
     QComboBox *m_scat2;
     QLabel *m_scat2_txt;

     //Annee d'etude
  QComboBox *m_year;
  QLabel *m_year_txt;

        //Drapeau
     QLabel *drap;

};

#endif
