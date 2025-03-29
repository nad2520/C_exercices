// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
typedef struct patient{
	char nom[100];
	char prenom[100];
	int rdv;
}patient;
typedef struct cellule{
	patient val;
	struct cellule *suiv;
}cellule;

cellule* ajouterEnFin(cellule*tete,patient p){
	cellule *point=tete;
	cellule *new_cel=(cellule*)malloc(sizeof(cellule));
	new_cel->val=p;
	new_cel->suiv=NULL;
	if(tete==NULL){
	tete=new_cel;
	}
	else{
		while(point->suiv!=NULL){
			point=point->suiv;
		}
		point->suiv=new_cel;
	}
	return tete;
}
cellule* AjoutPatient(cellule *tete, patient p){
	getchar();
	printf("saisir votre nom: ");
	fgets(p.nom,sizeof(p.nom),stdin);
	printf("saisir votre prenom: ");
	fgets(p.prenom,sizeof(p.prenom),stdin);
	printf("saisir votre rdv 1 ou 0: ");
	scanf("%d",&p.rdv);
	tete=ajouterEnFin(tete,p);
	return tete;
}

void afficher(cellule *tete){
	cellule *p=tete;
	
	while(p!=NULL){
		printf("%s\n",p->val.nom);
		printf("%s\n",p->val.prenom);
		printf("%d\n\n",p->val.rdv);
		p=p->suiv;
}}

void RendezVous(cellule *tete,int *rdv,int *sansRdv){
	cellule *p=tete;
	while(p!=NULL){
		if (p->val.rdv==0){
			*sansRdv=*sansRdv+1;
		}
		else{
			*rdv=*rdv+1;
		}
		p=p->suiv;
	}
}
"~~~~~suppression~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
cellule* supp_tete(cellule* tete){
	cellule *p;
	if (tete != NULL){
	p=tete;
	tete=tete->suiv;
	free(p);
	}
	return tete;
}
cellule* supprime(cellule *tete,int pos){
	cellule *supp,*p;
	int i;
	if (tete==NULL || pos==1){
	tete=supp_tete(tete);
	}
	else{
		p=tete;
		i=1;
		while(p->suiv->suiv!=NULL && i<pos-1){
			p=p->suiv;
			i++;
		}
	supp=p->suiv;
	p->suiv=p->suiv->suiv;
	free(supp);
	}
	return tete;
}
cellule* SupprimePatient(cellule *tete){
	cellule *p=tete;
	int avecrdv=0;
	int pos=1;
	while(p!=NULL){
		if(p->val.rdv==1){
			avecrdv++;
		}
		p=p->suiv;}
	if(avecrdv==0){
		tete=supprime(tete,1);
	}
	else{
		p=tete;
		while(p!=NULL && p->val.rdv!=1){
			p=p->suiv;
			pos++;
		}
		tete=supprime(tete,pos);
	}
	return tete;
	
}
"~~~~~suppression~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
void ConsulterSalleAttente(cellule *tete){
	cellule *p=tete;
	while(p!=NULL){
		if (p->val.rdv==1){
			printf("%s\n",p->val.prenom);
		}
		p=p->suiv;
	}
	printf("\n");
	p=tete;
	while(p!=NULL){
		if (p->val.rdv==0){
			printf("%s\n",p->val.prenom);
		}
		p=p->suiv;
	}
	
}
int main(){
	cellule *tete=NULL;
	patient p;
	int n;
	printf("saisir le nombre d'ajout que vous voulez ");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		tete=AjoutPatient(tete,p);
	}
	afficher(tete);
	int rdv=0,sansRdv=0;
	RendezVous(tete,&rdv,&sansRdv);
	printf("le nombre de ceux avec rdv est :%d\n",rdv);
	printf("le nombre de ceux sans rdv est :%d",sansRdv);
	tete=SupprimePatient(tete);
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	afficher(tete);
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	ConsulterSalleAttente(tete);
	return 0;
}
