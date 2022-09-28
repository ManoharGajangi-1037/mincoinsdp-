#include<stdio.h>


void merge(int arr[],int low,int mid,int high){
     int i=low;
     int j=mid+1;
     int k=low;
     int b[high+1];
     while(i<=mid&&j<=high){
          if(arr[i]<=arr[j]){
              b[k]=arr[i];
              i++;k++;
          }
          else{
              b[k]=arr[j];
              j++;
              k++;
          }
     }
     while(i<=mid){
        b[k]=arr[i];
        i++;k++;
     }
     while(j<=high){
         b[k]=arr[j];
         j++;k++;
     }
     for(int x=low;x<=high;x++){
         arr[x]=b[x];
     }
     
}
void mergesort(int arr[],int low,int high){
   int mid;
   if(low<high){
       mid=(low+high)/2;
       mergesort(arr,low,mid);
       mergesort(arr,mid+1,high);
       merge(arr,low,mid,high);
   
   }

}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    mergesort(arr,0,n-1);
     for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }

}
