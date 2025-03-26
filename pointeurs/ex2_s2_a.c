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
void nega(int t[100],int tn[100],int n,int *i){
    int *p,*pn;
    pn=tn;
    for(p=t;p<t+n;p++){
        if (*p<0){
            (*i)++;
            *pn=*p;
            pn++;
        }
    }
}
void posi(int t[100],int tp[100],int n,int *i){
    int *p,*pp;
    pp=tp;
    for(p=t;p<t+n;p++){
        if (*p>0){
            (*i)++;
            *pp=*p;
            pp++;
        }
    }
}
int main() {
    int t[100],tp[100],tn[100],n,i=0,j=0;
    n=saisi();
    saisi_tab(t, n);
    afficher_tab(t, n);
    printf("\n");
    nega(t,tn,n,&i);
    afficher_tab(tn, i);
    printf("\n");
    posi(t,tp,n,&j);
    afficher_tab(tp, j);
    return 0;
}