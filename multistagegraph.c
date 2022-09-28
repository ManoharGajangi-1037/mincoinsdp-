#include<stdio.h>
#include<limits.h>
int main(){
     int n;
     scanf("%d",&n);
     int a[n][n];
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           // printf("a[%d][%d]:\n ",i,j);
            scanf("%d",&a[i][j]);
        }
     }
     int cost[n];
     int c;
     cost[n-1]=0;
      for(int i=n-2;i>=0;i--){
        int  min=INT_MAX;
         for(int j=i+1;j<n;j++){
            if(a[i][j]!=-1){
             c=a[i][j]+cost[j];
             if(c<min){
               min=c;
             }
           }
         }
         cost[i]=min;
     }
     printf("min cost =%d",cost[0]);
    
return 0;
}
