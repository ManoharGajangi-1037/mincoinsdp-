#include<stdio.h>
int arr[100][100];
 
int binomial(int n,int k){
     
     if(n==k||k==0){
           return arr[n][k]=1;
     }
     if(arr[n][k]!=-1){
          return arr[n][k];
     }
     else{
        arr[n][k]=binomial(n-1,k)+binomial(n-1,k-1);
     } 
      return arr[n][k];
}

int main(){
  int n,k;
   scanf("%d",&n);
   scanf("%d",&k);
   
   for(int i=0;i<=n;i++){
      for(int j=0;j<=n;j++){
          arr[i][j]=-1;
      }
   }
   printf("%d\n",binomial(n,k));
   for(int i=0;i<=n;i++){
      for(int j=0;j<=n;j++){
          printf("%d\t",arr[i][j]);
      }
       printf("\n");
   }
return 0;
}

