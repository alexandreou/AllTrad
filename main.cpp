// Auteur : Alexandreou
#include <QApplication>
#include "Fenetre.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QString locale = QLocale::system().name().section('_', 0, 0);
	QTranslator translator;
	translator.load(QString("qt_") + locale, QLibraryInfo::location(QLibraryInfo::TranslationsPath));
	a.installTranslator(&translator);

	Fenetre fenetre;
	fenetre.show();

	return a.exec();
}

/*
Changelog :

v1.0
Ajout d'une barre de menu.
R�solution de quelques bugs.
Correction de fautes d'orthographes.
Ajout de bulles d'information.
Ajout de traduction des boites de dialogues de Qt.
Resolution d'un bug sur les apostrophes.
Bug avec une ligne strings.xml particuli�re corrig�.
Ajout d'un message d'erreur avec les menus si aucun fichier n'est ouvert.
Message de sortie s'affiche seulement si un travail est en cours.
Bug lorsqu'il y a des retours lignes dans strings.xml (manque des lettres).
Ajout de deux bouton dans le sous-programme fusion.
Multiples corrections dans l'ajout de lignes.
Bug de s�l�ction pour la partie arrays corrig�.
Correction d'un bug lors d'un changement d'apk au niveau de arrays.

v0.10
R�solution d'un bug de fin de traduction.
Gestion des apostrophes pour apktool.
Verification des espaces/tabulations pour �viter des bugs.
Ajout d'un message avant de quitter le programme.

v0.9
Am�lioration des algorithmes de lecture des fichiers strings.xml et arrays.xml (gestion des trous dans les fichiers).
Compatibilit� avec les autres applications Venom.
Compatibilit� avec d'autres langues.

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