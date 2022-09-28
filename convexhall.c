#include<stdio.h>
#include<stdlib.h>
struct array{
     int x;
     int y;
     int  z;
};

int main(){
   int n;
   printf("the number of points you need to enter \n");
   scanf("%d",&n);
  struct array arr[n];
  for(int i=0;i<n;i++){
        scanf("%d %d ",&arr[i].x,&arr[i].y);
        arr[i].z=1;//extra code for no repetition
  }
  int np,nn,l;
  int a,b,c;
  for(int i=0;i<n-1;i++){
     for(int j=i+1;j<n;j++){
        a=arr[i].y-arr[j].y;
        b=arr[j].x-arr[i].x;
        c=arr[j].y*arr[i].x-arr[i].y*arr[j].x;
        np=0;
        nn=0;
        for(int k=0;k<n;k++){
            l=a*arr[k].x+b*arr[k].y+c;
            if(l<0){
                  nn++;
            }
            else if(l>0){
                  np--;
            }
        }
        if(np==0||nn==0){
               if(arr[i].z==1&&arr[j].z){//extra
                arr[i].z=0;//extra
                arr[j].z=0;//extra
               printf("(%d  %d),(%d %d )\n",arr[i].x,arr[i].y,arr[j].x,arr[j].y);
                }//extra
          }
     }
  
  }
return 0;
}
