#include<stdio.h>
int max(int a,int b){
   if(a>b){
      return a;
   }
   else{
       return b;
   }
}

int unboundknapsack(int val[],int wt[],int w,int n){
       if(w==0||n==0){
            return 0;
       }
       if(wt[n-1]<=w){
           return max(val[n-1]+unboundknapsack(val,wt,w-wt[n-1],n),unboundknapsack(val,wt,w,n-1));
       }
       else{
           return unboundknapsack(val,wt,w,n-1);
        }

}
int main(){
    int n;
    scanf("%d",&n);
    int val[n];
    printf("enter the values of the array");
       for(int i=0;i<n;i++){
           scanf("%d",&val[i]);
       }
    int wt[n];
    printf("enter the value of weights of the array");
        for(int i=0;i<n;i++){
           scanf("%d",&wt[i]);
       }
   printf("enter the weight of the knaasack:");
    int w;
     scanf("%d",&w);
     printf("%d",unboundknapsack(val,wt,w,n));    
    
return 0;
}
