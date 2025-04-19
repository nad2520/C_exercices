#include <stdio.h>
#include <stdlib.h>

typedef struct client {
    int val;
    struct client *suiv;
} client;

typedef struct file {
    struct client *tete;
    struct client *queue;
} file;

file *creer_file() {
    file *f= malloc(sizeof(file));
    
    f->tete = f->queue = NULL;
    return f;
}

int file_vide(file * f){
	return (f->tete==NULL)&&(f->queue==NULL);
	}
	
int Taille_file(file * f){
	int taille=0;
	client *temp=f->tete;
	while(temp!=NULL){
		taille++;
		temp=temp->suiv;}
	return taille;
	}

void afficher_file(file * f){
    client *p = f->tete;
    while (p != NULL) {
        printf("%d\t", p->val);
        p = p->suiv;
    }
}

void Ajouter_File (int x, file * f){
	client* new_cel = (client*)malloc(sizeof(client));
    new_cel->val=x;
    new_cel->suiv = NULL;

    if (file_vide(f)) {
        f->tete = f->queue = new_cel;
    } else {
        f->queue->suiv = new_cel;
        f->queue = new_cel;
    }
}

void Extraire_File(int *x,file *f) {
    if (!file_vide(f)) {
        client *p = f->tete;
        *x = p->val;
        f->tete = f->tete->suiv;
        free(p);
        if (f->tete == NULL) {
            f->queue = NULL;
        }
    }
}
	

int main() {
    file *f = creer_file();
    int choix, valeur;

    do {
        printf("\n____ MENU ____\n");
        printf("1 - Ajouter a la file\n");
        printf("2 - Taille de la file\n");
        printf("3 - Afficher la file\n");
        printf("4 - Extraire de la file\n");
        printf("5 - La file est-elle vide ?\n");
        printf("6 - Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("Entrez une valeur à ajouter : ");
                scanf("%d", &valeur);
                Ajouter_File(valeur, f);
                break;

            case 2:
                printf("Taille de la file : %d\n", Taille_file(f));
                break;

            case 3:
                afficher_file(f);
                break;

            case 4:
                Extraire_File(&valeur, f);
                printf("Valeur extraite : %d\n", valeur);
                break;

            case 5:
                if (file_vide(f)) {
                    printf("La file est vide.\n");
                } else {
                    printf("La file n'est pas vide.\n");
                }
                break;

            case 6:
                printf("Fin du programme.\n");
                break;

            default:
                printf("Choix invalide. Réessayez.\n");
        }

    } while (choix != 6);

    // Libération mémoire
    while (!file_vide(f)) {
        Extraire_File(&valeur, f);
    }
    free(f);

    return 0;
}
