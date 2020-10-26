#ifndef DEF_MAFENETRE
#define DEF_MAFENETRE

#include <QApplication>
#include <QtWidgets>
#include <QtGui>
#include <qpixmap.h>

class in_out {public: QString reste; QString hira;};
class in_out RomaToHira(class in_out);
QString LoOp(char *);

class MaFenetre : public QWidget
{
    Q_OBJECT

    public:
    MaFenetre();

    public slots:
    void CreationMot();
    void SousClasse1();
    void SousClasse2();
    void SousCategorie1();
    void SousCategorie2();
    void ouvrirDialogue();
    void mot_cree();
    void Selectpath();

    private:
    QPushButton *m_boutonDialogue;
    QPushButton *m_bouton_close;
    QPushButton *m_bouton_num;
    QPushButton *m_bouton_path;

        //path
    QLineEdit *m_input_Path;
    QLabel *m_Path;
        //numero
    QLineEdit *m_input_num;
    QLabel *m_num;
        //Kanji
    QLineEdit *m_input_kanji;
    QLabel *m_kanji;
        //Hiragana
    QLineEdit *m_input_hira;
    QLabel *m_hira;
        //romaji
    QLineEdit *m_input_roma;
    QLabel *m_roma;
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

        //Drapeau
     QLabel *drap;

};

#endif
