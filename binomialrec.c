#include<stdio.h>
int binomial(int n,int k){
     
     if(n==k||k==0){
           return 1;
     }
     else{
           return binomial(n-1,k)+binomial(n-1,k-1);
     }

}

int main(){
   int n,k;
   scanf("%d",&n);
   scanf("%d",&k);
   printf("%d\n",binomial(n,k));
return 0;
}
