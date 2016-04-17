/*
区间dp。记录某个区间上的最大方案数。转移时，判断首尾两端字符是否相等。
如果相等就加上仅有首尾两个字符的情况，
如果不相等，就减去中间重复计算的部分。
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char in[70];
ll dp[70][70];

int main()
{
	int T, n, icase=1;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", in);
		n=strlen(in);
		memset(dp, 0, sizeof(dp));
		for (int i=n-1;i>=0;--i)
		{
			for (int j=i;j<n;++j)
			{
				dp[i][j]=dp[i+1][j]+dp[i][j-1];
				if (in[i]==in[j]) dp[i][j]+=1;
				if (in[i]!=in[j]) dp[i][j]-=dp[i+1][j-1];
			}
		}
		printf("Case %d: %lld\n", icase++, dp[0][n-1]);
	}
	return 0;
}