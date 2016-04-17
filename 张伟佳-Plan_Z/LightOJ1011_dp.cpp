/*状态保存选到第i行时，已经被选择过的列的位置信息。
这样在转移时，可以确定选择的具体位置和对应的幸福值*/
#include <bits/stdc++.h>
using namespace std;
const int maxn=17;
int dp[20][(1<<16)-1], a[maxn][maxn], n;

int main()
{
	int T, cnt=1;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i=0;i<n;++i) for (int j=0;j<n;++j) scanf("%d", &a[i][j]);
		memset(dp, 0, sizeof(dp));
		for (int i=0;i<n;++i)
		{
			int cur=1<<i;
			dp[0][cur]=a[0][i];
		}
		for (int i=1;i<n;++i)
		{
			for (int j=0;j<(1<<n);++j)
			{
				int cnt=0;
				for (int k=0;k<n;++k)
				{
					int cur=1<<k;
					if (cur&j) ++cnt; 
				}
				if (cnt!=i) continue;
				for (int k=0;k<n;++k)
				{
					int cur=1<<k;
					if (cur&j) continue;
					dp[i][j|cur]=max(dp[i][j|cur], dp[i-1][j]+a[i][k]);
				}
			}
		}
		printf("Case %d: %d\n", cnt++, dp[(n-1)][(1<<n)-1]);
	}
	return 0;
}