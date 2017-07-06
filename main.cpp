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
A faire plus tard :
Optimiser tout le code avec les QString (v2.0)
Lecture les strings arrays français d'origine (v2.0)
Support des arrays ou strings seul (v2.0)
Un peu beaucoup de reseau (v3.0 ou v4.0 ou jamais)
Traduction de AllTrad en anglais et autres (v3.0)
Console avec historique des info de la ligne d'information, eviter l'affichage de deux information identique 2 fois de suite (v2.0)
Création d'une base de données globale pour toutes les applications en plus de celles existantes. (traduction directe en -> fr). (v2.0/3.0)
Ajout de controles de déplacements pour encore augmenter la rapidité de la traduction. (v2.0)
Fichier avec les filtres appliqués et editeur de filtres. (v2.0)
etc...

v1.2
Ajout du raccourci entrer pour valider la traduction.
Mise à jour des bases de données Venom.
Mise à jour des filtres VenomHUB.
Amélioration de l'algorithme de filtre arrays.
Mise à jour de l'algorithmes de lecture pour revenir sur les lignes precedantes (strings).
Algorithme de lecture arrays mis à jour pour correspondre à l'algorithme de lecture strings.
J'en profite pour modifier la méthode de lecture les fichiers pour enlever la limitation avec les adresses avec des accents !
Du coup adaptation du code autour (pour la verification des adresses notamment).
Un peu de rangement dans le code des algos de lecture !
Optimisation du code pour l'ouverture des apks (plus rapide).
Barre de progression ajoutée !
Message d'erreur mis à jour pour enlever le conseil sur les accents dans les adresses.
Affichage de la progression dans la traduction ajouté.
Progression de la fusion de bases de données ajoutée.
Résolution d'un bug de codec qui corrompait les fichiers.
Mise à jour des filtres VenomTweaks.

v1.1
Mise en place des vector notrad pour strings.xml (déjà mis en place pour les arrays). Adaptation du code.
Mise en place de filtres pour strings.xml (comme avec arrays.xml).
Optimisation du code.
Ajout du support de Viper4Android.

v1.0
Ajout d'une barre de menu.
Résolution de quelques bugs.
Correction de fautes d'orthographes.
Ajout de bulles d'information.
Ajout de traduction des boites de dialogues de Qt.
Resolution d'un bug sur les apostrophes.
Bug avec une ligne strings.xml particulière corrigé.
Ajout d'un message d'erreur avec les menus si aucun fichier n'est ouvert.
Message de sortie s'affiche seulement si un travail est en cours.
Bug lorsqu'il y a des retours lignes dans strings.xml (manque des lettres).
Ajout de deux bouton dans le sous-programme fusion.
Multiples corrections dans l'ajout de lignes.
Bug de séléction pour la partie arrays corrigé.
Correction d'un bug lors d'un changement d'apk au niveau de arrays.

v0.10
Résolution d'un bug de fin de traduction.
Gestion des apostrophes pour apktool.
Verification des espaces/tabulations pour éviter des bugs.
Ajout d'un message avant de quitter le programme.

v0.9
Amélioration des algorithmes de lecture des fichiers strings.xml et arrays.xml (gestion des trous dans les fichiers).
Compatibilité avec les autres applications Venom.
Compatibilité avec d'autres langues.

v0.8
Vérification de la compatiilité d'un menu bdd avec un menu d'origine.
Fusion de bases de données ajoutée.
Amélioration de l'algorithme permettant de détecter les menus non traduisible.

v0.7
Gestion des erreurs (bouton Annuler lors de la demande d'ouverture d'un dossier, accent dans l'adresse, etc)
Réinitialisation des variables lors de l'ouverture d'un autre apk.
Changement de l'interface et ajout de boutons pour enregistrer une bdd.

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