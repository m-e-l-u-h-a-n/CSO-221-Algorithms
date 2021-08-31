#include <bits/stdc++.h>
using namespace std;

int rep[100005];
vector<int> va;
int edg;
int a[100005];
struct edge
{
    int a, b, c;
} arr[100005];

int finder(int x)
{
    if (rep[x] == x)
        return x;
    return rep[x] = finder(rep[x]);
}

void makeset(int n)
{
    for (int i = 1; i <= n; i++)
        rep[i] = i;
}

bool cmp(edge x, edge y)
{
    return x.c < y.c;
}

int unio2(int i, int sum)
{
    int x, y;
    x = finder(arr[i].a);
    y = finder(arr[i].b);
    if (x != y)
    {
        rep[x] = y;
        sum += arr[i].c;
        edg++;
    }
    return sum;
}

int unio(int i, int sum)
{
    int x, y;
    x = finder(arr[i].a);
    y = finder(arr[i].b);
    if (x != y)
    {
        rep[x] = y;
        va.push_back(i);
        sum += arr[i].c;
    }
    return sum;
}

int main()
{
    int n, m; // n vertices, m edges
    cin >> n >> m;

    makeset(n);

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        arr[i].a = a;
        arr[i].b = b;
        arr[i].c = c;
    }

    sort(arr, arr + m, cmp);

    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        sum = unio(i, sum);
    }

    cout << "MST: " << sum << "\n"; //cost

    int sec_best_mst = INT_MAX / 3;

    cout << "All other spanning trees:\n";

    sum = 0;
    int j;
    for (j = 0; j < va.size(); j++)
    {
        makeset(n);
        edg = 0;
        for (int i = 0; i < m; i++)
        {
            if (i == va[j])
                continue;
            sum = unio2(i, sum);
        }
        if (edg != n - 1)
        {
            sum = 0;
            continue;
        }
        cout << sum << "\n";
        if (sec_best_mst > sum)
            sec_best_mst = sum;
        sum = 0;
    }

    cout << "SEC BEST MST: " << sec_best_mst << "\n";
}