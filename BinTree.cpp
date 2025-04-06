#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "BinTree.h"

Node_t* InsertNode(Node_t* node, int value)
{
    if (node == NULL)
    {
        node = NewNode(value);
        return node;
    }

    if (value < node->value)
    {
        Node_t* left =  InsertNode(node->left, value);
        node->left = left;

        return node;
    }

    else
    {
        Node_t* right =  InsertNode(node->right, value);
        node->right = right;

        return node;
    }
}

// void Insert(Node_t* cur_node, int node)                             //простая версия, сохраняет результат (50(12(5)(15(17)))(70(60)))
// {                                                                   //почему-то ломается при Insert(root, 100)
//     while ((cur_node->left != NULL) || (cur_node->right != NULL))
//     {
//         if (node < cur_node->value)
//             cur_node->left;

//         else
//             cur_node = cur_node->right;
//     }

//     if (node < cur_node->value)
//         cur_node->left = NewNode(node);

//     else
//         cur_node->right = NewNode(node);                            //если node > cur_node->right
// }

// void Insert(Node_t* cur_node, int value)                    //продвинутая версия, но нерабочая
// {                                                           //почему-то не сохраняет результат  (50(12(5)(15))(70(60)))
//     while (cur_node != NULL)
//     {
//         // if (node < cur_node->value)
//         //     cur_node = cur_node->left;

//         // else
//         //     cur_node = cur_node->right;

//         cur_node = (value < cur_node->value) ? cur_node->left : cur_node->right; 
//     }

//     cur_node = NewNode(value);
// }

Node_t* NewNode(int value)
{
    Node_t* node = (Node_t *)calloc(1, sizeof(Node_t));

    node->value = value;
    node->left = NULL;
    node->right =NULL;

    return node;
}


Node_t* GrafDump(Node_t* node, FILE* file)
{
    assert(node != NULL);

    fprintf(file, "     node%p[shape=\"Mrecord\", label=\"{node%p | value = %d | {left = %p | right = %p}}\"] \n", node, node, node->value, node->left, node->right);

    if (node->left != NULL)
    {
        Node_t* left =  GrafDump(node->left, file);
        fprintf(file, "     node%p -> node%p \n\n", node, left);
    }

    if (node->right != NULL)
    {
        Node_t* right =  GrafDump(node->right, file);
        fprintf(file, "     node%p -> node%p \n\n", node, right);
    }

    return node;
}


void PrintTree(Node_t* node)        //PREORDER
{
    if (!node) return;

    printf("(");
    printf("%d", node->value);

    if (node->left)
        PrintTree(node->left);
    
    if (node->right)
        PrintTree(node->right);

    printf(")");
}