#include <gtk/gtk.h>

typedef struct
{
char code[30] ;
char marque[20];
char date_prise[15];
char heure[10];
char date_rest[15];
char heure1[10];
char prix[10] ;
}Voiture;
void ajouter_voiture(Voiture V);
void afficher_voiture(GtkWidget *liste);
int rechercher_voiture(Voiture V,char code[30]);
void supprimer_voiture(Voiture V,char code[30]);
void modifier_voiture(Voiture V,char code[30]);

