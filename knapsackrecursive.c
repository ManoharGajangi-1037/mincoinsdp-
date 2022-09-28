#include<stdio.h>
#include<stdlib.h>
int knapsack(int wt[],int val[],int n,int w){
     int x;
     int y;
     if(n==0||w==0){
               return 0;
     }
     if(wt[n-1]<=w){
          x=val[n-1]+knapsack(wt,val,n-1,w-wt[n-1]);
          y=knapsack(wt,val,n-1,w);
          if(x>y){
               return x;
          }  
          else {
               return y;
          }         
     }
     else{
          return knapsack(wt,val,n-1,w);
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
   int res;
   res=knapsack(wt,val,n,w);
   printf("%d",res);
}


