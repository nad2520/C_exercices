#include <stdio.h>
#include <stdlib.h>
typedef struct cellule{
    int val;
    struct cellule *suiv;
}noeud;
noeud *CreerListe(int n){
    int x;
    noeud *p;
    noeud *tete;
    for(int i=0;i<n;i++){
        if(i==0){
            tete=(noeud*)malloc(sizeof(noeud));
            p=tete;
        }
        else{
        p->suiv=(noeud*)malloc(sizeof(noeud));
        p=p->suiv;}
        scanf("%d",&p->val);
    }
    p->suiv=NULL;
    return(tete);
}
void afficher(noeud *tete){
    noeud *p;
    p=tete;
    while(p!=NULL){
        printf("%d \t",p->val);
        p=p->suiv;
    }
    printf("\n");
}
noeud* inverse(noeud *tete1){
    noeud* tete2=NULL;
    noeud*p;
    p=tete1;
    while(p!=NULL){
        noeud *p2=(noeud*)malloc(sizeof(noeud));
        p2->val=p->val;
        p2->suiv=tete2;
        tete2=p2;
        p=p->suiv;
    }
    return tete2;
}
int main(){
    noeud *tete;
    noeud *tete2;
    int n;
    printf("n= ");
    scanf("%d",&n);
    tete=CreerListe(n);
    afficher(tete);
    tete2=inverse(tete);
    afficher(tete2);
    
}