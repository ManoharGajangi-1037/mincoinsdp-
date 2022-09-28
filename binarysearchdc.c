#include<stdio.h>
int main(){
   int n;
   scanf("%d",&n);
   int arr[n];
   for(int i=0;i<n;i++){
      scanf("%d",&arr[i]);
   }
   int first=0;
   int last=n-1;
   int mid;
   int key;
   printf("enter the value you need to search");
    scanf("%d",&key);
   while(first<=last){
         mid=(first+last)/2;
         if(arr[mid]==key){
             printf("found at index%d:",mid);
             break;
         }
         if(arr[mid]<key){
             first=mid+1;
         }
         else{
              last=mid-1;
         }
   }
   if(first>last){
      printf("not found");
   }
   

return 0;
}
