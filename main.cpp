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

v0.6
Bug corrigé.
Protection contre l'ajout de traduction "vide" pour strings.xml ajouté.
Protection contre l'ajout de traduction "vide" pour arrays.xml ajouté.
Enregistrement des fichiers strings.xml et arrays.xml ajouté et corrigé.
Bouton Enregistrer fichiers pour recompilation fonctionnel.
Bouton Enregistrer sous fonctionnel.

v0.5
Fonction de la partie arrays ajoutées.
Bug au niveau de la QListWidget non resolu.

v0.4
Suppression de la partie "Nom de l'apk".
Ajout de la partie arrays.xml.
Bouton pour choisir une autre bdd.
L'adresse de l'apk s'affiche.
Fonction à traduire et ligne d'origine fonctionnent.

v0.3
Création de la méthode de lecture des arrays.xml.

v0.2
Création de la méthode de lecture des strings.xml.

v0.1
Interface faite completement.
Création des fichiers Traduction.h et Traduction.cpp.
*/