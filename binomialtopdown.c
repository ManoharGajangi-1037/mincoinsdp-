#include<stdio.h>
int main(){
   int n,k;
   scanf("%d %d",&n,&k);
   int dp[100][100];
   for(int i=0;i<=n;i++){
      for(int j=0;j<=i;j++){
          if(j==0||i==j){
              dp[i][j]=1;
          }
          else{
              dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
          }
      }
   }
   
   for(int i=0;i<=n;i++){
      for(int j=0;j<=k;j++){
          printf("%d\t",dp[i][j]);
      }
      printf("\n");
   }
   
   
return 0;   
   }
