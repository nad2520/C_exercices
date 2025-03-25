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
void elimine(int a[100],int *n,int x){
    int*p,*p1,i=0,test;
    for(p=a;p<a+(*n);p++){
        while (*p==x){
            for(p1=p;p1<p+(*n);p1++){
                *p1=*(p1+1);
            }
            (*n)--;
        }
    }
}
int main() {
    int n, a[100];
    n=saisi();
    saisi_tab(a,n);
    printf("\n");
    affiche_tab(a,n);
    printf("\n");
    int x=saisi();
    elimine(a,&n,x);
    printf("\n");
    affiche_tab(a,n);
    
    return 0;
}