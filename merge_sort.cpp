#include <iostream>
using namespace std;
void merge(int arr[], int l, int m, int r)
{
    int s1 = m - l + 1;
    int s2 = r - m;
    int t1[s1];
    int t2[s2];
    for (int i = 0; i < s1; i++)
    {
        t1[i] = arr[l + i];
    }
    for (int i = 0; i < s2; i++)
    {
        t2[i] = arr[m + 1 + i];
    }
    int i = 0, j = 0, k = l;
    while (i < s1 && j < s2)
    {
        if (t1[i] <= t2[j])
        {
            arr[k++] = t1[i++];
        }
        else
        {
            arr[k++] = t2[j++];
        }
    }
    while (i < s1)
    {
        arr[k++] = t1[i++];
    }
    while (j < s2)
    {
        arr[k++] = t2[j++];
    }
}
void mergesort(int arr[], int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int mid = (l + r - 1) / 2;
    mergesort(arr, l, mid);
    mergesort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}
int main()
{
    int size;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    mergesort(arr, 0, size - 1);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ' ';
    }
    return 0;
}