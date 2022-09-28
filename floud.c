#include<stdio.h>
#define inf 9999 
#include<limits.h>

int min(int x,int y){
   if(x<y){
      return x;
   }
   else{
        return y;
   }
}
int main(){
 
  int n;
  printf("enter the number of vertices ");
  scanf("%d",&n);
  int a[n][n];
  for(int i=0;i<n;i++){
     for(int j=0;j<n;j++){
         printf("a[%d %d]=\n",i,j);
         scanf("%d",&a[i][j]);
    }
  }
   /*for(int i=0;i<n;i++){
     for(int j=0;j<n;j++){
         printf("%d\t",a[i][j]);
    }
    printf("\n");
  }*/
  //int min=INT_MIN;
  for(int k=0;k<n;k++){
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                a[i][j]=0;
            }
            else{
                if(i==k||j==k){
                  a[i][j]=a[i][j];
                }
                else{
                  a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
                }
            
            }
        }
    
      }
      printf("for k =%d\n",k);
          for(int i=0;i<n;i++){
     for(int j=0;j<n;j++){
         printf("%d\t",a[i][j]);
    }
    printf("\n");
  }
  }
  
return 0;
}
