#include <iostream>
#define FOR(i, a, b) for (int i = a; i < b; i++)
int n;
int *a, *temp;
using namespace std;
void merge(int from, int mid, int last)
{
    int i = from, j = mid + 1, k = from;
    while (i <= mid && j <= last)
    {
        if (a[i] < a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
        }
    }
    while (i < n && i <= mid)
    {
        temp[k++] = a[i++];
    }
    while (j <= last)
    {
        temp[k++] = a[j++];
    }
    FOR(i, from, last + 1)
    {
        a[i] = temp[i];
    }
}

void mergeSort(int l, int h)
{
    for (int m = 1; m <= (h - l); m = 2 * m)
    {
        for (int i = l; i < h; i += 2 * m)
        {
            int from = i, mid = i + m - 1, last = min((i + 2 * m - 1), h);
            merge(from, mid, last);
        }
    }
}

int main()
{
    cin >> n;
    a = (int *)malloc(sizeof(int) * n);
    temp = (int *)malloc(sizeof(int) * n);
    FOR(i, 0, n)
    {
        cin >> a[i];
        temp[i] = a[i];
    }
    mergeSort(0, n - 1);
    FOR(i, 0, n)
    {
        cout << a[i] << ' ';
    }
    free(a);
    free (temp);
    return 0;
}