// Auteur : Alexandreou
#ifndef HEADER_TRADUCTION
#define HEADER_TRADUCTION

#include <QString>
#include <iostream>
#include <vector>

class Traduction
{
public:
	Traduction();
	int InStrVector(std::string elem, std::vector<std::string> dans);
	void setAdresseApk(QString adresse);
	bool traitement_ouverture_apk();

	std::vector<std::vector<std::string>> lecture_xml_typeStrings(std::string adresse_xml);
	std::vector<std::vector<std::vector<std::string>>> lecture_xml_typeArrays(std::string adresse_xml);

	bool traitement_ouverture_bdd();

	void setAdresseBdd(QString adresseS, QString adresseA);

	void creationEncours();

	QString getStringsFonctionATraduire();

	QString getStringsLigneDOrigine();

	void setPosString(int pos);

private:
	QString adresse_dossier_apk;
	std::string adresse_bdd_strings;
	std::string adresse_bdd_arrays;
	std::string adresse_strings;
	std::string adresse_arrays;

	std::vector<std::string> liste_strings_fonctions;
	std::vector<std::string> liste_strings_trad;

	std::vector<std::string> liste_arrays_fonctions;
	std::vector<std::vector<std::string>> liste_arrays_trad;

	std::vector<std::string> liste_arrays_trad_notrad;


	std::vector<std::string> bdd_liste_strings_fonctions;
	std::vector<std::string> bdd_liste_strings_trad;

	std::vector<std::string> bdd_liste_arrays_fonctions;
	std::vector<std::vector<std::string>> bdd_liste_arrays_trad;

	std::vector<std::string> bdd_liste_arrays_trad_notrad;


	std::vector<std::string> encours_liste_strings_fonctions;
	std::vector<std::string> encours_liste_strings_trad;
	int pos_strings;

	std::vector<std::string> encours_liste_arrays_fonctions;
	std::vector<std::vector<std::string>> encours_liste_arrays_trad;
	int pos_arrays;
};

#endif