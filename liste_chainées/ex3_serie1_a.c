// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct cellule{
    char val;
    struct cellule *suiv;
}noeud;
noeud *CreerListe(int n){
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
        scanf(" %c",&p->val);
    }
    p->suiv=NULL;
    return(tete);
}
void afficher(noeud *tete){
    noeud *p;
    p=tete;
    while(p!=NULL){
        printf("%c",p->val);
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
int palindrome(noeud *tete1,noeud *tete2){
    noeud *p,*p2;
    p=tete1;
    p2=tete2;
    while(p!=NULL){
        if(p->val!=p2->val){
            return 0;
        }
        
        p=p->suiv;
        p2=p2->suiv;
    return 1;
    }
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
    printf("\n");
    afficher(tete2);
    int x=palindrome(tete,tete2);
    if (x==1){
        printf("est palindrome");}
    else{
        printf("n'est pas palindrome");
    }
    
}