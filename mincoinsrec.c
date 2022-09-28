#include<stdio.h>
#include<limits.h>
 int min(int x,int y){
      if(x<y){
          return x;
      }
      else{
           return y;
      }
}
int cc(int wt[],int w ,int n){
    if(n==0){
        return INT_MAX-10;
    }
    if(w==0){
         return 0;
    }
    /*if(n==1){
          if(w%wt[n-1]==0){
               return w/wt[n-1];
          }
          else{
                return INT_MAX;
          }
    }*/
    if(wt[n-1]<=w){
         return min(1+cc(wt,w-wt[n-1],n),cc(wt,w,n-1));
    }
    else{
          return cc(wt,w,n-1);
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
    printf("%d",cc(wt,w,n));
       
return 0;
}
