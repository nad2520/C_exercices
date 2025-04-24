#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cellule{
	char nom[50],pren[50];
	int age;
	struct cellule *suiv;
	}cellule;
	
typedef struct file{
	struct cellule *tete;
	struct cellule *queue;
	}file;
	
file * creer_file(){
	file *f=(file*)malloc(sizeof(file));
	f->tete=f->queue=NULL;
	return f;}
	
int est_vide(file *f){
	return f->tete==NULL && f->queue==NULL;
	}
	
int Taille_file(file * f){
	int taille=0;
	cellule *point=f->tete;

		while(point !=NULL){
			taille++;
			point=point->suiv;
			}
		return taille;

	}
void afficher_file(file * f){
	cellule * point=f->tete;
	if (est_vide(f)!=1){
		while(point !=NULL){
			printf("%s\n",point->pren);
			printf("%s\n",point->nom);
			printf("%d\n",point->age);
			point=point->suiv;
			}
		}
	}	
void Ajouter_File (cellule * element, file * f){
	cellule * new_cel=(cellule*)malloc(sizeof(cellule));
	strcpy(new_cel->pren,element->pren);
	strcpy(new_cel->nom,element->nom);
	new_cel->age=element->age;
	new_cel->suiv=NULL;
	
	if (est_vide(f)!=1){
		f->queue->suiv=new_cel;
		f->queue=f->queue->suiv;
		}
	else{
		f->tete=f->queue=new_cel;
		}
	}

void Extraire_File (cellule * element, file *f){
	cellule * point=f->tete;
	strcpy(element->pren, point->pren);
    strcpy(element->nom, point->nom);
    element->age = point->age;
	if (est_vide(f)!=1){
		f->tete=f->tete->suiv;
		free(point);}
	}

int main(){
	file *f;
	int choix,bool,taille;
	cellule *element=(cellule*)malloc(sizeof(cellule));
	printf("-------MENU-------\n");
	printf("1- creer votre file\n");
	printf("2- voir si votre file est vide\n");
	printf("3- la taille de votre file\n");
	printf("4- afficher votre file\n");
	printf("5- ajouter un eleve a votre file\n");
	printf("6- supprimer un eleve de votre file\n");
	printf("7- FIN\n");
	
	
	do{
		printf("faire votre choix: ");
		scanf("%d",&choix);
		switch(choix){
			case 1:
			f=creer_file();
			break;
			
			case 2:
			bool=est_vide(f);
			printf("%d\n",bool);
			break ;
			
			case 3:
			taille=Taille_file(f);
			printf("%d\n",taille);
			break;
			
			case 4:
			afficher_file(f);
			break;
			
			case 5:
			getchar();
			printf("saisir votre prenom: ");
			fgets(element->pren,sizeof(element->pren),stdin);
			printf("saisir votre nom: ");
			fgets(element->nom,sizeof(element->nom),stdin);
			printf("saisir votre age: ");
			scanf("%d",&element->age);
			Ajouter_File(element,f);
			break;
			
			case 6:
			Extraire_File (element,f);
			printf("%s\n",element->pren);
			printf("%s\n",element->nom);
			printf("%d\n",element->age);
			break;
			}
			
		}while (choix!=7);
	
	return 0;}
