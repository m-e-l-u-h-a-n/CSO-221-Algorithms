#include <bits/stdc++.h>
using namespace std;

int n = 7;
int arr[] = {1, 2, 3, 4, 5, 6, 7};
struct node
{
    int data;
    struct node *left;
    struct node *right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

node *slowheap(int i, int j)
{
    if (i == j)
    {
        struct node *Node = new node(arr[i]);
        cout << arr[i] << " " << i << ' ' << j << endl;
        return Node;
    }
    int mi = INT_MAX, ind;
    for (int k = i; k <= j; k++)
    {
        if (arr[k] < mi)
            ind = k;
        mi = min(mi, arr[k]);
    }
    struct node *Node = new node(mi);
    cout << mi << " " << i << " " << j << endl;
    swap(arr[ind], arr[j]);
    if (i <= (i + j - 1) / 2)
        Node->left = slowheap(i, (i + j - 1) / 2);
    if ((i + j - 1) / 2 + 1 <= j - 1)
        Node->right = slowheap((i + j - 1) / 2 + 1, j - 1);
    return Node;
}

int main()
{
    int mi = INT_MAX, ind;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < mi)
            ind = i;
        mi = min(mi, arr[i]);
    }
    cout << mi << endl;
    swap(arr[n - 1], arr[ind]);
    struct node *root = new node(mi);
    if (n / 2 >= 1)
        root->left = slowheap(0, n / 2 - 1);
    if (n / 2 <= n - 2)
        root->right = slowheap(n / 2, n - 2);
}