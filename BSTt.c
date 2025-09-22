#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node* leftnode;
    struct Node* rightnode;
    int data;

};

struct Node* newnode(int value){
    struct Node* temp =(struct Node*)malloc(sizeof(struct Node));
    temp -> data = value;
    temp -> leftnode = NULL;
    temp -> rightnode = NULL;
    return temp;
}

struct Node* insert(struct Node* root,int value){
    if(root == NULL){
        return newnode(value);
     }
    else if(root -> data > value){
        root -> leftnode = insert(root -> leftnode, value);
    }
    else{
        root -> rightnode = insert(root -> rightnode, value);
    }
    return root;
}

struct Node* preorder(struct Node* root){
    if(root != NULL){
        printf("%d ", root -> data);
        preorder(root -> leftnode);
        preorder(root -> rightnode);
    }
}

struct Node* inorder(struct Node* root){
    if(root != NULL){
        inorder(root -> leftnode);
        printf("%d ", root -> data);
        inorder(root -> rightnode);
    }
}

struct Node* postorder(struct Node* root){
    if (root != NULL){
        postorder(root -> leftnode);
        postorder(root -> rightnode);
        printf("%d ", root -> data);
    }
}

int main(){

    struct Node* root = NULL;
    root = insert(root,30);
    insert(root,46);
    insert(root,35);
    insert(root,24);
    insert(root,28);
    insert(root,21);

    preorder(root);
    printf("\n");

    inorder(root);
    printf("\n");

    postorder(root);

    return 0;
}