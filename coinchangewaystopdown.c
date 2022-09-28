#include<stdio.h>

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
    int a[100][100];
   // printf("%d",cc(wt,w,n));
   for(int i=0;i<=n;i++){
      for(int j=0;j<=w;j++){
          if(i==0){
              a[i][j]=0;
          }
          else{
              if(j==0){
                  a[i][j]=1;
              }
              else{
                 if(wt[i-1]<=j){
                      a[i][j]=a[i][j-wt[i-1]]+a[i-1][j];
                 }
                 else{
                     a[i][j]=a[i-1][j];
                 }
              }
          }
      
      }
   }
   
   printf("\n");
   for(int i=0;i<=n;i++){
       for(int j=0;j<=w;j++){
          printf("%d\t",a[i][j]);
       }
      printf("\n");
   }
    
return 0;
}
