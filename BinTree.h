#ifndef BINTREE_H
#define BINTREE_H

#include <stdio.h>
#include <stdlib.h>
#define DEBUG

#ifdef DEBUG
    #define DBG(fmt, ...) \
        fprintf(stderr, "[DEBUG] %s:%d %s() " fmt "\n", __FILE__, __LINE__, __func__, ##__VA_ARGS__)
#else
    #define DBG(fmt, ...)
#endif

enum TreeError
{
    NULL_PTR = 0,
    OK = 1,
    VALUE_NOT_FOUND = 3
};

struct Node_t 
{
    int value;
    Node_t* left;
    Node_t* right;
};

Node_t* CreateNode(int value);
Node_t* InsertNode(Node_t* node, int value);
Node_t* InsertNodeLoop(Node_t* node, int value);
TreeError FindNode(Node_t* node, int value);
TreeError FreeTree(Node_t** node);
TreeError FreeNode(Node_t* node);
TreeError GrafDump(Node_t* node);
Node_t* RecursiveGrafDump(Node_t* node, FILE* file);
TreeError PrintPreorder(Node_t* node);
TreeError PrintPostorder(Node_t* node);
TreeError PrintInorder(Node_t* node);

#endif