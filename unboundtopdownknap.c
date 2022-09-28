#include<stdio.h>
int dp[100][100]; 

int max(int a ,int b){
     if(a>b){
         return a;
     }
     else{
         return b;
     }

}
int ks(int  wt[],int val[],int n,int w){
   for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++)
        {
             if(i==0||j==0){
             	dp[i][j]=0;
             	continue;
             }
             if(wt[i-1]<=j){
             
              dp[i][j]=max(val[i-1]+dp[i][j-wt[i-1]],dp[i-1][j]);
               /* int x;
               
                int y ;
                y=dp[i-1][j];
                if(x>y){
                    dp[i][j]=x;
                }
                else{
                   dp[i][j]=y;
                }*/
             }
             else{
             		dp[i][j]=dp[i-1][j];
             		
             }
        }
   }
 return dp[n][w];  
}   
int main(){
   int n;
   scanf("%d",&n);
   int w;
   scanf("%d",&w);
   int val[n];
   int wt[n];
   for(int i=0;i<n;i++){
       scanf("%d",&val[i]);
   }
   for(int i=0;i<n;i++){
       scanf("%d",&wt[i]);
   }
   
   int res=ks(wt,val,n,w);
   printf("%d\n",res);
   for(int i=0;i<=n;i++){
       for(int j=0;j<=w;j++){
                printf("%d\t",dp[i][j]);
       }
       printf("\n");
   }
   return 0;
}
