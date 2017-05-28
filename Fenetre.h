// Auteur : Alexandreou
#ifndef HEADER_FENETRE
#define HEADER_FENETRE

#include <QtWidgets>
#include "Traduction.h"

class Fenetre : public QMainWindow
{

	Q_OBJECT

public:
	Fenetre();

public slots:
	void getDossierApk();
	void getAdresseBdd();

	void btraduireAvecBdd();

	void stringLignePrec();

	void stringLigneSuiv();

	void stringLigneNoTrad();


private:
	Traduction t;
	QLineEdit *fonctionATraduite;
	QLineEdit *ligneDorigine;
	QLineEdit *ligneTraduite;
	QLineEdit *adresseApk;

};

#endif