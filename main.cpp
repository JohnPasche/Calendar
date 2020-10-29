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
#include <cstdlib>
#include <string>

#define VIDER_BUFFER   cin.clear();\
                        cin.ignore(numeric_limits<streamsize>::max(), '\n')

#define RECUPERE_NOM_JOURS_DU_MOIS   switch(moisCourrant) \
                                    {\
                                       case enumMois::Janvier:\
                                          nomMoisCourrant = "Janvier"; \
                                          nbJoursMoisCourrant = 31;\
                                          break;\
                                       case  enumMois::Fevrier:\
                                          nomMoisCourrant = "Fevrier";\
                                          nbJoursMoisCourrant = (anneeChoisie%400==0)||((anneeChoisie%4==0) && (anneeChoisie%100!=0)) ? 29 : 28 ;\
                                          break;\
                                       case  enumMois::Mars:\
                                          nomMoisCourrant = "Mars";\
                                          nbJoursMoisCourrant = 31;\
                                          break;\
                                       case  enumMois::Avril:\
                                          nomMoisCourrant = "Avril";  \
                                          nbJoursMoisCourrant = 30;\
                                          break;\
                                       case  enumMois::Mai:\
                                          nomMoisCourrant = "Mai";\
                                          nbJoursMoisCourrant = 31;\
                                          break;\
                                       case  enumMois::Juin:\
                                          nomMoisCourrant = "Juin"; \
                                          nbJoursMoisCourrant = 30;\
                                          break;\
                                       case  enumMois::Juillet:\
                                          nomMoisCourrant = "Juillet";\
                                          nbJoursMoisCourrant = 31;\
                                          break;\
                                       case  enumMois::Aout:\
                                          nomMoisCourrant = "Aout";\
                                          nbJoursMoisCourrant = 31;\
                                          break;\
                                       case  enumMois::Septembre:\
                                          nomMoisCourrant = "Septembre";\
                                          nbJoursMoisCourrant = 30;\
                                          break;\
                                       case  enumMois::Octobre:\
                                          nomMoisCourrant = "Octobre"; \
                                          nbJoursMoisCourrant = 31;\
                                          break;\
                                       case  enumMois::Novembre:\
                                          nomMoisCourrant = "Novembre"; \
                                          nbJoursMoisCourrant = 30;\
                                          break;\
                                       case  enumMois::Decembre:\
                                          nomMoisCourrant = "Decembre";\
                                          nbJoursMoisCourrant = 31;\
                                          break;\
                                       default:\
                                          nomMoisCourrant = "42 Error";\
                                          nbJoursMoisCourrant = 42;\
                                          break;\
                                    }

#define AFFICHE_LETTRE_JOUR   switch(nomJour) \
                              {\
                                 case   enumJours::Lundi:\
                                    cout << "L";\
                                    break;\
                                 case  enumJours::Mardi:\
                                 case   enumJours::Mercredi:\
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

/*******************************************/
// Declaration des enums
/*******************************************/
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
	//Initialisation des Variables et constantes
	/*********************************************/

	//Constantes
	const int NB_MOIS_PAR_AN = 12;
	const int NB_JOURS_PAR_SEMAINE = 7;

	const int ANNEE_MIN = 1900;
	const int ANNEE_MAX = 2100;

	const int TAILLE_CASE = 2;

	//Variables
	char continuer = 'O';
	bool saisieValidee;
	int nbJoursMoisCourrant;
	string nomMoisCourrant;
	int dernierJourDuMois = 0;
	int postitionJourSemaine;
	int anneeChoisie;
	int jour;

	/*********************************************/
	//Affichage de l'entete
	/*********************************************/

	cout << "Bonjour," << endl
		  << "Je suis un programme qui affiche un calendrier annuel pour une annee donnee" << endl;

	/*****************************************/
	// Demande de saisie des valeurs
	/*****************************************/
	do {
		/*****************************************/
		// Demande de saisie de l'année
		/*****************************************/
		do {
			saisieValidee = 0;
			cout << "Entrer une valeur [" << ANNEE_MIN << "-" << ANNEE_MAX << "] :";
			cin >> anneeChoisie;

			if (cin.fail() || (anneeChoisie < ANNEE_MIN || anneeChoisie > ANNEE_MAX)) {
				cout << endl << "/!\\ Recommencer" << endl;
			} else {
				saisieValidee = 1;
			}
			VIDER_BUFFER;
		} while (!saisieValidee);
		/**************************************************/


		/*********************************************************************/
		// Pour chaque mois
		for (int m = 1; m <= NB_MOIS_PAR_AN; m++) {
			enumMois moisCourrant = enumMois(m);
			RECUPERE_NOM_JOURS_DU_MOIS;
			cout << nomMoisCourrant << " " << anneeChoisie << endl;

			//Set de la position du jour de la semaine du nouveau mois
			postitionJourSemaine = dernierJourDuMois + 1;
			jour = 1;

			//Liste des initiales de jours
			for (int j = 1; j <= NB_JOURS_PAR_SEMAINE; j++) {
				enumJours nomJour = enumJours(j);
				cout << setw(TAILLE_CASE);
				AFFICHE_LETTRE_JOUR;
				cout << " ";
			}
			cout << endl;

			//Pour chaque case du calendrier du mois
			for (int c = 1; c <= nbJoursMoisCourrant + dernierJourDuMois; c++) {
				//Affiche vide si jour dans l'ancien mois
				if (c <= dernierJourDuMois) {
					cout << setw(TAILLE_CASE) << " ";
				} else {
					cout << setw(TAILLE_CASE) << jour;
					postitionJourSemaine++; // On decale le pointeur de jour
					jour++;
				}
				cout << " ";

				if (!(c % NB_JOURS_PAR_SEMAINE)) {
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
			if (cin.fail() || (continuer != 'O' && continuer != 'N')) {
				cout << endl << "/!\\ recommencer" << endl;
			} else {
				saisieValidee = 1;
			}
			VIDER_BUFFER;
		} while (!saisieValidee);
	} while (continuer != 'N');


	cout << "Merci de votre visite " << endl << endl
		  << "Presser ENTER pour quitter";
	cin.get();

	return EXIT_SUCCESS;
}