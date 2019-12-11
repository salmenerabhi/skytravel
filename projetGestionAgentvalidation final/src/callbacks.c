#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include "tree.h"
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "CRUD.h"
#include"controle.h"


void
on_Ajouter_clicked                     (GtkWidget       *button,
                                        gpointer user_data)
{
struct agent a;
GtkWidget *entry5;
GtkWidget *entry1;
GtkWidget *entry2;
GtkWidget *entry4;
GtkWidget *entry3;


GtkWidget *labelid;
GtkWidget *labelnom;
GtkWidget *labelprenom;
GtkWidget *labeladresse;
GtkWidget *labelnumtel;
GtkWidget *labelcontinent;
GtkWidget *combobox;
int b=1;


entry5=lookup_widget(gestionAgent,"entry5");
entry1=lookup_widget(gestionAgent,"entry1");
entry2=lookup_widget(gestionAgent,"entry2");
entry4=lookup_widget(gestionAgent,"entry4");
entry3=lookup_widget(gestionAgent,"entry3");
combobox=lookup_widget(gestionAgent,"combobox1");


labelid=lookup_widget(gestionAgent,"label31");
labelnom=lookup_widget(gestionAgent,"label32");
labelprenom=lookup_widget(gestionAgent,"label38");
labeladresse=lookup_widget(gestionAgent,"label34");
labelnumtel=lookup_widget(gestionAgent,"label35");
labelcontinent=lookup_widget(gestionAgent,"label46");




if(is_empty(entry5)==0){
		  gtk_widget_show (labelid);
b=0;
}
else {
		  gtk_widget_hide(labelid);
}

if(is_empty(entry1)==0){
		  gtk_widget_show (labelnom);
b=0;
}
else {
		  gtk_widget_hide(labelnom);
}

if(is_empty(entry2)==0){
		  gtk_widget_show (labelprenom);
b=0;
}
else {
		  gtk_widget_hide(labelprenom);
}

if(is_empty(entry4)==0){
		  gtk_widget_show (labeladresse);
b=0;
}
else {
		  gtk_widget_hide(labeladresse);
}
if(is_empty(entry3)==0){
		  gtk_widget_show (labelnumtel);
b=0;
}
else {
		  gtk_widget_hide(labelnumtel);
}

if(is_inactive(combobox)==-1){
		  gtk_widget_show (labelcontinent);
b=0;
}
else {
		  gtk_widget_hide(labelcontinent);
}


if(b==1){



        strcpy(a.id,gtk_entry_get_text(GTK_ENTRY(entry5) ) );
        strcpy(a.nom,gtk_entry_get_text(GTK_ENTRY(entry1) ) );
        strcpy(a.prenom,gtk_entry_get_text(GTK_ENTRY(entry2) ) );
        strcpy(a.adresse,gtk_entry_get_text(GTK_ENTRY(entry4) ) );
        strcpy(a.numtel,gtk_entry_get_text(GTK_ENTRY(entry3) ) );
        a.salaire =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestionAgent,"spin1")));
        strcpy(a.continent,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)));




        if(exist(a.id)==1)
        {
                GtkWidget *existe=lookup_widget(gestionAgent,"label9");
                gtk_label_set_text(GTK_LABEL(existe),"Agent Existe deja !!");
        }
        else {
                ajout(a);
                GtkWidget* existe=lookup_widget(gestionAgent,"label9");
                gtk_label_set_text(GTK_LABEL(existe),"Agent Ajouté avec succes");
        }
        GtkWidget* p=lookup_widget(gestionAgent,"treeview1");

        Agenttree(p,"agents.txt");
}
}

void
on_Modifier_clicked                    (GtkButton       *button,
                                        gpointer user_data)
{
        struct agent a;
        strcpy(a.id,gtk_label_get_text(GTK_LABEL(lookup_widget(gestionAgent,"label53"))));
        strcpy(a.nom,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestionAgent,"entry6"))));
        strcpy(a.prenom,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestionAgent,"entry7"))));
        strcpy(a.adresse,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestionAgent,"entry9"))));
        strcpy(a.numtel,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestionAgent,"entry8"))));
        a.salaire =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestionAgent,"spin2")));
        strcpy(a.continent,gtk_combo_box_get_active_text(GTK_COMBO_BOX(lookup_widget(gestionAgent,"combobox2"))));
        supp(a.id);
        ajout(a);
        Agenttree(lookup_widget(gestionAgent,"treeview1"),"agents.txt");
        GtkWidget* msg=lookup_widget(gestionAgent,"label20");
	
        gtk_label_set_text(GTK_LABEL(msg),"Agent Modifié avec succes");
        gtk_widget_show(msg);

}


void
on_GestionAcceuil_clicked              (GtkButton       *button,
                                        gpointer user_data)
{
        extern GtkWidget *gestionAgent;
        extern GtkWidget *acceuil;

        gtk_widget_show (acceuil);
        gtk_widget_destroy (gestionAgent);
}


void
on_AcceuilGestion_clicked              (GtkButton       *button,
                                        gpointer user_data)
{
  extern GtkWidget *gestionAgent;
  extern GtkWidget *acceuil;

GtkWidget *p;
GtkWidget *p1;
gtk_widget_hide (acceuil);
gestionAgent = create_gestionAgent ();
p=lookup_widget(gestionAgent,"treeview1");
p1=lookup_widget(gestionAgent,"treeview2");
i=0;
j=0;
Agenttree(p,"agents.txt");
Agenttree1(p1,"agents.txt");
gtk_widget_show (gestionAgent);

}


void
on_Supprimer_clicked                   (GtkButton       *button,
                                        gpointer user_data)
{
        extern GtkWidget *gestionAgent;
        GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget* p;
        GtkWidget *label;
        gchar* id;
        label=lookup_widget(gestionAgent,"label43");
        p=lookup_widget(gestionAgent,"treeview1");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  gtk_tree_model_get (model,&iter,0,&id,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);

           supp(id);

           gtk_widget_hide (label);}else{
                gtk_widget_show (label);
        }



}

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer user_data)
{
        gchar *id;
        gchar *nom;
        gchar *prenom;
        gchar *adresse;
        gchar *numtel;
        int salaire;
        gchar *continent;
        int x;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget *p=lookup_widget(gestionAgent,"treeview1");
        GtkTreeSelection *selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {
                gtk_tree_model_get (model,&iter,0,&id,1,&nom,2,&prenom,3,&adresse,4,&numtel,5,&salaire,6,&continent,-1);

                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestionAgent,"entry6")),nom);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestionAgent,"entry7")),prenom);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestionAgent,"entry9")),adresse);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestionAgent,"entry8")),numtel);
                gtk_spin_button_set_value (GTK_SPIN_BUTTON(lookup_widget(gestionAgent,"spin2")),salaire);
                if(strcmp(continent,"Afrique")==0) x=0;
                if(strcmp(continent,"Europe")==0) x=1;
                if(strcmp(continent,"Amerique")==0) x=2;
                if(strcmp(continent,"Asie")==0) x=3;


                char tmp [50];
                strcpy(tmp,"Modifier Agent N ");

                gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(gestionAgent,"combobox2")),x);
                GtkWidget* msg=lookup_widget(gestionAgent,"label20");
                GtkWidget* msgId=lookup_widget(gestionAgent,"label53");

                gtk_label_set_text(GTK_LABEL(msg),tmp);
                gtk_label_set_text(GTK_LABEL(msgId),id);
                gtk_widget_show(msg);
                gtk_widget_show(lookup_widget(gestionAgent,"button5"));
                gtk_notebook_prev_page(GTK_NOTEBOOK(lookup_widget(gestionAgent,"notebook1")));
        }

}

void
on_chercher_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

extern GtkWidget *gestionAgent;
GtkWidget *p1;
GtkWidget *entry;
GtkWidget *labelnom;
GtkWidget *nbResultat;
GtkWidget *message;
char nom[30];
char chnb[30];
int b=0,nb;
entry=lookup_widget(gestionAgent,"entry10");
labelnom=lookup_widget(gestionAgent,"label49");
p1=lookup_widget(gestionAgent,"treeview2");


if(is_empty(entry)==0){
  gtk_widget_show (labelnom);b=0;
}else{
b=1;
gtk_widget_hide (labelnom);}

if(b==0){return;}else{
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(entry)));
nb=ChercherAgentTree(p1,"agents.txt",nom);

sprintf(chnb,"%d",nb);
nbResultat=lookup_widget(gestionAgent,"label51");
message=lookup_widget(gestionAgent,"label50");
gtk_label_set_text(GTK_LABEL(nbResultat),chnb);

gtk_widget_show (nbResultat);
gtk_widget_show (message);



}

}

