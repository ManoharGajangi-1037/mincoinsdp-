#include<stdio.h>

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int findparent(int i,int parent[]){
    while(parent[i]!=-1){
         i=parent[i];
    }
    return i;
}
int krushkul(int source[],int destination[],int weight[],int parent[],int x ,int n){
      for(int i=0;i<x-1;i++){
          for(int j=0;j<x-i-1;j++){
               if(weight[j]>weight[j+1]){
                   swap(&weight[j+1],&weight[j]);
                   swap(&source[j+1],&source[j]);
                   swap(&destination[j+1],&destination[j]);
                   
               }
          }
      }
      
      /*printf("sorted order\n:");
      for(int i=0;i<x;i++){
           printf("%d %d %d\n",source[i],destination[i],weight[i]);
      }*/
      int l,k;
        for(int i=0;i<n;i++){
          parent[i]=-1;
      }
      int sum=0;
      for(int i=0;i<x;i++){
          l=findparent(source[i],parent);
          k=findparent(destination[i],parent);
          if(l!=k){
              parent[k]=l;
              printf("%d %d %d\n",source[i],destination[i],weight[i]);
              sum=sum+weight[i];
          }
      }
      return sum;

}

int main(){
      int n;
      scanf("%d",&n);
      int a[n][n];
      int count=0;
      for(int i=0;i<n;i++){
         for(int j=0;j<n;j++){
             scanf("%d",&a[i][j]);
             if(a[i][j]!=-1){
                count++;
             }
         }
      }
      int source[count];
      int destination[count];
      int parent[n];
      int weight[count];
      
      int x=0;
      for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){
               if(a[i][j]!=-1){
                    source[x]=i;
                    destination[x]=j;
                    weight[x]=a[i][j];
                    x++; 
               }
          }
      }
      printf("%d",krushkul(source,destination,weight,parent,x,n));
      
return 0;
}
