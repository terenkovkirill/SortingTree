#include <stdio.h>
#include <stdlib.h>
#include "BinTree.h"


int main()
{   
    int tree_data[] = {12, 70, 1, 15, 60};
    Node_t* root = InsertNode(0, 50);

    DBG("InsertNode(0, 50)");

    int len_array = sizeof(tree_data) / sizeof(int);

    for (int i = 0; i < len_array; i++)
    {
        InsertNode(root, tree_data[i]);
        DBG("InsertNode(%p, %d) works", root, tree_data[i]);
    }
    
    FILE* file = fopen("BTree.dot", "w");
    fprintf(file, "digraph\n{\n");

    GrafDump(root, file);

    fprintf(file, "} \n");

    PrintTree(root);

    //system("dot BTree.dot -T png -o BTree.png");

    DBG("BinTree works");

    return 0;
}


// TODO:
// 1. Graf Dump
// 2. InsertNode
// 2.5 InsertNode (loop)
// 3. FreeNode
// 4. NodeFind
// 5. TreeTraversal (Print)