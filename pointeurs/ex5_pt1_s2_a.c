// Online C compiler to run C program online
#include <stdio.h>
int saisi(){
    int n;
    printf("n= ");
    scanf("%d",&n);
    return n;
}
void saisi_mat(int t[100][100],int n,int m){
    int *p,i,j;
    p=&t[0][0];
    for(i=0;i<n;i++){
        for(j=0;j<m;j++)
        { scanf(" %d" , p+i*m+j);}}
}
void afficher_mat(int t[100][100],int n,int m){
    int *p,i,j;
    p=&t[0][0];
    for(i=0;i<n;i++){
        for(j=0;j<m;j++)
        { printf(" %d\t" , *(p+i*m+j));
        }printf("\n");}
}


int main() {
    int t[100][100],n,m;
    n=saisi();
    m=saisi();
    saisi_mat(t, n,m);
    afficher_mat(t, n,m);
    
    return 0;
}