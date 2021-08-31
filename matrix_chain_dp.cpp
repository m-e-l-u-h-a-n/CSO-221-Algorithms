#include <bits/stdc++.h>
using namespace std;
int dp[101][101];
//TOP DOWN APPROACH
int matrix_chain(int matrics[], int i, int j)
{
	if (i == j)return 0;
	if (dp[i][j] != -1)return dp[i][j];
	int mii = 1e18;
	for (int k = i; k < j; k++)
	{
		int ans = matrix_chain(matrics, i, k) + matrix_chain(matrics, k + 1, j) + matrics[i - 1] * matrics[k] * matrics[j];
		mii = min(mii, ans);
	}
	return dp[i][j] = mii;
}


int32_t main()
{
	int matrics[] = {1, 2, 3, 4};
	int n = sizeof(matrics) / sizeof(int);
	memset(dp, -1, sizeof(dp));
	//cout << matrix_chain(matrics, 1, n - 1);
	//BOTTOM UP APPROACH
	for (int i = 1; i < n; i++)dp[i][i] = 0;
	for (int l = 2; l < n; l++)
	{
		for (int i = 1; i <= n - l; i++)
		{
			int j = i + l - 1;
			dp[i][j] = 1e18;
			for (int k = i; k < j; k++)
			{
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + matrics[i - 1] * matrics[k] * matrics[j]);
			}
		}
	}
	cout << dp[1][n - 1];

}