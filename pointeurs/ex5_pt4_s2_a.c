#include <stdio.h>
int saisi() {
    int n;
    printf("n= ");
    scanf("%d", &n);
    return n;
}

void saisi_mat(int t[100][100], int n, int m) {
    int *p, i, j;
    p = &t[0][0];
    for (i=0;i<n;i++) {
        for (j=0;j<m;j++) {
            scanf("%d",p+i*m+j);
        }
    }
}

void afficher_mat(int t[100][100], int n, int m) {
    int *p, i, j;
    p = &t[0][0];
    for (i=0; i<n; i++) {
        for (j= 0; j< m; j++) {
            printf("%d\t", *(p+i*m+j));
        }
        printf("\n");
    }
}

void afficher_mat1(int t[100][100], int n, int m) {
    int *p, i, j;
    p = &t[0][0];
    for (i=0;i<n;i++) {  
        for (j=0;j<m;j++) {
            printf("%d\t", *(p+i*m+j));
        }
        printf("\n");
    }
}

void transpo(int t[100][100], int t1[100][100], int n, int m) {
    int *p,i,j,*p1;
    p = &t[0][0];
    p1 = &t1[0][0];
    for (i=0;i<n;i++) {
        for (j=0;j<m;j++) {
            *(p1+j*n+i)=*(p+i*m+j);
        }
    }
}

int main() {
    int t[100][100], t1[100][100], n, m;
    n=saisi();
    m=saisi();
    saisi_mat(t,n,m);
    printf("\nOriginal Matrix:\n");
    afficher_mat(t,n,m);
    transpo(t,t1,n,m);
    printf("\nTransposed Matrix:\n");
    afficher_mat(t1,m,n);  

    return 0;
}