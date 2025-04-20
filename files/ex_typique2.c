#include <stdio.h>
#include <stdlib.h>

typedef struct cellule{
	int val;
	struct cellule *suiv;
	}cellule;
	
typedef struct file{
	struct cellule *tete;
	struct cellule *queue;
	}file;
	
file initialiser_file(){
	file f;
	f.tete=f.queue=NULL;
	return f;
	}
	
int est_vide(file f){
	return f.tete==NULL && f.queue==NULL;
	}
	
file enfiler(file f,int x){
	cellule * new_cel=(cellule*)malloc(sizeof(cellule));
	new_cel->val=x;
	new_cel->suiv=NULL;
	if(est_vide(f)){
		f.tete=f.queue=new_cel;}
	else{
		f.queue->suiv=new_cel;
		f.queue=f.queue->suiv;}
	return f;
	}

file afficher(file f){
	cellule *point=f.tete;
	while (point !=NULL){
		printf("%d \t",point->val);
		point=point->suiv;
		}
	return f;
	}
	
file defiler(file f){
	if(est_vide(f)!=1){
		cellule *cel=f.tete;
		f.tete=f.tete->suiv;
		free(cel);
		}
	else{
		printf("je ne peux plus défiler");}
	return f;
	}
int main(){
	int choix,bool,element;
	file f;
	
	do{
	printf("\n------MENU------\n");
	printf("1-initialisez votre file\n");
	printf("2-verifiez si votre file est vide\n");
	printf("3-ajouter un element à votre file\n");
	printf("4-afficher votre file\n");
	printf("5-supprimer un element de votre file\n");
	printf("6-FIN\n");
	
	printf("faites votre choix ");
	scanf("%d",&choix);
	
	switch(choix){
		case 1:
			f=initialiser_file();
			break;
			
		case 2:
			bool=est_vide(f);
			printf("%d",bool);
			break;
		case 3:
			printf("saisissez votre element ");
			scanf("%d",&element);
			f=enfiler(f,element);
			break;
		case 4:
			f=afficher(f);
			break;
		case 5:
			f=defiler(f);
			break;
			
		}
	}while(choix!=6);
	
	return 0;
	}
