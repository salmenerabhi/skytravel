#include <gtk/gtk.h>
typedef struct agent agent;
struct agent{
char id[30];
char nom[30];
char prenom[30];
char adresse[30];
char numtel[9];
int salaire;
char continent[30];
};
int i,j;
GtkWidget *gestionAgent;
GtkWidget *acceuil;
void
on_Ajouter_clicked                     (GtkWidget       *button,
                                        gpointer         user_data);



void
on_Modifier_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_GestionAcceuil_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_AcceuilGestion_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_Supprimer_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_chercher_clicked                    (GtkButton       *button,
                                        gpointer         user_data);
