#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>

#include "voiture.h"

enum
{    
          CODE,
          MARQUE,
          DATE_PRISE,
          HEURE,
          DATE_REST,
          HEURE1,
          PRIX,
          COLUMNS
};
void ajouter_voiture(Voiture V)
{
   FILE *f;
   f=fopen("voitures.txt","a+");
if (f!=NULL)
{
 fprintf(f,"%s %s %s %s %s %s %s  \n",V.code,V.marque,V.date_prise,V.heure,V.date_rest,V.heure1,V.prix);
fclose(f);
}
}


void afficher_voiture(GtkWidget *liste)
{
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
   
    GtkTreeIter  iter;
   
   GtkListStore *store;
 
char code[30] ;
char marque[20];
char date_prise_en_charge[15];
char heure[10];
char date_restitution[15];
char heure1[10];
char prix[10] ;
Voiture V ;
   store=NULL ;
   FILE *f;
   store=gtk_tree_view_get_model(liste);
  if (store==NULL)
  {
     renderer = gtk_cell_renderer_text_new () ;
     column = gtk_tree_view_column_new_with_attributes("code", renderer, "text", CODE,NULL);
     gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;

renderer = gtk_cell_renderer_text_new () ;
     column = gtk_tree_view_column_new_with_attributes("marque", renderer, "text", MARQUE,NULL);
     gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;

renderer = gtk_cell_renderer_text_new () ;
     column = gtk_tree_view_column_new_with_attributes("date_prise_en_charge", renderer, "text", DATE_PRISE,NULL);
     gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;

 renderer = gtk_cell_renderer_text_new () ;
     column = gtk_tree_view_column_new_with_attributes("heure", renderer, "text", HEURE,NULL);
     gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;

renderer = gtk_cell_renderer_text_new () ;
     column = gtk_tree_view_column_new_with_attributes("date_restitution", renderer, "text", DATE_REST,NULL);
     gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;

renderer = gtk_cell_renderer_text_new () ;
     column = gtk_tree_view_column_new_with_attributes("heure1", renderer, "text", HEURE1,NULL);
     gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;

renderer = gtk_cell_renderer_text_new () ;
     column = gtk_tree_view_column_new_with_attributes("prix", renderer, "text", PRIX,NULL);
     gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;


store = gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f = fopen("voitures.txt","r");
if(f==NULL)
return;
else
{
f = fopen("voitures.txt","a+");
while(fscanf(f,"%s %s %s %s %s %s %s\n",code,marque,date_prise_en_charge,heure,date_restitution,heure1,prix)!=EOF)
{
gtk_list_store_append (store,&iter);

gtk_list_store_set (store,&iter,CODE,code,MARQUE,marque,DATE_PRISE,date_prise_en_charge,HEURE,heure,DATE_REST,date_restitution,HEURE1,heure1,PRIX,prix, -1);
}
 fclose(f);
 gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
 g_object_unref (store);
}
}
}


int rechercher_voiture(Voiture V,char code[30])
{
FILE*f;
int t=0;

f=fopen("voitures.txt","r+");
if(f!=NULL){
while(fscanf(f,"%s %s %s %s %s %s %s",V.code,V.marque,V.date_prise,V.heure,V.date_rest,V.heure1,V.prix)!=EOF){
if(strcmp(code,V.code)==0){
t++;
break;
}
}
}fclose(f);
return t;
}

void supprimer_voiture(Voiture V,char code[30])
{
FILE*f;
FILE*t;

f=fopen("voitures.txt","r+");
t=fopen("tmp.txt","w+");
if(f!=NULL){
while(fscanf(f,"%s %s %s %s %s %s %s",V.code,V.marque,V.date_prise,V.heure,V.date_rest,V.heure1,V.prix)!=EOF){
if(strcmp(code,V.code)!=0){
fprintf(t,"%s %s %s %s %s %s %s \n",V.code,V.marque,V.date_prise,V.heure,V.date_rest,V.heure1,V.prix);
}
}
}fclose(t);
fclose(f);
remove("voitures.txt");
rename("tmp.txt","voitures.txt");
}

void modifier_voiture(Voiture V,char code[30])
{

supprimer_voiture(V,code);
ajouter_voiture(V);

}




















