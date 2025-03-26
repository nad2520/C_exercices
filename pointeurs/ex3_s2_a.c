// Online C compiler to run C program online
#include <stdio.h>
int saisi(){
    int n;
    printf("n= ");
    scanf("%d",&n);
    return n;
}
void saisi_tab(int t[100],int n){
    int *p;
    for(p=t;p<t+n;p++){
        scanf("%d",p);
    }
}
void afficher_tab(int t[100],int n){
    int *p;
    for(p=t;p<t+n;p++){
        printf("%d\t",*p);
    }
}

int calculer(int t[100],int n,int x){
    int *p;
    int i=0;
    for(p=t;p<t+n;p++){
        if (*p==x){
            i++;
        }
    }
    return i;
}
int main() {
    int t[100],n,nb_occ;
    n=saisi();
    saisi_tab(t, n);
    afficher_tab(t, n);
    printf("\n");
    int x=saisi();
    nb_occ=calculer(t,n,x);
    printf("\n");
    printf("%d",nb_occ);
    return 0;
}