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
    int i = low, j = high;
    int pivot = a[low];
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
        if (j > i)
        {
            swap(a[i], a[j]);
        }
    }
    swap(a[low], a[j]);
    return j;
}
void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int p = partition(a, low, high);
        quickSort(a, low, p);
        quickSort(a, p + 1, high);
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