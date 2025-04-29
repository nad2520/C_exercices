// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
typedef struct cellule{
	char nom[50];
	int age;
	struct cellule *suiv;
	}cellule;
typedef cellule *pile;

void initialiser_pile(pile *p){
	*p=NULL;
	}
	
void Empiler (pile *p){
	cellule *new_cel=(cellule*)malloc(sizeof(cellule));
	getchar();
	printf("saisir votre nom: ");
	fgets(new_cel->nom,sizeof(new_cel->nom),stdin);
	printf("saisir votre age: ");
	scanf("%d",&new_cel->age);
	new_cel->suiv=*p;
	*p=new_cel;
	}
	
void depiler (pile *p){
	cellule *point=*p;
	*p=(*p)->suiv;
	free(point);
	}
	
void afficher(pile *p){
	cellule *point=*p;
	while(point !=NULL){
		printf("%s\n",point->nom);
		printf("%d\n",point->age);
		point=point->suiv;}
	}
	
pile sommet_p(pile p){
	return p;
	}
	
void liberer(pile *p){
	cellule *point=*p;
	while(point!=NULL){
		*p=(*p)->suiv;
		free(point);
		}
	}
int main(){
	pile p,sommet;
	int choix;
	printf("\n------MENU------\n");
	printf("1 - initialiser votre pile\n");
	printf("2 - empiler\n");
	printf("3 - depiler\n");
	printf("4 - afficher votre pile\n");
	printf("5 - regarder le sommet\n");
	printf("6 - liberation de la memoire\n");
	printf("7 - FIN\n");
	
	do{
		printf("faire votre choix: ");
		scanf("%d",&choix);
		switch(choix){
			case 1:
			initialiser_pile(&p);
			break;
			
			case 2:
			Empiler (&p);
			break;
			
			case 3:
			depiler(&p);
			break;
			
			case 4:
			afficher(&p);
			break;
			
			case 5:
			sommet=sommet_p(p);
			printf("%s\n",sommet->nom);
			printf("%d\n",sommet->age);
			break;
			
			case 6:
			liberer(&p);
			break;
		}
	}while (choix!=7);
	return 0;
}
