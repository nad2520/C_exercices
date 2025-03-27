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
	tete=ajouterEnTete(tete,x);
    afficher(tete);
    
    return 0;
}
