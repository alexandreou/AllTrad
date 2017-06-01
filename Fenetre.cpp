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
	setWindowTitle("All Trad v0.8");
	QGridLayout *layoutOption = new QGridLayout;
	layoutOption->setContentsMargins(0, 0, 0, 20);
	QPushButton *traduireAvecBdd = new QPushButton("Traduire avec la base de données");
	traduireAvecBdd->setMinimumHeight(40);

	QLabel *logo = new QLabel;
	logo->setPixmap(QPixmap("files/logo.png"));

	QGridLayout *layoutOption1 = new QGridLayout;
	layoutOption1->setContentsMargins(0, 0, 20, 0);
	QComboBox *boutonAppliTrad = new QComboBox;
	boutonAppliTrad->addItem("VenomTweaks.apk");
	//boutonAppliTrad->addItem("VenomHUB.apk");
	//boutonAppliTrad->addItem("VenomSideBar.apk");
	//boutonAppliTrad->addItem("VenomPie.apk");
	QComboBox *langueVers = new QComboBox;
	langueVers->addItem("Anglais -> Français");
	//langueVers->addItem("Anglais -> Espagnol");
	QPushButton *ouvrirApk = new QPushButton("Ouvrir le dossier de l'apk décompilé");
	QPushButton *ouvrirAutreBdd = new QPushButton("Ouvrir une autre base de données");

	QGridLayout *layoutOption2 = new QGridLayout;
	layoutOption2->setContentsMargins(20, 0, 0, 0);
	QPushButton *enregistrerFichiers = new QPushButton("Enregistrer les fichiers traduits sous");
	QPushButton *enregistrerApk = new QPushButton("Enregistrer les fichiers traduits");
	QPushButton *enregistrerBddSous = new QPushButton("Enregistrer la base de données sous");
	QPushButton *enregistrerBdd = new QPushButton("Enregistrer la base de données");


	QTabWidget *onglets = new QTabWidget;
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
	QPushButton *autre3 = new QPushButton;
	QPushButton *autre4 = new QPushButton;
	QPushButton *autre5 = new QPushButton;

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
	QLabel *texte = new QLabel("Logiciel de traduction d'apks. Créé par Alexandreou.");
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
	QPushButton *arraysBddB2 = new QPushButton("Fichier de base de données 2");
	arraysBddT2 = new QLineEdit;
	QPushButton *arraysBddB3 = new QPushButton("Dossier d'enregistrement");
	arraysBddT3 = new QLineEdit;
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
	QPushButton *stringsBddB2 = new QPushButton("Fichier de base de données 2");
	stringsBddT2 = new QLineEdit;
	QPushButton *stringsBddB3 = new QPushButton("Dossier d'enregistrement");
	stringsBddT3 = new QLineEdit;
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

			adresseApk->setText(dossier);
			nbLigneStrings->setText(QString::fromStdString(std::to_string(t.getPosStrings() + 1)) + "/" + QString::fromStdString(std::to_string(t.totalLigneStrings())));
			nbLigneArrays->setText(QString::fromStdString(std::to_string(t.getPosArrays() + 1)) + "/" + QString::fromStdString(std::to_string(t.totalLigneArrays())));
		}
	}
}

void Fenetre::getAdresseBdd()
{
	QString fichierS = QFileDialog::getOpenFileName(this, "Ouvrir une bdd string", QString(), "Base de données (*.xml)");
	if (fichierS != "")
	{
		QString fichierA = QFileDialog::getOpenFileName(this, "Ouvrir une bdd arrays", QString(), "Base de données (*.xml)");
		if(fichierA != "")
			t.setAdresseBdd(fichierS, fichierA);
	}
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
		t.enregistrementStringxml(adresseApk->text().toStdString() + "/res/values-fr/strings.xml");
		t.enregistrementArraysxml(adresseApk->text().toStdString() + "/res/values-fr/arrays.xml");
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
		t.enregistrementBddStringxml("bdd/VenomTweaks_fr_strings.xml");
		t.enregistrementBddArraysxml("bdd/VenomTweaks_fr_arrays.xml");
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
		QString dossier = QFileDialog::getExistingDirectory(this, "Dossier d'enregistrement des bases de données");
		t.enregistrementBddStringxml(dossier.toStdString() + "/VenomTweaks_fr_strings.xml");
		t.enregistrementBddArraysxml(dossier.toStdString() + "/VenomTweaks_fr_arrays.xml");
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
	std::vector<std::vector<std::string>> question;
	std::vector<std::string> question1, question2;
	int reponse;
	std::string texte;
	int gardeQui = 0;
	do
	{
		question = t.fusionArrays(arraysBddT1->text(), arraysBddT2->text(), arraysBddT3->text(), gardeQui);
		if (question[0][0] != "FFIINN")
		{
			if (question[1].size() > question[2].size())
			{
				question1 = question[1];
				question2 = question[2];
			}
			else
			{
				question1 = question[2];
				question2 = question[1];
			}
			texte = "Un doublon a été trouvé. Choisir \"Oui\" si le premier menu vous convient, sinon choisir \"Non\".\n" + question[0][0] + "\nMenu 1 | Menu 2\n";
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

			reponse = QMessageBox::question(this, "Doublon", QString::fromStdString(texte), QMessageBox::Yes | QMessageBox::No);
			if (reponse == QMessageBox::Yes)
			{
				gardeQui = 1;
			}
			else if (reponse == QMessageBox::No)
			{
				gardeQui = 2;
			}
		}

	} while (question[0][0] != "FFIINN");
	QMessageBox::information(this, "Réussite", "La fusion est terminé !");
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
	std::vector<std::string> question;
	std::string question1, question2;
	int reponse;
	std::string texte;
	int gardeQui = 0;
	do
	{
		question = t.fusionStrings(stringsBddT1->text(), stringsBddT2->text(), stringsBddT3->text(), gardeQui);

		if (question[0] != "FFIINN")
		{
			texte = "Un doublon a été trouvé. Choisir \"Oui\" si le premier menu vous convient, sinon choisir \"Non\".\n" + question[0] + "\nTrad 1 | Trad 2\n";
			texte += question[1] + "  |  "+ question[2] + "\n";

			reponse = QMessageBox::question(this, "Doublon", QString::fromStdString(texte), QMessageBox::Yes | QMessageBox::No);
			if (reponse == QMessageBox::Yes)
			{
				gardeQui = 1;
			}
			else if (reponse == QMessageBox::No)
			{
				gardeQui = 2;
			}
		}

	} while (question[0] != "FFIINN");
	QMessageBox::information(this, "Réussite", "La fusion est terminé !");
}