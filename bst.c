#include<stdio.h>
#include<stdlib.h>
struct node{ 
    int data;
   struct node* left;
   struct node* right;
};
struct node * create(int data){
    struct node* nn;
    nn=(struct node*)malloc(sizeof(struct node));
    nn->data=data;
    nn->left=NULL;
    nn->right=NULL;
    return nn;

}
void inorder(struct node* root){
    if(root!=NULL){
             inorder(root->left);
             printf("%d\t ",root->data);
             inorder(root->right);
    }

}
void preorder(struct node* root){
    if(root!=NULL){
         printf("%d\t",root->data);
         preorder(root->left);
         preorder(root->right);
    }
}
void postorder(struct node* root){
   if(root!=NULL){
       postorder(root->left);
       postorder(root->right);
       printf("%d\t",root->data);
   }
 

}
struct node* insert(struct node* root,int data){
    
      if(root==NULL){
             struct node* temp=create(data);
             root=temp;
      } 
      if(data<root->data){
           root->left=insert(root->left,data);
      }
      else if(data>root->data){
           root->right=insert(root->right,data);
      }
      return root;
}

struct node* inpred(struct node* root){
     root=root->left;
     while(root->right!=NULL){
          root=root->right;
     }
     return root;
}

struct node* delete(struct node* root,int data){
    struct node *ipre;
    if(root==NULL){
            return NULL;
    }
    if(root->left==NULL&&root->right==NULL){
          
          free(root);
          return NULL;
    }
    if(data<root->data){
         root->left=delete(root->left,data);
    }
    else if(data>root->data){
         root->right=delete(root->right,data);
    }
    else{
        ipre=inpred(root);
         root->data=ipre->data;
         root->left=delete(root->left,ipre->data);
    }
    return root;
}
int main(){
      struct node* root=NULL;
      root=insert(root,5);
      insert(root,35);
       insert(root,56);
        insert(root,75);
       insert(root,88);
        insert(root,97);
       insert(root,55);
       
       inorder(root);
         printf("\n");
      // preorder(root);
        // printf("\n");
       //postorder(root);
  //printf("\n");
     delete(root,55);
      inorder(root);
         printf("\n");
return 0;
}
