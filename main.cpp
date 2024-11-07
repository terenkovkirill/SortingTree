#include <TXLib.h>
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


int main()
{
    Node_t* root = NewNode(50);

    root->left = NewNode(12);
    root->right = NewNode(70);

    (root->left)->left = NewNode(5);
    (root->left)->right = NewNode(15);
    (root->right)->left = NewNode(60);

    int node = 17;
    Insert(root, node);
}

void Insert(Node_t* cur_node, int node)
{

    while ((cur_node->left != NULL) || (cur_node->right != NULL))
    {
        if (node < cur_node->data)
            cur_node = cur_node->left;

        else
            cur_node = cur_node->right;
    }

    if (node < cur_node->data)
        cur_node->left = NewNode(node);

    else
        cur_node->right = NewNode(node);            //если node > cur_node->right
}

Node_t* NewNode(int data)
{
    Node_t* node = (Node_t *)calloc(1, sizeof(Node_t));
    node->data = data;

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


