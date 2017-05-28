// Auteur : Alexandreou
#include "Traduction.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

Traduction::Traduction()
{

}

void Traduction::setAdresseApk(QString adresse)
{
	adresse_dossier_apk = adresse;
}

bool Traduction::traitement_ouverture_apk()
{
	string adresse = adresse_dossier_apk.toStdString();
	adresse_strings = adresse + "/res/values/strings.xml";
	adresse_arrays  = adresse + "/res/values/arrays.xml";

	ifstream fichier_strings("D:/VenomTweaks/res/values-fr/strings.xml"), fichier_arrays("D:/VenomTweaks/res/values-fr/arrays.xml");

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
		liste_strings_fonctions = xml[0];
		liste_strings_trad = xml[1];

		vector<vector<vector<string>>> xml1 = lecture_xml_typeArrays(adresse_arrays);
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
	vector<string> fonctions, trad;
	int compt;
	char temp_char = 'a';
	getline(xml, ligne);
	getline(xml, ligne); 
	getline(xml, ligne);
	while (ligne != "</resources>")
	{
		compt = 18;
		temp = "";
		temp_char = 'a';
		while (temp_char != '\"')
		{
			temp += ligne[compt];
			compt++;
			temp_char = ligne[compt];
		}
		fonctions.push_back(temp);
		compt += 2;
		temp = "";
		for (int i = ligne.size() - 9; i < ligne.size(); i++)
		{
			temp += ligne[i];
		}
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
			trad.push_back(temp);
		}
		else
		{
			temp = "";
			temp_char = 'a';
			for(int i = compt; i < ligne.size(); i++)
			{
				temp += ligne[i];
			}
			temp += "@RetourLigne@";
			do 
			{
				temp1 = "";
				compt = 0;
				getline(xml, ligne);
				for (int i = ligne.size() - 9; i < ligne.size(); i++)
				{
					temp1 += ligne[i];
				}
				if(temp1 == "</string>")
				{
					while (temp_char != '<')
					{
						temp += ligne[compt];
						compt++;
						temp_char = ligne[compt];
					}
				}
				else
				{
					for (int i = compt; i < ligne.size(); i++)
					{
						temp += ligne[i];
					}
					temp += "@RetourLigne@";
				}
				compt = 0;
			} while (temp1 != "</string>");
			trad.push_back(temp);
		}
		getline(xml, ligne);
	}
	return { fonctions, trad };
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
			for (int i = ligne.size() - 8; i < ligne.size(); i++)
			{
				temp += ligne[i];
			}
			if (temp == "values\">")
			{
				notrad.push_back(ligne);
				while (ligne != "    </string-array>")
				{
					getline(xml, ligne);
					notrad.push_back(ligne);
				}
			}
			else
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
	return { {fonctions}, trad, {notrad} };
}