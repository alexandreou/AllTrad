// Auteur : Alexandreou
#ifndef HEADER_FENETRE
#define HEADER_FENETRE

#include <QtWidgets>
#include <vector>
#include "Traduction.h"

class Fenetre : public QMainWindow
{

	Q_OBJECT

public:
	Fenetre();
	void erreurNoDossierApk();
	void actualiserMenu();

public slots:
	void getDossierApk();
	void getAdresseBdd();
	void btraduireAvecBdd();
	void stringLignePrec();
	void stringLigneSuiv();
	void stringLigneNoTrad();
	void ajouterTradLigneArrays();
	void arraysLignePrec();
	void arraysLigneSuiv();
	void enregistrementsDansApk();
	void enregistrementsSous();
	void enregistrementsBdd();
	void enregistrementsBddSous();
	void fArraysBddB1();
	void fArraysBddB2();
	void fArraysBddB3();
	void fArraysBddB4();
	void fStringsBddB1();
	void fStringsBddB2();
	void fStringsBddB3();
	void fStringsBddB4();
	void addLigneDOrigine(int ligneSelect);

private:
	Traduction t;
	QLineEdit *fonctionATraduite;
	QLineEdit *ligneDorigine;
	QLineEdit *ligneTraduite;
	QLineEdit *adresseApk;
	QLineEdit *menuATraduite;
	QLineEdit *ligneDorigineM;
	QLineEdit *ligneTraduiteM;
	QListWidget *lignesDuMenu;
	QLabel *nbLigneArrays;
	QLabel *nbLigneStrings;
	std::vector<QString> lignesDansMenu;
	QLineEdit *arraysBddT1;
	QLineEdit *arraysBddT2;
	QLineEdit *arraysBddT3;
	QLineEdit *stringsBddT1;
	QLineEdit *stringsBddT2;
	QLineEdit *stringsBddT3;
};

#endif