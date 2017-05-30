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
	std::vector<QString> lignesDansMenu;
};

#endif