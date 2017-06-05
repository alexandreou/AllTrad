// Auteur : Alexandreou
#include "Traduction.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

Traduction::Traduction()
{
	pos_arrays_fusion = 0;
	pos_strings_fusion = 0;
}

void Traduction::remplace(string &dans)
{
	vector<int> pos;
	int temp = 0;
	for (int i = 0; i < dans.size(); i++)
	{
		if (dans[i] == '\'' || dans[i] == '\"')
		{
			pos.push_back(i);
		}
	}
	for (int i = 0; i < pos.size(); i++)
	{
		if (pos[i] - 1 >= 0)
		{
			if (dans[pos[i] - 1] != '\\')
			{
				dans.insert(pos[i] + temp, "\\");
				temp++;
			}
		}
		else
		{
			dans.insert(pos[i] + temp, "\\");
			temp++;
		}
	}
}

int Traduction::InStrVector(string elem, vector<string> dans)
{
	for (int i = 0; i < dans.size(); i++)
	{
		if (dans[i] == elem)
			return i;
	}
	return -1;
}

bool operator==(vector<QString> a, vector<QString>b)
{
	if (a.size() != b.size())
		return false;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i])
			return false;
	}
	return true;
}

int Traduction::InQString2xVector(vector<QString> elem, vector<vector<QString>> dans)
{
	for (int i = 0; i < dans.size(); i++)
	{
		if (dans[i] == elem)
			return i;
	}
	return -1;
}

void Traduction::setAdresseApk(QString adresse)
{
	liste_strings_fonctions = {};
	liste_strings_trad = {};

	liste_arrays_fonctions = {};
	liste_arrays_trad = {};

	liste_arrays_trad_notrad = {};


	bdd_liste_strings_fonctions = {};
	bdd_liste_strings_trad = {};

	bdd_liste_arrays_fonctions = {};
	bdd_liste_arrays_trad = {};

	bdd_liste_arrays_trad_notrad = {};


	encours_liste_strings_fonctions = {};
	encours_liste_strings_trad = {};
	pos_strings = 0;

	liste_arrays_fonctions = {};
	encours_liste_arrays_trad = {};
	pos_arrays = 0;

	adresse_strings = (adresse + "/res/values/strings.xml").toStdString();
	adresse_arrays = (adresse + "/res/values/arrays.xml").toStdString();
}

void Traduction::setAdresseFichiers(QString strings, QString arrays)
{
	liste_strings_fonctions = {};
	liste_strings_trad = {};

	liste_arrays_fonctions = {};
	liste_arrays_trad = {};

	liste_arrays_trad_notrad = {};


	bdd_liste_strings_fonctions = {};
	bdd_liste_strings_trad = {};

	bdd_liste_arrays_fonctions = {};
	bdd_liste_arrays_trad = {};

	bdd_liste_arrays_trad_notrad = {};


	encours_liste_strings_fonctions = {};
	encours_liste_strings_trad = {};
	pos_strings = 0;

	liste_arrays_fonctions = {};
	encours_liste_arrays_trad = {};
	pos_arrays = 0;

	adresse_strings = strings.toStdString();
	adresse_arrays = arrays.toStdString();
}

bool Traduction::traitement_ouverture_apk()
{
	ifstream fichier_strings(adresse_strings), fichier_arrays(adresse_arrays);

	if (!fichier_strings || !fichier_arrays)
	{
		adresse_strings = "";
		adresse_arrays = "";
		fichier_strings.close();
		fichier_arrays.close();
		return false;
	}
	else
	{
		fichier_strings.close();
		fichier_arrays.close();
		vector<vector<string>> xml = lecture_xml_typeStrings(adresse_strings);
		//xml[0].push_back("fin_traduction");
		//xml[1].push_back("fin_traduction");
		liste_strings_fonctions = xml[0];
		liste_strings_trad = xml[1];
		liste_strings_trad_notrad = xml[2];

		vector<vector<vector<string>>> xml1 = lecture_xml_typeArrays(adresse_arrays);
		//xml1[0][0].push_back("fin_traduction");
		//xml1[1].push_back({ "fin_traduction" });
		liste_arrays_fonctions = xml1[0][0];
		liste_arrays_trad = xml1[1];
		liste_arrays_trad_notrad = xml1[2][0];
	}
	return true;
}

vector<vector<string>> Traduction::lecture_xml_typeStrings(string adresse_xml)
{
	ifstream xml(adresse_xml);
	string ligne, temp, temp1;
	vector<string> fonctions, trad, notrad, toutes_les_lignes;
	int compt;
	char temp_char = 'a';
	int comptemp = 2;
	while (getline(xml, ligne))
	{
		toutes_les_lignes.push_back(ligne);
	}
	ligne = toutes_les_lignes[comptemp];
	while (ligne != "</resources>")
	{
		while (ligne == "" || ligne == "	" || ligne == " ")
		{
			comptemp++;
			//cout << comptemp << endl;
			ligne = toutes_les_lignes[comptemp];
		}

		if (ligne[0] == '	')
		{
			ligne.erase(ligne.begin());
			ligne.insert(0, "    ");
		}

		temp = ligne.substr(0, 11);
		while (temp != "    <string")
		{
			notrad.push_back(ligne);
			comptemp++;
			//cout << comptemp << endl;
			ligne = toutes_les_lignes[comptemp];
			temp = ligne.substr(0, 11);
		}

		compt = 18;
		temp = "";
		temp_char = 'a';
		while (temp_char != '\"')
		{
			temp += ligne[compt];
			compt++;
			temp_char = ligne[compt];
		}
		compt += 1;
		if (ligne[compt] == ' ' && ligne[compt+1] == 'f' && ligne[compt + 2] == 'o')
		{
			temp += '\"';
			for(int i = 0; i < 17; i++)
				temp += ligne[compt+i];
			compt += 19;
		}
		else
		{
			compt += 1;
		}

		vector<string> filtre;
		if (nom_appli == "VenomTweaks")
			filtre = {};
		if (nom_appli == "VenomHUB")
			filtre = {};
		if (nom_appli == "VenomSideBar")
			filtre = {};
		if (nom_appli == "Viper4Android")
			filtre = {"text_drv_blank", "abc_action_bar_home_description_format", "abc_action_bar_home_subtitle_description_format", 
			"character_counter_pattern", "appbar_scrolling_view_behavior", "bottom_sheet_behavior", "text_forum_link", "text_updatelink" };


		if (InStrVector(temp, filtre) != -1)
		{
			notrad.push_back(ligne);
		}
		else
		{
			fonctions.push_back(temp);
			temp = "";
			if (ligne[compt] == '\"')
				ligne.erase(ligne.begin() + compt);

			temp += ligne.substr(ligne.size() - 9, ligne.size());

			if (temp == "</string>")
			{
				temp = "";
				temp_char = 'a';
				while (temp_char != '<')
				{
					temp += ligne[compt];
					compt++;
					temp_char = ligne[compt];
				}

				if (temp[temp.size() - 1] == '\"')
					temp.erase(temp.begin() + temp.size() - 1);

				trad.push_back(temp);
			}
			else
			{
				temp = "";
				temp_char = 'a';
				for (int i = compt; i < ligne.size(); i++)
				{
					temp += ligne[i];
				}
				temp += "@@";
				do
				{
					temp1 = "";
					compt = 0;
					comptemp++;
					//cout << comptemp << endl;
					ligne = toutes_les_lignes[comptemp];
					for (int i = ligne.size() - 9; i < ligne.size(); i++)
					{
						temp1 += ligne[i];
					}
					if (temp1 == "</string>")
					{
						if (ligne.size() != 9)
						{
							while (temp_char != '<')
							{
								temp += ligne[compt];
								compt++;
								temp_char = ligne[compt];
							}
						}
					}
					else
					{
						for (int i = compt; i < ligne.size(); i++)
						{
							temp += ligne[i];
						}
						temp += "@@";
					}
					compt = 0;
				} while (temp1 != "</string>");

				if (temp[temp.size() - 1] == '\"')
					temp.erase(temp.begin() + temp.size() - 1);

				trad.push_back(temp);
			}
		}
		comptemp++;
		//cout << comptemp << endl;
		ligne = toutes_les_lignes[comptemp];
	}
	return { fonctions, trad, notrad };
}

vector<vector<vector<string>>> Traduction::lecture_xml_typeArrays(string adresse_xml)
{
	ifstream xml(adresse_xml);
	string ligne, temp, temp1;
	vector<string> fonctions, notrad;
	vector<vector<string>> trad = { {} };
	int compt, pos_trad = 0;
	char temp_char = 'a';
	getline(xml, ligne);
	getline(xml, ligne);
	getline(xml, ligne);
	while (ligne != "</resources>")
	{
		temp = "";
		while (ligne == "" || ligne == "	" || ligne == " ")
			getline(xml, ligne);

		if (ligne[0] == '	')
		{
			ligne.erase(ligne.begin());
			ligne.insert(0, "    ");
		}

		for (int i = 4; i < 10; i++)
		{
			temp += ligne[i];
		}
		if (temp == "<array")
		{
			notrad.push_back(ligne);
			while (ligne != "    </array>")
			{
				getline(xml, ligne);
				notrad.push_back(ligne);
			}
		}
		else
		{
			temp = "";
			vector<string> filtre;
			if(nom_appli == "VenomTweaks")
				filtre = { "values\">", "_icons\">", "_ids\">", "_values_up\">", "values_new\">", "values_elite\">" };
			if (nom_appli == "VenomHUB")
				filtre = { "values\">", "_list\">", "upport_irc_channel\">", "_labels\">", "_types\">", "harsets\">" };
			if (nom_appli == "VenomSideBar")
				filtre = { "values\">", "_icons\">", "_ids\">" };
			if (nom_appli == "Viper4Android")
				filtre = { "values\">", "_modes\">" };

			bool test = false;

			for (int j = 0; j < filtre.size(); j++)
			{
				temp = "";
				if (ligne.size() - filtre[j].size() > 0)
				{
					for (int i = ligne.size() - filtre[j].size(); i < ligne.size(); i++)
					{
						temp += ligne[i];
					}
					if (temp == filtre[j])
					{
						test = true;
						notrad.push_back(ligne);
						while (ligne != "    </string-array>")
						{
							getline(xml, ligne);
							notrad.push_back(ligne);
						}
					}
				}
			}

			if(!test)
			{
				temp = "";
				compt = 24;
				temp_char = 'a';
				while (temp_char != '\"')
				{
					temp += ligne[compt];
					compt++;
					temp_char = ligne[compt];
				}
				fonctions.push_back(temp);
				getline(xml, ligne);
				while (ligne != "    </string-array>")
				{
					if (ligne[0] == '	' && ligne[1] == '	')
					{
						ligne.erase(ligne.begin());
						ligne.erase(ligne.begin());
						ligne.insert(0, "        ");
					}
					temp = "";
					compt = 14;
					temp_char = 'a';
					while (temp_char != '<')
					{
						temp += ligne[compt];
						compt++;
						temp_char = ligne[compt];
					}
					trad[pos_trad].push_back(temp);
					getline(xml, ligne);
				}
				pos_trad++;
				trad.push_back({});
			}
		}
		getline(xml, ligne);
	}
	trad.pop_back();
	return { {fonctions}, trad, {notrad} };
}

bool Traduction::traitement_ouverture_bdd()
{
	ifstream fichier_strings(adresse_bdd_strings), fichier_arrays(adresse_bdd_arrays);

	if (!fichier_strings || !fichier_arrays)
	{
		fichier_strings.close();
		fichier_arrays.close();
		return false;
	}
	else
	{
		fichier_strings.close();
		fichier_arrays.close();
		vector<vector<string>> xml = lecture_xml_typeStrings(adresse_bdd_strings);
		bdd_liste_strings_fonctions = xml[0];
		bdd_liste_strings_trad = xml[1];

		vector<vector<vector<string>>> xml1 = lecture_xml_typeArrays(adresse_bdd_arrays);
		bdd_liste_arrays_fonctions = xml1[0][0];
		bdd_liste_arrays_trad = xml1[1];
		bdd_liste_arrays_trad_notrad = xml1[2][0];
	}
	return true;
}

void Traduction::setAdresseBdd(QString adresseS, QString adresseA)
{
	adresse_bdd_strings = adresseS.toStdString();
	adresse_bdd_arrays = adresseA.toStdString();
}

void Traduction::creationEncours()
{
	int temp; 
	pos_strings = 0;
	pos_arrays = 0;
	encours_liste_strings_fonctions = {};
	encours_liste_strings_trad = {};
	encours_liste_arrays_fonctions = {};
	encours_liste_arrays_trad = {};

	for (int i = 0; i < liste_strings_fonctions.size(); i++)
	{
		temp = InStrVector(liste_strings_fonctions[i], bdd_liste_strings_fonctions);
		if (temp != -1)
		{
			encours_liste_strings_fonctions.push_back(bdd_liste_strings_fonctions[temp]);
			encours_liste_strings_trad.push_back(bdd_liste_strings_trad[temp]);
			pos_strings++;
		}
	}
	for (int i = 0; i < liste_strings_fonctions.size(); i++)
	{
		temp = InStrVector(liste_strings_fonctions[i], encours_liste_strings_fonctions);
		if (temp == -1)
		{
			encours_liste_strings_fonctions.push_back(liste_strings_fonctions[i]);
			encours_liste_strings_trad.push_back(liste_strings_trad[i]);
		}
	}

	for (int i = 0; i < liste_arrays_fonctions.size(); i++)
	{
		temp = InStrVector(liste_arrays_fonctions[i], bdd_liste_arrays_fonctions);
		if (temp != -1 && bdd_liste_arrays_trad[temp].size() == liste_arrays_trad[i].size())
		{
			encours_liste_arrays_fonctions.push_back(bdd_liste_arrays_fonctions[temp]);
			encours_liste_arrays_trad.push_back(bdd_liste_arrays_trad[temp]);
			pos_arrays++;
		}
	}
	for (int i = 0; i < liste_arrays_fonctions.size(); i++)
	{
		temp = InStrVector(liste_arrays_fonctions[i], encours_liste_arrays_fonctions);
		if (temp == -1)
		{
			encours_liste_arrays_fonctions.push_back(liste_arrays_fonctions[i]);
			encours_liste_arrays_trad.push_back(liste_arrays_trad[i]);
		}
	}
	if (pos_strings >= encours_liste_strings_fonctions.size())
		pos_strings = encours_liste_strings_fonctions.size() - 1;
	if (pos_arrays >= encours_liste_arrays_fonctions.size())
		pos_arrays = encours_liste_arrays_fonctions.size() - 1;
}

QString Traduction::getStringsFonctionATraduire()
{
	return QString::fromStdString(encours_liste_strings_fonctions[pos_strings]);
}

QString Traduction::getStringsLigneDOrigine()
{
	return QString::fromStdString(encours_liste_strings_trad[pos_strings]);
}

void Traduction::setPosString(int pos)
{
	pos_strings += pos;
	if (pos_strings < 0)
		pos_strings = 0;
	else if(pos_strings >= encours_liste_strings_fonctions.size())
		pos_strings = encours_liste_strings_fonctions.size() - 1;
}

QString Traduction::setTraductionString(QString trad, bool question)
{
	if (trad == "" || encours_liste_strings_trad[pos_strings] == trad.toStdString())
	{
		return "";
	}
	if (question)
	{
		int temp = InStrVector(encours_liste_strings_fonctions[pos_strings], bdd_liste_strings_fonctions);
		bdd_liste_strings_trad[temp] = trad.toStdString();
		encours_liste_strings_trad[pos_strings] = trad.toStdString();
		return "";
	}

	if (InStrVector(encours_liste_strings_fonctions[pos_strings], bdd_liste_strings_fonctions) == -1)
	{
		bdd_liste_strings_fonctions.push_back(encours_liste_strings_fonctions[pos_strings]);
		bdd_liste_strings_trad.push_back(trad.toStdString());
		encours_liste_strings_trad[pos_strings] = trad.toStdString();
		return "";
	}
	else
	{
		return QString::fromStdString(encours_liste_strings_trad[pos_strings]);
	}
}

QString Traduction::getArraysFonctionATraduire()
{
	return QString::fromStdString(encours_liste_arrays_fonctions[pos_arrays]);
}

vector<QString> Traduction::getArraysLignesATraduire()
{
	vector<string> temp = encours_liste_arrays_trad[pos_arrays];
	vector<QString> temp1;
	for (int i = 0; i < temp.size(); i++)
	{
		temp1.push_back(QString::fromStdString(temp[i]));
	}
	return temp1;
}

void Traduction::setPosArrays(int pos)
{
	pos_arrays += pos;
	if (pos_arrays < 0)
		pos_arrays = 0;
	else if (pos_arrays >= encours_liste_arrays_fonctions.size())
		pos_arrays = encours_liste_arrays_fonctions.size() - 1;
}

bool Traduction::setTraductionArrays(vector<QString> trad, bool question)
{
	vector<string> trad_string;
	for (int i = 0; i < trad.size(); i++)
	{
		trad_string.push_back(trad[i].toStdString());
	}

	if (encours_liste_arrays_trad[pos_arrays] == trad_string)
	{
		return false;
	}

	if (question)
	{
		int temp = InStrVector(encours_liste_arrays_fonctions[pos_arrays], bdd_liste_arrays_fonctions);
		bdd_liste_arrays_trad[temp] = trad_string;
		encours_liste_arrays_trad[pos_arrays] = trad_string;
		return false;
	}

	if (InStrVector(encours_liste_arrays_fonctions[pos_arrays], bdd_liste_arrays_fonctions) == -1)
	{
		bdd_liste_arrays_fonctions.push_back(encours_liste_arrays_fonctions[pos_arrays]);
		bdd_liste_arrays_trad.push_back(trad_string);
		encours_liste_arrays_trad[pos_arrays] = trad_string;
		return false;
	}
	else
	{
		return true;
	}
}

bool Traduction::enregistrementStrings(string adresseavecnom, vector<string> fonctions, vector<string> trad, vector<string> notrad, bool mettrenotrad)
{
	ofstream fichier(adresseavecnom.c_str());
	if (fichier)
	{
		string temp;
		bool antierreur;
		fichier << "<?xml version=\"1.0\" encoding=\"utf-8\"?>" << endl << "<resources>" << endl;
		if (mettrenotrad)
		{
			for (int i = 0; i < notrad.size(); i++)
			{
				fichier << notrad[i] << endl;
			}
		}
		for (int i = 0; i < fonctions.size(); i++)
		{
			fichier << "    <string name=\"" << fonctions[i] << "\">";
			temp = "";
			antierreur = false;
			for (int j = 0; j < trad[i].size()-1; j++)
			{
				if (trad[i][j] == '@' && trad[i][j + 1] == '@')
				{
					trad[i].erase(trad[i].begin()+j);
					//trad[i].erase(trad[i].begin() + j + 1);
					remplace(temp);
					fichier << temp << endl;
					temp = "";
					antierreur = true;
				}
				else
				{
					temp.push_back(trad[i][j]);
				}
			}
			temp.push_back(trad[i][trad[i].size() - 1]);
			remplace(temp);
			fichier << temp << "</string>" << endl;
		}
		fichier << "</resources>";
		fichier.close();
		return true;
	}
	else
	{
		return false;
	}
}

bool Traduction::enregistrementArrays(string adresseavecnom, vector<string> fonctions, vector<vector<string>> trad, vector<string> notrad, bool mettrenotrad)
{
	ofstream fichier(adresseavecnom.c_str());
	if (fichier)
	{
		string temp;
		bool antierreur;
		fichier << "<?xml version=\"1.0\" encoding=\"utf-8\"?>" << endl << "<resources>" << endl;
		if (mettrenotrad)
		{
			for (int i = 0; i < notrad.size(); i++)
			{
				fichier << notrad[i] << endl;
			}
		}
		for (int i = 0; i < fonctions.size(); i++)
		{
			fichier << "    <string-array name=\"" << fonctions[i] << "\">" << endl;
			for (int j = 0; j < trad[i].size(); j++)
			{
				remplace(trad[i][j]);
				fichier << "        <item>" << trad[i][j] << "</item>" << endl;
			}
			fichier << temp << "    </string-array>" << endl;
		}
		fichier << "</resources>";
		fichier.close();
		return true;
	}
	else
	{
		return false;
	}
}

void Traduction::enregistrementStringxml(string adresse)
{
	enregistrementStrings(adresse, encours_liste_strings_fonctions, encours_liste_strings_trad, liste_strings_trad_notrad, true);
}

void Traduction::enregistrementArraysxml(string adresse)
{
	enregistrementArrays(adresse, encours_liste_arrays_fonctions, encours_liste_arrays_trad, liste_arrays_trad_notrad, true);
}

void Traduction::enregistrementBddStringxml(string adresse)
{
	enregistrementStrings(adresse, bdd_liste_strings_fonctions, bdd_liste_strings_trad, {}, false);
}

void Traduction::enregistrementBddArraysxml(string adresse)
{
	enregistrementArrays(adresse, bdd_liste_arrays_fonctions, bdd_liste_arrays_trad, {}, false);
}

int Traduction::totalLigneArrays()
{
	return encours_liste_arrays_fonctions.size();
}

int Traduction::totalLigneStrings()
{
	return encours_liste_strings_fonctions.size();
}

int Traduction::getPosArrays()
{
	return pos_arrays;
}

int Traduction::getPosStrings()
{
	return pos_strings;
}

vector<vector<string>> Traduction::fusionArrays(QString adresseBdd1, QString adresseBdd2, QString adresseEnregistBdd, int reponse)
{
	int temp;
	vector<vector<vector<string>>> bdd1;
	bdd1 = lecture_xml_typeArrays(adresseBdd1.toStdString());
	vector<vector<vector<string>>> bdd2;
	bdd2 = lecture_xml_typeArrays(adresseBdd2.toStdString());
	vector<string> bdd1fonction, bdd2fonction;
	vector<vector<string>> bdd1trad, bdd2trad;

	if (bdd1[0][0].size() > bdd2[0][0].size())
	{
		bdd1fonction = bdd1[0][0];
		bdd2fonction = bdd2[0][0];
		bdd1trad = bdd1[1];
		bdd2trad = bdd2[1];
	}
	else
	{
		bdd1fonction = bdd2[0][0];
		bdd2fonction = bdd1[0][0];
		bdd1trad = bdd2[1];
		bdd2trad = bdd1[1];
	}

	for (int i = pos_arrays_fusion; i < bdd1fonction.size(); i++)
	{
		temp = InStrVector(bdd1fonction[i], bdd2fonction);
		if (reponse == 1)
		{
			fusion_liste_arrays_fonctions.push_back(bdd1fonction[temp]);
			fusion_liste_arrays_trad.push_back(bdd1trad[temp]);
			reponse = 0;
		}
		else if (reponse == 2)
		{
			fusion_liste_arrays_fonctions.push_back(bdd2fonction[temp]);
			fusion_liste_arrays_trad.push_back(bdd2trad[temp]);
			reponse = 0;
		}
		else if (temp != -1)
		{
			pos_arrays_fusion = i;
			return{ { bdd1fonction[i] }, bdd1trad[i], bdd2trad[temp] };
		}
	}
	for (int i = 0; i < bdd1fonction.size(); i++)
	{
		temp = InStrVector(bdd1fonction[i], fusion_liste_arrays_fonctions);
		if (temp == -1)
		{
			fusion_liste_arrays_fonctions.push_back(bdd1fonction[i]);
			fusion_liste_arrays_trad.push_back(bdd1trad[i]);
		}
	}
	for (int i = 0; i < bdd2fonction.size(); i++)
	{
		temp = InStrVector(bdd2fonction[i], fusion_liste_arrays_fonctions);
		if (temp == -1)
		{
			fusion_liste_arrays_fonctions.push_back(bdd2fonction[i]);
			fusion_liste_arrays_trad.push_back(bdd2trad[i]);
		}
	}
	pos_arrays_fusion = 0;
	enregistrementArrays(adresseEnregistBdd.toStdString(), fusion_liste_arrays_fonctions, fusion_liste_arrays_trad, liste_arrays_trad_notrad, false);
	return{ {"FFIINN"} };
}

vector<string> Traduction::fusionStrings(QString adresseBdd1, QString adresseBdd2, QString adresseEnregistBdd, int reponse)
{
	int temp;
	vector<vector<string>> bdd1;
	bdd1 = lecture_xml_typeStrings(adresseBdd1.toStdString());
	vector<vector<string>> bdd2;
	bdd2 = lecture_xml_typeStrings(adresseBdd2.toStdString());

	vector<string> bdd1fonction, bdd2fonction, bdd1trad, bdd2trad;

	if (bdd1[0][0].size() > bdd2[0][0].size())
	{
		bdd1fonction = bdd1[0];
		bdd2fonction = bdd2[0];
		bdd1trad = bdd1[1];
		bdd2trad = bdd2[1];
	}
	else
	{
		bdd1fonction = bdd2[0];
		bdd2fonction = bdd1[0];
		bdd1trad = bdd2[1];
		bdd2trad = bdd1[1];
	}

	for (int i = pos_strings_fusion; i < bdd1fonction.size(); i++)
	{
		temp = InStrVector(bdd1fonction[i], bdd2fonction);
		if (reponse == 1)
		{
			fusion_liste_strings_fonctions.push_back(bdd1fonction[temp]);
			fusion_liste_strings_trad.push_back(bdd1trad[temp]);
			reponse = 0;
		}
		else if (reponse == 2)
		{
			fusion_liste_strings_fonctions.push_back(bdd2fonction[temp]);
			fusion_liste_strings_trad.push_back(bdd2trad[temp]);
			reponse = 0;
		}
		else if (temp != -1)
		{
			pos_strings_fusion = i;
			return{ { bdd1fonction[i] }, bdd1trad[i], bdd2trad[i] };
		}
	}
	for (int i = 0; i < bdd1fonction.size(); i++)
	{
		temp = InStrVector(bdd1fonction[i], fusion_liste_strings_fonctions);
		if (temp == -1)
		{
			fusion_liste_strings_fonctions.push_back(bdd1fonction[i]);
			fusion_liste_strings_trad.push_back(bdd1trad[i]);
		}
	}
	for (int i = 0; i < bdd2fonction.size(); i++)
	{
		temp = InStrVector(bdd2fonction[i], fusion_liste_strings_fonctions);
		if (temp == -1)
		{
			fusion_liste_strings_fonctions.push_back(bdd2fonction[i]);
			fusion_liste_strings_trad.push_back(bdd2trad[i]);
		}
	}
	pos_strings_fusion = 0;
	enregistrementStrings(adresseEnregistBdd.toStdString(), fusion_liste_strings_fonctions, fusion_liste_strings_trad, {}, false);
	return{ "FFIINN" };
}

void Traduction::setNomAppli(string nom, string langue1)
{
	adresse_bdd_strings = "bdd/" + nom + "_" + langue1 + "_strings.xml";
	adresse_bdd_arrays = "bdd/" + nom + "_" + langue1 + "_arrays.xml";
	nom_appli = nom;
	langue = langue1;
}