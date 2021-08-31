#define FOR(i, a, b) for (int i = a; i < b; i++)
#include <bits/stdc++.h>
using namespace std;

void run()
{
    int e, x, y, c=0;
    cin >> e;
    vector<int> arr(10000, 0);
    FOR(i, 0, e)
    {
        cin>>x>>y;
        if(arr[x] == 0) {
            arr[x]++;
            c++;
        }
        if(arr[y] == 0) {
            arr[y]++;
            c++;
        }
    }
    cout<<c<<'\n';
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        run();
    }
}
