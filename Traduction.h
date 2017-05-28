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
	void setAdresseApk(QString adresse);
	bool traitement_ouverture_apk();

	std::vector<std::vector<std::string>> lecture_xml_typeStrings(std::string adresse_xml);
	std::vector<std::vector<std::vector<std::string>>> lecture_xml_typeArrays(std::string adresse_xml);

private:
	QString adresse_dossier_apk;
	QString adresse_bdd_perso_strings;
	QString adresse_bdd_perso_arrays;
	std::string adresse_strings;
	std::string adresse_arrays;
	std::vector<std::string> liste_strings_fonctions;
	std::vector<std::string> liste_strings_trad;

	std::vector<std::string> liste_arrays_fonctions;
	std::vector<std::vector<std::string>> liste_arrays_trad;

	std::vector<std::string> liste_arrays_trad_notrad;
};

#endif