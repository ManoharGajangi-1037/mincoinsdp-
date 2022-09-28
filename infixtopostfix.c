#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack{
    int top;
    int size;
    char *arr;
    
};

void push(char val,struct stack *sp){
    if(sp->top==sp->size-1){
        printf("full");
    }
    else{
         sp->top=sp->top+1;
         sp->arr[sp->top]=val;
    }
}
int isempty(struct stack *sp){
   if(sp->top==-1){
        return 1;
   }
   else{
       return 0;
   }
}
char pop(struct stack *sp){
    if(isempty(sp)){
         printf("not able to pop");
    }
    else{
        char val;
        val=sp->arr[sp->top];
        sp->top--;
        return val;
    }
}
char stacktop(struct stack *sp){
   char val;
   val=sp->arr[sp->top];
   return val;
}
int isoperator(char ch){
         if(ch=='+'||ch=='-'||ch=='*'||ch=='/'){
              return 1;
         }
         else{
              return 0;
         }
}
int precedence(char ch){
       if(ch=='*'||ch=='/'){
           return 3;
       }
       else if(ch=='+'||ch=='-'){
             return 2;
       }
       else{
           return 0;
       }

}
char* infixtopostfix(struct stack *sp,char *infix){
    char *postfix=(char *)malloc((strlen(infix)+1)*sizeof(char));
    int i=0;
    int j=0;
    while(infix[i]!='\0'){
           if(!isoperator(infix[i])){
                postfix[j]=infix[i];
                i++;
                j++;
           }  
           else{
                if(precedence(infix[i])>precedence(stacktop(sp))){
                     push(infix[i],sp);
                     i++;
                }
                else{
                    postfix[j]=pop(sp);
                    j++;               
                }
           
           }  
    }
    while(!isempty(sp)){
        postfix[j]=pop(sp);
        j++;
    }
    postfix[j]='\0';
    return postfix;
    

}
int main(){
  struct stack *sp=(struct stack*)malloc(sizeof(struct stack));
  sp->size=100;
  sp->top=-1;
  sp->arr=(char *)malloc(sp->size*sizeof(char));
  char *infix=(char *)malloc(sp->size*sizeof(char));
  scanf("%s",infix);
  printf("%s",infixtopostfix(sp,infix));
  
  return 0;
}
