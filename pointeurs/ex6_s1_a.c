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
int indice(int a[100],int d,int f){
    int*p,*min=a+d;int i=d;
    for(p=a+1+d;p<a+f;p++){
        if (*p<*min){
            min=p;
        }
        i++;
    }
    return i;
}
int main() {
    int n, a[100];
    n=saisi();
    saisi_tab(a,n);
    printf("\n");
    affiche_tab(a,n);
    int i=indice(a,2,5);
    printf("\n");
    printf("%d",i);
    return 0;
}