#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cellule{
	char prenom[50];
	int moy;
	struct cellule * suiv;
	}cellule;

typedef struct file{
	struct cellule *tete;
	struct cellule *queue;
	}file;
	
	
file initialiser(){
	file f;
	f.tete=f.queue=NULL;
	return f;
	}
	
int file_vide(file f){
	return (f.queue==NULL && f.tete==NULL);
	}
	
file enfiler(file f,cellule element){
	cellule *new_cel=(cellule*)malloc(sizeof(cellule));
	new_cel->moy=element.moy;
	strcpy(new_cel->prenom, element.prenom);
	new_cel->suiv=NULL;
	if (file_vide(f)!=1){
		f.queue->suiv=new_cel;
		f.queue=f.queue->suiv;
		}
	else{
		f.tete=f.queue=new_cel;
		}
	return f;
	}
	
file afficher(file f){
	cellule *point=f.tete;
	while(point != NULL){
		printf("%s",point->prenom);
		printf("%d\n",point->moy);
		point=point->suiv;}
	return f;
	}

file defiler(file f){
	cellule *point=f.tete;
	if (file_vide(f)!=1){
		f.tete=f.tete->suiv;
		free(point);
		}
	return f;
	}	
	
void admis(file f){
	cellule *point=f.tete;
	while(point != NULL){
		if((point->moy)>=10){
		printf("%s",point->prenom);
		printf("%d\n",point->moy);}
		point=point->suiv;}
	}
	
void refuse(file f){
	cellule *point=f.tete;
	while(point != NULL){
		if((point->moy)<10){
		printf("%s",point->prenom);
		printf("%d\n",point->moy);}
		point=point->suiv;}
	}	
	
int main(){
	file f;
	int choix,bool;
	cellule eleve;
	
	printf("------MENU------\n");
	printf("1 - initialiser votre file\n");
	printf("2 - voir si votre file est vide\n");
	printf("3 - ajouter un eleve à la file\n");
	printf("4 - afficher la file d'eleves\n");
	printf("5 - defiler la file \n");
	printf("6 - afficher la file dont les eleves ont une moyenne sup a 10 \n");
	printf("7 - afficher la file dont les eleves ont une moyenne inf a 10\n");
	printf("8 - FIN");
	
	do{
		printf("\nfaire votre choix: ");
		scanf("%d",&choix);
		
		switch(choix){
			case 1:
			f=initialiser();
			break;
			
			case 2:
			bool=file_vide(f);
			printf("%d",bool);
			break;

			
			case 3:
			getchar();
			printf("saisir prenom: ");
			fgets(eleve.prenom,sizeof(eleve.prenom),stdin);
			printf("saisir moy: ");
			scanf("%d",&(eleve.moy));
			f=enfiler(f,eleve);
			break;
			
			case 4:
			f=afficher(f);
			break;
			
			case 5:
			f=defiler(f);
			break;
			
			case 6:
			admis(f);
			break;
			
			case 7:
			refuse(f);
			break;}
		
		}while(choix!=8);


	return 0;}
