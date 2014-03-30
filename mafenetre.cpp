#include "mafenetre.h"
#include <QWidget>
#include <QFont>
#include <Qt>
#include <QPushButton>
#include <unite.h>
#include <longueur.h>
#include <poids.h>
#include <temps.h>
#include <cmath>

MaFenetre::MaFenetre() : QWidget()
{
    setFixedSize(1024, 768);
    for(int i = 0; i < 5; i += 1){
        for(int j = 0; j < 3; j += 1){
            tabVal[i][j] = NULL;
        }
    }
    /*
     * Layouts
     */
    main_layout = new QVBoxLayout;
    button_layout = new QHBoxLayout;
    content_layout = new QHBoxLayout;
    form_layout = new QFormLayout;

    /*
     * Boutons
     */
    bouton_quitter = new QPushButton("Quitter");
    bouton_quitter->setFont(QFont("Andale Mono", 14));
    bouton_quitter->setCursor(Qt::PointingHandCursor);
    QObject::connect(bouton_quitter, SIGNAL(clicked()), qApp, SLOT(quit()));

    bouton_ajouter = new QPushButton("Ajouter");
    bouton_ajouter->setFont(QFont("Andale Mono", 14));
    bouton_ajouter->setCursor(Qt::PointingHandCursor);
    QObject::connect(bouton_ajouter, SIGNAL(clicked()), this, SLOT(ajouter()));

    bouton_total = new QPushButton("Total");
    bouton_total->setFont(QFont("Andale Mono", 14));
    bouton_total->setCursor(Qt::PointingHandCursor);
    QObject::connect(bouton_total, SIGNAL(clicked()), this, SLOT(total()));

    bouton_effacer = new QPushButton("Effacer");
    bouton_effacer->setFont(QFont("Andale Mono", 14));
    bouton_effacer->setCursor(Qt::PointingHandCursor);
    QObject::connect(bouton_effacer, SIGNAL(clicked()), this, SLOT(effacer()));

    /*
     * Form
     */
    input_valeur = new QSpinBox();
    input_echelle = new QSpinBox();
    input_echelle->setRange(-3, 3);
    combo_ligne = new QComboBox();
    combo_ligne->addItem("1");
    combo_ligne->addItem("2");
    combo_ligne->addItem("3");
    combo_ligne->addItem("4");
    combo_ligne->addItem("5");
    combo_unite = new QComboBox();
    combo_unite->addItem("Longueur");
    combo_unite->addItem("Poids");
    combo_unite->addItem("Temps");

    form_layout->addRow("Valeur", input_valeur);
    form_layout->addRow("Echelle", input_echelle);
    form_layout->addRow("Ligne", combo_ligne);
    form_layout->addRow("Unite", combo_unite);

    /*
     * Group box
     */
    group_box = new QGroupBox("Total");
    group_box->setAlignment(Qt::AlignHCenter);

    group_box_layout = new QHBoxLayout();
    label_longueur = new QLabel("Longueur :");
    label_poids = new QLabel("Poids :");
    label_temps = new QLabel("Temps :");
    input_longueur = new QLineEdit();
    input_poids = new QLineEdit();
    input_temps = new QLineEdit();

    group_box_layout->addWidget(label_longueur);
    group_box_layout->addWidget(input_longueur);

    group_box_layout->addWidget(label_poids);
    group_box_layout->addWidget(input_poids);

    group_box_layout->addWidget(label_temps);
    group_box_layout->addWidget(input_temps);
    group_box->setLayout(group_box_layout);

    /*
     * Table
     */
    int rows = 5;
    int cols = 3;
    table = new QTableWidget(rows, cols);
    table->setHorizontalHeaderItem(0, new QTableWidgetItem("Longueur"));
    table->setHorizontalHeaderItem(1, new QTableWidgetItem("Poids"));
    table->setHorizontalHeaderItem(2, new QTableWidgetItem("Temps"));
    for(int r = 0; r < rows; r+=1){
        for(int c = 0; c < cols; c+=1) {
            QTableWidgetItem *item;
            item = new QTableWidgetItem();
            table->setItem(r,c,item);
        }
    }

    /*
     * Frame
     */
    button_layout->addWidget(bouton_ajouter);
    button_layout->addWidget(bouton_total);
    button_layout->addWidget(bouton_effacer);
    button_layout->addWidget(bouton_quitter);

    content_layout->addWidget(table);
    content_layout->addLayout(form_layout);

    main_layout->addLayout(content_layout);
    main_layout->addWidget(group_box);
    main_layout->addLayout(button_layout);

    this->setLayout(main_layout);
}


void MaFenetre::ajouter()
{
    Unite* u;
    int unite = this->combo_unite->currentIndex();
    int ligne = this->combo_ligne->currentIndex();
    switch (unite) {
    case 0:
        u = new Longueur();
        u->setValeur(this->input_valeur->value());
        u->setEchelle(this->input_echelle->value());
        tabVal[ligne][unite] = u;
        this->table->setItem(ligne, unite, new QTableWidgetItem(((Longueur*)u)->toString()));
        break;
    case 1:
        u = new Poids();
        u->setValeur(this->input_valeur->value());
        u->setEchelle(this->input_echelle->value());
        tabVal[ligne][unite] = u;
        this->table->setItem(ligne, unite, new QTableWidgetItem(((Poids*)u)->toString()));
        break;
    case 2:
        u = new Temps();
        u->setValeur(this->input_valeur->value());
        u->setEchelle(this->input_echelle->value());
        tabVal[ligne][unite] = u;
        this->table->setItem(ligne, unite, new QTableWidgetItem(((Temps*)u)->toString()));
        break;
    default:
        break;
    }
}

void MaFenetre::total()
{
    double s_longueurs = 0.0, s_poids = 0.0, s_temps = 0.0;
    for(int i = 0; i < 5; i+=1) {
        if (tabVal[i][0] != NULL)
          s_longueurs += tabVal[i][0]->getValeur() * pow(10, tabVal[i][0]->getEchelle());
        if (tabVal[i][1] != NULL)
            s_poids += tabVal[i][1]->getValeur() * pow(10, tabVal[i][1]->getEchelle());
        if (tabVal[i][2] != NULL){
            if (tabVal[i][2]->getEchelle() == 3) {
                s_temps += tabVal[i][2]->getValeur() * 3600 * 24;
            } else if(tabVal[i][2]->getEchelle() == 2) {
                s_temps += tabVal[i][2]->getValeur() * 3600;
            } else if(tabVal[i][2]->getEchelle() == 1) {
                s_temps += tabVal[i][2]->getValeur() * 60;
            } else {
                s_temps += tabVal[i][2]->getValeur() * pow(10, tabVal[i][2]->getEchelle());
            }
        }
    }
    input_longueur->setText(QString::number(s_longueurs) + " m");
    input_poids->setText(QString::number(s_poids) + " g");
    input_temps->setText(QString::number(s_temps) + " s");
}

void MaFenetre::effacer()
{
    if (table->selectedItems().size() == 0) {
        for(int r = 0; r < 5; r+=1){
            for(int c = 0; c < 3; c+=1) {
                QTableWidgetItem *item;
                item = new QTableWidgetItem();
                table->setItem(r,c,item);
            }
        }
    } else {
        for(QTableWidgetItem *item : this->table->selectedItems()) {
            table->setItem(item->row(), item->column(), new QTableWidgetItem());
        }
    }
}
