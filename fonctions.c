#include "fonctions.h"


PGconn *Connexion(){
    PGconn* dbconn;
    dbconn = PQsetdbLogin( "localhost", "5433" , " " , " " , "Projet" , "postgres" , "root123" );
    return dbconn;
}

  void Valider(GtkWidget* widget, gpointer data){
//  GtkWidget* pEntry;
  const gchar* FText[20];
  FText[3]= gtk_entry_get_text(GTK_ENTRY(entree[3]));
  FText[4]= gtk_entry_get_text(GTK_ENTRY(entree[4]));
  FText[5]= gtk_entry_get_text(GTK_ENTRY(entree[5]));
  FText[6]= gtk_entry_get_text(GTK_ENTRY(entree[6]));
  FText[7]= gtk_entry_get_text(GTK_ENTRY(entree[7]));
  FText[8]= gtk_entry_get_text(GTK_ENTRY(entree[8]));
  FText[9]= gtk_entry_get_text(GTK_ENTRY(entree[9]));
  //FText[10]= gtk_entry_get_text(GTK_LABEL(bouton[1]));

  char res[700];

  strcpy(res,"INSERT INTO Evenement VALUES('");
  strcat(res,FText[3]);
  strcat(res,"','");
  strcat(res,FText[4]);
  strcat(res,"','");
  strcat(res,FText[5]);
  strcat(res,"','");
  strcat(res,FText[6]);
  strcat(res,"','");
  strcat(res,FText[7]);
  strcat(res,"','");
  strcat(res,FText[8]);
  strcat(res,"','");
  strcat(res,FText[9]);
  strcat(res,"')");

  PQexec(Connexion(),res);
  }
void on_quitte_btn(GtkWidget* widget , gpointer data){
    GtkWidget* pQuestion;
    pQuestion = gtk_message_dialog_new(GTK_WINDOW(data),GTK_DIALOG_MODAL,GTK_MESSAGE_QUESTION,GTK_BUTTONS_YES_NO,
                                                   "Voulez Vraiment\nQuiter ce Programme?");
    switch(gtk_dialog_run(GTK_DIALOG(pQuestion))){
      case GTK_RESPONSE_YES:
            gtk_main_quit();
            break;
    case GTK_RESPONSE_NO:
           gtk_widget_destroy(pQuestion);
           break;
      }
}
/*----------------------------------------------------------------------------------------------------------------------------------------------*/
void ajouter_even(GtkWidget widget, gpointer data){

    GtkWidget* Frame;
    GtkWidget* BOxFrame;
    GtkWidget* Separator;
    gchar* sUtf8;

    fen[1]=gtk_window_new(GTK_WINDOW_TOPLEVEL);
  //  g_signal_connect(G_OBJECT(fen[1]),"destroy",G_CALLBACK(gtk_main_quit),NULL);
    box[1]=gtk_vbox_new(TRUE,0);
       GtkWidget* bouton[10];
     gtk_container_add(GTK_CONTAINER(fen[1]),box[1]);

    Frame = gtk_frame_new("PLANNING");
        gtk_box_pack_start(GTK_BOX(box[1]),Frame,TRUE,FALSE,0);
    BOxFrame = gtk_vbox_new(TRUE,0);
        gtk_container_add(GTK_CONTAINER(Frame),BOxFrame);

    lab[3] = gtk_label_new("Date_rv");
        gtk_box_pack_start(GTK_BOX(BOxFrame),lab[3],TRUE,FALSE,0);
        entree[3] = gtk_entry_new();
        gtk_box_pack_start(GTK_BOX(BOxFrame),entree[3],TRUE,FALSE,0);;

    lab[4]=gtk_label_new("Date_fin");
       gtk_box_pack_start(GTK_BOX(BOxFrame),lab[4],TRUE,FALSE,0);
       entree[4] = gtk_entry_new();
       gtk_box_pack_start(GTK_BOX(BOxFrame),entree[4],TRUE,FALSE,0);

     Separator = gtk_hseparator_new();
        gtk_box_pack_start(GTK_BOX(BOxFrame),Separator,TRUE,FALSE,0);

    lab[5]=gtk_label_new("Heure_debut");
       gtk_box_pack_start(GTK_BOX(BOxFrame),lab[5],TRUE,FALSE,0);
       entree[5] = gtk_entry_new();
       gtk_box_pack_start(GTK_BOX(BOxFrame),entree[5],TRUE,FALSE,0);

    lab[6]=gtk_label_new("heure fin");
      gtk_box_pack_start(GTK_BOX(BOxFrame),lab[6],TRUE,FALSE,0);
      entree[6] = gtk_entry_new();
      gtk_box_pack_start(GTK_BOX(BOxFrame),entree[6],TRUE,FALSE,0);


     Frame = gtk_frame_new("NOTE");
        gtk_box_pack_start(GTK_BOX(box[1]),Frame,TRUE,FALSE,0);
     BOxFrame = gtk_vbox_new(TRUE,0);
        gtk_container_add(GTK_CONTAINER(Frame),BOxFrame);

    lab[7]=gtk_label_new("Nom_rv");
       gtk_box_pack_start(GTK_BOX(BOxFrame),lab[7],TRUE,FALSE,0);
       entree[7] = gtk_entry_new();
       gtk_box_pack_start(GTK_BOX(BOxFrame),entree[7],TRUE,FALSE,0);

   lab[8]=gtk_label_new("Lieu_rv");
      gtk_box_pack_start(GTK_BOX(BOxFrame),lab[8],TRUE,FALSE,0);
      entree[8] = gtk_entry_new();
      gtk_box_pack_start(GTK_BOX(BOxFrame),entree[8],TRUE,FALSE,0);

    lab[9]=gtk_label_new("Description");
       gtk_box_pack_start(GTK_BOX(BOxFrame),lab[9],TRUE,FALSE,0);
       entree[9] = gtk_entry_new();
       gtk_box_pack_start(GTK_BOX(BOxFrame),entree[9],TRUE,FALSE,0);

     bouton[1] = gtk_button_new_with_label("Envoyez....") ;
         gtk_box_pack_start(GTK_BOX(BOxFrame),bouton[1],TRUE,FALSE,0);
        g_signal_connect(G_OBJECT(bouton[1]),"clicked",G_CALLBACK(Valider),fen[1]);
         g_signal_connect(G_OBJECT(bouton[1]),"activate",G_CALLBACK(Valider),fen[1]);

    bouton[2] = gtk_button_new_from_stock(GTK_STOCK_QUIT);
       gtk_box_pack_start(GTK_BOX(BOxFrame),bouton[2],TRUE,TRUE,0);
        g_signal_connect(G_OBJECT(bouton[2]),"clicked",G_CALLBACK(on_quitte_btn),fen[1]);
        g_signal_connect(G_OBJECT(bouton[2]),"activate",G_CALLBACK(on_quitte_btn),fen[1]);

    //label=gtk_label_new("Rien pour l'instant");
    //gtk_box_pack_start(GTK_BOX(box),label,FALSE,FALSE,0);
    gtk_widget_show_all(fen[1]);
    //gtk_widget_destroy(fen[1]);
}
/*---------------------------------------------------------------------------------------------------------------*/
char* reponse_BD(PGconn* dbconn){
   int i,j;
  const gchar* text[700];
   PGresult*res;
   res = PQexec(dbconn,"SELECT * FROM Evenement;");
   int nlignes = PQntuples(res);
   int ncolonnes = PQnfields(res);
   for(i=0 ; i < nlignes ; i++){
     for(j=0 ; j < ncolonnes ; j++){
          //res = PQexec(dbconn,"SELECT * FROM Evenement;");
            strcat(text,PQgetvalue(res,i,j));
     }
     strcat(text,'\n');
   }
   return text;
}
/*-------------------------------------------------------------------------------------------------------------------*/
void supprimer_ligne(PGconn *dbconn){
     PQexec(dbconn,"DELETE FROM Evenement WHERE heure_debut='15:30:00'");
}
/*----------------------------------------------------------------------------------------------------------------------------*/
void Ajout(GtkWidget *widget, gpointer data){
	GtkWidget *pTable;
	GtkWidget *pButton[70];
	GtkWidget *label;

	fen[4]= gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(fen[4]), "Evenement");
	gtk_window_set_default_size(GTK_WINDOW(fen[4]),10,20);
	g_signal_connect(G_OBJECT(fen[4]), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    pTable=gtk_table_new(3,2,TRUE);
	gtk_container_add(GTK_CONTAINER(fen[4]), GTK_WIDGET(pTable));

	/* Creation des boutons */
	pButton[1] = gtk_button_new_with_label("Ajout...");
	pButton[2] = gtk_button_new_with_label("Supp....");
    //label = gtk_label_new()
  /*pButton[4] = gtk_button_new_with_label("3");
	pButton[5] = gtk_button_new_with_label("4");*/

    gtk_table_attach(GTK_TABLE(pTable),pButton[1],0,2,0,1,GTK_EXPAND|GTK_FILL,GTK_EXPAND|GTK_FILL,0,0);
    g_signal_connect(G_OBJECT(pButton[1]), "clicked", G_CALLBACK(ajouter_even),fen[4]);

   gtk_table_attach(GTK_TABLE(pTable),pButton[2],0,2,1,2,GTK_EXPAND|GTK_FILL,GTK_EXPAND,0,0);
   g_signal_connect(G_OBJECT(pButton[2]), "clicked", G_CALLBACK(supprimer_ligne),fen[4]);



    gtk_widget_show_all(fen[4]);
}
/*-------------------------------------------------------------------------------------------------------------------------*/
int diference_jour(int jour_donne, int mois_donne, int annee_donnee){

    int jour_ref = 1, mois_ref = 1, annee_ref = 1;
    int dif_jour = 0, dif_mois = 0, dif_annee = 0;

    dif_jour = jour_donne - jour_ref;
    dif_mois = mois_donne - mois_ref;
    dif_annee = annee_donnee - annee_ref;

    if (mois_donne > 2 && bissextile(annee_donnee))
        dif_jour += 1;

    dif_jour += ((dif_annee * 365) + dif_annee / 4);

    if (dif_mois > 0) {
        switch (dif_mois) {
            case 1:
                dif_jour += 31;
                break;
            case 2:
                dif_jour += 31 + 28;
                break;
            case 3:
                dif_jour += 31 + 28 + 31;
                break;
            case 4:
                dif_jour += 31 + 28 + 31 + 30;
                break;
            case 5:
                dif_jour += 31 + 28 + 31 + 30 + 31;
                break;
            case 6:
                dif_jour += 31 + 28 + 31 + 30 + 31 + 30;
                break;
            case 7:
                dif_jour += 31 + 28 + 31 + 30 + 31 + 30 + 31;
                break;
            case 8:
                dif_jour += 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31;
                break;
            case 9:
                dif_jour += 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
                break;
            case 10:
                dif_jour += 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
                break;
            case 11:
                dif_jour += 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
                break;
            default:
                break;
            }
        }

    return dif_jour;
}
/*-------------------------------------------------------------------------------------------------------------------------*/
int bissextile(int annee_donnee){
	return (annee_donnee % 400 == 0 || (annee_donnee % 4 == 0 && annee_donnee % 100 != 0)) ? 1 : 0;
}
/*-------------------------------------------------------------------------------------------------------------------------*/
char * jour_correspondant(int ndre_jr){
    char *jr[7] = {"DIMANCHE", "LUNDI", "MARDI", "MERCREDI", "JEUDI", "VENDREDI", "SAMEDI"};
    return jr[ndre_jr%7];
}
/*-------------------------------------------------------------------------------------------------------------------------*/
void Detruire(GtkWidget *pWidget, gpointer pData){
	/* Arret de la boucle evenementielle */
	gtk_main_quit();
}
/*-------------------------------------------------------------------------------------------------------------------------*/
int colorer(DATE date){
    char text_jour[3];
    int i;
    sprintf(text_jour,"%d",date.jour);
    for(i=0; i<30 && strcmp(gtk_button_get_label(pButton[i]),text_jour)!=0; i++);
    //gchar text_bouton[3] = gtk_button_get_label(pButton[i]);

    return i;
}
/*-------------------------------------------------------------------------------------------------------------------------*/
void	forme_calendrier(DATE date){

	pWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gchar *text;
	gtk_window_set_default_size(GTK_WINDOW(pWindow), 200, 450);
	gtk_window_set_title(GTK_WINDOW(pWindow), "CALENDRIER");
	gtk_window_set_position (GTK_WINDOW (pWindow), GTK_WIN_POS_CENTER);
	g_signal_connect(G_OBJECT(pWindow), "destroy", G_CALLBACK(Detruire), NULL);

		//Creation et insertion de la table de 9 lignes et de 7 colonnes
	pTable=gtk_table_new(9,7,TRUE);

		//Ajout de la table dans la fenêtre
	gtk_container_add(GTK_CONTAINER(pWindow), GTK_WIDGET(pTable));

		// Creation des boutons
	pButton[0] = gtk_button_new_with_label("1");
	pButton[1] = gtk_button_new_with_label("2");
	pButton[2] = gtk_button_new_with_label("3");
	pButton[3] = gtk_button_new_with_label("4");
	pButton[4] = gtk_button_new_with_label("5");
	pButton[5] = gtk_button_new_with_label("6");
	pButton[6] = gtk_button_new_with_label("7");
	pButton[7] = gtk_button_new_with_label("8");
	pButton[8] = gtk_button_new_with_label("9");
	pButton[9] = gtk_button_new_with_label("10");

	pButton[10] = gtk_button_new_with_label("11");
	pButton[11] = gtk_button_new_with_label("12");
	pButton[12] = gtk_button_new_with_label("13");
	pButton[13] = gtk_button_new_with_label("14");
	pButton[14] = gtk_button_new_with_label("15");
	pButton[15] = gtk_button_new_with_label("16");
	pButton[16] = gtk_button_new_with_label("17");
	pButton[17] = gtk_button_new_with_label("18");
	pButton[18] = gtk_button_new_with_label("19");
	pButton[19] = gtk_button_new_with_label("20");

	pButton[20] = gtk_button_new_with_label("21");
	pButton[21] = gtk_button_new_with_label("22");
	pButton[22] = gtk_button_new_with_label("23");
	pButton[23] = gtk_button_new_with_label("24");
	pButton[24] = gtk_button_new_with_label("25");
	pButton[25] = gtk_button_new_with_label("26");
	pButton[26] = gtk_button_new_with_label("27");
	pButton[27] = gtk_button_new_with_label("28");
	pButton[28] = gtk_button_new_with_label("29");
	pButton[29] = gtk_button_new_with_label("30");
	pButton[30] = gtk_button_new_with_label("31");

	pButton[31] =  gtk_button_new_from_stock(GTK_STOCK_GO_BACK);
	pButton[32] =  gtk_button_new_from_stock(GTK_STOCK_GO_FORWARD);
	pButton[33] = gtk_button_new_with_label("Aujourd'hui");

	pButton[34] = gtk_button_new_with_label("Add event");
	pButton[35] = gtk_button_new_with_label("Search Date");

    GdkColor color;
	color.blue=65000;
    color.red=0;
    color.green=0;
    gtk_widget_modify_bg(pButton[colorer(date)],GTK_STATE_NORMAL,&color);



				//ajout des boutons de l'entête de la fenetre
	gtk_table_attach(GTK_TABLE(pTable),pButton[31], 2,3,0,2,GTK_EXPAND,GTK_EXPAND,0,0);
	gtk_table_attach(GTK_TABLE(pTable),pButton[33], 3,4,0,2,GTK_EXPAND,GTK_EXPAND,0,0);		// boutons de la deuxième ligne
	gtk_table_attach(GTK_TABLE(pTable),pButton[32], 4,5,0,2,GTK_EXPAND,GTK_EXPAND,0,0);

	gtk_table_attach(GTK_TABLE(pTable),pButton[34], 0,2,0,1,GTK_EXPAND,GTK_EXPAND,0,0);		// boutons de la premiere ligne
	gtk_table_attach(GTK_TABLE(pTable),pButton[35], 5,7,0,1,GTK_EXPAND,GTK_EXPAND,0,0);

		// declaration des labels
	label[0] = gtk_label_new("LUN");
	label[1] = gtk_label_new("MAR");
	label[2] = gtk_label_new("MER");
	label[3] = gtk_label_new("JEU");
	label[4] = gtk_label_new("VEN");

    GdkColor color1;
	color1.blue=0;
    color1.red=50000;
    color1.green=0;
	label[5] = gtk_label_new("SAM");
	gtk_widget_modify_bg(label[5],GTK_STATE_NORMAL,&color1);

	label[6] = gtk_label_new("DIM");
    gtk_widget_modify_bg(label[6],GTK_STATE_NORMAL,&color1);

    text = g_locale_to_utf8(date_char(date),-1,NULL,NULL,NULL);
    /** Gras Italique **/
    label[7] = gtk_label_new(text);
    g_free(text);
			// affichage de la date sur le label d'entête
	//gtk_label_set_text(GTK_LABEL(label[7]),date_char(date));

				//ajout des labels dans la fenetre
	gtk_table_attach(GTK_TABLE(pTable),label[0], 0,1,1,3,GTK_EXPAND,GTK_EXPAND,0,0);
	gtk_table_attach(GTK_TABLE(pTable),label[1], 1,2,1,3,GTK_EXPAND,GTK_EXPAND,0,0);
	gtk_table_attach(GTK_TABLE(pTable),label[2], 2,3,1,3,GTK_EXPAND,GTK_EXPAND,0,0);
	gtk_table_attach(GTK_TABLE(pTable),label[3], 3,4,1,3,GTK_EXPAND,GTK_EXPAND,0,0);		// label de jours
	gtk_table_attach(GTK_TABLE(pTable),label[4], 4,5,1,3,GTK_EXPAND,GTK_EXPAND,0,0);
	gtk_table_attach(GTK_TABLE(pTable),label[5], 5,6,1,3,GTK_EXPAND,GTK_EXPAND,0,0);
	gtk_table_attach(GTK_TABLE(pTable),label[6], 6,7,1,3,GTK_EXPAND,GTK_EXPAND,0,0);

	gtk_table_attach(GTK_TABLE(pTable),label[7], 3,4,0,1,GTK_EXPAND,GTK_EXPAND,0,0);

		//declaration des variables permettant de positionner les differents widgets dans la table
	gint 	l1,l2,l3,l4,l5,l6,l7,l8,l9,l10,l11,l12,l13,l14,l15,l16,l17;
	gint	l18,l19,l20,l21,l22,l23,l24,l25,l26,l27,l28,l29,l30,l31;

	gint	c1_1,c1_2,c1_3,c1_4,c1_5,c1_6,c1_7,c1_8,c1_9,c1_10,c1_11;
	gint	c1_12,c1_13,c1_14,c1_15,c1_16,c1_17,c1_18,c1_19,c1_20,c1_21;
	gint	c1_22,c1_23,c1_24,c1_25,c1_26,c1_27,c1_28,c1_29,c1_30,c1_31;

	gint	c2_1,c2_2,c2_3,c2_4,c2_5,c2_6,c2_7,c2_8,c2_9,c2_10,c2_11;
	gint	c2_12,c2_13,c2_14,c2_15,c2_16,c2_17,c2_18,c2_19,c2_20,c2_21;
	gint	c2_22,c2_23,c2_24,c2_25,c2_26,c2_27,c2_28,c2_29,c2_30,c2_31;

		// positionner les boutons en fonction du jour de commencement du mois
	switch(diference_jour(1, date.mois, date.annee)%7){
		case 0 :	//DIM
			l1=4; l2=l3=l4=l5=l6=l7=l8=5; l9=l10=l11=l12=l13=l14=l15=6;
			l16=l17=l18=l19=l20=l21=l22=7; l23=l24=l25=l26=l27=l28=l29=8; l30=l31=9;
			c1_1=6; c1_2=7;
			c2_1=0; c2_2=c1_3=1; c2_3=c1_4=2; c2_4=c1_5=3; c2_5=c1_6=4; c2_6=c1_7=5; c2_7=c1_8=6; c2_8=7;
			c1_9=0; c2_9=c1_10=1; c2_10=c1_11=2; c2_11=c1_12=3; c2_12=c1_13=4; c2_13=c1_14=5; c2_14=c1_15=6; c2_15=7;
			c1_16=0; c2_16=c1_17=1; c2_17=c1_18=2; c2_18=c1_19=3; c2_19=c1_20=4; c2_20=c1_21=5; c2_21=c1_22=6; c2_22=7;		//OK DIMANCHE
			c1_23=0; c2_23=c1_24=1; c2_24=c1_25=2; c2_25=c1_26=3; c2_26=c1_27=4; c2_27=c1_28=5; c2_28=c1_29=6; c2_29=7;
			c1_30=0; c2_30=c1_31=1; c2_31=2;
			break;
		case 1 :	//LUN
			l1=l2=l3=l4=l5=l6=l7=4;l8=l9=l10=l11=l12=l13=l14=5;l15=l16=l17=l18=l19=l20=l21=6;
			l22=l23=l24=l25=l26=l27=l28=7; l29=l30=l31=8;
			c1_1=0; c1_2=c2_1=1; c2_2=c1_3=2; c2_3=c1_4=3; c2_4=c1_5=4; c2_5=c1_6=5; c2_6=c1_7=6; c2_7 = 7;
			c1_8=0; c2_8=c1_9=1; c2_9=c1_10=2; c2_10=c1_11=3; c2_11=c1_12=4; c2_12=c1_13=5; c2_13=c1_14=6; c2_14=7;			//OK LUNDI
			c1_15=0; c2_15=c1_16=1; c2_16=c1_17=2; c2_17=c1_18=3; c2_18=c1_19=4; c2_19=c1_20=5; c2_20=c1_21=6; c2_21=7;
			c1_22=0; c2_22=c1_23=1; c2_23=c1_24=2; c2_24=c1_25=3; c2_25=c1_26=4; c2_26=c1_27=5; c2_27=c1_28=6; c2_28=7;
			c1_29=0; c2_29=c1_30=1; c2_30=c1_31=2; c2_31=3;
			break;
		case 2 : 	//MAR
			l1=l2=l3=l4=l5=l6=4; l7=l8=l9=l10=l11=l12=l13=5; l14=l15=l16=l17=l18=l19=l20=6;
			l21=l22=l23=l24=l25=l26=l27=7; l28=l29=l30=l31=8;
			c1_1=1; c1_2=c2_1=2; c2_2=c1_3=3; c2_3=c1_4=4; c2_4=c1_5=5; c2_5=c1_6=6; c2_6=7;
			c1_7=0; c2_7=c1_8=1; c2_8=c1_9=2; c2_9=c1_10=3; c2_10=c1_11=4; c2_11=c1_12=5; c2_12=c1_13=6; c2_13=7;
			c1_14=0; c2_14=c1_15=1; c2_15=c1_16=2; c2_16=c1_17=3; c2_17=c1_18=4; c2_18=c1_19=5; c2_19=c1_20=6; c2_20=7;
			c1_21=0; c2_21=c1_22=1; c2_22=c1_23=2; c2_23=c1_24=3; c2_24=c1_25=4; c2_25=c1_26=5; c2_26=c1_27=6; c2_27=7;		//OK MARDI
			c1_28=0; c2_28=c1_29=1; c2_29=c1_30=2; c2_30=c1_31=3; c2_31=4;
			break;
		case 3 :	//MER
			l1=l2=l3=l4=l5=4; l6=l7=l8=l9=l10=l11=l12=5; l13=l14=l15=l16=l17=l18=l19=6;
			l20=l21=l22=l23=l24=l25=l26=7; l27=l28=l29=l30=l31=8;
			c1_1=2; c1_2=3; c2_1=3; c2_2=4; c1_3=4; c2_3=c1_4=5; c2_4=c1_5=6; c2_5=7;
			c1_6=0; c2_6=c1_7=1; c2_7=c1_8=2; c2_8=c1_9=3; c2_9=c1_10=4; c2_10=c1_11=5; c2_11=c1_12=6; c2_12=7;
			c1_13=0; c2_13=c1_14=1; c2_14=c1_15=2; c2_15=c1_16=3; c2_16=c1_17=4; c2_17=c1_18=5; c2_18=c1_19=6; c2_19=7;		//	OK MERCREDI
			c1_20=0; c2_20=c1_21=1; c2_21=c1_22=2; c2_22=c1_23=3; c2_23=c1_24=4; c2_24=c1_25=5; c2_25=c1_26=6; c2_26=7;
			c1_27=0; c2_27=c1_28=1; c2_28=c1_29=2; c2_29=c1_30=3; c2_30=c1_31=4; c2_31=5;
			break;
		case 4 :	//JEU
			l1=l2=l3=l4=4; l5=l6=l7=l8=l9=l10=l11=5; l12=l13=l14=l15=l16=l17=l18=6;
			l19=l20=l21=l22=l23=l24=l25=7; l26=l27=l28=l29=l30=l31=8;
			c1_1=3; c1_2=c2_1=4; c2_2=c1_3=5; c2_3=c1_4=6; c2_4=7;
			c1_5=0; c2_5=c1_6=1; c2_6=c1_7=2; c2_7=c1_8=3; c2_8=c1_9=4; c2_9=c1_10=5; c2_10=c1_11=6; c2_11=7;
			c1_12=0; c2_12=c1_13=1; c2_13=c1_14=2; c2_14=c1_15=3; c2_15=c1_16=4; c2_16=c1_17=5; c2_17=c1_18=6; c2_18=7;		//OK JEUDI
			c1_19=0; c2_19=c1_20=1; c2_20=c1_21=2; c2_21=c1_22=3; c2_22=c1_23=4; c2_23=c1_24=5; c2_24=c1_25=6; c2_25=7;
			c1_26=0; c2_26=c1_27=1; c2_27=c1_28=2; c2_28=c1_29=3; c2_29=c1_30=4; c2_30=c1_31=5; c2_31=6;
			break;
		case 5 : 	//VEN
			l1=l2=l3=4; l4=l5=l6=l7=l8=l9=l10=5; l11=l12=l13=l14=l15=l16=l17=6;
			l18=l19=l20=l21=l22=l23=l24=7; l25=l26=l27=l28=l29=l30=l31=8;
			c1_1=4; c1_2=c2_1=5; c2_2=c1_3=6; c2_3=7;
			c1_4=0; c2_4=c1_5=1; c2_5=c1_6=2; c2_6=c1_7=3; c2_7=c1_8=4; c2_8=c1_9=5; c2_9=c1_10=6; c2_10=7;
			c1_11=0; c2_11=c1_12=1; c2_12=c1_13=2; c2_13=c1_14=3; c2_14=c1_15=4; c2_15=c1_16=5; c2_16=c1_17=6; c2_17=7;
			c1_18=0; c2_18=c1_19=1; c2_19=c1_20=2; c2_20=c1_21=3; c2_21=c1_22=4; c2_22=c1_23=5; c2_23=c1_24=6; c2_24=7;		//OK VENDREDI
			c1_25=0; c2_25=c1_26=1; c2_26=c1_27=2; c2_27=c1_28=3; c2_28=c1_29=4; c2_29=c1_30=5; c2_30=c1_31=6; c2_31=7;

			break;
		case 6 :	//SAM
			l1=l2=4; l3=l4=l5=l6=l7=l8=l9=5; l10=l11=l12=l13=l14=l15=l16=6;
			l17=l18=l19=l20=l21=l22=l23=7; l24=l25=l26=l27=l28=l29=l30=8; l31=9;
			c1_1=5; c1_2=c2_1=6; c2_2=7;
			c1_3=0; c2_3=c1_4=1; c2_4=c1_5=2; c2_5=c1_6=3; c2_6=c1_7=4; c2_7=c1_8=5; c2_8=c1_9=6; c2_9=7;
			c1_10=0; c2_10=c1_11=1; c2_11=c1_12=2; c2_12=c1_13=3; c2_13=c1_14=4; c2_14=c1_15=5; c2_15=c1_16=6; c2_16=7;
			c1_17=0; c2_17=c1_18=1; c2_18=c1_19=2; c2_19=c1_20=3; c2_20=c1_21=4; c2_21=c1_22=5; c2_22=c1_23=6; c2_23=7;		//OK SAMEDI
			c1_24=0; c2_24=c1_25=1; c2_25=c1_26=2; c2_26=c1_27=3; c2_27=c1_28=4; c2_28=c1_29=5; c2_29=c1_30=6; c2_30=7;
			c1_31=0; c2_31=1;
			break;
		default :
			break;
	}

		// Ajout des Boutons dans la GtkBox

	gtk_table_attach(GTK_TABLE(pTable),pButton[0], c1_1,c2_1,1,l1,GTK_EXPAND,GTK_EXPAND,0,0);
	g_signal_connect(G_OBJECT(pButton[0]), "clicked", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);
    g_signal_connect(G_OBJECT(pButton[0]), "activate", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);

	gtk_table_attach(GTK_TABLE(pTable),pButton[1], c1_2,c2_2,1,l2,GTK_EXPAND,GTK_EXPAND,0,0);
	g_signal_connect(G_OBJECT(pButton[1]), "clicked", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);
    g_signal_connect(G_OBJECT(pButton[1]), "activate", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);

	gtk_table_attach(GTK_TABLE(pTable),pButton[2], c1_3,c2_3,1,l3,GTK_EXPAND,GTK_EXPAND,0,0);
	g_signal_connect(G_OBJECT(pButton[2]), "clicked", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);
    g_signal_connect(G_OBJECT(pButton[2]), "activate", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);

	gtk_table_attach(GTK_TABLE(pTable),pButton[3], c1_4,c2_4,1,l4,GTK_EXPAND,GTK_EXPAND,0,0);
    g_signal_connect(G_OBJECT(pButton[3]), "clicked", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);
    g_signal_connect(G_OBJECT(pButton[3]), "activate", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);

	gtk_table_attach(GTK_TABLE(pTable),pButton[4], c1_5,c2_5,1,l5,GTK_EXPAND,GTK_EXPAND,0,0);
	g_signal_connect(G_OBJECT(pButton[4]), "clicked", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);
    g_signal_connect(G_OBJECT(pButton[4]), "activate", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);

	gtk_table_attach(GTK_TABLE(pTable),pButton[5], c1_6,c2_6,1,l6,GTK_EXPAND,GTK_EXPAND,0,0);
	g_signal_connect(G_OBJECT(pButton[5]), "clicked", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);
    g_signal_connect(G_OBJECT(pButton[5]), "activate", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);

	gtk_table_attach(GTK_TABLE(pTable),pButton[6], c1_7,c2_7,1,l7,GTK_EXPAND,GTK_EXPAND,0,0);
	g_signal_connect(G_OBJECT(pButton[6]), "clicked", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);
    g_signal_connect(G_OBJECT(pButton[6]), "activate", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);

	gtk_table_attach(GTK_TABLE(pTable),pButton[7], c1_8,c2_8,1,l8,GTK_EXPAND,GTK_EXPAND,0,0);
	g_signal_connect(G_OBJECT(pButton[7]), "clicked", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);
    g_signal_connect(G_OBJECT(pButton[7]), "activate", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);

	gtk_table_attach(GTK_TABLE(pTable),pButton[8], c1_9,c2_9,1,l9,GTK_EXPAND,GTK_EXPAND,0,0);
	g_signal_connect(G_OBJECT(pButton[8]), "clicked", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);
    g_signal_connect(G_OBJECT(pButton[8]), "activate", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);

	gtk_table_attach(GTK_TABLE(pTable),pButton[9], c1_10,c2_10,1,l10,GTK_EXPAND,GTK_EXPAND,0,0);
	g_signal_connect(G_OBJECT(pButton[9]), "clicked", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);
    g_signal_connect(G_OBJECT(pButton[9]), "activate", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);

	gtk_table_attach(GTK_TABLE(pTable),pButton[10], c1_11,c2_11,1,l11,GTK_EXPAND,GTK_EXPAND,0,0);
	g_signal_connect(G_OBJECT(pButton[10]), "clicked", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);
    g_signal_connect(G_OBJECT(pButton[10]), "activate", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);

	gtk_table_attach(GTK_TABLE(pTable),pButton[11], c1_12,c2_12,1,l12,GTK_EXPAND,GTK_EXPAND,0,0);
	g_signal_connect(G_OBJECT(pButton[11]), "clicked", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);
    g_signal_connect(G_OBJECT(pButton[11]), "activate", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);

	gtk_table_attach(GTK_TABLE(pTable),pButton[12], c1_13,c2_13,1,l13,GTK_EXPAND,GTK_EXPAND,0,0);
    g_signal_connect(G_OBJECT(pButton[12]), "clicked", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);
    g_signal_connect(G_OBJECT(pButton[12]), "activate", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);

	gtk_table_attach(GTK_TABLE(pTable),pButton[13], c1_14,c2_14,1,l14,GTK_EXPAND,GTK_EXPAND,0,0);
	g_signal_connect(G_OBJECT(pButton[13]), "clicked", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);
    g_signal_connect(G_OBJECT(pButton[13]), "activate", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);

	gtk_table_attach(GTK_TABLE(pTable),pButton[14], c1_15,c2_15,1,l15,GTK_EXPAND,GTK_EXPAND,0,0);
	g_signal_connect(G_OBJECT(pButton[14]), "clicked", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);
    g_signal_connect(G_OBJECT(pButton[14]), "activate", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);

	gtk_table_attach(GTK_TABLE(pTable),pButton[15], c1_16,c2_16,1,l16,GTK_EXPAND,GTK_EXPAND,0,0);
	g_signal_connect(G_OBJECT(pButton[15]), "clicked", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);
    g_signal_connect(G_OBJECT(pButton[15]), "activate", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);

	gtk_table_attach(GTK_TABLE(pTable),pButton[16], c1_17,c2_17,1,l17,GTK_EXPAND,GTK_EXPAND,0,0);		// (button[], colone, ligne, ...)
	g_signal_connect(G_OBJECT(pButton[16]), "clicked", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);
    g_signal_connect(G_OBJECT(pButton[16]), "activate", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);

	gtk_table_attach(GTK_TABLE(pTable),pButton[17], c1_18,c2_18,1,l18,GTK_EXPAND,GTK_EXPAND,0,0);
	g_signal_connect(G_OBJECT(pButton[17]), "clicked", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);
    g_signal_connect(G_OBJECT(pButton[17]), "activate", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);

	gtk_table_attach(GTK_TABLE(pTable),pButton[18], c1_19,c2_19,1,l19,GTK_EXPAND,GTK_EXPAND,0,0);
	g_signal_connect(G_OBJECT(pButton[18]), "clicked", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);
    g_signal_connect(G_OBJECT(pButton[18]), "activate", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);

	gtk_table_attach(GTK_TABLE(pTable),pButton[19], c1_20,c2_20,1,l20,GTK_EXPAND,GTK_EXPAND,0,0);
	g_signal_connect(G_OBJECT(pButton[19]), "clicked", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);
    g_signal_connect(G_OBJECT(pButton[19]), "activate", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);

	gtk_table_attach(GTK_TABLE(pTable),pButton[20], c1_21,c2_21,1,l21,GTK_EXPAND,GTK_EXPAND,0,0);
	g_signal_connect(G_OBJECT(pButton[20]), "clicked", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);
    g_signal_connect(G_OBJECT(pButton[20]), "activate", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);

	gtk_table_attach(GTK_TABLE(pTable),pButton[21], c1_22,c2_22,1,l22,GTK_EXPAND,GTK_EXPAND,0,0);
	g_signal_connect(G_OBJECT(pButton[21]), "clicked", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);
    g_signal_connect(G_OBJECT(pButton[21]), "activate", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);

	gtk_table_attach(GTK_TABLE(pTable),pButton[22], c1_23,c2_23,1,l23,GTK_EXPAND,GTK_EXPAND,0,0);
	g_signal_connect(G_OBJECT(pButton[22]), "clicked", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);
    g_signal_connect(G_OBJECT(pButton[22]), "activate", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);

	gtk_table_attach(GTK_TABLE(pTable),pButton[23], c1_24,c2_24,1,l24,GTK_EXPAND,GTK_EXPAND,0,0);
	g_signal_connect(G_OBJECT(pButton[23]), "clicked", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);
    g_signal_connect(G_OBJECT(pButton[23]), "activate", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);

	gtk_table_attach(GTK_TABLE(pTable),pButton[24], c1_25,c2_25,1,l25,GTK_EXPAND,GTK_EXPAND,0,0);
	g_signal_connect(G_OBJECT(pButton[24]), "clicked", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);
    g_signal_connect(G_OBJECT(pButton[24]), "activate", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);

	gtk_table_attach(GTK_TABLE(pTable),pButton[25], c1_26,c2_26,1,l26,GTK_EXPAND,GTK_EXPAND,0,0);
	g_signal_connect(G_OBJECT(pButton[25]), "clicked", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);
    g_signal_connect(G_OBJECT(pButton[25]), "activate", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);

	gtk_table_attach(GTK_TABLE(pTable),pButton[26], c1_27,c2_27,1,l27,GTK_EXPAND,GTK_EXPAND,0,0);
	g_signal_connect(G_OBJECT(pButton[26]), "clicked", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);
    g_signal_connect(G_OBJECT(pButton[26]), "activate", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);

	gtk_table_attach(GTK_TABLE(pTable),pButton[27], c1_28,c2_28,1,l28,GTK_EXPAND,GTK_EXPAND,0,0);
    g_signal_connect(G_OBJECT(pButton[27]), "clicked", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);
    g_signal_connect(G_OBJECT(pButton[27]), "activate", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);

	g_signal_connect(G_OBJECT(pButton[31]), "clicked", G_CALLBACK(mois_prec), pWindow); // connection signal a la fonction mois_prec

	g_signal_connect(G_OBJECT(pButton[32]), "clicked", G_CALLBACK(mois_suiv), pWindow); // connection signal a la fonction mois_suiv

	g_signal_connect(G_OBJECT(pButton[33]), "clicked", G_CALLBACK(Aujourd), pWindow); // connection signal a la fonction Aujourd

	g_signal_connect(G_OBJECT(pButton[34]), "clicked", G_CALLBACK(ajouter_even), NULL); // connection signal a la fonction ajouter evenement

	g_signal_connect(G_OBJECT(pButton[35]), "clicked", G_CALLBACK(rechercher_date), NULL); // connection signal a la fonction rechercher date


	switch(date.mois){
		case 1 :
		case 3 :
		case 5 :
		case 7 :
		case 8 :
		case 10:
		case 12:
			gtk_table_attach(GTK_TABLE(pTable),pButton[28], c1_29,c2_29,1,l29,GTK_EXPAND,GTK_EXPAND,0,0);
			g_signal_connect(G_OBJECT(pButton[28]), "clicked", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);
            g_signal_connect(G_OBJECT(pButton[28]), "activate", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);

			gtk_table_attach(GTK_TABLE(pTable),pButton[29], c1_30,c2_30,1,l30,GTK_EXPAND,GTK_EXPAND,0,0);
			g_signal_connect(G_OBJECT(pButton[29]), "clicked", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);
            g_signal_connect(G_OBJECT(pButton[29]), "activate", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);

			gtk_table_attach(GTK_TABLE(pTable),pButton[30], c1_31,c2_31,1,l31,GTK_EXPAND,GTK_EXPAND,0,0);
	         g_signal_connect(G_OBJECT(pButton[30]), "clicked", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);
             g_signal_connect(G_OBJECT(pButton[30]), "activate", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);
			break;
		case 2 :
			if(bissextile(date.annee))
			  	gtk_table_attach(GTK_TABLE(pTable),pButton[28], c1_29,c2_29,1,l29,GTK_EXPAND,GTK_EXPAND,0,0);
			     g_signal_connect(G_OBJECT(pButton[28]), "clicked", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);
                  g_signal_connect(G_OBJECT(pButton[28]), "activate", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);
			break;
		case 4 :
		case 6 :
		case 9 :
		case 11:
			gtk_table_attach(GTK_TABLE(pTable),pButton[28], c1_29,c2_29,1,l29,GTK_EXPAND,GTK_EXPAND,0,0);
			g_signal_connect(G_OBJECT(pButton[28]),"clicked", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);
             g_signal_connect(G_OBJECT(pButton[28]), "activate", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);

			gtk_table_attach(GTK_TABLE(pTable),pButton[29], c1_30,c2_30,1,l30,GTK_EXPAND,GTK_EXPAND,0,0);
			g_signal_connect(G_OBJECT(pButton[29]), "clicked", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);
            g_signal_connect(G_OBJECT(pButton[29]), "activate", G_CALLBACK(ajouter_even),(GtkWidget*)pWindow);
			break;
		default :
			break;
	}


	gtk_widget_show_all(pWindow);
	gtk_main();
}
/*-------------------------------------------------------------------------------------------------------------------------*/
void rechercher_date(GtkWidget widget, gpointer data){

	fen[0] = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	box[0] = gtk_vbox_new(TRUE,0);

	gtk_container_add(GTK_CONTAINER(fen[0]),box[0]);

	entree[0] = gtk_entry_new();
	entree[1] = gtk_entry_new();
	entree[2] = gtk_entry_new();


	lab[0] = gtk_label_new("jour");
	lab[1]=gtk_label_new("mois");
	lab[2]=gtk_label_new("annee");

	gtk_box_pack_start(GTK_BOX(box[0]),lab[0],FALSE,FALSE,0);
	gtk_box_pack_start(GTK_BOX(box[0]),entree[0],FALSE,FALSE,0);

	gtk_box_pack_start(GTK_BOX(box[0]),lab[1],FALSE,FALSE,0);
	gtk_box_pack_start(GTK_BOX(box[0]),entree[1],FALSE,FALSE,0);

	gtk_box_pack_start(GTK_BOX(box[0]),lab[2],FALSE,FALSE,0);
	gtk_box_pack_start(GTK_BOX(box[0]),entree[2],FALSE,FALSE,0);

    bouton[0] = gtk_button_new_with_label("rechercher");
	gtk_box_pack_start(GTK_BOX(box[0]),bouton[0],FALSE,FALSE,0);
    g_signal_connect(G_OBJECT(bouton[0]),"clicked",G_CALLBACK(lancer),(GtkWidget*)fen[0]);
    g_signal_connect(G_OBJECT(bouton[0]),"activate",G_CALLBACK(lancer),(GtkWidget*)fen[0]);


	gtk_widget_show_all(fen[0]);
}
/*----------------------------------------------------------------------------------------------------------*/
void lancer(GtkWidget widget, gpointer data){
    const gchar* FText[3];
    DATE date;

    FText[0]= gtk_entry_get_text(GTK_ENTRY(entree[0]));
    FText[1]= gtk_entry_get_text(GTK_ENTRY(entree[1]));
    FText[2]= gtk_entry_get_text(GTK_ENTRY(entree[2]));

    date.jour = atoi(FText[0]);
    date.mois = atoi(FText[1]);
    date.annee = atoi(FText[2]);

    gtk_widget_destroy(pWindow);

    forme_calendrier(date);
}
/*-------------------------------------------------------------------------------------------------------------------------*/
void mois_suiv(GtkWidget widget, gpointer data){

	if(++dat.mois == 13){
		dat.mois = 1;
		dat.annee++;
	}
	gtk_widget_destroy(pWindow);
	forme_calendrier(dat);
}
/*------------------------------------------------------------------------------------------------------------------------*/
void Aujourd(GtkWidget widget, gpointer data){

	dat = date_systeme();
	gtk_widget_destroy(pWindow);
	forme_calendrier(dat);
}
/*------------------------------------------------------------------------------------------------------------------------*/
void mois_prec(GtkWidget widget, gpointer data){

	if(--dat.mois == 0){
		dat.mois = 12;
		dat.annee--;
	}
	gtk_widget_destroy(pWindow);
	forme_calendrier(dat);
}
/*------------------------------------------------------------------------------------------------------------------------*/
char * date_char(DATE date){

	char *mois_annee = (char*)malloc(15*sizeof(char)), *annee = (char*)malloc(10*sizeof(char));

	sprintf(annee, " %d",date.annee);

	/*	conversion du nombre int de mois en son nom char correepondant */
	switch(date.mois){
		case 1 :
			strcpy(mois_annee, "Janvier");
			break;
		case 2 :
			strcpy(mois_annee, "Fevrier");
			break;
		case 3 :
			strcpy(mois_annee, "Mars");
			break;
		case 4 :
			strcpy(mois_annee, "Avril");
			break;
		case 5 :
			strcpy(mois_annee, "Mai");
			break;
		case 6 :
			strcpy(mois_annee, "Juin");
			break;
		case 7 :
			strcpy(mois_annee, "Juillet");
			break;
		case 8 :
			strcpy(mois_annee, "Aout");
			break;
		case 9 :
			strcpy(mois_annee, "Semptembre");
			break;
		case 10 :
			strcpy(mois_annee, "Octobre");
			break;
		case 11 :
			strcpy(mois_annee, "Novembre");
			break;
		case 12 :
			strcpy(mois_annee, "Decembre");
			break;
		default :
			break;
	}
	strcat(mois_annee, annee);

	return mois_annee;
}
/*-------------------------------------------------------------------------------------------------------------------------*/
DATE 	date_systeme(){

	time_t t;

	time(&t);

	char dat[30], jour[3], mois[4], annee[5];

	strcpy(dat, ctime(&t));

	strncpy(mois,	dat+4,	3);		//	copie	le	mois
	strncpy(jour,	dat+8,	2);		// copie	le	jour
	strncpy(annee,	dat+20,	4);	//	copie	l'année

	//	il  reste à convertir le jour le mois et l'année en integer
	DATE date;
	date.jour = atoi(jour);
	//date.mois = atoi(mois);
	date.annee = atoi(annee);

	//	conversion du type char de mois en int
	if(strcmp(mois,"Jan") == 0)
		date.mois = 1;
	else	if(strcmp(mois,	"Fev")	==	0)
		date.mois =  2;
	else	if(strcmp(mois,	"Mar")	==	0)
		date.mois = 3;
	else	if(strcmp(mois,	"Apr")	==	0)
		date.mois = 4;
	else	if(strcmp(mois,	"May")	==	0)
		date.mois = 5;
	else	if(strcmp(mois,	"Jun")	==	0)
		date.mois = 6;
	else	if(strcmp(mois,	"Jul")	==	0)
		date.mois = 7;
	else	if(strcmp(mois,	"Aug")	==	0)
		date.mois = 8;
	else	if(strcmp(mois,	"Sep")	==	0)
		date.mois = 9;
	else	if(strcmp(mois,	"Oct")	==	0)
		date.mois = 10;
	else	if(strcmp(mois,	"Nov")	==	0)
		date.mois = 11;
	else	if(strcmp(mois,	"Dec")	==	0)
		date.mois = 12;

	return date;
}
/*-----------------------------------------------------------------------------------------------------------------------*/

