// Auteur : Alexandreou
#include "Fenetre.h"
#include "Traduction.h"
#include <iostream>
#include <vector>

Fenetre::Fenetre()
{
	QWidget *zoneCentrale = new QWidget;
	QGridLayout *layoutPrincipal = new QGridLayout;

	setWindowIcon(QIcon("files/logo.png"));
	setWindowTitle("All Trad v1.1");

	QGridLayout *layoutOption = new QGridLayout;
	layoutOption->setContentsMargins(0, 0, 0, 20);
	QPushButton *traduireAvecBdd = new QPushButton("Traduire avec la base de données");
	traduireAvecBdd->setToolTip("Permet de traduire l'application avec la base de données par défaut ou avec votre base de données.");
	traduireAvecBdd->setMinimumHeight(40);

	QLabel *logo = new QLabel;
	logo->setPixmap(QPixmap("files/logo.png"));
	logo->setAlignment(Qt::AlignCenter);

	QGridLayout *layoutOption1 = new QGridLayout;
	layoutOption1->setContentsMargins(0, 0, 20, 0);
	boutonAppliTrad = new QComboBox;
	boutonAppliTrad->addItem("VenomTweaks");
	boutonAppliTrad->addItem("VenomHUB");
	boutonAppliTrad->addItem("VenomSideBar");
	boutonAppliTrad->addItem("Viper4Android");
	boutonAppliTrad->addItem("Autre");
	boutonAppliTrad->setToolTip("Séléctionnez l'application que vous voulez traduire. Si elle n'y est pas, vous pouvez choisir \"Autre\" ou demander à Alexandreou.");
	langueVers = new QComboBox;
	langueVers->addItem("Anglais -> Français");
	langueVers->addItem("Anglais -> Espagnol");
	langueVers->addItem("Anglais -> Allemand");
	langueVers->setToolTip("Séléctionnez la langue dans laquelle vous voulez traduire l'application.");
	QPushButton *ouvrirApk = new QPushButton("Ouvrir le dossier de l'apk décompilé");
	ouvrirApk->setToolTip("Ouvrir le dossier du .apk décompilé avec ApkTool.");
	QPushButton *ouvrirAutreBdd = new QPushButton("Ouvrir une autre base de données");
	ouvrirAutreBdd->setToolTip("Cliquez ici pour ouvrir une autre base de données. Si vous ne choisissez pas une autre base de données, celle par défaut sera choisi.");

	QGridLayout *layoutOption2 = new QGridLayout;
	layoutOption2->setContentsMargins(20, 0, 0, 0);
	QPushButton *enregistrerFichiers = new QPushButton("Enregistrer les fichiers traduits sous");
	enregistrerFichiers->setToolTip("Permet de choisir un dossier dans lequel sera enregistré les fichiers traduis.");
	QPushButton *enregistrerApk = new QPushButton("Enregistrer les fichiers traduits");
	enregistrerApk->setToolTip("Permet d'enregistrer les fichiers traduis dans le dossier de l'application. Ne fonctionnera pas si vous avez choisi un dossier personnalisé.");
	QPushButton *enregistrerBddSous = new QPushButton("Enregistrer la base de données sous");
	enregistrerBddSous->setToolTip("Permet d'enregistrer la base de données dans un dossier de votre choix.");
	QPushButton *enregistrerBdd = new QPushButton("Enregistrer la base de données");
	enregistrerBdd->setToolTip("Permet d'enregistrer la base de données dans le dossier bdd du programme (donc deviendra la base de données par défaut).");

	onglets = new QTabWidget;
	QWidget *page1 = new QWidget;
	QGridLayout *layoutPage1 = new QGridLayout;
	QLabel *labelFonctionATraduite = new QLabel("Fonction à traduire");
	QLabel *labelLigneDorigine = new QLabel("Ligne d'origine");
	QLabel *labelLigneTraduite = new QLabel("Traduction");
	fonctionATraduite = new QLineEdit;
	fonctionATraduite->setReadOnly(true);
	nbLigneStrings = new QLabel("000/000");
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
	nbLigneArrays = new QLabel("000/000");
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
	QPushButton *autre1 = new QPushButton("A propos de All Trad");
	QPushButton *autre2 = new QPushButton("Fusion de bases de données");
	autre2->setToolTip("Permet de fusionner deux bases de données.");
	QPushButton *autre3 = new QPushButton;
	QPushButton *autre4 = new QPushButton;
	QPushButton *autre5 = new QPushButton;

	QMenu *menuFichier = menuBar()->addMenu("Fichier");
	QMenu *menuEdition = menuBar()->addMenu("Edition");
	QAction *actionOuvrirApk = new QAction("Ouvrir dossier apk décompilé", this);
	QAction *actionOuvrirFichiers = new QAction("Ouvrir fichiers à traduire", this);
	QAction *actionOuvrirBdd = new QAction("Ouvrir une autre base de données", this);
	QAction *actionOuvrirBddOrigine = new QAction("Remettre la base de données d'origine", this);
	QAction *actionEnregistrerTout = new QAction("Enregistrer tout", this);
	QAction *actionEnregistrerToutSous = new QAction("Enregistrer tout sous...", this);
	QAction *actionQuitter = new QAction("Quitter", this);

	QAction *actionAllerAuDebut = new QAction("Aller au début", this);
	QAction *actionReculer10 = new QAction("Reculer de 10 lignes / menus", this);
	QAction *actionAvancer10 = new QAction("Avancer de 10 lignes / menus", this);
	QAction *actionAllerALaFin = new QAction("Aller à la fin", this);

	menuFichier->addAction(actionOuvrirApk);
	menuFichier->addAction(actionOuvrirFichiers);
	menuFichier->addSeparator();
	menuFichier->addAction(actionOuvrirBdd);
	menuFichier->addAction(actionOuvrirBddOrigine);
	menuFichier->addSeparator();
	menuFichier->addAction(actionEnregistrerTout);
	menuFichier->addAction(actionEnregistrerToutSous);
	menuFichier->addSeparator();
	menuFichier->addAction(actionQuitter);

	menuEdition->addAction(actionAllerAuDebut);
	menuEdition->addAction(actionReculer10);
	menuEdition->addSeparator();
	menuEdition->addAction(actionAvancer10);
	menuEdition->addAction(actionAllerALaFin);

	layoutOption1->addWidget(boutonAppliTrad, 0, 0);
	layoutOption1->addWidget(langueVers, 0, 1);
	layoutOption1->addWidget(ouvrirApk, 1, 0);
	layoutOption1->addWidget(ouvrirAutreBdd, 1, 1);

	layoutOption2->addWidget(enregistrerFichiers, 1, 0);
	layoutOption2->addWidget(enregistrerApk, 0, 0);
	layoutOption2->addWidget(enregistrerBddSous, 1, 1);
	layoutOption2->addWidget(enregistrerBdd, 0, 1);

	layoutPage1->addWidget(labelFonctionATraduite, 0, 0);
	layoutPage1->addWidget(fonctionATraduite, 0, 1);
	layoutPage1->addWidget(nbLigneStrings, 0, 2);
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
	layoutPage2->addWidget(nbLigneArrays, 0, 3);
	layoutPage2->addWidget(lignesDuMenu, 0, 0, 5, 1);
	layoutPage2->addWidget(labelLigneDorigineM, 1, 1);
	layoutPage2->addWidget(labelLigneTraduiteM, 2, 1);
	layoutPage2->addWidget(ligneDorigineM, 1, 2, 1, 2);
	layoutPage2->addWidget(ligneTraduiteM, 2, 2, 1, 2);
	layoutPage2->addWidget(validerM, 3, 1, 1, 3);
	layoutPage2->addWidget(lignePrecM, 4, 1);
	layoutPage2->addWidget(ligneSuivM, 4, 2, 1, 2);
	page2->setLayout(layoutPage2);

	onglets->addTab(page1, "string.xml");
	onglets->addTab(page2, "array.xml");

	infoSuppApk->addWidget(labelAdresseApk, 0, 0);
	infoSuppApk->addWidget(adresseApk, 0, 1, 1, 3);
	
	boutonsSuppl->addWidget(autre1, 0, 0);
	boutonsSuppl->addWidget(autre2, 0, 1);
	//boutonsSuppl->addWidget(autre3, 0, 2);
	//boutonsSuppl->addWidget(autre4, 0, 3);
	//boutonsSuppl->addWidget(autre5, 0, 4);

	layoutOption->addLayout(layoutOption1, 0, 0);
	layoutOption->addWidget(logo, 0, 1);
	layoutOption->addLayout(layoutOption2, 0, 2);
	layoutOption->addWidget(traduireAvecBdd, 1, 0, 1, 3);

	layoutPrincipal->addLayout(layoutOption, 0, 0, 1, 2);
	layoutPrincipal->addWidget(onglets, 1, 0, 1, 2);
	layoutPrincipal->addLayout(infoSuppApk, 2, 0, 1, 2);
	layoutPrincipal->addLayout(boutonsSuppl, 3, 0, 1, 2);

	zoneCentrale->setLayout(layoutPrincipal);
	setCentralWidget(zoneCentrale);

	QDialog *fenetreAPropos = new QDialog;
	fenetreAPropos->setWindowIcon(QIcon("files/logo.png"));
	fenetreAPropos->setWindowTitle("A propos de All Trad");
	QVBoxLayout *layout1 = new QVBoxLayout;
	QLabel *image = new QLabel;
	QLabel *texte = new QLabel("Logiciel de traduction d'apks. Créé par Alexandreou.\n https://github.com/alexandreou/ViperTradTool");
	texte->setOpenExternalLinks(true);
	image->setPixmap(QPixmap("files/logo_long.png"));
	layout1->addWidget(image);
	layout1->addWidget(texte);
	fenetreAPropos->setLayout(layout1);

	QDialog *fenetreFusion = new QDialog;
	fenetreFusion->setWindowIcon(QIcon("files/logo.png"));

	fenetreFusion->setWindowTitle("Fusion de bases de données");
	QHBoxLayout *layout2 = new QHBoxLayout;
	QVBoxLayout *layout21 = new QVBoxLayout;
	layout21->setContentsMargins(0, 0, 20, 0);
	QVBoxLayout *layout22 = new QVBoxLayout;
	layout22->setContentsMargins(20, 0, 0, 0);

	QLabel *texteBddArrays = new QLabel("Fusion de bases de données Arrays.xml");
	QPushButton *arraysBddB1 = new QPushButton("Fichier de base de données 1");
	arraysBddT1 = new QLineEdit;
	arraysBddT1->setReadOnly(true);
	QPushButton *arraysBddB2 = new QPushButton("Fichier de base de données 2");
	arraysBddT2 = new QLineEdit;
	arraysBddT2->setReadOnly(true);
	QPushButton *arraysBddB3 = new QPushButton("Dossier d'enregistrement");
	arraysBddT3 = new QLineEdit;
	arraysBddT3->setReadOnly(true);
	QPushButton *arraysBddB4 = new QPushButton("Démarrer la fusion");
	layout21->addWidget(texteBddArrays);
	layout21->addWidget(arraysBddB1);
	layout21->addWidget(arraysBddT1);
	layout21->addWidget(arraysBddB2);
	layout21->addWidget(arraysBddT2);
	layout21->addWidget(arraysBddB3);
	layout21->addWidget(arraysBddT3);
	layout21->addWidget(arraysBddB4);

	QLabel *texteBddStrings = new QLabel("Fusion de bases de données Strings.xml");
	QPushButton *stringsBddB1 = new QPushButton("Fichier de base de données 1");
	stringsBddT1 = new QLineEdit;
	stringsBddT1->setReadOnly(true);
	QPushButton *stringsBddB2 = new QPushButton("Fichier de base de données 2");
	stringsBddT2 = new QLineEdit;
	stringsBddT2->setReadOnly(true);
	QPushButton *stringsBddB3 = new QPushButton("Dossier d'enregistrement");
	stringsBddT3 = new QLineEdit;
	stringsBddT3->setReadOnly(true);
	QPushButton *stringsBddB4 = new QPushButton("Démarrer la fusion");
	layout22->addWidget(texteBddStrings);
	layout22->addWidget(stringsBddB1);
	layout22->addWidget(stringsBddT1);
	layout22->addWidget(stringsBddB2);
	layout22->addWidget(stringsBddT2);
	layout22->addWidget(stringsBddB3);
	layout22->addWidget(stringsBddT3);
	layout22->addWidget(stringsBddB4);

	layout2->addLayout(layout21);
	layout2->addLayout(layout22);
	fenetreFusion->setLayout(layout2);

	QShortcut *shortcut1 = new QShortcut(QKeySequence("Ctrl+S"), this);

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
	connect(enregistrerBdd, SIGNAL(clicked()), this, SLOT(enregistrementsBdd()));
	connect(enregistrerBddSous, SIGNAL(clicked()), this, SLOT(enregistrementsBddSous()));
	connect(autre1, SIGNAL(clicked()), fenetreAPropos, SLOT(exec()));
	connect(autre2, SIGNAL(clicked()), fenetreFusion, SLOT(exec()));
	connect(arraysBddB1, SIGNAL(clicked()), this, SLOT(fArraysBddB1()));
	connect(arraysBddB2, SIGNAL(clicked()), this, SLOT(fArraysBddB2()));
	connect(arraysBddB3, SIGNAL(clicked()), this, SLOT(fArraysBddB3()));
	connect(arraysBddB4, SIGNAL(clicked()), this, SLOT(fArraysBddB4()));
	connect(stringsBddB1, SIGNAL(clicked()), this, SLOT(fStringsBddB1()));
	connect(stringsBddB2, SIGNAL(clicked()), this, SLOT(fStringsBddB2()));
	connect(stringsBddB3, SIGNAL(clicked()), this, SLOT(fStringsBddB3()));
	connect(stringsBddB4, SIGNAL(clicked()), this, SLOT(fStringsBddB4()));
	connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));
	connect(shortcut1, SIGNAL(activated()), this, SLOT(enregistrementsDansApk()));
	connect(shortcut1, SIGNAL(activated()), this, SLOT(enregistrementsBdd()));
	connect(actionOuvrirApk, SIGNAL(triggered()), this, SLOT(getDossierApk()));
	connect(actionOuvrirFichiers, SIGNAL(triggered()), this, SLOT(getDossierFichiers()));
	connect(actionOuvrirBdd, SIGNAL(triggered()), this, SLOT(getAdresseBdd()));
	connect(actionOuvrirBddOrigine, SIGNAL(triggered()), this, SLOT(getAdresseBddOrigine()));
	connect(actionAllerAuDebut, SIGNAL(triggered()), this, SLOT(ASDebut()));
	connect(actionAllerALaFin, SIGNAL(triggered()), this, SLOT(ASFin()));
	connect(actionAvancer10, SIGNAL(triggered()), this, SLOT(ASPlus10()));
	connect(actionReculer10, SIGNAL(triggered()), this, SLOT(ASMoins10()));
}

std::string Fenetre::getLangue()
{
	if (langueVers->currentText() == "Anglais -> Français")
		return "fr";
	if (langueVers->currentText() == "Anglais -> Espagnol")
		return "es";
	if (langueVers->currentText() == "Anglais -> Allemand")
		return "de";
	return "fr";
}

void Fenetre::erreurNoDossierApk()
{
	QMessageBox::warning(this, "Erreur", "Ouvrez d'abord un dossier apk.");
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
	if (dossier != "")
	{
		t.setNomAppli(boutonAppliTrad->currentText().toStdString(), getLangue());
		t.setAdresseApk(dossier);
		bool reussite = t.traitement_ouverture_apk();
		if (!reussite)
		{
			QMessageBox::critical(this, "Erreur", "Le dossier spécifié ne contient pas de fichiers à traduire.\nAssurez-vous qu'il n'y est pas d'accent dans l'adresse du dossier.\nS'il contient un accent, déplacez le dossier autre part (à la racine du disque dur par exemple).\n\nAdresse du dossier : "+dossier);
		}
		else
		{
			t.creationEncours();
			fonctionATraduite->setText(t.getStringsFonctionATraduire());
			ligneDorigine->setText(t.getStringsLigneDOrigine());

			menuATraduite->setText(t.getArraysFonctionATraduire());
			lignesDansMenu = t.getArraysLignesATraduire();
			actualiserMenu();
			if(adresseApk->text() != "")
				lignesDuMenu->removeItemWidget(lignesDuMenu->takeItem(0));
			addLigneDOrigine(0);

			adresseApk->setText(dossier);
			nbLigneStrings->setText(QString::fromStdString(std::to_string(t.getPosStrings() + 1)) + "/" + QString::fromStdString(std::to_string(t.totalLigneStrings())));
			nbLigneArrays->setText(QString::fromStdString(std::to_string(t.getPosArrays() + 1)) + "/" + QString::fromStdString(std::to_string(t.totalLigneArrays())));
			lignesDuMenu->setCurrentRow(0);
		}
	}
}

void Fenetre::getDossierFichiers()
{
	QString fichierA = QFileDialog::getOpenFileName(this, "Ouvrir un fichier arrays.xml", QString(), "Fichier de traduction arrays (*.xml)");
	if (fichierA != "")
	{
		QString fichierS = QFileDialog::getOpenFileName(this, "Ouvrir un fichier strings.xml", QString(), "Fichier de traduction strings (*.xml)");
		if (fichierS != "")
		{
			t.setNomAppli(boutonAppliTrad->currentText().toStdString(), getLangue());
			t.setAdresseFichiers(fichierS, fichierA);
			t.traitement_ouverture_apk();
			t.creationEncours();
			fonctionATraduite->setText(t.getStringsFonctionATraduire());
			ligneDorigine->setText(t.getStringsLigneDOrigine());

			menuATraduite->setText(t.getArraysFonctionATraduire());
			lignesDansMenu = t.getArraysLignesATraduire();
			actualiserMenu();

			adresseApk->setText("Emplacements personnalisés");
			nbLigneStrings->setText(QString::fromStdString(std::to_string(t.getPosStrings() + 1)) + "/" + QString::fromStdString(std::to_string(t.totalLigneStrings())));
			nbLigneArrays->setText(QString::fromStdString(std::to_string(t.getPosArrays() + 1)) + "/" + QString::fromStdString(std::to_string(t.totalLigneArrays())));
			
		}
	}
}

void Fenetre::getAdresseBdd()
{
	QString fichierA = QFileDialog::getOpenFileName(this, "Ouvrir une bdd arrays", QString(), "Base de données (*.xml)");
	if (fichierA != "")
	{
		QString fichierS = QFileDialog::getOpenFileName(this, "Ouvrir une bdd strings", QString(), "Base de données (*.xml)");
		if(fichierS != "")
			t.setAdresseBdd(fichierS, fichierA);
	}
}

void Fenetre::getAdresseBddOrigine()
{
	t.setNomAppli(boutonAppliTrad->currentText().toStdString(), getLangue());
}

void Fenetre::btraduireAvecBdd()
{
	if (adresseApk->text() == "")
	{
		erreurNoDossierApk();
		getDossierApk();
	}
	else
	{
		bool reussite = t.traitement_ouverture_bdd();
		if (!reussite)
		{
			QMessageBox::critical(this, "Erreur", "La base de donnée n'a pas pu être ouverte ou n'existe pas.\nAssurez-vous qu'il n'y est pas d'accent dans l'adresse du dossier contenant les bases de données.\nAssurez-vous aussi que le dossier \"bdd\" est dans le dossier du programme.");
		}
		else
		{
			t.creationEncours();
			fonctionATraduite->setText(t.getStringsFonctionATraduire());
			ligneDorigine->setText(t.getStringsLigneDOrigine());
			menuATraduite->setText(t.getArraysFonctionATraduire());
			lignesDansMenu = t.getArraysLignesATraduire();
			actualiserMenu();
			lignesDuMenu->removeItemWidget(lignesDuMenu->takeItem(0));
			addLigneDOrigine(0);
			nbLigneStrings->setText(QString::fromStdString(std::to_string(t.getPosStrings() + 1)) + "/" + QString::fromStdString(std::to_string(t.totalLigneStrings())));
			nbLigneArrays->setText(QString::fromStdString(std::to_string(t.getPosArrays() + 1)) + "/" + QString::fromStdString(std::to_string(t.totalLigneArrays())));
		}
	}
}

void Fenetre::stringLignePrec()
{
	if (adresseApk->text() == "")
	{
		erreurNoDossierApk();
		getDossierApk();
	}
	else
	{
		t.setPosString(-1);
		fonctionATraduite->setText(t.getStringsFonctionATraduire());
		ligneDorigine->setText(t.getStringsLigneDOrigine());
		nbLigneStrings->setText(QString::fromStdString(std::to_string(t.getPosStrings() + 1)) + "/" + QString::fromStdString(std::to_string(t.totalLigneStrings())));
	}
}

void Fenetre::stringLigneSuiv()
{
	if (adresseApk->text() == "")
	{
		erreurNoDossierApk();
		getDossierApk();
	}
	else
	{
		QString temp = t.setTraductionString(ligneTraduite->text(), false);
		if (temp != "")
		{
			int reponse = QMessageBox::question(this, "Doublon", "Une autre traduction a été trouvé dans la base de donnée.\nVoulez-vous remplacer la traduction de la base de donnée ?\n\nTraduction de la base de donnée : " + temp + "\nVotre traduction : " + ligneTraduite->text(), QMessageBox::Yes | QMessageBox::No);
			if (reponse == QMessageBox::Yes)
			{
				temp = t.setTraductionString(ligneTraduite->text(), true);
			}
		}
		t.setPosString(+1);
		ligneTraduite->setText("");
		fonctionATraduite->setText(t.getStringsFonctionATraduire());
		ligneDorigine->setText(t.getStringsLigneDOrigine());
		nbLigneStrings->setText(QString::fromStdString(std::to_string(t.getPosStrings() + 1)) + "/" + QString::fromStdString(std::to_string(t.totalLigneStrings())));
	}
}

void Fenetre::stringLigneNoTrad()
{
	if (adresseApk->text() == "")
	{
		erreurNoDossierApk();
		getDossierApk();
	}
	else
	{
		t.setPosString(+1);
		fonctionATraduite->setText(t.getStringsFonctionATraduire());
		ligneDorigine->setText(t.getStringsLigneDOrigine());
		nbLigneStrings->setText(QString::fromStdString(std::to_string(t.getPosStrings() + 1)) + "/" + QString::fromStdString(std::to_string(t.totalLigneStrings())));
	}
}

void Fenetre::ASPlus10()
{
	if (adresseApk->text() == "")
	{
		erreurNoDossierApk();
		getDossierApk();
	}
	else
	{
		if (onglets->currentIndex() == 1)
		{
			t.setPosArrays(+10);
			menuATraduite->setText(t.getArraysFonctionATraduire());
			lignesDansMenu = t.getArraysLignesATraduire();
			actualiserMenu();
			lignesDuMenu->removeItemWidget(lignesDuMenu->takeItem(0));
			addLigneDOrigine(0);
			nbLigneArrays->setText(QString::fromStdString(std::to_string(t.getPosArrays() + 1)) + "/" + QString::fromStdString(std::to_string(t.totalLigneArrays())));
		}
		else
		{
			t.setPosString(+10);
			fonctionATraduite->setText(t.getStringsFonctionATraduire());
			ligneDorigine->setText(t.getStringsLigneDOrigine());
			nbLigneStrings->setText(QString::fromStdString(std::to_string(t.getPosStrings() + 1)) + "/" + QString::fromStdString(std::to_string(t.totalLigneStrings())));
		}
	}
}

void Fenetre::ASMoins10()
{
	if (adresseApk->text() == "")
	{
		erreurNoDossierApk();
		getDossierApk();
	}
	else
	{
		if (onglets->currentIndex() == 1)
		{
			t.setPosArrays(-10);
			menuATraduite->setText(t.getArraysFonctionATraduire());
			lignesDansMenu = t.getArraysLignesATraduire();
			actualiserMenu();
			lignesDuMenu->removeItemWidget(lignesDuMenu->takeItem(0));
			addLigneDOrigine(0);
			nbLigneArrays->setText(QString::fromStdString(std::to_string(t.getPosArrays() + 1)) + "/" + QString::fromStdString(std::to_string(t.totalLigneArrays())));
		}
		else
		{
			t.setPosString(-10);
			fonctionATraduite->setText(t.getStringsFonctionATraduire());
			ligneDorigine->setText(t.getStringsLigneDOrigine());
			nbLigneStrings->setText(QString::fromStdString(std::to_string(t.getPosStrings() + 1)) + "/" + QString::fromStdString(std::to_string(t.totalLigneStrings())));
		}
	}
}

void Fenetre::ASDebut()
{
	if (adresseApk->text() == "")
	{
		erreurNoDossierApk();
		getDossierApk();
	}
	else
	{
		if (onglets->currentIndex() == 1)
		{
			t.setPosArrays(-999999);
			menuATraduite->setText(t.getArraysFonctionATraduire());
			lignesDansMenu = t.getArraysLignesATraduire();
			actualiserMenu();
			lignesDuMenu->removeItemWidget(lignesDuMenu->takeItem(0));
			addLigneDOrigine(0);
			nbLigneArrays->setText(QString::fromStdString(std::to_string(t.getPosArrays() + 1)) + "/" + QString::fromStdString(std::to_string(t.totalLigneArrays())));
		}
		else
		{
			t.setPosString(-999999);
			fonctionATraduite->setText(t.getStringsFonctionATraduire());
			ligneDorigine->setText(t.getStringsLigneDOrigine());
			nbLigneStrings->setText(QString::fromStdString(std::to_string(t.getPosStrings() + 1)) + "/" + QString::fromStdString(std::to_string(t.totalLigneStrings())));
		}
	}
}

void Fenetre::ASFin()
{
	if (adresseApk->text() == "")
	{
		erreurNoDossierApk();
		getDossierApk();
	}
	else
	{
		if (onglets->currentIndex() == 1)
		{
			t.setPosArrays(+999999);
			menuATraduite->setText(t.getArraysFonctionATraduire());
			lignesDansMenu = t.getArraysLignesATraduire();
			actualiserMenu();
			lignesDuMenu->removeItemWidget(lignesDuMenu->takeItem(0));
			addLigneDOrigine(0);
			nbLigneArrays->setText(QString::fromStdString(std::to_string(t.getPosArrays() + 1)) + "/" + QString::fromStdString(std::to_string(t.totalLigneArrays())));
		}
		else
		{
			t.setPosString(+999999);
			fonctionATraduite->setText(t.getStringsFonctionATraduire());
			ligneDorigine->setText(t.getStringsLigneDOrigine());
			nbLigneStrings->setText(QString::fromStdString(std::to_string(t.getPosStrings() + 1)) + "/" + QString::fromStdString(std::to_string(t.totalLigneStrings())));
		}
	}
}

void Fenetre::ajouterTradLigneArrays()
{
	if (adresseApk->text() == "")
	{
		erreurNoDossierApk();
		getDossierApk();
	}
	else
	{
		if (ligneTraduiteM->text() != "")
		{
			lignesDansMenu[lignesDuMenu->currentRow()] = ligneTraduiteM->text();
			lignesDuMenu->removeItemWidget(lignesDuMenu->takeItem(lignesDuMenu->currentRow()));
			lignesDuMenu->insertItem(lignesDuMenu->currentRow(), ligneTraduiteM->text());
			lignesDuMenu->item(lignesDuMenu->currentRow() - 1)->setBackgroundColor("#50FF50");
			ligneTraduiteM->setText("");
		}
		if (lignesDuMenu->currentRow() < lignesDansMenu.size())
			lignesDuMenu->setCurrentRow(lignesDuMenu->currentRow());
	}
}

void Fenetre::arraysLignePrec()
{
	if (adresseApk->text() == "")
	{
		erreurNoDossierApk();
		getDossierApk();
	}
	else
	{
		t.setPosArrays(-1);
		menuATraduite->setText(t.getArraysFonctionATraduire());
		lignesDansMenu = t.getArraysLignesATraduire();
		actualiserMenu();
		lignesDuMenu->removeItemWidget(lignesDuMenu->takeItem(0));
		addLigneDOrigine(0);
		
		nbLigneArrays->setText(QString::fromStdString(std::to_string(t.getPosArrays()+1))+"/"+QString::fromStdString(std::to_string(t.totalLigneArrays())));
	}
}

void Fenetre::arraysLigneSuiv()
{
	if (adresseApk->text() == "")
	{
		erreurNoDossierApk();
		getDossierApk();
	}
	else
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
		nbLigneArrays->setText(QString::fromStdString(std::to_string(t.getPosArrays()+1)) + "/" + QString::fromStdString(std::to_string(t.totalLigneArrays())));
	}
}

void Fenetre::enregistrementsDansApk()
{
	if (adresseApk->text() == "")
	{
		erreurNoDossierApk();
		getDossierApk();
	}
	else
	{
		std::string temp = getLangue();
		t.enregistrementStringxml(adresseApk->text().toStdString() + "/res/values-" + temp + "/strings.xml");
		t.enregistrementArraysxml(adresseApk->text().toStdString() + "/res/values-" + temp + "/arrays.xml");
	}
}

void Fenetre::enregistrementsSous()
{
	if (adresseApk->text() == "")
	{
		erreurNoDossierApk();
		getDossierApk();
	}
	else
	{
		QString dossier = QFileDialog::getExistingDirectory(this, "Dossier d'enregistrement des fichiers arrays.xml et strings.xml traduits");
		t.enregistrementStringxml(dossier.toStdString() + "/strings.xml");
		t.enregistrementArraysxml(dossier.toStdString() + "/arrays.xml");
	}
}

void Fenetre::enregistrementsBdd()
{
	if (adresseApk->text() == "")
	{
		erreurNoDossierApk();
		getDossierApk();
	}
	else
	{
		std::string temp = getLangue();
		t.enregistrementBddStringxml("bdd/" + boutonAppliTrad->currentText().toStdString() + "_" + temp + "_strings.xml");
		t.enregistrementBddArraysxml("bdd/" + boutonAppliTrad->currentText().toStdString() + "_" + temp + "_arrays.xml");
	}
}

void Fenetre::enregistrementsBddSous()
{
	if (adresseApk->text() == "")
	{
		erreurNoDossierApk();
		getDossierApk();
	}
	else
	{
		std::string temp = getLangue();
		QString dossier = QFileDialog::getExistingDirectory(this, "Dossier d'enregistrement des bases de données");
		t.enregistrementBddStringxml(dossier.toStdString() + "/" + boutonAppliTrad->currentText().toStdString() + "_" + temp + "_strings.xml");
		t.enregistrementBddArraysxml(dossier.toStdString() + "/" + boutonAppliTrad->currentText().toStdString() + "_" + temp + "_arrays.xml");
	}
}

void Fenetre::fArraysBddB1()
{
	QString fichier = QFileDialog::getOpenFileName(this, "Ouvrir la base de données 1", QString(), "Base de données (*.xml)");
	if (fichier != "")
	{
		arraysBddT1->setText(fichier);
	}
}

void Fenetre::fArraysBddB2()
{
	QString fichier = QFileDialog::getOpenFileName(this, "Ouvrir la base de données 2", QString(), "Base de données (*.xml)");
	if (fichier != "")
	{
		arraysBddT2->setText(fichier);
	}
}

void Fenetre::fArraysBddB3()
{
	QString dossier = QFileDialog::getExistingDirectory(this, "Ouvrir un dossier pour enregistrer la base de données fusionné");
	if (dossier != "")
	{
		arraysBddT3->setText(dossier + "/VenomTweaks_fr_arrays.xml");
	}
}

void Fenetre::fArraysBddB4()
{
	if(arraysBddT1->text() == "" || arraysBddT2->text() == "" || arraysBddT3->text() == "")
		QMessageBox::critical(this, "Erreur", "Assurez-vous d'avoir rempli les 3 adresses au-dessus du bouton \"Démarrer la fusion\"");
	else
	{
		std::vector<std::vector<std::string>> question;
		std::vector<std::string> question1, question2;
		int reponse;
		std::string texte;
		int gardeQui = 0;
		bool oui_pour_tout = false;
		do
		{
			question = t.fusionArrays(arraysBddT1->text(), arraysBddT2->text(), arraysBddT3->text(), gardeQui);
			if (question[0][0] != "FFIINN")
			{
				if (!oui_pour_tout)
				{
					if (question[1].size() > question[2].size())
					{
						question1 = question[1];
						question2 = question[2];
						texte = "Un doublon a été trouvé. Choisir \"Oui\" si le premier menu vous convient, sinon choisir \"Non\".\n" + question[0][0] + "\nMenu 1 | Menu 2\n";
					}
					else
					{
						question1 = question[2];
						question2 = question[1];
						texte = "Un doublon a été trouvé. Choisir \"Oui\" si le premier menu vous convient, sinon choisir \"Non\".\n" + question[0][0] + "\nMenu 2 | Menu 1\n";
					}
					for (int i = 0; i < question1.size(); i++)
					{
						texte += question1[i] + "  |  ";
						if (i < question2.size())
						{
							texte += question2[i];
						}
						else
						{
							texte += "Erreur : Pas de traduction";
						}
						texte += "\n";
					}

					reponse = QMessageBox::question(this, "Doublon", QString::fromStdString(texte), QMessageBox::YesToAll | QMessageBox::Yes | QMessageBox::No | QMessageBox::NoToAll);
					if (reponse == QMessageBox::Yes)
					{
						gardeQui = 1;
					}
					else if (reponse == QMessageBox::No)
					{
						gardeQui = 2;
					}
					else if (reponse == QMessageBox::YesToAll)
					{
						gardeQui = 1;
						oui_pour_tout = true;
					}
					else if (reponse == QMessageBox::NoToAll)
					{
						gardeQui = 2;
						oui_pour_tout = true;
					}
				}
			}
		} while (question[0][0] != "FFIINN");
		QMessageBox::information(this, "Réussite", "La fusion est terminé !");
	}
}

void Fenetre::fStringsBddB1()
{
	QString fichier = QFileDialog::getOpenFileName(this, "Ouvrir la base de données 1", QString(), "Base de données (*.xml)");
	if (fichier != "")
	{
		stringsBddT1->setText(fichier);
	}
}

void Fenetre::fStringsBddB2()
{
	QString fichier = QFileDialog::getOpenFileName(this, "Ouvrir la base de données 2", QString(), "Base de données (*.xml)");
	if (fichier != "")
	{
		stringsBddT2->setText(fichier);
	}
}

void Fenetre::fStringsBddB3()
{
	QString dossier = QFileDialog::getExistingDirectory(this, "Ouvrir un dossier pour enregistrer la base de données fusionné");
	if (dossier != "")
	{
		stringsBddT3->setText(dossier + "/VenomTweaks_fr_strings.xml");
	}
}

void Fenetre::fStringsBddB4()
{
	if (stringsBddT1->text() == "" || stringsBddT2->text() == "" || stringsBddT3->text() == "")
		QMessageBox::critical(this, "Erreur", "Assurez-vous d'avoir rempli les 3 adresses au-dessus du bouton \"Démarrer la fusion\"");

	else
	{
		std::vector<std::string> question;
		std::string question1, question2;
		int reponse;
		std::string texte;
		int gardeQui = 0;
		bool oui_pour_tout = false;
		do
		{
			question = t.fusionStrings(stringsBddT1->text(), stringsBddT2->text(), stringsBddT3->text(), gardeQui);

			if (question[0] != "FFIINN")
			{
				if (!oui_pour_tout)
				{
					texte = "Un doublon a été trouvé. Choisir \"Oui\" si le premier menu vous convient, sinon choisir \"Non\".\n" + question[0] + "\nTrad 1 | Trad 2\n";
					texte += question[1] + "  |  " + question[2] + "\n";

					reponse = QMessageBox::question(this, "Doublon", QString::fromStdString(texte), QMessageBox::YesToAll | QMessageBox::Yes | QMessageBox::No | QMessageBox::NoToAll);
					if (reponse == QMessageBox::Yes)
					{
						gardeQui = 1;
					}
					else if (reponse == QMessageBox::No)
					{
						gardeQui = 2;
					}
					else if (reponse == QMessageBox::YesToAll)
					{
						gardeQui = 1;
						oui_pour_tout = true;
					}
					else if (reponse == QMessageBox::NoToAll)
					{
						gardeQui = 2;
						oui_pour_tout = true;
					}
				}
			}

		} while (question[0] != "FFIINN");
		QMessageBox::information(this, "Réussite", "La fusion est terminé !");
	}
}

void Fenetre::closeEvent(QCloseEvent* event) 
{
	if (adresseApk->text() != "")
	{
		int reponse = QMessageBox::question(this, "Fermeture du programme", "Voulez-vous vraiment quitter ?\nAssurez-vous d'avoir sauvegardé votre travail !", QMessageBox::Yes | QMessageBox::No);

		if (reponse == QMessageBox::Yes)
			event->accept();

		else
			event->ignore();
	}
	else
	{
		event->accept();
	}
}