/*最简单的dp*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=105;
int dp[maxn<<1][maxn], a[maxn<<1][maxn];


int main()
{
	int T, n, cnt=1;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i=0;i<n;++i)
		{
			for (int j=0;j<=i;++j)
				scanf("%d", &a[i][j]);
		}
		for (int i=n;i<2*n-1;++i)
		{
			for (int j=0;j<2*n-i-1;++j)
				scanf("%d", &a[i][j]);
		}
		memset(dp, 0, sizeof(dp));
		dp[0][0]=a[0][0];
		for (int i=0;i<n;++i)
		{
			if (i>0)
			{
				dp[i][0]=dp[i-1][0]+a[i][0];
				dp[i][i]=dp[i-1][i-1]+a[i][i];
			}
			for (int j=1;j<i;++j)
				dp[i][j]=max(dp[i-1][j], dp[i-1][j-1])+a[i][j];	
		}
		for (int i=n;i<2*n-1;++i)
		{
			for (int j=0;j<2*n-i;++j)
				dp[i][j]=max(dp[i-1][j], dp[i-1][j+1])+a[i][j];
		}
		printf("Case %d: %d\n", cnt++, dp[n*2-2][0]);
	}
	return 0;
}