#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "BinTree.h"


Node_t* CreateNode(int value)
{
    Node_t* node = (Node_t *)calloc(1, sizeof(Node_t));

    node->value = value;
    node->left = NULL;
    node->right =NULL;

    return node;
}


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
    {
        node = CreateNode(value);
        return node;
    }

    while (node != NULL)
    { 
        if (value < node->value)
        {
            if (node->left == NULL)
            {
                node->left = CreateNode(value);
                return node->left;
            }

            else
                node = node->left;
        }
        
        if (value > node->value)
        {
            if (node->right == NULL)
            {
                node->right = CreateNode(value);
                return node->right;
            }

            else
                node = node->right;
        }
    }

    return NULL;                                            
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


void PrintPreorder(Node_t* node)       
{
    if (!node) return;

    printf("(");
    printf("%d", node->value);

    if (node->left)
        PrintPreorder(node->left);
    
    if (node->right)
        PrintPreorder(node->right);

    printf(")");
}


void PrintPostorder(Node_t* node)
{
    if (!node)
        return;
    
    printf("(");

    if (node->left)
        PrintPostorder(node->left);
    
    if (node->right)
        PrintPostorder(node->right);
    
    printf("%d)", node->value);
}


void PrintInorder(Node_t* node)
{
    if (!node)
        return;
    
    printf("(");

    if (node->left)
        PrintInorder(node->left);
    
    printf("%d", node->value);

    if (node->right)
        PrintInorder(node->right);
    
    printf(")");
}


TreeError FindNode(Node_t* node, int value)
{
    if (node == NULL)
        return VALUE_NOT_FOUND;                                //This may means, that root = NULL 

    if (node->value == value)
    {
        printf("[INFO] Node found %p with value = %d", node, value);
        return OK;
    }
    
    if (node->value < value)
        FindNode(node->left, value);

    if (node->value > value)
        FindNode(node->right, value);

    return OK;
}