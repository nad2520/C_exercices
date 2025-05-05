#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cellule{
	int coeff;
	int deg;
	struct cellule *suiv;
	}cellule;
	
cellule *remplissage(cellule *tete){
	cellule *temp=tete;
	cellule *new_cel=(cellule*)malloc(sizeof(cellule));
	printf("donnez le coeff: ");
	scanf("%d",&new_cel->coeff);
	printf("donnez le deg: ");
	scanf("%d",&new_cel->deg);
	new_cel->suiv=NULL;
	if(tete==NULL){
		return new_cel;}
	while(temp->suiv!=NULL){
		temp=temp->suiv;
		}
	temp->suiv=new_cel;
	return tete;
	}
	
cellule *tri_decroi(cellule *tete){
	cellule *point1,*point2;
	int temp;

	if (tete == NULL) return NULL;
	
	for(point1=tete;point1!=NULL;point1=point1->suiv){
		for(point2=point1->suiv;point2!=NULL;point2=point2->suiv){
			if(point2->deg > point1->deg){
				temp=point1->deg;
				point1->deg=point2->deg;
				point2->deg=temp;
				}
			}
		}
	return tete;
	}	
	
int puiss(int a,int b){
	int x=1;
	if(b==0){return 1;}
	for (int i=0;i<b;i++){
		x=x*a;
		}
	return x;
	}
	
int valeur(cellule *tete,int x)	{
	cellule *temp=tete;
	int res=0;
	while(temp!=NULL){
		res=res+(temp->coeff)*(puiss(x,temp->deg));
		temp=temp->suiv;
		}
	return res;
	}
	
void afficher(cellule *tete){
    cellule *temp = tete;
    while (temp != NULL) {
        printf("%d*x^%d", temp->coeff, temp->deg);
        if (temp->suiv != NULL && temp->suiv->coeff >= 0) {
            printf(" + ");
        }
        temp = temp->suiv;
    }
    printf("\n");
}
	
int main(){
	cellule *tete=NULL;
	int x;
	tete=remplissage(tete);
	tete=remplissage(tete);
	tete=remplissage(tete);
	tete=tri_decroi(tete);
	printf("donner une valeur: ");
	scanf("%d",&x);
	int resultat=valeur(tete,x);
	printf("le resultat du polynome est: %d\n",resultat);
	afficher(tete);
	return 0;
	}
