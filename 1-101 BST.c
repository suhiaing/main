#include "stdio.h"
#include "stdlib.h"

struct Node{

    int data;
    struct Node* left;
    struct Node* right;


};

struct Node* creatNode(int key){

    struct Node* newNode =(struct Node*)malloc(sizeof (struct Node));
    newNode->data = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(int start, int end){
    
    if(start > end){
        return NULL;
    }

    int middile = (start + end)/2;
    
    struct Node* root = creatNode(middile);
    
    root->left = insertNode(start, middile -1);
    root->right =insertNode(middile +1, end);

    return root;

}

void inorderTraversal(struct Node* node){

    if(node !=NULL){

        inorderTraversal(node->left);
        printf("data: %d\n",node->data);

        inorderTraversal(node->right);
    }


}

void finder(struct Node* node , int toFindKey){

    if(node !=NULL){
        if(node->data == toFindKey){

            printf("We Found\n");
        }
        inorderTraversal(node->left);


        inorderTraversal(node->right);
    }


}


int main(){

    struct Node* root = NULL;
    
    int data[101] = {};
    for(int i = 1; i< 102; i++){
        data[i] = i;
        printf("data in array in %d:%d\n",i,data[i]);
    }




    root = insertNode(data[0],data[101]);
    // // root = insertNode(root , 8);
    // // root = insertNode(root , 12);
    // // root = insertNode(root , 5);
    // // root = insertNode(root , 15);
    // // root = insertNode(root , 3);
    // // root = insertNode(root , 4);
    // // root = insertNode(root , 13);
    // // root = insertNode(root , 1);
    // // root = insertNode(root , 20);
    inorderTraversal(root);
    // finder(root, 13);







    return 0;
}
