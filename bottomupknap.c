#include<stdio.h>
#include<stdlib.h>
int dp[100][100];
int knapsack(int wt[],int val[],int n,int w){
     int x;
     int y;
     if(n==0||w==0){
               return  dp[n][w]=0;
     }
     if(dp[n][w]!=-1){
              return dp[n][w];
     }
     if(wt[n-1]<=w){
          x=val[n-1]+knapsack(wt,val,n-1,w-wt[n-1]);
          y=knapsack(wt,val,n-1,w);
          if(x>y){
               return dp[n][w]=x;
          }  
          else {
               return dp[n][w]=y;
          }         
     }
     else{
          return dp[n][w]=knapsack(wt,val,n-1,w);
     }



}
int main(){
   int n;
   int w;
   printf("enter the number of items");
   scanf("%d",&n);
   printf("enter the max weight");
   scanf("%d",&w);
   int val[n];
   int wt[n];
   printf("enter the values of items");
   for(int i=0;i<n;i++){
       scanf("%d",&val[i]);
   }
   printf("enter the weights of items");
   for(int i=0;i<n;i++){
      scanf("%d",&wt[i]);
   }
  // printf("enter the values into the matrix\n");
   for(int i=0;i<=n;i++){
       for(int j=0;j<=w;j++){
            dp[i][j]=-1;
       }
   }
   int res;
   res=knapsack(wt,val,n,w);
   printf("%d\n",res);
   for(int i=0;i<=n;i++){
       for(int j=0;j<=w;j++){
            printf("%d\t",dp[i][j]);
       }
       printf("\n");
   }
   
}


