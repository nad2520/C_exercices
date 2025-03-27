// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

typedef struct noeud{
    int val;
    struct noeud* suiv;
}noeud;

noeud *ajouterEnTete(noeud* tete,int x){
    noeud* new_cel;
    new_cel=(noeud*)malloc(sizeof(noeud));
    new_cel->val=x;
    new_cel->suiv=tete;
    tete=new_cel;
    return tete;
}

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
    int n;
    for (int i=0;i<3;i++){
		printf("choisir votre option 1 ou 0: ");
		scanf("%d",&n);
		if(n==1){
			printf("choisir la valeur que vous voulez ajouter en tete");
			int x;
			scanf("%d",&x);
			tete=ajouterEnTete(tete,x);}
		else{
			printf("choisir la valeur que vous voulez ajouter en fin");
			int x;
			scanf("%d",&x);
			tete=ajouterEnFin(tete,x);
			}
	}
    afficher(tete);
    return 0;
}
