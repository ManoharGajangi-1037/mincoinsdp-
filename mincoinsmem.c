#include<stdio.h>
int dp[100][100];
int min(int a,int b){
    if(a<b){
        return a;
    }
    else{
         return b;
    }
}
int cc(int wt[],int w,int n){
    if(n==0){
        return  dp[n][w]=9999;
    }
    else if(w==0){
         return dp[n][w]=0;
    }
    else if(w==0&&n==0){
         return dp[n][w]=9999;
    }
    else if(dp[n][w]!=-1){
         return dp[n][w];
    }
    else{
          if(wt[n-1]<=w){
              return dp[n][w]=min(1+cc(wt,w-wt[n-1],n),cc(wt,w,n-1));
          }
          else{
             return dp[n][w]=cc(wt,w,n-1);
          }
    }
}
int main(){   
    int n;
    scanf("%d",&n);
    int wt[n];
    for(int i=0;i<n;i++){
         scanf("%d",&wt[i]);
    }
    int w;
    scanf("%d",&w);
    for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++){
             dp[i][j]=-1;
        }
    }
    printf("the min coins are%d\n",cc(wt,w,n));
    
     for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++){
             printf("%d\t",dp[i][j]);
        }
        printf("\n");
    }
return 0;
}
