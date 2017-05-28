// Auteur : Alexandreou
#include <QApplication>
#include "Fenetre.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	Fenetre fenetre;
	fenetre.show();

	return a.exec();
}

/*
Changelog :

v0.3
Création de la méthode de lecture des arrays.xml.

v0.2
Création de la méthode de lecture des strings.xml.

v0.1
Interface faite completement.
Création des fichiers Traduction.h et Traduction.cpp.
*/