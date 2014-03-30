#include <unite.h>
#include <iostream>
#include <QApplication>
#include <mafenetre.h>
#include <longueur.h>

using namespace std;

int main(int argc, char *argv[]) {
    const int NB_LIGNES = 10;
    QApplication app(argc, argv);
    MaFenetre* frame = new MaFenetre(NB_LIGNES, 3);
    frame->show();
    return app.exec();
}
