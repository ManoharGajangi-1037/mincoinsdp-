#include<stdio.h>
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
   printf("enter the no.of n");
   int n;
   scanf("%d",&n);
   int wt[n];
   printf("enter the values of array");
   for(int i=0;i<n;i++){
       scanf("%d",&wt[i]);
   }
   int w;
   printf("enter the change you need to obtain");
   scanf("%d",&w);
   int a[n+1][w+1];
   for(int i=0;i<=n;i++){
       for(int j=0;j<=w;j++){
          
           if(i==0){
                 a[i][j]=9999;
               
           }
           else if(j==0){
                a[i][j]=0;
                
           }
            /*if(i==0&&j==0){
                 a[i][j]=INT_MAX;
           }
           
           else if(i==1){
                if(j%wt[i-1]==0){
                     a[i][j]=j/wt[i-1];
                }
                else{
                     a[i][j]=INT_MAX;
                }  
           }*/

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

return 0;
}
