#include <stdio.h>
#include <stdlib.h>
#include "BinTree.h" 

#include <iostream>
#include <cstdlib>

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

    PrintPreorder(root);
    printf("\n");

    PrintPostorder(root);
    printf("\n");

    PrintInorder(root);
    printf("\n");

    FindNode(root, 17);  

    FreeTree(&root);

    system("dot BTree.dot -T png -o BTree.png");
    
    DBG("BinTree works");

    //Для подключения задержки в конце:
    // #ifdef __linux__
    //     std::cout << "Press Enter to exit...";
    //     std::cin.get();  // Ждём нажатия Enter (для Linux/WSL)
    // #endif

    return 0;
}