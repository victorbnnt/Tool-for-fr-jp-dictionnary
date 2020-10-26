#include "MaFenetre.h"
#include <QString>
#include <QTextStream>
#include <QtCore/QCoreApplication>


using namespace std;

MaFenetre::MaFenetre() : QWidget()
{
    setFixedSize(775, 700);
    setWindowTitle("Nihonka - Creer un mot");

    QFont maPolice("Meiryo",12,QFont::Bold,false);
    QIcon monIcone(QCoreApplication::applicationDirPath() + "/nihon.png");

    //Drapeau
    drap = new QLabel(this);
    drap->setPixmap(QPixmap(QCoreApplication::applicationDirPath()+"/hiver.png" ));

    // Construction du bouton close
    m_bouton_close = new QPushButton("Quitter", this);
    m_bouton_close->setFont(maPolice);
    m_bouton_close->setCursor(Qt::PointingHandCursor);
    m_bouton_close->setIcon(monIcone);
    m_bouton_close->move(260,660);
    QObject::connect(m_bouton_close, SIGNAL(clicked()), qApp, SLOT(quit()));

    // Construction du bouton création
    m_bouton_num = new QPushButton("Creer le mot", this);
    m_bouton_num->setFont(maPolice);
    m_bouton_num->setCursor(Qt::PointingHandCursor);
    m_bouton_num->setIcon(monIcone);
    m_bouton_num->move(10,660);
    QObject::connect(m_bouton_num, SIGNAL(clicked()), this, SLOT(CreationMot()));

    //Création input pour le dossier de sortie
    m_input_Path = new QLineEdit(this);
    m_input_Path->setGeometry(10, 100, 600, 20);
    m_Path = new QLabel("Sélectionner le répertoire où enregistrer:",this);
    m_Path->move(12,80);

    // Construction du bouton sélection du chemin
    m_bouton_path = new QPushButton("...", this);
    m_bouton_path->setCursor(Qt::PointingHandCursor);
    m_bouton_path->setGeometry(620,100,50,20);
    m_bouton_path->setIcon(monIcone);
    QObject::connect(m_bouton_path, SIGNAL(clicked()), this, SLOT(Selectpath()));

    //Creation input numero
    m_input_num = new QLineEdit(this);
    m_input_num->setGeometry(10, 210, 150, 20);
    m_num = new QLabel("Numero du mot",this);
    m_num->move(12,195);

    //Creation input kanji
    m_input_kanji = new QLineEdit(this);
    m_input_kanji->setGeometry(10, 270, 150, 20);
    m_kanji = new QLabel("Ecriture en Kanji",this);
    m_kanji->move(12,255);

    //Creation input romaji
    m_input_roma = new QLineEdit(this);
    m_input_roma->setGeometry(10, 330, 150, 20);
    m_roma = new QLabel("Ecriture en Romaji",this);
    m_roma->move(12,315);

    //Creation input fr1
    m_input_fr1 = new QLineEdit(this);
    m_input_fr1->setGeometry(10, 410, 150, 20);
    m_fr1 = new QLabel("Traduction 1",this);
    m_fr1->move(12,395);

    //Creation input fr2
    m_input_fr2 = new QLineEdit(this);
    m_input_fr2->setGeometry(210, 410, 150, 20);
    m_fr2 = new QLabel("Traduction 2",this);
    m_fr2->move(212,395);

    //Creation input fr3
    m_input_fr3 = new QLineEdit(this);
    m_input_fr3->setGeometry(10, 470, 150, 20);
    m_fr3 = new QLabel("Traduction 3",this);
    m_fr3->move(12,455);

    //Creation input fr4
    m_input_fr4 = new QLineEdit(this);
    m_input_fr4->setGeometry(210, 470, 150, 20);
    m_fr4 = new QLabel("Traduction 4",this);
    m_fr4->move(212,455);

    //Creation Classe 1
    m_classe1 = new QComboBox(this);
    m_classe1->setGeometry(10, 550, 150, 20);
    m_classe1->addItem("Choisir une classe");
    m_classe1->addItem("1. Nom commun");
    m_classe1->addItem("2. Nom propre");
    m_classe1->addItem("3. Verbe");
    m_classe1->addItem("4. Adjectif");
    m_classe1->addItem("5. Adverbe");
    m_classe1->addItem("6. Determinant");
    m_classe1->addItem("7. Pronom");
    m_classe1->addItem("8. Conjonction");
    m_classe1->addItem("9. Particule");
    m_classe1->addItem("10. Expression");
    m_classe1->addItem("11. Compteur");
    m_classe1_txt = new QLabel("Classe 1*",this);
    m_classe1_txt->move(12,535);
    QObject::connect(m_classe1, SIGNAL(activated(int)),this, SLOT(SousClasse1()));

    //Creation Sous Classe 1
    m_sclasse1 = new QComboBox(this);
    m_sclasse1->setGeometry(210, 550, 150, 20);
    m_sclasse1_txt = new QLabel("Sous-Classe 1",this);
    m_sclasse1_txt->move(212,535);

    //Creation Classe 2
    m_classe2 = new QComboBox(this);
    m_classe2->setGeometry(10, 610, 150, 20);
    m_classe2->addItem("Choisir une classe");
    m_classe2->addItem("1. Nom commun");
    m_classe2->addItem("2. Nom propre");
    m_classe2->addItem("3. Verbe");
    m_classe2->addItem("4. Adjectif");
    m_classe2->addItem("5. Adverbe");
    m_classe2->addItem("6. Determinant");
    m_classe2->addItem("7. Pronom");
    m_classe2->addItem("8. Conjonction");
    m_classe2->addItem("9. Particule");
    m_classe2->addItem("10. Expression");
    m_classe2->addItem("11. Compteur");
    m_classe2_txt = new QLabel("Classe 2",this);
    m_classe2_txt->move(12,595);
    QObject::connect(m_classe2, SIGNAL(activated(int)),this, SLOT(SousClasse2()));

    //Creation Sous Classe 2
    m_sclasse2 = new QComboBox(this);
    m_sclasse2->setGeometry(210, 610, 150, 20);
    m_sclasse2_txt = new QLabel("Sous-Classe 2",this);
    m_sclasse2_txt->move(212,595);

    //Creation Categorie 1
    m_cat1 = new QComboBox(this);
    m_cat1->setGeometry(410,210, 150, 20);
    m_cat1->addItem("Aucune");
    m_cat1->addItem("1. Lieu");
    m_cat1->addItem("2. Geographie");
    m_cat1->addItem("3. Travail");
    m_cat1->addItem("4. Construction");
    m_cat1->addItem("5. Divertissement");
    m_cat1->addItem("6. Etudes");
    m_cat1->addItem("7. Objet");
    m_cat1->addItem("8. Deplacement");
    m_cat1->addItem("9. Nourriture");
    m_cat1->addItem("10. Etre humain");
    m_cat1->addItem("11. Nature");
    m_cat1->addItem("12. Katakana");
    m_cat1->addItem("13. Communication");
    m_cat1->addItem("14. Temporel");
    m_cat1->addItem("15. Art");
    m_cat1->addItem("16. Appareil");
    m_cat1->addItem("17. Guerre");
    m_cat1->addItem("18. Sante");
    m_cat1->addItem("19. Consommation");
    m_cat1->addItem("20. Energie");
    m_cat1_txt = new QLabel("Categorie 1",this);
    m_cat1_txt->move(412,195);
    QObject::connect(m_cat1, SIGNAL(activated(int)),this, SLOT(SousCategorie1()));

    //Creation Sous Categorie 1
    m_scat1 = new QComboBox(this);
    m_scat1->setGeometry(610,210, 150, 20);
    m_scat1_txt = new QLabel("Sous-categorie 1",this);
    m_scat1_txt->move(612,195);

    //Creation Categorie 2
    m_cat2 = new QComboBox(this);
    m_cat2->setGeometry(410, 270, 150, 20);
    m_cat2->addItem("Aucune");
    m_cat2->addItem("1. Lieu");
    m_cat2->addItem("2. Geographie");
    m_cat2->addItem("3. Travail");
    m_cat2->addItem("4. Construction");
    m_cat2->addItem("5. Divertissement");
    m_cat2->addItem("6. Etudes");
    m_cat2->addItem("7. Objet");
    m_cat2->addItem("8. Deplacement");
    m_cat2->addItem("9. Nourriture");
    m_cat2->addItem("10. Etre humain");
    m_cat2->addItem("11. Nature");
    m_cat2->addItem("12. Katakana");
    m_cat2->addItem("13. Communication");
    m_cat2->addItem("14. Temporel");
    m_cat2->addItem("15. Art");
    m_cat2->addItem("16. Appareil");
    m_cat2->addItem("17. Guerre");
    m_cat2->addItem("18. Sante");
    m_cat2->addItem("19. Consommation");
    m_cat2->addItem("20. Energie");
    m_cat2_txt = new QLabel("Categorie 2",this);
    m_cat2_txt->move(412,255);
    QObject::connect(m_cat2, SIGNAL(activated(int)),this, SLOT(SousCategorie2()));

    //Creation Sous Categorie 2
    m_scat2 = new QComboBox(this);
    m_scat2->setGeometry(610,270, 150, 20);
    m_scat2_txt = new QLabel("Sous-categorie 2",this);
    m_scat2_txt->move(612,255);
}


void MaFenetre::ouvrirDialogue()
{
        QMessageBox::warning(this, "Champ manquant", "Un champ necessaire n'est pas rempli ...");
}

void MaFenetre::mot_cree()
{
    QMessageBox::warning(this, "Ok", "Le mot a ete cree dans MotDuJour.js");
    QString n_ = m_input_num->text();
    int n__=n_.toInt();
    int n__2 = n__+1;
    QString n_d= QString::number(n__2);
    m_input_num->setText(n_d);

    m_input_kanji->setText("");
    m_input_roma->setText("");
    m_input_fr1->setText("");
    m_input_fr2->setText("");
    m_input_fr3->setText("");
    m_input_fr4->setText("");
    m_classe1->setCurrentIndex(0);
    m_sclasse1->setCurrentIndex(0);
    m_classe2->setCurrentIndex(0);
    m_sclasse2->setCurrentIndex(0);
    m_cat1->setCurrentIndex(0);
    m_scat1->setCurrentIndex(0);
    m_cat2->setCurrentIndex(0);
    m_scat2->setCurrentIndex(0);
}

class in_out RomaToHira(class in_out Ctx) {
    QString x = Ctx.reste;
    if (x.left(1)=="a") {Ctx.hira=Ctx.hira+"あ";Ctx.reste=x.right(strlen(qPrintable(x))-1);return Ctx;}
    else if (x.left(1)=="e") {Ctx.hira=Ctx.hira+"え";Ctx.reste=x.right(strlen(qPrintable(x))-1);return Ctx;}
    else if (x.left(1)=="i") {Ctx.hira=Ctx.hira+"い";Ctx.reste=x.right(strlen(qPrintable(x))-1);return Ctx;}
    else if (x.left(1)=="o") {Ctx.hira=Ctx.hira+"お";Ctx.reste=x.right(strlen(qPrintable(x))-1);return Ctx;}
    else if (x.left(1)=="u") {Ctx.hira=Ctx.hira+"う";Ctx.reste=x.right(strlen(qPrintable(x))-1);return Ctx;}
    else if (x.left(1)==" " || x.left(1)=="'") {Ctx.reste=x.right(strlen(qPrintable(x))-1);return Ctx;}
    else if (x.left(1)=="-") {Ctx.hira=Ctx.hira+"-";Ctx.reste=x.right(strlen(qPrintable(x))-1);return Ctx;}
    else if (x.left(2)=="ka") {Ctx.hira=Ctx.hira+"か";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="ki") {Ctx.hira=Ctx.hira+"き";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="ku") {Ctx.hira=Ctx.hira+"く";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="ke") {Ctx.hira=Ctx.hira+"け";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="ko") {Ctx.hira=Ctx.hira+"こ";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="sa") {Ctx.hira=Ctx.hira+"さ";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="su") {Ctx.hira=Ctx.hira+"す";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="se") {Ctx.hira=Ctx.hira+"せ";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="so") {Ctx.hira=Ctx.hira+"そ";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="ta") {Ctx.hira=Ctx.hira+"た";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="te") {Ctx.hira=Ctx.hira+"て";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="to") {Ctx.hira=Ctx.hira+"と";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="na") {Ctx.hira=Ctx.hira+"な";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="ni") {Ctx.hira=Ctx.hira+"に";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="nu") {Ctx.hira=Ctx.hira+"ぬ";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="ne") {Ctx.hira=Ctx.hira+"ね";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="no") {Ctx.hira=Ctx.hira+"の";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="ha") {Ctx.hira=Ctx.hira+"は";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="hi") {Ctx.hira=Ctx.hira+"ひ";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="fu") {Ctx.hira=Ctx.hira+"ふ";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="he") {Ctx.hira=Ctx.hira+"へ";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="ho") {Ctx.hira=Ctx.hira+"ほ";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="ma") {Ctx.hira=Ctx.hira+"ま";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="mi") {Ctx.hira=Ctx.hira+"み";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="mu") {Ctx.hira=Ctx.hira+"む";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="me") {Ctx.hira=Ctx.hira+"め";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="mo") {Ctx.hira=Ctx.hira+"も";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="ra") {Ctx.hira=Ctx.hira+"ら";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="ri") {Ctx.hira=Ctx.hira+"り";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="ru") {Ctx.hira=Ctx.hira+"る";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="re") {Ctx.hira=Ctx.hira+"れ";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="ro") {Ctx.hira=Ctx.hira+"ろ";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="ya") {Ctx.hira=Ctx.hira+"や";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="yu") {Ctx.hira=Ctx.hira+"ゆ";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="yo") {Ctx.hira=Ctx.hira+"よ";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="wa") {Ctx.hira=Ctx.hira+"わ";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="wo") {Ctx.hira=Ctx.hira+"を";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="ga") {Ctx.hira=Ctx.hira+"が";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="gi") {Ctx.hira=Ctx.hira+"ぎ";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="gu") {Ctx.hira=Ctx.hira+"ぐ";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="ge") {Ctx.hira=Ctx.hira+"げ";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="go") {Ctx.hira=Ctx.hira+"ご";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="za") {Ctx.hira=Ctx.hira+"ざ";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="ji") {Ctx.hira=Ctx.hira+"じ";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="zu") {Ctx.hira=Ctx.hira+"ず";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="ze") {Ctx.hira=Ctx.hira+"ぜ";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="zo") {Ctx.hira=Ctx.hira+"ぞ";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="da") {Ctx.hira=Ctx.hira+"だ";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="di") {Ctx.hira=Ctx.hira+"ぢ";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="du") {Ctx.hira=Ctx.hira+"づ";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="de") {Ctx.hira=Ctx.hira+"で";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="do") {Ctx.hira=Ctx.hira+"ど";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="ba") {Ctx.hira=Ctx.hira+"ば";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="bi") {Ctx.hira=Ctx.hira+"び";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="bu") {Ctx.hira=Ctx.hira+"ぶ";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="be") {Ctx.hira=Ctx.hira+"べ";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="bo") {Ctx.hira=Ctx.hira+"ぼ";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="pa") {Ctx.hira=Ctx.hira+"ぱ";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="pi") {Ctx.hira=Ctx.hira+"ぴ";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="pu") {Ctx.hira=Ctx.hira+"ぷ";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="pe") {Ctx.hira=Ctx.hira+"ぺ";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="po") {Ctx.hira=Ctx.hira+"ぽ";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="ja") {Ctx.hira=Ctx.hira+"じゃ";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="ju") {Ctx.hira=Ctx.hira+"じゅ";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(2)=="jo") {Ctx.hira=Ctx.hira+"じょ";Ctx.reste=x.right(strlen(qPrintable(x))-2);return Ctx;}
    else if (x.left(3)=="shi") {Ctx.hira=Ctx.hira+"し";Ctx.reste=x.right(strlen(qPrintable(x))-3);return Ctx;}
    else if (x.left(3)=="chi") {Ctx.hira=Ctx.hira+"ち";Ctx.reste=x.right(strlen(qPrintable(x))-3);return Ctx;}
    else if (x.left(3)=="tsu") {Ctx.hira=Ctx.hira+"つ";Ctx.reste=x.right(strlen(qPrintable(x))-3);return Ctx;}
    else if (x.left(3)=="kya") {Ctx.hira=Ctx.hira+"きゃ";Ctx.reste=x.right(strlen(qPrintable(x))-3);return Ctx;}
    else if (x.left(3)=="kyu") {Ctx.hira=Ctx.hira+"きゅ";Ctx.reste=x.right(strlen(qPrintable(x))-3);return Ctx;}
    else if (x.left(3)=="kyo") {Ctx.hira=Ctx.hira+"きょ";Ctx.reste=x.right(strlen(qPrintable(x))-3);return Ctx;}
    else if (x.left(3)=="gya") {Ctx.hira=Ctx.hira+"ぎゃ";Ctx.reste=x.right(strlen(qPrintable(x))-3);return Ctx;}
    else if (x.left(3)=="gyu") {Ctx.hira=Ctx.hira+"ぎゅ";Ctx.reste=x.right(strlen(qPrintable(x))-3);return Ctx;}
    else if (x.left(3)=="gyo") {Ctx.hira=Ctx.hira+"ぎょ";Ctx.reste=x.right(strlen(qPrintable(x))-3);return Ctx;}
    else if (x.left(3)=="sha") {Ctx.hira=Ctx.hira+"しゃ";Ctx.reste=x.right(strlen(qPrintable(x))-3);return Ctx;}
    else if (x.left(3)=="shu") {Ctx.hira=Ctx.hira+"しゅ";Ctx.reste=x.right(strlen(qPrintable(x))-3);return Ctx;}
    else if (x.left(3)=="sho") {Ctx.hira=Ctx.hira+"しょ";Ctx.reste=x.right(strlen(qPrintable(x))-3);return Ctx;}
    else if (x.left(3)=="cha") {Ctx.hira=Ctx.hira+"ちゃ";Ctx.reste=x.right(strlen(qPrintable(x))-3);return Ctx;}
    else if (x.left(3)=="chu") {Ctx.hira=Ctx.hira+"ちゅ";Ctx.reste=x.right(strlen(qPrintable(x))-3);return Ctx;}
    else if (x.left(3)=="cho") {Ctx.hira=Ctx.hira+"ちょ";Ctx.reste=x.right(strlen(qPrintable(x))-3);return Ctx;}
    else if (x.left(3)=="nya") {Ctx.hira=Ctx.hira+"にゃ";Ctx.reste=x.right(strlen(qPrintable(x))-3);return Ctx;}
    else if (x.left(3)=="nyu") {Ctx.hira=Ctx.hira+"にゅ";Ctx.reste=x.right(strlen(qPrintable(x))-3);return Ctx;}
    else if (x.left(3)=="nyo") {Ctx.hira=Ctx.hira+"にょ";Ctx.reste=x.right(strlen(qPrintable(x))-3);return Ctx;}
    else if (x.left(3)=="hya") {Ctx.hira=Ctx.hira+"ひゃ";Ctx.reste=x.right(strlen(qPrintable(x))-3);return Ctx;}
    else if (x.left(3)=="hyu") {Ctx.hira=Ctx.hira+"ひゅ";Ctx.reste=x.right(strlen(qPrintable(x))-3);return Ctx;}
    else if (x.left(3)=="hyo") {Ctx.hira=Ctx.hira+"ひょ";Ctx.reste=x.right(strlen(qPrintable(x))-3);return Ctx;}
    else if (x.left(3)=="bya") {Ctx.hira=Ctx.hira+"びゃ";Ctx.reste=x.right(strlen(qPrintable(x))-3);return Ctx;}
    else if (x.left(3)=="byu") {Ctx.hira=Ctx.hira+"びゅ";Ctx.reste=x.right(strlen(qPrintable(x))-3);return Ctx;}
    else if (x.left(3)=="byo") {Ctx.hira=Ctx.hira+"びょ";Ctx.reste=x.right(strlen(qPrintable(x))-3);return Ctx;}
    else if (x.left(3)=="pya") {Ctx.hira=Ctx.hira+"ぴゃ";Ctx.reste=x.right(strlen(qPrintable(x))-3);return Ctx;}
    else if (x.left(3)=="pyu") {Ctx.hira=Ctx.hira+"ぴゅ";Ctx.reste=x.right(strlen(qPrintable(x))-3);return Ctx;}
    else if (x.left(3)=="pyo") {Ctx.hira=Ctx.hira+"ぴょ";Ctx.reste=x.right(strlen(qPrintable(x))-3);return Ctx;}
    else if (x.left(3)=="mya") {Ctx.hira=Ctx.hira+"みゃ";Ctx.reste=x.right(strlen(qPrintable(x))-3);return Ctx;}
    else if (x.left(3)=="myu") {Ctx.hira=Ctx.hira+"みゅ";Ctx.reste=x.right(strlen(qPrintable(x))-3);return Ctx;}
    else if (x.left(3)=="myo") {Ctx.hira=Ctx.hira+"みょ";Ctx.reste=x.right(strlen(qPrintable(x))-3);return Ctx;}
    else if (x.left(3)=="rya") {Ctx.hira=Ctx.hira+"りゃ";Ctx.reste=x.right(strlen(qPrintable(x))-3);return Ctx;}
    else if (x.left(3)=="ryu") {Ctx.hira=Ctx.hira+"りゅ";Ctx.reste=x.right(strlen(qPrintable(x))-3);return Ctx;}
    else if (x.left(3)=="ryo") {Ctx.hira=Ctx.hira+"りょ";Ctx.reste=x.right(strlen(qPrintable(x))-3);return Ctx;}
    else if (x.left(1)=="n") {Ctx.hira=Ctx.hira+"ん";Ctx.reste=x.right(strlen(qPrintable(x))-1);return Ctx;}
    return Ctx;
}

QString LoOp(const char * Ct) {
    class in_out px;
    px.reste = Ct;
    px.hira = "";
    while (strlen(qPrintable(px.reste))>0) {
        px = RomaToHira(px);
    }
    return px.hira;
}

void MaFenetre::CreationMot()
{
    QString num = m_input_num->text();
    QString kanj = m_input_kanji->text();
    QString roma = m_input_roma->text();
    QString fr_1 = m_input_fr1->text();
    QString fr_2 = m_input_fr2->text();
    QString fr_3 = m_input_fr3->text();
    QString fr_4 = m_input_fr4->text();
    int selec_classe1 = m_classe1->currentIndex();
    int selec_sclasse1 = m_sclasse1->currentIndex();
    int selec_classe2 = m_classe2->currentIndex();
    int selec_sclasse2 = m_sclasse2->currentIndex();
    int selec_cat1 = m_cat1->currentIndex();
    int selec_scat1 = m_scat1->currentIndex();
    int selec_cat2 = m_cat2->currentIndex();
    int selec_scat2 = m_scat2->currentIndex();

    if (strcmp(qPrintable(num),"")==0 || strcmp(qPrintable(kanj),"")==0 || strcmp(qPrintable(roma),"")==0 || strcmp(qPrintable(fr_1),"")==0 || selec_classe1==0) {
        ouvrirDialogue();
        return;
    }

    QString PAth = m_input_Path->text();
    QByteArray PATh = PAth.toLatin1();
    const char *PATH = PATh.data();
    char monPath[250];
    strcpy(monPath,PATH);
    strcat(monPath,"/kanjisDuJour.js");
    FILE *f=fopen(monPath,"a");

    fprintf(f,"WORD[%s] = {kanji:\"%s\",\n",qPrintable(num),qPrintable(kanj));
    //if (strcmp(remarque,"n")==0) {
    fprintf(f,"              notes:\"\",\n");
    //}
    //else {
    //    fprintf(f,"              notes:\"%s\",\n",remarque);
    //}
    fprintf(f,"              say:[[\"%s\",\"%s\"]],\n",qPrintable(roma),qPrintable(LoOp(qPrintable(roma))));
    if (strcmp(qPrintable(fr_2),"")==0 && strcmp(qPrintable(fr_3),"")==0 && strcmp(qPrintable(fr_4),"")==0) {
        fprintf(f,"              fr:[\"%s\"],\n",qPrintable(fr_1));
    }
    else if (strcmp(qPrintable(fr_3),"")==0 && strcmp(qPrintable(fr_4),"")==0) {
        fprintf(f,"              fr:[\"%s\",\"%s\"],\n",qPrintable(fr_1),qPrintable(fr_2));
    }
    else if (strcmp(qPrintable(fr_4),"")==0) {
        fprintf(f,"              fr:[\"%s\",\"%s\",\"%s\"],\n",qPrintable(fr_1),qPrintable(fr_2),qPrintable(fr_3));
    }
    else {
        fprintf(f,"              fr:[\"%s\",\"%s\",\"%s\",\"%s\"],\n",qPrintable(fr_1),qPrintable(fr_2),qPrintable(fr_3),qPrintable(fr_4));
    }
    if (selec_classe2==0) {
        if (selec_sclasse1==0) {
            fprintf(f,"              classe:[[%d]],\n",selec_classe1);
        }
        else {
            fprintf(f,"              classe:[[%d,%d]],\n",selec_classe1,selec_sclasse1);
        }
    }
    else {
        if (selec_sclasse1==0 && selec_sclasse2==0) {
            fprintf(f,"              classe:[[%d],[%d]],\n",selec_classe1,selec_classe2);
        }
        else if (selec_sclasse2==0) {
            fprintf(f,"              classe:[[%d,%d],[%d]],\n",selec_classe1,selec_sclasse1,selec_classe2);
        }
        else if (selec_sclasse1==0) {
            fprintf(f,"              classe:[[%d],[%d,%d]],\n",selec_classe1,selec_classe2,selec_sclasse2);
        }
        else {
            fprintf(f,"              classe:[[%d,%d],[%d,%d]],\n",selec_classe1,selec_classe2,selec_sclasse1,selec_sclasse2);
        }
    }
    if (selec_cat1==0 && selec_cat2==0) {
        fprintf(f,"              cat:[[0]]};\n\n");
    }
    else if (selec_cat2==0) {
        if (selec_scat1==0) {
            fprintf(f,"              cat:[[%d]]};\n\n",selec_cat1);
        }
        else {
            fprintf(f,"              cat:[[%d,%d]]};\n\n",selec_cat1,selec_scat1);
        }
    }
    else {
        if (selec_scat1==0 && selec_scat2==0) {
            fprintf(f,"              cat:[[%d],[%d]]};\n\n",selec_cat1,selec_cat2);
        }
        else if (selec_scat2==0) {
            fprintf(f,"              cat:[[%d,%d],[%d]]};\n\n",selec_cat1,selec_scat1,selec_cat2);
        }
        else if (selec_scat1==0) {
            fprintf(f,"              cat:[[%d],[%d,%d]]};\n\n",selec_cat1,selec_cat2,selec_scat2);
        }
        else {
            fprintf(f,"              cat:[[%d,%d],[%d,%d]]};\n\n",selec_cat1,selec_scat1,selec_cat2,selec_scat2);
        }
    }
    fclose(f);
    mot_cree();
}

void MaFenetre::SousClasse1()
{
    int num_sclasse1 = m_sclasse1->count();
    int selected_classe1 = m_classe1->currentIndex();
    for (int i=0;i<=num_sclasse1;i++) {
        m_sclasse1->removeItem(0);
    }
    if (selected_classe1==1) {
        m_sclasse1->addItem("Aucune");
        m_sclasse1->addItem("Masculin");
        m_sclasse1->addItem("Feminin");
        m_sclasse1->addItem("Compose");
    }
    else if (selected_classe1==2) {
        m_sclasse1->addItem("Aucune");
        m_sclasse1->addItem("Lieu");
        m_sclasse1->addItem("Nom de famille");
    }
    else if (selected_classe1==3) {
        m_sclasse1->addItem("Aucune");
        m_sclasse1->addItem("Transitif");
        m_sclasse1->addItem("Intransitif");
        m_sclasse1->addItem("Verbe en suru");
    }
    else if (selected_classe1==4) {
        m_sclasse1->addItem("Aucune");
        m_sclasse1->addItem("Adjectif en i");
        m_sclasse1->addItem("Adjectif en na");
    }
    else if (selected_classe1==7) {
        m_sclasse1->addItem("Aucune");
        m_sclasse1->addItem("Personnel");
        m_sclasse1->addItem("Interrogatif");
    }
    else {
        m_sclasse1->addItem("Aucune");
    }
}

void MaFenetre::SousClasse2()
{
    int num_sclasse2 = m_sclasse2->count();
    int selected_classe2 = m_classe2->currentIndex();
    for (int i=0;i<=num_sclasse2;i++) {
        m_sclasse2->removeItem(0);
    }
    if (selected_classe2==1) {
        m_sclasse2->addItem("Aucune");
        m_sclasse2->addItem("Masculin");
        m_sclasse2->addItem("Feminin");
        m_sclasse2->addItem("Compose");
    }
    else if (selected_classe2==2) {
        m_sclasse2->addItem("Aucune");
        m_sclasse2->addItem("Lieu");
        m_sclasse2->addItem("Nom de famille");
    }
    else if (selected_classe2==3) {
        m_sclasse2->addItem("Aucune");
        m_sclasse2->addItem("Transitif");
        m_sclasse2->addItem("Intransitif");
        m_sclasse2->addItem("Verbe en suru");
    }
    else if (selected_classe2==4) {
        m_sclasse2->addItem("Aucune");
        m_sclasse2->addItem("Adjectif en i");
        m_sclasse2->addItem("Adjectif en na");
    }
    else if (selected_classe2==7) {
        m_sclasse2->addItem("Aucune");
        m_sclasse2->addItem("Personnel");
        m_sclasse2->addItem("Interrogatif");
    }
    else {
        m_sclasse2->addItem("Aucune");
    }
}

void MaFenetre::SousCategorie1()
{
    int num_scat1 = m_scat1->count();
    int selected_cat1 = m_cat1->currentIndex();
    for (int i=0;i<=num_scat1;i++) {
        m_scat1->removeItem(0);
    }
    if (selected_cat1==1) {
        m_scat1->addItem("Aucune");
        m_scat1->addItem("Ville");
    }
    else if (selected_cat1==2) {
        m_scat1->addItem("Aucune");
        m_scat1->addItem("Pays");
        m_scat1->addItem("Terre");
        m_scat1->addItem("Orientation");
    }
    else if (selected_cat1==3) {
        m_scat1->addItem("Aucune");
        m_scat1->addItem("Commerce");
        m_scat1->addItem("Politique");
        m_scat1->addItem("Science");
        m_scat1->addItem("Economie");
        m_scat1->addItem("Medecine");
        m_scat1->addItem("Artisanat");
        m_scat1->addItem("Sciences humaines");
        m_scat1->addItem("Art");
        m_scat1->addItem("Agriculture");
        m_scat1->addItem("Enseignement");
    }
    else if (selected_cat1==4) {
        m_scat1->addItem("Aucune");
        m_scat1->addItem("Batiment");
        m_scat1->addItem("Infrastructure");
    }
    else if (selected_cat1==5) {
        m_scat1->addItem("Aucune");
        m_scat1->addItem("Evenement");
        m_scat1->addItem("Cinema");
        m_scat1->addItem("Musique");
        m_scat1->addItem("Sport");
        m_scat1->addItem("Voyage");
        m_scat1->addItem("Lecture");
        m_scat1->addItem("Jeu");
    }
    else if (selected_cat1==6) {
        m_scat1->addItem("Aucune");
        m_scat1->addItem("Grammaire");
        m_scat1->addItem("Litterature");
        m_scat1->addItem("Scolarite");
        m_scat1->addItem("Science");
    }
    else if (selected_cat1==7) {
        m_scat1->addItem("Aucune");
        m_scat1->addItem("Hi-tech");
        m_scat1->addItem("Outil");
        m_scat1->addItem("Vetement");
        m_scat1->addItem("Meuble");
    }
    else if (selected_cat1==8) {
        m_scat1->addItem("Aucune");
        m_scat1->addItem("Moyen de transport");
    }
    else if (selected_cat1==10) {
        m_scat1->addItem("Aucune");
        m_scat1->addItem("Personne");
        m_scat1->addItem("Sentiment");
        m_scat1->addItem("Anatomie");
    }
    else if (selected_cat1==11) {
        m_scat1->addItem("Aucune");
        m_scat1->addItem("Faune");
        m_scat1->addItem("Flore");
        m_scat1->addItem("Univers");
        m_scat1->addItem("Terre");
        m_scat1->addItem("Meteo");
    }
    else if (selected_cat1==15) {
        m_scat1->addItem("Aucune");
        m_scat1->addItem("Couleur");
    }
    else if (selected_cat1==16) {
        m_scat1->addItem("Aucune");
        m_scat1->addItem("Electro-menager");
        m_scat1->addItem("TV/Hi-Fi");
    }
    else {
        m_scat1->addItem("Aucune");
    }
}

void MaFenetre::SousCategorie2()
{
    int num_scat2 = m_scat2->count();
    int selected_cat2 = m_cat2->currentIndex();
    for (int i=0;i<=num_scat2;i++) {
        m_scat2->removeItem(0);
    }
    if (selected_cat2==1) {
        m_scat2->addItem("Aucune");
        m_scat2->addItem("Ville");
    }
    else if (selected_cat2==2) {
        m_scat2->addItem("Aucune");
        m_scat2->addItem("Pays");
        m_scat2->addItem("Terre");
        m_scat2->addItem("Orientation");
    }
    else if (selected_cat2==3) {
        m_scat2->addItem("Aucune");
        m_scat2->addItem("Commerce");
        m_scat2->addItem("Politique");
        m_scat2->addItem("Science");
        m_scat2->addItem("Economie");
        m_scat2->addItem("Medecine");
        m_scat2->addItem("Artisanat");
        m_scat2->addItem("Sciences humaines");
        m_scat2->addItem("Art");
        m_scat2->addItem("Agriculture");
        m_scat2->addItem("Enseignement");
    }
    else if (selected_cat2==4) {
        m_scat2->addItem("Aucune");
        m_scat2->addItem("Batiment");
        m_scat2->addItem("Infrastructure");
    }
    else if (selected_cat2==5) {
        m_scat2->addItem("Aucune");
        m_scat2->addItem("Evenement");
        m_scat2->addItem("Cinema");
        m_scat2->addItem("Musique");
        m_scat2->addItem("Sport");
        m_scat2->addItem("Voyage");
        m_scat2->addItem("Lecture");
        m_scat2->addItem("Jeu");
    }
    else if (selected_cat2==6) {
        m_scat2->addItem("Aucune");
        m_scat2->addItem("Grammaire");
        m_scat2->addItem("Litterature");
        m_scat2->addItem("Scolarite");
        m_scat2->addItem("Science");
    }
    else if (selected_cat2==7) {
        m_scat2->addItem("Aucune");
        m_scat2->addItem("Hi-tech");
        m_scat2->addItem("Outil");
        m_scat2->addItem("Vetement");
        m_scat2->addItem("Meuble");
    }
    else if (selected_cat2==8) {
        m_scat2->addItem("Aucune");
        m_scat2->addItem("Moyen de transport");
    }
    else if (selected_cat2==10) {
        m_scat2->addItem("Aucune");
        m_scat2->addItem("Personne");
        m_scat2->addItem("Sentiment");
        m_scat2->addItem("Anatomie");
    }
    else if (selected_cat2==11) {
        m_scat2->addItem("Aucune");
        m_scat2->addItem("Faune");
        m_scat2->addItem("Flore");
        m_scat2->addItem("Univers");
        m_scat2->addItem("Terre");
        m_scat2->addItem("Meteo");
    }
    else if (selected_cat2==15) {
        m_scat2->addItem("Aucune");
        m_scat2->addItem("Couleur");
    }
    else if (selected_cat2==16) {
        m_scat2->addItem("Aucune");
        m_scat2->addItem("Electro-menager");
        m_scat2->addItem("TV/Hi-Fi");
    }
    else {
        m_scat2->addItem("Aucune");
    }
}
void MaFenetre::Selectpath()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                 "/home",
                                                 QFileDialog::ShowDirsOnly
                                                 | QFileDialog::DontResolveSymlinks);
    m_input_Path->setText(dir);
}

