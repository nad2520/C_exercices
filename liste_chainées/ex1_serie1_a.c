#include <stdio.h>
#include <stdlib.h>
typedef struct cellule{
    int val;
    struct cellule *suiv;
}noeud;
void afficheListe(noeud* tete){
    noeud *p;
    p=tete;
    int n=1;
    while (p!=NULL){
        printf("le noeud %d a comme valeur: %d \n",n,p->val);
        p=p->suiv;
        n++;
    }
    printf("\n");
}
noeud* ajouterEnTete(noeud* tete,int x){
    noeud *new_cel=(noeud*)malloc(sizeof(noeud));
    new_cel->val=x;
    new_cel->suiv=tete;
    tete=new_cel;
    return tete;
}
noeud* ajouterEnFin(noeud* tete,int x){
    noeud *new_cel=(noeud*)malloc(sizeof(noeud));
    new_cel->val=x;
    new_cel->suiv=NULL;
    if (tete==NULL){
        tete=new_cel;
    }
    else{
        noeud *p=tete;
        while(p->suiv!=NULL){
            p=p->suiv;
    }
    p->suiv=new_cel;
    }
    return tete;
}
int main() {
    noeud *tete=NULL;
    tete=ajouterEnFin(tete,5);
    int x;
    printf("saisir x: ");
    scanf("%d",&x);
    int n;
    printf("saisir n: ");
    scanf("%d",&n);
    if(n==1){
        tete=ajouterEnTete(tete,x);
        afficheListe(tete);
    }else{
        tete=ajouterEnFin(tete,x);
        afficheListe(tete);
    }

    return 0;
}