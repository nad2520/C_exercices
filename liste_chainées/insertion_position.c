#include <stdio.h>
#include <stdlib.h>
typedef struct cellule{
    int val;
    struct cellule *suiv;
}noeud;
noeud *creer(int n){
    noeud*tete;
    noeud*p;
    for(int i=0;i<n;i++){
        if (i==0){
            tete=(noeud*)malloc(sizeof(noeud));
            p=tete;
        }else{
            p->suiv=(noeud*)malloc(sizeof(noeud));
            p=p->suiv;
        }
        scanf("%d",&p->val);
    }
    p->suiv=NULL;
    return(tete);
}
void afficher(noeud *tete){
    noeud*p=tete;
    while(p!=NULL){
        printf("%d \t",p->val);
        p=p->suiv;}
    printf("\n");
}
noeud *inserer(noeud *tete,int x,int pos){
    noeud* newCel=(noeud*)malloc(sizeof(noeud));
    newCel->val=x;
    noeud *p;
    p=tete;
    if (pos==0){
        tete=newCel;
        newCel->suiv=NULL;
    }
    else{
        int i=1;
        while(i+1<pos){
            p=p->suiv;
            i++;
        }
        newCel->suiv=p->suiv;
        p->suiv=newCel;
    }
    return tete;
}
int main(){
    noeud *tete=NULL;
    printf("donner vos valeurs");
    tete=creer(5);
    afficher(tete);
    inserer(tete,10,2);
    afficher(tete);
    return 0;
}