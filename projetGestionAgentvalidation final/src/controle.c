#include <stdlib.h>
#include <stdio.h>
#include<string.h>
#include <gtk/gtk.h>
#include "interface.h"
#include "callbacks.h"
#include "controle.h"
int is_inactive(GtkWidget *combobox){
return(gtk_combo_box_get_active (GTK_COMBO_BOX(combobox)));
}
int is_empty(GtkWidget *entry){
char ch[10];
strcpy(ch,gtk_entry_get_text(GTK_ENTRY(entry)));
if(strcmp(ch,"")==0)return 0;
else return 1;
}
