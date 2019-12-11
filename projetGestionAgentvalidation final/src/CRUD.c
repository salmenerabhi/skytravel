#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include "callbacks.h"
#include<string.h>


void ajout( agent a){
FILE*f=NULL;
f=fopen("agents.txt","a+");
fprintf(f,"%s %s %s %s %s %d %s\n",a.id,a.nom,a.prenom,a.adresse,a.numtel,a.salaire,a.continent);
fclose(f);

}

int exist(char*id){
FILE*f=NULL;
 agent a;
f=fopen("agents.txt","r");
while(fscanf(f,"%s %s %s %s %s %d %s\n",a.id,a.nom,a.prenom,a.adresse,a.numtel,&a.salaire,a.continent)!=EOF){
if(strcmp(a.id,id)==0)return 1;
}
fclose(f);
return 0;
}


void supp(char*id){
FILE*f=NULL;
FILE*f1=NULL;
agent a;
f=fopen("agents.txt","r");

f1=fopen("ancien.txt","w+");
while(fscanf(f,"%s %s %s %s %s %d %s\n",a.id,a.nom,a.prenom,a.adresse,a.numtel,&a.salaire,a.continent)!=EOF){
if(strcmp(id,a.id)!=0)fprintf(f1,"%s %s %s %s %s %d %s\n",a.id,a.nom,a.prenom,a.adresse,a.numtel,a.salaire,a.continent);
}
fclose(f);
fclose(f1);
remove("agents.txt");
rename("ancien.txt","agents.txt");
}
