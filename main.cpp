/*
  --------------------------------------------------------------------------------------
  Fichier     : main.cpp
  Nom du labo : Laboratoire 03
  Auteur(s)   : Pasche Jonathan
  Date        : 26.10.2020
  But         :

  Remarque(s) :

  Compilateur : Mingw-w64 g++
  ---------------------------------------------------------------------------------------
*/
#include <iostream>
#include <iomanip>
#include <string>

#define VIDER_BUFFER 	cin.ignore(numeric_limits<streamsize>::max(), '\n')
#define ERREUR_SAISIE 	cout << "Une erreur de saisie est survenue" << endl \
								<< endl << "Presser ENTER pour quitter"; \
								VIDER_BUFFER; cin.get(); return EXIT_SUCCESS

using namespace std;

int main() {
	/*********************************************/
	//Initialisation des Variables et Constantes
	/*********************************************/
	//Initalisation et déclaration des constantes

	const int 	 HEURE_JOUR_FIN			= 20;

	//Initalisation et declaration des variables de saisie
	char continuer = 'O';


	/*********************************************/
	//Affichage des prix des elements
	/*********************************************/

	cout << "Bonjour," << endl
		  << "Un programme qui calcule le prix d une course en taxi en Euros" << endl
		  << "Voici les conditions" 	<< endl
		  << "=====================" 	<< endl;


	/*****************************************/
	// Demande de saisie des valeurs
	/*****************************************/
	do {
		VIDER_BUFFER;
		cout << PUCE_AVEC_ESPACE + "nbre de bagage     " << "[" << NB_BAGAGES_MIN
			  << PUCE << NB_BAGAGES_MAX << "]" << CARACTERE_ESPACE
			  << CARACTERE_SEPARATION << CARACTERE_ESPACE;
		cin >> nbrBagages;
		if(nbrBagages < NB_BAGAGES_MIN or nbrBagages > NB_BAGAGES_MAX){
			ERREUR_SAISIE;
		}

	}
	while (continuer != 'N');

	/************************************************/
	// Calcul des totaux et affichage des resultats
	/************************************************/





	cout << "Merci de votre visite " << endl << endl
		  << "Presser ENTER pour quitter";
	cin.get();

	return EXIT_SUCCESS;
}