#ifndef __fonctions_h__
#define __fonctions_h__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include <libpq-fe.h>
#include <time.h>

typedef	struct date{
	unsigned int jour;
	unsigned int mois;
	unsigned int annee;
}DATE;

DATE dat;

GtkWidget *label[8], *pWindow, *pTable, *pButton[42]; 	// variables de la fonction forme calendrier

GtkWidget *fen[2], *box[2], *entree[11], *lab[11], *bouton[2];	// variables des fonctions add_even et search_date

int diference_jour(int, int, int);
int bissextile(int);
int colorer(DATE);

char * jour_correspondant(int);
char * date_char(DATE);
char* reponse_BD(PGconn*);

void lancer(GtkWidget, gpointer);
void Detruire(GtkWidget *, gpointer);
void forme_calendrier(DATE);
void rechercher_date(GtkWidget, gpointer);
void ajouter_even(GtkWidget, gpointer);
void mois_suiv(GtkWidget, gpointer);
void mois_prec(GtkWidget, gpointer);
void Aujourd(GtkWidget, gpointer);
void on_quitte_btn(GtkWidget*, gpointer);
void Valider(GtkWidget*, gpointer);
void Suppression_BD(PGconn*);
void Ajout(GtkWidget *, gpointer);

PGconn *Connexion();

DATE 	date_systeme();

#endif
