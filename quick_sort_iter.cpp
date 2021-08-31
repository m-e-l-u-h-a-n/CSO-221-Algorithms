#include <iostream>

using namespace std;
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low, j = high;
    while (i < j)
    {
        do
        {
            i++;
        } while (a[i] <= pivot && i < high);
        do
        {
            j--;
        } while (a[j] > pivot && j > low);
        if (i < j)
        {
            swap(a[i], a[j]);
        }
    }
    swap(a[low], a[j]);
    return j;
}
void quickSort(int a[], int l, int h)
{
    int stack[h - l + 1], p;
    int top = -1;
    stack[++top] = l;
    stack[++top] = h;
    while (top > -1)
    {
        h = stack[top--];
        l = stack[top--];
        p = partition(a, l, h);
        if (l < p)
        {
            stack[++top] = l;
            stack[++top] = p;
        }
        if (p + 1 < h)
        {
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    quickSort(a, 0, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }
    return 0;
}