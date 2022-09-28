#include<stdio.h>
#include<limits.h>
int min(int a ,int b){
   if(a<b){
       return a;
   }
   else{return b;}
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
   int a[n+1][w+1];
   for(int i=0;i<=n;i++){
     for(int j=0;j<=w;j++){
       if(i==0){
          a[i][j]=INT_MAX-10;
       }
       else if(j==0){
          a[i][j]=0;
       }
       else{
          if(wt[i-1]<=j){
              a[i][j]=min(1+a[i][j-wt[i-1]],a[i-1][j]);
          }
          else{
             a[i][j]=a[i-1][j];
          }
       
       }
       
     }
   }
   for(int i=0;i<=n;i++){
     for(int j=0;j<=w;j++){
        printf("%d\t",a[i][j]);
     }
     printf("\n");
   }
   printf("max ways%d",a[n][w]);
return 0;
}
