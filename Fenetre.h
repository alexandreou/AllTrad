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

private:
	Traduction t;

};

#endif