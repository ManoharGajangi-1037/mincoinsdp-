#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct array{
       int x;
       int y;
 };   
int main(){

 struct array arr[5];
   
     for(int i =0;i<5;i++){
         scanf("%d %d",&arr[i].x,&arr[i].y);
            }
            
  printf("the given points\n");
  for(int i =0;i<5;i++){
         printf("%d %d\t ",arr[i].x,arr[i].y);
            }
            printf("\n");
            int mindist;
            mindist=((arr[1].x-arr[0].x)*(arr[1].x-arr[0].x)+(arr[1].y-arr[0].y)*(arr[1].y-arr[0].y));
            printf("%d\n",mindist);//for checking of distance b/w first two points
 int min;
 int indi,indj;
 for(int i =0;i<5;i++){
       for(int j=i+1;j<5;j++){
           min=((arr[j].x-arr[i].x)*(arr[j].x-arr[i].x))+((arr[j].y-arr[i].y)*(arr[j].y-arr[i].y));
           if(min<mindist){
                  mindist=min;
                  indi=i;
                  indj=j;                    
             }
       }
  }
  printf("%d \n",mindist);
  printf("the points are (%d, %d) ( %d ,%d )",arr[indi].x,arr[indi].y,arr[indj].x,arr[indj].y);  
return 0;
}
