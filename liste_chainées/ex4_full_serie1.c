#include <stdio.h>
#include <stdlib.h>

typedef struct compte{
	int num;
	char nom[100];
	float solde;
}compte;
typedef struct cellule{
	compte val;
	struct cellule *suiv;
}cellule;

cellule * ajouterEnTete(cellule *tete,compte x){
	cellule *new_cel=(cellule*)malloc(sizeof(cellule));
	new_cel->val=x;
	new_cel->suiv=tete;
	tete=new_cel;
	return tete;
}

void afficher(cellule *tete){
	cellule *p=tete;
	 while(p!=NULL){
		printf("%d\t",p->val.num);
		printf("%f\t",p->val.solde);
		printf("%s\t",p->val.nom);
		printf("\n");
		p=p->suiv;}
}

cellule* AjouterCompte (cellule* tete){
	compte comp;
	do{
		printf("donner votre num: ");
		scanf("%d",&comp.num);
		printf("donner votre nom: ");
		getchar();
		fgets(comp.nom,sizeof(comp.nom),stdin);
		printf("donner votre solde: ");
		scanf("%f",&comp.solde);
	}while(comp.solde<0);
	tete=ajouterEnTete(tete,comp);
	return tete;
}

float SoldeCompte(cellule* tete,int x){
	cellule *p=tete;
	while(p!=NULL){
		if (p->val.num==x){
			return p->val.solde;}
		p=p->suiv;}
	return -1.0f;
}

float total(cellule *tete){
	cellule *p=tete;
	float s=0;
	while(p!=NULL){
		s=s+p->val.solde;
		p=p->suiv;}
	return s;
}

int CompteMax(cellule *tete){
	cellule *p=tete;
	cellule *max=p;
	p=p->suiv;
	while(p!=NULL){
		if((p->val.solde)>(max->val.solde)){
			max=p;
    }
		p=p->suiv;
  }
	return max->val.num;}



int main(){
	cellule *tete=NULL;
	int numero;
	int n,x;

	printf("combien de compte voulez vous ajouter: ");
	scanf("%d",&n);

	for (int i=0;i<n;i++){
	tete=AjouterCompte (tete);}
	
	printf("\n entrer votre numero de compte: ");
	scanf("%d",&numero);
	printf("\n");
	float a=SoldeCompte(tete,numero);
	printf("%f",a);

	printf("\n le total des soldes est ");
	float tot=total(tete);
	printf("%f",tot);

	printf("\n le compte qui a le solde le plus élevé est ");
	x=CompteMax(tete);
	printf("%d",x);
	printf("\n");

	afficher(tete);
	return 0;
}
