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
v0.4
Suppression de la partie "Nom de l'apk".
Ajout de la partie arrays.xml.
Bouton pour choisir une autre bdd.
L'adresse de l'apk s'affiche.
Fonction � traduire et ligne d'origine fonctionnent.

v0.3
Cr�ation de la m�thode de lecture des arrays.xml.

v0.2
Cr�ation de la m�thode de lecture des strings.xml.

v0.1
Interface faite completement.
Cr�ation des fichiers Traduction.h et Traduction.cpp.
*/