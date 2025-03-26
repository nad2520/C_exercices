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

int verif(int t[100],int t2[100],int n){
    int *p,*p2;
    p2=t2;
    for(p=t;p<t+n;p++){
        if (*p==*p2){
            *p2++;}
        else{
            return 0;
        }
    }
    return 1;
}
int main() {
    int t[100],t2[100],n;
    n=saisi();
    saisi_tab(t, n);
    afficher_tab(t, n);
    printf("\n");
    saisi_tab(t2, n);
    afficher_tab(t2, n);
    int x=verif(t,t2,n);
    if (x==1){
        printf("VRAI");
    }
    else{
        printf("FAUX");
    }
    return 0;
}