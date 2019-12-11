#include <stdlib.h>
#include <stdio.h>
#include<string.h>
#include <gtk/gtk.h>
#include "interface.h"
#include "callbacks.h"
#include "tree.h"

GtkListStore *adstore;
GtkTreeViewColumn *adcolumn;
GtkCellRenderer *cellad;
FILE *f;

void Agenttree(GtkWidget* treeview1,char*l)
{

agent a;


        
        adstore = gtk_list_store_new(7,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_INT,
                                     G_TYPE_STRING);
       
        f=fopen(l,"r");
while(fscanf(f,"%s %s %s %s %s %d %s\n",a.id,a.nom,a.prenom,a.adresse,a.numtel,&a.salaire,a.continent)!=EOF)
        {GtkTreeIter pIter;

         
         gtk_list_store_append(adstore, &pIter);
         
         gtk_list_store_set(adstore, &pIter,
                            0,a.id,
                            1,a.nom,
                            2,a.prenom,
                            3,a.adresse,
                            4,a.numtel,
                            5,a.salaire,
                            6,a.continent,
                            -1);}
        fclose(f);

	
if(i==0)
	{cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("ID",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


        
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("NOM",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("PRENOM",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("ADERESSE",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("NUMTEL",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("SALAIRE",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);
	
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("CONTINENT",
                                                            cellad,
                                                            "text", 6,
                                                            NULL);
	
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);







	i++;}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(adstore)  );

}



void Agenttree1(GtkWidget* treeview1,char*l)
{

agent a;


        
        adstore = gtk_list_store_new(7,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_INT,
                                     G_TYPE_STRING);
       
        f=fopen(l,"r");
while(fscanf(f,"%s %s %s %s %s %d %s\n",a.id,a.nom,a.prenom,a.adresse,a.numtel,&a.salaire,a.continent)!=EOF)
        {GtkTreeIter pIter;
	
         
         gtk_list_store_append(adstore, &pIter);
         
         gtk_list_store_set(adstore, &pIter,
                            0,a.id,
                            1,a.nom,
                            2,a.prenom,
                            3,a.adresse,
                            4,a.numtel,
                            5,a.salaire,
                            6,a.continent,
                            -1);}
        fclose(f);

	
if(j==0)
	{cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("ID",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


        
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("NOM",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("PRENOM",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("ADERESSE",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("NUMTEL",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("SALAIRE",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);
	
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("CONTINENT",
                                                            cellad,
                                                            "text", 6,
                                                            NULL);
	
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);







	j++;}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(adstore)  );

}



int ChercherAgentTree(GtkWidget* treeview1,char*l,char*nom)
{

agent a;
int nb=0;

        
        adstore = gtk_list_store_new(7,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_INT,
                                     G_TYPE_STRING);
        
        f=fopen(l,"r");
while(fscanf(f,"%s %s %s %s %s %d %s\n",a.id,a.nom,a.prenom,a.adresse,a.numtel,&a.salaire,a.continent)!=EOF)
        {
	if( strcmp(nom,a.nom)==0){ nb++;
	GtkTreeIter pIter;
         
         gtk_list_store_append(adstore, &pIter);
        
         gtk_list_store_set(adstore, &pIter,
                            0,a.id,
                            1,a.nom,
                            2,a.prenom,
                            3,a.adresse,
                            4,a.numtel,
                            5,a.salaire,
                            6,a.continent,
                            -1);}
}
        fclose(f);

	
if(j==0)
	{cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("ID",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


        
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("NOM",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("PRENOM",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("ADERESSE",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("NUMTEL",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("SALAIRE",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);
	
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("CONTINENT",
                                                            cellad,
                                                            "text", 6,
                                                            NULL);
	
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);







	j++;}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(adstore)  );
return nb;
}







