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
v0.8
V�rification de la compatiilit� d'un menu bdd avec un menu d'origine.
Fusion de bases de donn�es ajout�e.
Am�lioration de l'algorithme permettant de d�tecter les menus non traduisible.

v0.7
Gestion des erreurs (bouton Annuler lors de la demande d'ouverture d'un dossier, accent dans l'adresse, etc)
R�initialisation des variables lors de l'ouverture d'un autre apk.
Changement de l'interface et ajout de boutons pour enregistrer une bdd.

v0.6
Bug corrig�.
Protection contre l'ajout de traduction "vide" pour strings.xml ajout�.
Protection contre l'ajout de traduction "vide" pour arrays.xml ajout�.
Enregistrement des fichiers strings.xml et arrays.xml ajout� et corrig�.
Bouton Enregistrer fichiers pour recompilation fonctionnel.
Bouton Enregistrer sous fonctionnel.

v0.5
Fonction de la partie arrays ajout�es.
Bug au niveau de la QListWidget non resolu.

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