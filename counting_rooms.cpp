#define FOR(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define fi first
#define se second
#define lli long long int

#include <bits/stdc++.h>
using namespace std;
int n, m;
int rooms = 0;
vector<vector<bool>> visited;
vector<pair<int, int>> moves = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
bool is_valid(int i, int j)
{
    if (!(i >= 0 && i < n) || !(j >= 0 && j < m))
    {
        return false;
    }
    if (visited[i][j])
    {
        return false;
    }
    return true;
}
void dfs(int i, int j)
{
    visited[i][j] = true;
    for (auto p : moves)
    {
        if (is_valid(p.fi + i, p.se + j))
        {
            dfs(p.fi + i, p.se + j);
        }
    }
}

int main()
{
    cin >> n >> m;
    char arr[n][m];
    visited.resize(n);
    FOR(i, 0, n)
    {
        visited[i].resize(m);
        FOR(j, 0, m)
        {
            cin >> arr[i][j];
            if (arr[i][j] == '#')
            {
                visited[i][j] = true;
            }
            else
            {
                visited[i][j] = false;
            }
        }
    }
    FOR(i, 0, n)
    {
        FOR(j, 0, m)
        {
            if (!visited[i][j])
            {
                rooms++;
                dfs(i, j);
            }
        }
    }
    cout << rooms;
    return 0;
}