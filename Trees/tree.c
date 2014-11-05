#include <stdio.h>
#include<stdlib.h>

#define DEBUG

typedef struct node{
    int data;
    struct node* right;
    struct node* left;
}node;

main() {
    //creatting a constant pointer for the root node
    
    node  const* root_ptr;
    
    //creating the root node
    root_ptr=(node *) malloc(sizeof(node));
    
    #ifdef DEBUG
    printf("The address where the root node is stored is : %p \n", root_ptr);
    #endif
    
    
    
    return 0;
}
