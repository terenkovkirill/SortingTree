#include <stdio.h>
#include "BinTree.h"

int main()
{
    Node_t* root = NewNode(50);

    root->left = NewNode(12);
    root->right = NewNode(70);

    (root->left)->left = NewNode(5);
    (root->left)->right = NewNode(15);
    (root->right)->left = NewNode(60);
    // Insert(root, 12);
    // Insert(root, 70);
    // Insert(root, 5);
    // Insert(root, 15);
    // Insert(root, 60);
    
    int node = 17;
    Insert(root, node);
    //Insert(root, 100);                      //это не работает, почему?
    // Insert(root, 101);

    Print(root);
    printf("\n BinTree works \n");
}


