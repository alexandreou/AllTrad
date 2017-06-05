# AllTrad
Outil de traduction des applications Venom et autres !

Développé avec Qt 5.8. 

## Changelog :

### v1.1

Mise en place des vector notrad pour strings.xml (déjà mis en place pour les arrays). Adaptation du code.

Mise en place de filtres pour strings.xml (comme avec arrays.xml).

Optimisation du code.

Ajout du support de Viper4Android.


### v1.0

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


### v0.10

Résolution d'un bug de fin de traduction.

Gestion des apostrophes pour apktool.

Verification des espaces/tabulations pour éviter des bugs.

Ajout d'un message avant de quitter le programme.


### v0.9

Amélioration des algorithmes de lecture des fichiers strings.xml et arrays.xml (gestion des trous dans les fichiers).

Compatibilité avec les autres applications Venom.

Compatibilité avec d'autres langues.


### v0.8

Vérification de la compatiilité d'un menu bdd avec un menu d'origine.

Fusion de bases de données ajoutée.

Amélioration de l'algorithme permettant de détecter les menus non traduisible.


### v0.7

Gestion des erreurs (bouton Annuler lors de la demande d'ouverture d'un dossier, accent dans l'adresse, etc)

Réinitialisation des variables lors de l'ouverture d'un autre apk.

Changement de l'interface et ajout de boutons pour enregistrer une bdd.


### v0.6

Bug corrigé.

Protection contre l'ajout de traduction "vide" pour strings.xml ajouté.

Protection contre l'ajout de traduction "vide" pour arrays.xml ajouté.

Enregistrement des fichiers strings.xml et arrays.xml ajouté et corrigé.

Bouton Enregistrer fichiers pour recompilation fonctionnel.

Bouton Enregistrer sous fonctionnel.


### v0.5

Fonction de la partie arrays ajoutées.

Bug au niveau de la QListWidget non resolu.


### v0.4

Suppression de la partie "Nom de l'apk".

Ajout de la partie arrays.xml.

Bouton pour choisir une autre bdd.

L'adresse de l'apk s'affiche.

Fonction à traduire et ligne d'origine fonctionnent.


### v0.3

Création de la méthode de lecture des arrays.xml.


### v0.2

Création de la méthode de lecture des strings.xml.


### v0.1

Interface faite completement.

Création des fichiers Traduction.h et Traduction.cpp.
