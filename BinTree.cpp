#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "BinTree.h"

Node_t* InsertNode(Node_t* node, int value)
{
    if (node == NULL)
    {
        return CreateNode(value);
    }

    if (value < node->value)
    {
        Node_t* left =  InsertNode(node->left, value);
        node->left = left;
    }
    
    if (value > node->value)
    {
        Node_t* right =  InsertNode(node->right, value);
        node->right = right;
    }

    return node;
}


Node_t* InsertNodeLoop(Node_t* node, int value)
{
    if (node == NULL)
        return CreateNode(value);

    DBG("cur_node = node = %p", node);

    while (node != NULL)
    {
        if (node != NULL && value < node->value)
        {
            DBG("value = %d < node->value = %d, so cur_node = %p (node->left)", value, node->value, node->left);
            Node_t* cur_node = node->left;
            node = cur_node;
        }
        
        if (node != NULL && value > node->value)            //В этой строке Segmentation Fault
        {
            DBG("value = %d > node->value = %d, so cur_node = %p (node->right)", value, node->value, node->right);
            Node_t* cur_node = node->right;
            node = cur_node;
        }
    }

    return CreateNode(value);
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
//         cur_node->left = CreateNode(node);

//     else
//         cur_node->right = CreateNode(node);                            //если node > cur_node->right
// }

Node_t* CreateNode(int value)
{
    Node_t* node = (Node_t *)calloc(1, sizeof(Node_t));

    node->value = value;
    node->left = NULL;
    node->right =NULL;

    return node;
}


TreeError GrafDump(Node_t* node)
{
    if (node == NULL)
        return NULL_PTR;

    FILE* file = fopen("BTree.dot", "w");
    fprintf(file, "digraph\n{\n");

    RecursiveGrafDump(node, file);

    fprintf(file, "} \n");
    fclose(file);

    return OK;
}


Node_t* RecursiveGrafDump(Node_t* node, FILE* file)
{
    assert(node != NULL);

    fprintf(file, "     node%p[shape=\"Mrecord\", label=\"{node%p | value = %d | {left = %p | right = %p}}\"] \n", node, node, node->value, node->left, node->right);

    if (node->left != NULL)
    {
        Node_t* left =  RecursiveGrafDump(node->left, file);
        fprintf(file, "     node%p -> node%p \n\n", node, left);
    }

    if (node->right != NULL)
    {
        Node_t* right =  RecursiveGrafDump(node->right, file);
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