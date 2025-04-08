#include <stdio.h>
#include <stdlib.h>
#include "BinTree.h" // TODO убрать лишние include


int main()
{   
    int tree_data[] = {70, 12, 15, 60, 5, 17};

    DBG("InsertNodeLoop(0, 50)");

    int len_array = sizeof(tree_data) / sizeof(int);

    Node_t* root = InsertNode(0, 50);
    for (int i = 0; i < len_array; i++)
    {
        InsertNode(root, tree_data[i]);
        DBG("InsertNode(%p, %d)", root, tree_data[i]);
    }

    // Node_t* root = InsertNodeLoop(0, 50);
    // for (int i = 0; i < len_array; i++)
    // {
    //     InsertNodeLoop(root, tree_data[i]);
    //     DBG("InsertNodeLoop(%p, %d)", root, tree_data[i]);
    // }

    GrafDump(root);

    PrintTree(root);

    system("dot BTree.dot -T png -o BTree.png");
    
    DBG("BinTree works");

    return 0;
}


// TODO:
// 1. Graf Dump                                         +
// 2. InsertNode                                        +
// 2.1 Поработать над внешним видом graf_dump           +
// 2.5 InsertNode (loop)                                +
// 3. FreeNode
// 4. NodeFind
// 5. TreeTraversal (Print)