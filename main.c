#include "fonctions.h"

int main(int argc, char **argv){

		// r�cup�ration de la date du syst�me
	dat = date_systeme();

		// v�rification des fonction date_systeme & date_char
	printf("%d/%d/%d\n",dat.jour, dat.mois,dat.annee);
	printf("%s\n", date_char(dat));

		//initialisation de gtk
	gtk_init(&argc,&argv);

    //printf("%d",reponse_BD(Connexion()));
		// appel de la fonction affichage de calendrier
	forme_calendrier(dat);

	return EXIT_SUCCESS;
}
