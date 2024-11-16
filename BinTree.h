#ifndef BINTREE_H
#define BINTREE_H

#include <stdio.h>


struct Node_t 
{
    int data;
    Node_t* left;
    Node_t* right;
};

void Insert(Node_t* root, int node);
Node_t* NewNode(int data);
void Print(Node_t* node);

#endif