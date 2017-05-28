// Auteur : Alexandreou
#include "Fenetre.h"
#include "Traduction.h"
#include <iostream>

Fenetre::Fenetre()
{
	Traduction t;
	QWidget *zoneCentrale = new QWidget;
	QGridLayout *layoutPrincipal = new QGridLayout;

	QGridLayout *layoutOption1 = new QGridLayout;
	layoutOption1->setContentsMargins(0, 0, 20, 20);
	QComboBox *boutonAppliTrad = new QComboBox;
	boutonAppliTrad->addItem("VenomTweaks.apk");
	QComboBox *langueVers = new QComboBox;
	langueVers->addItem("Anglais -> Français");
	QPushButton *ouvrirApk = new QPushButton("Ouvrir le dossier de l'apk décompilé");
	QPushButton *ouvrirAutreBdd = new QPushButton("Ouvrir une autre Bdd");

	QGridLayout *layoutOption2 = new QGridLayout;
	layoutOption2->setContentsMargins(20, 0, 0, 20);
	QPushButton *traduireAvecBdd = new QPushButton("Traduire avec Bdd");
	QPushButton *enregistrerFichiers = new QPushButton("Enregistrer les fichiers traduits sous");
	QPushButton *enregistrerApk = new QPushButton("Enregistrer dans le dossier de l'apk (prêt à recompiler)");

	QTabWidget *onglets = new QTabWidget;
	QWidget *page1 = new QWidget;
	QGridLayout *layoutPage1 = new QGridLayout;
	QLabel *labelFonctionATraduite = new QLabel("Fonction à traduire");
	QLabel *labelLigneDorigine = new QLabel("Ligne d'origine");
	QLabel *labelLigneTraduite = new QLabel("Traduction");
	fonctionATraduite = new QLineEdit;
	ligneDorigine = new QLineEdit;
	ligneTraduite = new QLineEdit;
	QPushButton *lignePrec = new QPushButton("< Ligne précédante");
	QPushButton *ligneSuiv = new QPushButton("Valider / Ligne suivante >");
	QPushButton *tradNonTrouv = new QPushButton("Passer / Traduction non trouvée >");

	QWidget *page2 = new QWidget;
	QGridLayout *layoutPage2 = new QGridLayout;
	QLabel *labelMenuATraduite = new QLabel("Menu à traduire");
	QLineEdit *menuATraduite = new QLineEdit;
	QListWidget *lignesDuMenu = new QListWidget;
	QLabel *labelLigneDorigineM = new QLabel("Ligne d'origine");
	QLabel *labelLigneTraduiteM = new QLabel("Traduction");
	QLineEdit *ligneDorigineM = new QLineEdit;
	QLineEdit *ligneTraduiteM = new QLineEdit;
	QPushButton *lignePrecM = new QPushButton("< Ligne précédante");
	QPushButton *ligneSuivM = new QPushButton("Valider / Ligne suivante >");

	QGridLayout *infoSuppApk = new QGridLayout;
	infoSuppApk->setContentsMargins(0, 20, 0, 0);
	QLabel *labelAdresseApk = new QLabel("Adresse de l'apk d'origine");
	adresseApk = new QLineEdit;

	QGridLayout *boutonsSuppl = new QGridLayout;
	QPushButton *autre1 = new QPushButton;
	QPushButton *autre2 = new QPushButton;
	QPushButton *autre3 = new QPushButton;
	QPushButton *autre4 = new QPushButton;
	QPushButton *autre5 = new QPushButton;

	layoutOption1->addWidget(boutonAppliTrad, 0, 0);
	layoutOption1->addWidget(langueVers, 0, 1);
	layoutOption1->addWidget(ouvrirApk, 1, 0);
	layoutOption1->addWidget(ouvrirAutreBdd, 1, 1);

	layoutOption2->addWidget(traduireAvecBdd, 0, 0);
	layoutOption2->addWidget(enregistrerFichiers, 0, 1);
	layoutOption2->addWidget(enregistrerApk, 1, 0, 1, 2);

	layoutPage1->addWidget(labelFonctionATraduite, 0, 0);
	layoutPage1->addWidget(fonctionATraduite, 0, 1);
	layoutPage1->addWidget(labelLigneDorigine, 1, 0);
	layoutPage1->addWidget(ligneDorigine, 1, 1, 1, 4);
	layoutPage1->addWidget(labelLigneTraduite, 2, 0);
	layoutPage1->addWidget(ligneTraduite, 2, 1, 1, 4);
	layoutPage1->addWidget(lignePrec, 3, 0);
	layoutPage1->addWidget(ligneSuiv, 3, 1);
	layoutPage1->addWidget(tradNonTrouv, 3, 2, 1, 3);
	page1->setLayout(layoutPage1);

	layoutPage2->addWidget(labelMenuATraduite, 0, 1);
	layoutPage2->addWidget(menuATraduite, 0, 2);
	layoutPage2->addWidget(lignesDuMenu, 0, 0, 4, 1);
	layoutPage2->addWidget(labelLigneDorigineM, 1, 1);
	layoutPage2->addWidget(labelLigneTraduiteM, 2, 1);
	layoutPage2->addWidget(ligneDorigineM, 1, 2);
	layoutPage2->addWidget(ligneTraduiteM, 2, 2);
	layoutPage2->addWidget(lignePrecM, 3, 1);
	layoutPage2->addWidget(ligneSuivM, 3, 2);
	page2->setLayout(layoutPage2);

	onglets->addTab(page1, "string.xml");
	onglets->addTab(page2, "array.xml");

	infoSuppApk->addWidget(labelAdresseApk, 0, 0);
	infoSuppApk->addWidget(adresseApk, 0, 1, 1, 3);
	
	boutonsSuppl->addWidget(autre1, 0, 0);
	boutonsSuppl->addWidget(autre2, 0, 1);
	boutonsSuppl->addWidget(autre3, 0, 2);
	boutonsSuppl->addWidget(autre4, 0, 3);
	boutonsSuppl->addWidget(autre5, 0, 4);

	layoutPrincipal->addLayout(layoutOption1, 0, 0);
	layoutPrincipal->addLayout(layoutOption2, 0, 1);
	layoutPrincipal->addWidget(onglets, 1, 0, 1, 2);
	layoutPrincipal->addLayout(infoSuppApk, 2, 0, 1, 2);
	layoutPrincipal->addLayout(boutonsSuppl, 3, 0, 1, 2);

	zoneCentrale->setLayout(layoutPrincipal);
	setCentralWidget(zoneCentrale);
	connect(ouvrirApk, SIGNAL(clicked()), this, SLOT(getDossierApk()));
	connect(ouvrirAutreBdd, SIGNAL(clicked()), this, SLOT(getAdresseBdd()));
	connect(traduireAvecBdd, SIGNAL(clicked()), this, SLOT(btraduireAvecBdd()));
	connect(lignePrec, SIGNAL(clicked()), this, SLOT(stringLignePrec()));
	connect(ligneSuiv, SIGNAL(clicked()), this, SLOT(stringLigneSuiv()));
	connect(tradNonTrouv, SIGNAL(clicked()), this, SLOT(stringLigneNoTrad()));
}

void Fenetre::getDossierApk()
{
	QString dossier = QFileDialog::getExistingDirectory(this);
	t.setAdresseApk(dossier);
	bool reussite = t.traitement_ouverture_apk();
	t.creationEncours();
	fonctionATraduite->setText(t.getStringsFonctionATraduire());
	ligneDorigine->setText(t.getStringsLigneDOrigine());
	adresseApk->setText(dossier);
}

void Fenetre::getAdresseBdd()
{
	QString fichierS = QFileDialog::getOpenFileName(this, "Ouvrir une bdd string", QString(), "Base de données (*.xml)");
	QString fichierA = QFileDialog::getOpenFileName(this, "Ouvrir une bdd arrays", QString(), "Base de données (*.xml)");
	t.setAdresseBdd(fichierS, fichierA);
}

void Fenetre::btraduireAvecBdd()
{
	t.traitement_ouverture_bdd();
	t.creationEncours();
	fonctionATraduite->setText(t.getStringsFonctionATraduire());
	ligneDorigine->setText(t.getStringsLigneDOrigine());
}

void Fenetre::stringLignePrec()
{
	t.setPosString(-1);
	fonctionATraduite->setText(t.getStringsFonctionATraduire());
	ligneDorigine->setText(t.getStringsLigneDOrigine());
}

void Fenetre::stringLigneSuiv()
{
	t.setPosString(+1);
	fonctionATraduite->setText(t.getStringsFonctionATraduire());
	ligneDorigine->setText(t.getStringsLigneDOrigine());
}

void Fenetre::stringLigneNoTrad()
{
	t.setPosString(+1);
	fonctionATraduite->setText(t.getStringsFonctionATraduire());
	ligneDorigine->setText(t.getStringsLigneDOrigine());
}