//Binary search tree
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*left;
    struct node*right;
};

struct node*createnode(int value){
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->left=newnode->right=NULL;
    return newnode;
}
struct node*insert(struct node*root,int value){
    if(root==NULL)
        return createnode(value);
    if(value<root->data){
        root->left=insert(root->left,value);
    }
    else if(value>root->data){
        root->right=insert(root->right,value);
    }
    return root;
}
void inorder(struct node*root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void postorder(struct node*root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
void preorder(struct node*root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void search(struct node*root,int key){
    if(root==NULL){
        printf("NULL\n");
        return;
    }
    if(key==root->data){
        printf("found\n");
    }
    else if(key<root->data){
        search(root->left,key);
    }
    else{
        search(root->right,key);
    }
}
int main(){
    struct node*root=NULL;
    int n,value,key;
    printf("enter the number of node:");
    scanf("%d",&n);
    printf("enter the %d element:\n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&value);
        root=insert(root,value);
    }
    printf("\nInorder traversal:");
    inorder(root);
    printf("\nPreorder traversal:");
    preorder(root);
    printf("\nPostorder traversal:");
    postorder(root);
    printf("\nenter the element to search:");
    scanf("%d",&key);
    search(root,key);
    return 0;
   
}