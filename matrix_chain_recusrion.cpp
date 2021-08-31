#include <bits/stdc++.h>
using namespace std;

int matrix_chain(int matrics[], int i, int j)
{
	if (i == j)return 0;
	int mii = 1e18;
	for (int k = i; k < j; k++)
	{
		int ans = matrix_chain(matrics, i, k) + matrix_chain(matrics, k + 1, j)
		          + matrics[i - 1] * matrics[k] * matrics[j];
		mii = min(mii, ans);
	}
	return mii;
}
int32_t main()
{
	int matrics[] = {1, 2, 3, 4};
	int n = sizeof(matrics) / sizeof(int);
	cout << matrix_chain(matrics, 1, n - 1);
}