#include <stdio.h>
void saisir_tab(int a[100],int n){
    int *p1;
    int i=0;
    for(p1=a;p1<a+n;p1++){
        printf("t[%d]= ",i);
        scanf("%d",p1);
        i++;
    }
}
void afficher(int a[100],int n){
    int *p1;
    for(p1=a;p1<a+n;p1++){
        printf("%d\t",*p1);
    }
}

void comb(int a[100], int b[100], int n) {
    int *p1, *p2;
    
    for (p1 = a + n, p2 = b; p2 < b + 4; p1++, p2++) {
        *p1 = *p2;
    }
}

int main() {
    int a[100];
    int b[100];
    int n=3;
    saisir_tab(a,n);
    saisir_tab(b,4);
    afficher(a,n);
    printf("\n");
    afficher(b,4);
    printf("\n");
    comb(a,b,n);
    afficher(a,n+4);
    return 0;
}
