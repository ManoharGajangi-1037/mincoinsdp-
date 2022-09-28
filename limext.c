#include<stdio.h>
#include<math.h>
int max(int a,int b){
   if(a<b){
      return a;
   }
   else{
       return b;
   }
}
long int divide(long int m){
      long int count=0;
      while(m!=0){
          m=m/10;
          count++;
      }
      return count;


}
long int lim(long int m,long int n){

      if(m<=9||n<=9){
          return m*n;
      }
      long int a,b,c,d;
      long int N=max(divide(m),divide(n));
      long int half=N/2;
      a=m/((long int)pow(10,half));
      printf("a=%ld\n",a);
      b=m%((long int)pow(10,half));
      c=n/((long int )pow(10,half));
      d=n%((long int)pow(10,half));
      long int c1=lim(a,c);
      long int c3=lim(b,d);
      long int c2=lim(a+b,c+d)-c1-c3;
      return (c1*(long int)pow(10,2*half))+(c2*(long int)pow(10,half))+c3;     
}
int main(){
  long int m,n;
  scanf("%ld %ld",&m,&n);
  printf("%ld",lim(m,n));
return 0;
}
