#include<stdio.h>
int a[100]={0};
int fib(int n){
   a[0]=1;
   a[1]=1;
    for(int i=2;i<=n;i++){
        a[i]=a[i-1]+a[i-2];
    }
    return a[n];
}
int main(){
   int n;
   scanf("%d",&n);
  
  int res= fib(n);
  printf("%d",res);
return 0;
}
