#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
   char a[10];
   char b[5];
   scanf("%s",a);
   scanf("%s",b);
   int f=-1;
   int m;
   int n;
   m=strlen(a);
   n=strlen(b);
   printf("%d\n",m);
   printf("%d\n",n);
   int i,j;
   for( i=0;i<=m-n;i++){
         for( j=i;j<i+n;j++){
      		     if(a[j]!=b[j-i]){
    		           break;
    		     }
    		}
    	if(j==i+n){
    	     f=i;
    	     break;
    	}
   }
   if(f==-1){
        printf("no substring");
   }
   else{
        printf("the string matched from index %d",f);
   }
return 0;
}
