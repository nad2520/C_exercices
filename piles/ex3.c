#include <stdio.h>
#include <stdlib.h>

typedef struct cellule{
	int val;
	struct cellule *suiv;
	}cellule;
	
typedef cellule *pile;

void initialiser_pile(pile *p){
	*p=NULL;
	}
	
int nb_element(pile p){
	cellule *point=p;
	int nb=0;
	while (point!=NULL){
		nb++;
		point=point->suiv;
		}
	return nb;
	}

void afficher_pile(pile p){
	cellule *point=p;
	while(point!=NULL){
		printf("%d",point->val);
		point=point->suiv;
		}
	}
	
int pile_vide(pile p){
	return p==NULL;
	}
	
void empiler(int x,pile *p){
	cellule *new_cel=(cellule*)malloc(sizeof(cellule));
	new_cel->val=x;
	new_cel->suiv=*p;
	*p=new_cel;
	}
	
void depiler(int *x,pile *p){
	*x=(*p)->val;
	cellule *point=*p;
	(*p)=(*p)->suiv;
	free(point);
	}

int main(){
	pile p;
	int x,choix,bool,nb;

	printf("\n------MENU------\n");
	printf("1 - initialiser votre pile\n");
	printf("2 - calcul nb elements de la pile\n");
	printf("3 - afficher la pile\n");
	printf("4 - voir si la pile est vide\n");
	printf("5 - empiler\n");
	printf("6 - depiler\n");
	printf("7 - FIN\n");
	
	do{
		printf("faire votre choix: ");
		scanf("%d",&choix);
		switch(choix){
			case 1:
			initialiser_pile(&p);
			break;
			
			case 2:
			nb=nb_element(p);
			printf("%d\n",nb);
			break;
			
			case 3:
			afficher_pile(p);
			break;
			
			case 4:
			bool=pile_vide(p);
			printf("%d\n",bool);
			break;
			
			case 5:
			printf("saisir votre element: ");
			scanf("%d",&x);
			empiler(x,&p);
			break;
			
			case 6:
			depiler(&x,&p);
			printf("%d\n",x);
			break;
			
		}
	}while (choix!=7);
	
	return 0;}
