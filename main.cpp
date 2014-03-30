#include <unite.h>
#include <iostream>
#include <QApplication>
#include <mafenetre.h>
#include <longueur.h>

using namespace std;

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MaFenetre frame;
    frame.show();
    return app.exec();
}
