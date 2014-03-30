#ifndef MAFENETRE_H
#define MAFENETRE_H

#include <QWidget>
#include <QPushButton>

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QSpinBox>
#include <QComboBox>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QGroupBox>
#include <QLineEdit>
#include <QLabel>
#include <unite.h>
#include <QObject>

class MaFenetre : public QWidget
{
    Q_OBJECT
public:
    MaFenetre(int rows, int cols);

private:
    int rows, cols;
    QVBoxLayout *main_layout;
    QHBoxLayout *button_layout;
    QHBoxLayout *content_layout;
    QFormLayout *form_layout;

    QSpinBox *input_valeur;
    QSpinBox *input_echelle;

    QLabel *label_longueur;
    QLabel *label_poids;
    QLabel *label_temps;

    QLineEdit *input_longueur;
    QLineEdit *input_poids;
    QLineEdit *input_temps;

    QComboBox *combo_ligne;
    QComboBox *combo_unite;

    QGroupBox *group_box;
    QHBoxLayout *group_box_layout;

    QPushButton *bouton_quitter;
    QPushButton *bouton_ajouter;
    QPushButton *bouton_total;
    QPushButton *bouton_effacer;

    QTableWidget *table;

    Unite*** tabVal;

public slots:
    void ajouter();
    void total();
    void effacer();
};

#endif // MAFENETRE_H
