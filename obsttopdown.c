#include<stdio.h>
#include<limits.h>
int a[100][100]={0};
int fsum(int freq[],int i,int j){
   int maxsum=0;
    for(int x=i;x<=j;x++){
        maxsum+=freq[x];
    }
    return maxsum;
}
int main(){
   int n;
   scanf("%d",&n);
   int freq[n];
   for(int i=0;i<n;i++){
       scanf("%d",&freq[i]);
   }
   int i,j,min;
   for(int d=0;d<n;d++){
       for(i=0;i<n-d;i++){
            j=i+d;
             min=INT_MAX;
           for(int k=i;k<=j;k++){
              int r=a[i][k-1]+a[k+1][j];
              if(r<min){
                 min=r;
              }
           }
           a[i][j]=min+fsum(freq,i,j);
       }
   }
   printf("%d\n",a[0][n-1]);
return 0;
}
