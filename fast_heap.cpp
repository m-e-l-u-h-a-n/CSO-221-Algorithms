#include <bits/stdc++.h>
using namespace std;

int n = 7;
int arr[] = {1, 2, 3, 4, 5, 6, 7};
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
void print(node *node)
{
    cout << node->data << " ";
    if (node->left != NULL)
    {
        print(node->left);
    }
    if (node->right != NULL)
    {
        print(node->right);
    }
}
void down_heapify(node *Node)
{
    node *small = Node;
    if (Node->left != NULL && Node->left->data < Node->data)
        small = Node->left;
    if (Node->right != NULL && Node->right->data < small->data)
        small = Node->right;
    if (small != Node)
    {
        //cout<<Node->data<<" "<<small->data<<endl;
        swap(Node->data, small->data);
        //cout<<Node->data<<" "<<small->data<<endl;
        down_heapify(small);
    }
}

node *fastheap(int i, int j)
{
    if (i == j)
    {
        struct node *Node = new node();
        Node->data = arr[i];
        Node->left = NULL;
        Node->right = NULL;
        //cout<<arr[i]<<" "<<i<<' '<<j<<endl;
        return Node;
    }
    struct node *Node = new node();
    Node->left = NULL;
    Node->right = NULL;
    if (i <= (i + j - 1) / 2)
        Node->left = fastheap(i, (i + j - 1) / 2);
    if ((i + j - 1) / 2 + 1 <= j - 1)
        Node->right = fastheap((i + j - 1) / 2 + 1, j - 1);
    Node->data = arr[j];
    //cout<<arr[j]<<" "<<i<<" "<<j<<endl;
    down_heapify(Node);
    return Node;
}

int main()
{
    struct node *root = fastheap(0, n - 1);
    print(root);
}