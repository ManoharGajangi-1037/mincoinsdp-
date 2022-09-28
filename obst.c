#include<stdio.h>
#include<limits.h>

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
        return 0;
   }
   if(i==j){
         return freq[i];
   } 
   else{

         for(int l=i;l<=j;l++){
              int cost=obst(freq,i,l-1)+obst(freq,l+1,j);
              if(cost<mincost){
                  mincost=cost;
              }
         }
       
    }
 return mincost+sum(freq,i,j);  

}
int main(){
     int  n;
     scanf("%d",&n);
     int freq[n];
     for(int i=0;i<n;i++){
         scanf("%d",&freq[i]);
     }
     int res=obst(freq,0,n-1);
     printf("the result is %d",res);
return 0;
}
