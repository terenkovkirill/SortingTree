#ifndef BINTREE_H
#define BINTREE_H

#include <stdio.h>
#include <stdlib.h>
// #define DEBUG

#ifdef DEBUG
    #define DBG(fmt, ...) \
        fprintf(stderr, "[DEBUG] %s:%d %s() " fmt "\n", __FILE__, __LINE__, __func__, ##__VA_ARGS__)
#else
    #define DBG(fmt, ...)
#endif
//         fprintf(stderr, "[DEBUG] %s:%s.%d() " fmt "\n", __FILE__, __func__, __LINE__, ##__VA_ARGS__)

struct Node_t 
{
    int value;
    Node_t* left;
    Node_t* right;
};

Node_t* CreateNode(int value);
Node_t* InsertNode(Node_t* node, int value);
Node_t* GrafDump(Node_t* node, FILE* file);
void PrintTree(Node_t* node);

#endif