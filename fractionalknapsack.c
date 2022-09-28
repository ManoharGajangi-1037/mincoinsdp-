#include<stdio.h>
int main(){
   int n;
   printf("enter the number of nodes \n:");
   scanf("%d",&n);
  float  val[n];
   printf("enter the values of knapsack\n");
   for(int i=0;i<n;i++){
      scanf("%f",&val[i]);
   }
   float wt[n];
   printf("enter the weights of knapsack\n");
   for(int i=0;i<n;i++){
      scanf("%f",&wt[i]);
   }
   float x,y;
   float temp1;
   float temp2;
   for(int i=0;i<n-1;i++){
       for(int j=0;j<n-i-1;j++){
            x=val[j]/wt[j];
            y=val[j+1]/wt[j+1];
            //printf("%f %f\n",x,y);
            if(x<y){
                temp1=val[j+1];
                temp2=wt[j+1];
                val[j+1]=val[j];
                wt[j+1]=wt[j];
                val[j]=temp1;
                wt[j]=temp2;
            }
       }
   }
   int w;
   printf("enter the maximum weight of the knapsack\n");
   scanf("%d",&w);
   float sum=0;
   for(int i=0;i<n;i++){
        if(wt[i]<=w){
            sum=sum+val[i];
            w=w-wt[i];
        }
        else{
            sum=sum+(w*val[i])/wt[i];
            break;
        }
   }
   
   
  /*  for(int i=0;i<n;i++){
      printf("%f\t",val[i]);
   }
   printf("\n");
    for(int i=0;i<n;i++){
      printf("%f\t",wt[i]);
   }*/
   printf("the max value is%f",sum);
   
return 0;
}
