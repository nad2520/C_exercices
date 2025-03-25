// Online C compiler to run C program online
#include <stdio.h>
int saisi(){
    int n;
    printf("n= ");
    scanf("%d",&n);
    return n;
}
void saisi_tab(int a[100],int n){
    int *p;
    for(p=a;p<a+n;p++){
        scanf("%d",p);
    }
}
void affiche_tab(int a[100],int n){
    int *p;
    for(p=a;p<a+n;p++){
        printf("%d\t",*p);
    }
}
void range(int a[100],int n){
    int aide,*p,*p2;
    
    for(p=a,p2=a+n-1;p<(a+(n/2));p++,p2--){
        aide=*p;
        *p=*p2;
        *p2=aide;
        
    }
}
int main() {
    int n, a[100];
    n=saisi();
    saisi_tab(a,n);
    printf("\n");
    affiche_tab(a,n);
    range(a,n);
    printf("\n");
    affiche_tab(a,n);
    return 0;
}