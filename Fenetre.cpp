// Auteur : Alexandreou
#include "Fenetre.h"
#include "Traduction.h"
#include <iostream>

Fenetre::Fenetre()
{
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
	fonctionATraduite->setReadOnly(true);
	ligneDorigine = new QLineEdit;
	ligneDorigine->setReadOnly(true);
	ligneTraduite = new QLineEdit;
	
	QPushButton *lignePrec = new QPushButton("< Ligne précédante");
	QPushButton *ligneSuiv = new QPushButton("Valider / Ligne suivante >");
	QPushButton *tradNonTrouv = new QPushButton("Passer / Traduction non trouvée >");

	QWidget *page2 = new QWidget;
	QGridLayout *layoutPage2 = new QGridLayout;
	QLabel *labelMenuATraduite = new QLabel("Menu à traduire");
	menuATraduite = new QLineEdit;
	menuATraduite->setReadOnly(true);
	lignesDuMenu = new QListWidget;
	QLabel *labelLigneDorigineM = new QLabel("Ligne d'origine");
	QLabel *labelLigneTraduiteM = new QLabel("Traduction");
	ligneDorigineM = new QLineEdit;
	ligneDorigineM->setReadOnly(true);
	ligneTraduiteM = new QLineEdit;
	QPushButton *validerM = new QPushButton("Valider la traduction de la ligne");
	QPushButton *lignePrecM = new QPushButton("< Menu précédant");
	QPushButton *ligneSuivM = new QPushButton("Valider / Menu suivant >");

	QGridLayout *infoSuppApk = new QGridLayout;
	infoSuppApk->setContentsMargins(0, 20, 0, 0);
	QLabel *labelAdresseApk = new QLabel("Adresse de l'apk d'origine");
	adresseApk = new QLineEdit;
	adresseApk->setReadOnly(true);

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
	layoutPage2->addWidget(lignesDuMenu, 0, 0, 5, 1);
	layoutPage2->addWidget(labelLigneDorigineM, 1, 1);
	layoutPage2->addWidget(labelLigneTraduiteM, 2, 1);
	layoutPage2->addWidget(ligneDorigineM, 1, 2);
	layoutPage2->addWidget(ligneTraduiteM, 2, 2);
	layoutPage2->addWidget(validerM, 3, 1, 1, 2);
	layoutPage2->addWidget(lignePrecM, 4, 1);
	layoutPage2->addWidget(ligneSuivM, 4, 2);
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
	connect(lignesDuMenu, SIGNAL(currentRowChanged(int)), this, SLOT(addLigneDOrigine(int)));
	connect(validerM, SIGNAL(clicked()), this, SLOT(ajouterTradLigneArrays()));
	connect(lignePrecM, SIGNAL(clicked()), this, SLOT(arraysLignePrec()));
	connect(ligneSuivM, SIGNAL(clicked()), this, SLOT(arraysLigneSuiv()));
	connect(enregistrerApk, SIGNAL(clicked()), this, SLOT(enregistrementsDansApk()));
	connect(enregistrerFichiers, SIGNAL(clicked()), this, SLOT(enregistrementsSous()));
}

void Fenetre::actualiserMenu()
{
	int temp = lignesDuMenu->count();
	for(int i = 0; i < temp-1; i++)
	{
		lignesDuMenu->removeItemWidget(lignesDuMenu->takeItem(0));
	}
	for (int i = 0; i < lignesDansMenu.size(); i++)
	{
		lignesDuMenu->addItem(lignesDansMenu[i]);
	}
}

void Fenetre::addLigneDOrigine(int ligneSelect)
{
	ligneDorigineM->setText(lignesDansMenu[ligneSelect]);
}

void Fenetre::getDossierApk()
{
	QString dossier = QFileDialog::getExistingDirectory(this, "Ouvrir un .apk décompilé");
	t.setAdresseApk(dossier);
	bool reussite = t.traitement_ouverture_apk();
	t.creationEncours();
	fonctionATraduite->setText(t.getStringsFonctionATraduire());
	ligneDorigine->setText(t.getStringsLigneDOrigine());

	menuATraduite->setText(t.getArraysFonctionATraduire());
	lignesDansMenu = t.getArraysLignesATraduire();
	actualiserMenu();

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
	menuATraduite->setText(t.getArraysFonctionATraduire());
	lignesDansMenu = t.getArraysLignesATraduire();
	actualiserMenu();
	lignesDuMenu->removeItemWidget(lignesDuMenu->takeItem(0));
	addLigneDOrigine(0);
}

void Fenetre::stringLignePrec()
{
	t.setPosString(-1);
	fonctionATraduite->setText(t.getStringsFonctionATraduire());
	ligneDorigine->setText(t.getStringsLigneDOrigine());
}

void Fenetre::stringLigneSuiv()
{
	QString temp = t.setTraductionString(ligneTraduite->text(), false);
	if (temp != "")
	{
		int reponse = QMessageBox::question(this, "Doublon", "Une autre traduction a été trouvé dans la base de donnée.\nVoulez-vous remplacer la traduction de la base de donnée ?\n\nTraduction de la base de donnée : "+temp+"\nVotre traduction : "+ ligneTraduite->text(), QMessageBox::Yes | QMessageBox::No);
		if (reponse == QMessageBox::Yes)
		{
			temp = t.setTraductionString(ligneTraduite->text(), true);
		}
	}
	t.setPosString(+1);
	ligneTraduite->setText("");
	fonctionATraduite->setText(t.getStringsFonctionATraduire());
	ligneDorigine->setText(t.getStringsLigneDOrigine());
}

void Fenetre::stringLigneNoTrad()
{
	t.setPosString(+1);
	fonctionATraduite->setText(t.getStringsFonctionATraduire());
	ligneDorigine->setText(t.getStringsLigneDOrigine());
}

void Fenetre::ajouterTradLigneArrays()
{
	if (ligneTraduiteM->text() != "")
	{
		lignesDansMenu[lignesDuMenu->currentRow()] = ligneTraduiteM->text();
		lignesDuMenu->removeItemWidget(lignesDuMenu->takeItem(lignesDuMenu->currentRow()));
		lignesDuMenu->insertItem(lignesDuMenu->currentRow(), ligneTraduiteM->text());
		lignesDuMenu->item(lignesDuMenu->currentRow() - 1)->setBackgroundColor("#50FF50");
		ligneTraduiteM->setText("");
	}
	if(lignesDuMenu->currentRow() < lignesDansMenu.size())
		lignesDuMenu->setCurrentRow(lignesDuMenu->currentRow());
}

void Fenetre::arraysLignePrec()
{
	t.setPosArrays(-1);
	menuATraduite->setText(t.getArraysFonctionATraduire());
	lignesDansMenu = t.getArraysLignesATraduire();
	actualiserMenu();
	lignesDuMenu->removeItemWidget(lignesDuMenu->takeItem(0));
	addLigneDOrigine(0);
}

void Fenetre::arraysLigneSuiv()
{
	bool temp = t.setTraductionArrays(lignesDansMenu, false);
	if (temp)
	{
		int reponse = QMessageBox::question(this, "Doublon", "Une autre traduction a été trouvé dans la base de donnée.\nVoulez-vous remplacer la traduction de la base de donnée ?", QMessageBox::Yes | QMessageBox::No);
		if (reponse == QMessageBox::Yes)
		{
			temp = t.setTraductionArrays(lignesDansMenu, true);
		}
	}
	t.setPosArrays(+1);
	menuATraduite->setText(t.getArraysFonctionATraduire());
	lignesDansMenu = t.getArraysLignesATraduire();
	actualiserMenu();
	lignesDuMenu->removeItemWidget(lignesDuMenu->takeItem(0));
	addLigneDOrigine(0);
}

void Fenetre::enregistrementsDansApk()
{
	t.enregistrementStringxml(adresseApk->text().toStdString()+"/res/values-fr/strings.xml");
	t.enregistrementArraysxml(adresseApk->text().toStdString() + "/res/values-fr/arrays.xml");
}

void Fenetre::enregistrementsSous()
{
	QString dossier = QFileDialog::getExistingDirectory(this, "Dossier d'enregistrement des fichiers arrays.xml et strings.xml traduits");
	t.enregistrementStringxml(dossier.toStdString() + "/strings.xml");
	t.enregistrementArraysxml(dossier.toStdString() + "/arrays.xml");
}