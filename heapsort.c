#include<stdio.h>
void swap(int *a,int *b){
   int temp=*a;
   *a=*b;
   *b=temp;
}
void minheapify(int a[],int n,int i){
    int smallest=i;
     int l=2*i+1;//left child
     int r=2*i+2;//right child 
     if(a[l]<a[smallest]&&l<n){//checking whether the leftelement is smallest 
            smallest=l;//updating the smallest
     }
     if(a[r]<a[smallest]&&r<n){//checking whether the right element is smallest 
            smallest=r;//updating the smallest
     }
     /* 
     
         for creating maxheap 
         for userreadable make large=i;
         check arr[l]>arr[large]&&l<n
         update large=l;
          check arr[r]>arr[large]&&r<n
         update large=r;
         
     */
      
    
      if(smallest!=i){//if the passed node is not the smallest 
          swap(&a[i],&a[smallest]);//swapping element with the smallest index element 
          minheapify(a,n,smallest);//then again call for minheap to  the index which got replaced
      }
      

}
void heapsort(int a[],int n){
     for(int i=n/2-1;i>=0;i--){
          minheapify(a,n,i);//creating minheap 
     }
     for(int i=n-1;i>=0;i--){
          swap(&a[0],&a[i]);
          minheapify(a,i,0);
     }
}
int main(){
   int n;
   scanf("%d",&n);
   int a[n];
   for(int i=0;i<n;i++){
       scanf("%d",&a[i]);
   }
   heapsort(a,n);
     for(int i=0;i<n;i++){
       printf("%d\t",a[i]);
   }
return 0;
}
