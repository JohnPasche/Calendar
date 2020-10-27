/*
  --------------------------------------------------------------------------------------
  Fichier     : main.cpp
  Nom du labo : Laboratoire 03
  Auteur(s)   : Pasche Jonathan, Renaud Gregory
  Date        : 26.10.2020
  But         : Afficher les grilles de calendrier pour une annee donnee

  Remarque(s) :

  Compilateur : Mingw-w64 g++
  ---------------------------------------------------------------------------------------
*/
#include <iostream>
#include <iomanip>
#include <string>

#define VIDER_BUFFER   cin.ignore(numeric_limits<streamsize>::max(), '\n')
#define ERREUR_SAISIE   cout << "Une erreur de saisie est survenue" << endl \
                        << endl << "Presser ENTER pour quitter"; \
                        VIDER_BUFFER; cin.get(); return EXIT_SUCCESS

#define AFFICHE_NOM_DU_MOIS   switch(mois) \
                              {\
                                 case enumMois::Janvier:\
                                    cout << "Janvier"; \
                                    nbJours = 31;\
                                    break;\
                                 case  enumMois::Fevrier:\
                                    cout << "Fevrier";\
                                    nbJours = (anneeChoisie%400==0)||((anneeChoisie%4==0) && (anneeChoisie%100!=0)) ? 29 : 30 ;\
                                    break;\
                                 case  enumMois::Mars:\
                                    cout << "Mars";\
                                    nbJours = 31;\
                                    break;\
                                 case  enumMois::Avril:\
                                    cout << "Avril";  \
                                    nbJours = 30;\
                                    break;\
                                 case  enumMois::Mai:\
                                    cout << "Mai";\
                                    nbJours = 31;\
                                    break;\
                                 case  enumMois::Juin:\
                                    cout << "Juin"; \
                                    nbJours = 30;\
                                    break;\
                                 case  enumMois::Juillet:\
                                    cout << "Juillet";\
                                    nbJours = 31;\
                                    break;\
                                 case  enumMois::Aout:\
                                    cout << "Aout";\
                                    nbJours = 31;\
                                    break;\
                                 case  enumMois::Septembre:\
                                    cout << "Septembre";\
                                    nbJours = 30;\
                                    break;\
                                 case  enumMois::Octobre:\
                                    cout << "Octobre"; \
                                    nbJours = 31;\
                                    break;\
                                 case  enumMois::Novembre:\
                                    cout << "Novembre"; \
                                    nbJours = 30;\
                                    break;\
                                 case  enumMois::Decembre:\
                                    cout << "Decembre";\
                                    nbJours = 31;\
                                    break;\
                                 default:\
                                    cout << "42 Error";           \
                                    nbJours = 0;\
                                    break;\
                              }

#define AFFICHE_LETTRE_JOUR   switch(nomJour) \
                              {\
                                 case enumJours::Lundi:\
                                    cout << "L";\
                                    break;\
                                 case  enumJours::Mardi:\
                                    cout << "M";\
                                    break;\
                                 case  enumJours::Mercredi:\
                                    cout << "M";\
                                    break;\
                                 case  enumJours::Jeudi:\
                                    cout << "J";\
                                    break;\
                                 case  enumJours::Vendredi:\
                                    cout << "V";\
                                    break;\
                                 case  enumJours::Samedi:\
                                    cout << "S";\
                                    break;\
                                 case  enumJours::Dimanche:\
                                    cout << "D";\
                                    break;\
                                 default:\
                                    cout << "42 Error";\
                                    break;\
                              }

using namespace std;

enum class enumJours {
	Lundi = 1,
	Mardi,
	Mercredi,
	Jeudi,
	Vendredi,
	Samedi,
	Dimanche
};
enum class enumMois {
	Janvier = 1,
	Fevrier,
	Mars,
	Avril,
	Mai,
	Juin,
	Juillet,
	Aout,
	Septembre,
	Octobre,
	Novembre,
	Decembre
};


int main() {
	/*********************************************/
	//Initialisation des Variables et Constantes
	/*********************************************/

	//Initalisation et declaration des variables de saisie
	char continuer = 'O';
	bool saisieValidee = 0;
	int nbJours;
	int dernierJourDuMois = 0;
	int postitionJourSemaine;
	int anneeChoisie;
	int jour;

	/*********************************************/
	//Affichage de l'entete
	/*********************************************/

	cout << "Bonjour," << endl
		  << "Un programme qui affiche un calendrier annuel" << endl;

	/*****************************************/
	// Demande de saisie des valeurs
	/*****************************************/
	do {
		/*****************************************/
		// Demande de saisie de l'année
		/*****************************************/
		do {
			saisieValidee = 0;
			cout << "Entrer une valeur [1900-2100] :";
			cin >> anneeChoisie;
			VIDER_BUFFER;
			if (cin.fail() || anneeChoisie < 1900 || anneeChoisie > 2100) {
				cout << endl << "/!\\ Recommencer" << endl;
			} else {
				saisieValidee = 1;
			}
			cin.clear();
		} while (!saisieValidee);
		/**************************************************/


		/*********************************************************************/
		// Pour chaque mois
		for (int m = 1; m <= 12; m++) {
			enumMois mois = enumMois(m);
			AFFICHE_NOM_DU_MOIS;
			cout << " " << anneeChoisie << endl;

			//Set de la position du jour de la semaine du nouveau mois
			postitionJourSemaine = dernierJourDuMois + 1;
			jour = 1;

			//Liste des initiales de jours
			for (int j = 1; j <= 7; j++) {
				enumJours nomJour = enumJours(j);
				cout << setw(2);
				AFFICHE_LETTRE_JOUR;
				cout << " ";
			}
			cout << endl;

			//Pour chaque case du calendrier du mois
			for (int c = 1; c <= nbJours + dernierJourDuMois; c++) {
				//Affiche vide si jour dans l'ancien mois
				if (c <= dernierJourDuMois) {
					cout << setw(2) << " ";
				} else {
					cout << setw(2) << jour;
					postitionJourSemaine++; // On decale le pointeur de jour
					jour++;
				}
				cout << " ";

				if (!(c % 7)) {
					postitionJourSemaine = 0;
					cout << endl;
				}
			}
			dernierJourDuMois = postitionJourSemaine;
			cout << endl << endl;
		}

		/*********************************************************************/
		/****************************************************/
		// Demande de saisie si l'utilisateur veux recommencer
		/****************************************************/
		do {
			saisieValidee = 0;
			cout << "voulez-vous recommencer [O/N] ";
			cin >> continuer;
			VIDER_BUFFER;
			if (cin.fail() || (continuer != 'O' && continuer != 'N')) {
				cout << endl << "/!\\ recommencer" << endl;
			} else {
				saisieValidee = 1;
			}
			cin.clear();
		} while (!saisieValidee);
	} while (continuer != 'N');


	cout << "Merci de votre visite " << endl << endl
		  << "Presser ENTER pour quitter";
	cin.get();

	return EXIT_SUCCESS;
}