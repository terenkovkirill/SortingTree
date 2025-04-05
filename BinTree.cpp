#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "BinTree.h"

Node_t* InsertNode(Node_t* node, int value)
{
    if (node == NULL)
    {
        Node_t* test_ptr = NewNode(value);
        return test_ptr;
    }

    if (value < node->data)
        return InsertNode(node->left, value);

    else
        return InsertNode(node->right, value);
}

// void Insert(Node_t* cur_node, int node)                             //простая версия, сохраняет результат (50(12(5)(15(17)))(70(60)))
// {                                                                   //почему-то ломается при Insert(root, 100)
//     while ((cur_node->left != NULL) || (cur_node->right != NULL))
//     {
//         if (node < cur_node->data)
//             cur_node->left;

//         else
//             cur_node = cur_node->right;
//     }

//     if (node < cur_node->data)
//         cur_node->left = NewNode(node);

//     else
//         cur_node->right = NewNode(node);                            //если node > cur_node->right
// }

// void Insert(Node_t* cur_node, int value)                    //продвинутая версия, но нерабочая
// {                                                           //почему-то не сохраняет результат  (50(12(5)(15))(70(60)))
//     while (cur_node != NULL)
//     {
//         // if (node < cur_node->data)
//         //     cur_node = cur_node->left;

//         // else
//         //     cur_node = cur_node->right;

//         cur_node = (value < cur_node->data) ? cur_node->left : cur_node->right; 
//     }

//     cur_node = NewNode(value);
// }

Node_t* NewNode(int data)
{
    Node_t* node = (Node_t *)calloc(1, sizeof(Node_t));

    node->data = data;
    node->left = NULL;
    node->right =NULL;

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