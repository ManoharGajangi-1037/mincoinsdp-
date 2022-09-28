#include<stdio.h>
int a[1000][1000];
int cc(int wt[],int w ,int n){
    if(n==0){
        return a[n][w]=0;
    }
    if(w==0){
        return a[n][w]=1;
    }
    if(a[n][w]!=-1){
          return a[n][w];
    }
    else{
    if(wt[n-1]<=w){
        return a[n][w]=cc(wt,w-wt[n-1],n)+cc(wt,w,n-1);
    }
    else{
        return a[n][w]=cc(wt,w,n-1);
    }
    }
}
int main(){
   printf("enter the no.of coins");
    int n;
    scanf("%d",&n);
    printf("enetr the values");
    int wt[n];
    for(int i=0;i<n;i++){
        scanf("%d",&wt[i]);
    }
    int w;
    printf("enter the change you need to get ");
    scanf("%d",&w);
    for(int i=0;i<=n;i++){
             for(int j=0;j<=w;j++){
                   a[i][j]=-1;
             }   
    }
    printf("%d\n",cc(wt,w,n));
     for(int i=0;i<=n;i++){
             for(int j=0;j<=w;j++){
                   printf("%d\t",a[i][j]);
             }   
             printf("\n");
    }  
return 0;
}
