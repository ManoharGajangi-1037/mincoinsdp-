#include<stdio.h>
#include<limits.h>
int a[100][100];
int sum(int freq[],int i,int j){
    int maxsum=0;
    for(int k=i;k<=j;k++){
       maxsum=maxsum+freq[k];
    }
    return maxsum;
}
int obst(int freq[],int i,int j){
   int mincost =INT_MAX;
   if(i>j){
        return a[i][j]=0;
   }
   if(a[i][j]!=-1){
          return a[i][j];
   }
   else{
   if(i==j){
         return a[i][j]=freq[i];
   } 
   
      else{

          for(int l=i;l<=j;l++){
              int cost=obst(freq,i,l-1)+obst(freq,l+1,j);
              if(cost<mincost){
                  mincost=cost;
              }
         }
       
    }
     return a[i][j]=mincost+sum(freq,i,j);  
  }
}
int main(){
     int  n;
     scanf("%d",&n);
     int freq[n];
     for(int i=0;i<n;i++){
         for(int j=0;j<n;j++){
              a[i][j]=-1;
         }
     }
     for(int i=0;i<n;i++){
         scanf("%d",&freq[i]);
     }
     int res=obst(freq,0,n-1);
     printf("the result is %d\n",res);
      for(int i=0;i<n;i++){
         for(int j=0;j<n;j++){
              printf("%d\t",a[i][j]);
         }
         printf("\n");
     }
return 0;
}
