// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
typedef struct noeud{
    int val;
    struct noeud* suiv;
}noeud;
noeud *creer_liste(int n){
    noeud* tete,*new_cel;
    for(int i=0;i<n;i++){
        if (i==0){
            tete=(noeud*)malloc(sizeof(noeud));
            new_cel=tete;
        }
        else{
            new_cel->suiv=(noeud*)malloc(sizeof(noeud));
            new_cel=new_cel->suiv;
        }
        scanf("%d",&new_cel->val);
    }
    new_cel->suiv=NULL;
    return(tete);
}
void afficher (noeud* tete){
    noeud* p=tete;
    while (p!=NULL){
        printf("%d\t",p->val);
        p=p->suiv;
    }
}
int main() {
    int n;
    printf("n= ");
    scanf("%d",&n);
    noeud* tete=creer_liste(n);
    afficher(tete);
    return 0;
}
