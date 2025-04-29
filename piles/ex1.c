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

int est_vide(pile p){
	return p==NULL;}
	
void empiler(pile *p){
	cellule *new_cel=(cellule*)malloc(sizeof(cellule));
	int x;
	printf("donner votre element: ");
	scanf("%d",&x);
	new_cel->val=x;
	new_cel->suiv=*p;
	*p=new_cel;
	}
	
void depiler(pile *p){
	cellule *point=*p;
	(*p)=(*p)->suiv;
	free(point);
	}
	
void afficher(pile *p){
	cellule *point=*p;
	while((point)!=NULL){
		printf("%d",(point)->val);
		(point)=(point)->suiv;}
	}
	
int max(pile *p){
	int val_max=(*p)->val;
	while((*p)!=NULL){
		if(((*p)->val)>val_max){
			val_max=((*p)->val);
			}
		(*p)=(*p)->suiv;}
	return val_max;
	}

int nbElement(pile *p){
	int nb=0;
	cellule *point=*p;
	while((point)!=NULL){
		nb++;
		(point)=(point)->suiv;}
	return nb;
	}
	
void separer(pile p){
	cellule *point=p;
	while(point!=NULL){
		if ((point->val)%2==0){
			printf("%d\t",point->val);
			}
		point=point->suiv;
		}
	point=p;
	printf("\n");
	while(point!=NULL){
		if ((point->val)%2!=0){
			printf("%d\t",point->val);
			}
		point=point->suiv;
		}
	}
int main(){
	pile p;
	int choix,bool,val_max,nb;
	
	printf("------MENU------\n");
	printf("1 - initialiser votre pile\n");
	printf("2 - empiler\n");
	printf("3 - depiler\n");
	printf("4 - afficher la pile \n");
	printf("5 - afficher le max de la pile \n");
	printf("6 - afficher le nombre d'elemnts\n");
	printf("7 - creer 2 piles une paire et une impaire\n");
	printf("8 - FIN");
	
	do{
		printf("\nfaire votre choix: ");
		scanf("%d",&choix);
		switch(choix){
			case 1:
			initialiser_pile(&p);
			bool=est_vide(p);
			printf("%d",bool);
			break;
			
			case 2:
			empiler(&p);
			break;
			
			case 3:
			depiler(&p);
			break;
			
			case 4:
			afficher(&p);
			break;
			
			case 5:
			val_max=max(&p);
			printf("%d",val_max);
			break;
			
			case 6:
			nb=nbElement(&p);
			printf("%d",nb);
			break;
			
			case 7:
			separer(p);
			break;
			
			case 8:
			printf("FIN");
			break;}
		}while(choix!=8);
	
	return 0;}
