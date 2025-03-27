// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
typedef struct noeud{
    int val;
    struct noeud* suiv;
}noeud;
noeud *ajouterEnFin(noeud* tete,int x){
	noeud* new_cel,*p=tete;
    new_cel=(noeud*)malloc(sizeof(noeud));
    new_cel->val=x;
    new_cel->suiv=NULL;
    if(tete==NULL){
		tete=new_cel;
	}
	else {
    while (p->suiv!=NULL){
		p=p->suiv;
	}
	p->suiv=new_cel;}
	return tete;
}

void afficher (noeud* tete){
    noeud* p=tete;
    while (p!=NULL){
        printf("%d\t",p->val);
        p=p->suiv;
    }
}

int main() {
    noeud* tete=NULL;
    int x;
    scanf("%d",&x);
	  tete=ajouterEnFin(tete,x);
    afficher(tete);
    
    return 0;
}
