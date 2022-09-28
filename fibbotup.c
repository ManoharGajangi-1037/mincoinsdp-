#include<stdio.h>
int a[100]={0};

int fib(int n){
        if(n==0){
	     return a[n]=0;
	}
	if(n==1){
	     return a[n]=1;
	}
	if(a[n]!=0){
		return a[n];
	}
	return a[n]=fib(n-1)+fib(n-2);
}
int main(){
  int n;
  scanf("%d",&n);
  fib(n);
  printf("%d",a[n]);
return 0;
}
