#include <stdio.h>
#include <stdlib.h>
#include "BinTree.h"


void Insert(Node_t* cur_node, int node)
{
    while ((cur_node->left != NULL) || (cur_node->right != NULL))
    {
        if (node < cur_node->data)
            cur_node = cur_node->left;

        else
            cur_node = cur_node->right;
    }

    if (node < cur_node->data)
        cur_node->left = NewNode(node);

    else
        cur_node->right = NewNode(node);            //если node > cur_node->right
}

// void Insert(Node_t* cur_node, int value)                    //продвинутая, но нерабочая версия
// {
//     while (cur_node != NULL)
//     {
//         // if (node < cur_node->data)
//         //     cur_node = cur_node->left;

//         // else
//         //     cur_node = cur_node->right;

//         cur_node = (value < cur_node->data) ? cur_node->left : cur_node->right; 
//     }

//     cur_node->left = NewNode(value);
// }

Node_t* NewNode(int data)
{
    Node_t* node = (Node_t *)calloc(1, sizeof(Node_t));
    node->data = data;

    return node;
}


void Print(Node_t* node)        //PREORDER
{
    if (!node) return;

    printf("(");
    printf("%d", node->data);

    if (node->left)
        Print(node->left);
    
    if (node->right)
        Print(node->right);

    printf(")");
}

