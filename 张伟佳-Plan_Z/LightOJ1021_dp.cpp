/*
dp[i][j]记录了选泽了若干个数字之后，构成所有数字中mod k余j的个数。
转移的时候只将数字插入到最低位，这样方便计算余数。
dp[i][j]可以由任何一个选择的子集所处的状态转移得到，所以不会遗漏别的排列的情况。
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char in[20];
int num[20];
ll dp[(1<<16)+10][20];

int transform(char c)
{
	if (c>='0' && c<='9')
		return (int)(c-'0');
	else return (int)(c-'A'+10);
}

int main()
{
	int T, base, k, icase=1, n;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%s", &base, &k, in);
		n=strlen(in);
		for (int i=0;i<n;++i)
			num[i]=transform(in[i]);
		memset(dp, 0, sizeof(dp));
		dp[0][0]=1;
		for (int i=0;i<(1<<n);++i)
		{
			for (int j=0;j<n;++j)
			{
				int cur=1<<j;
				if (cur&i) continue;
				for (int r=0;r<k;++r)
				{
					if (dp[i][r]==0)
						continue;
					dp[i|cur][(r*base+num[j])%k]+=dp[i][r];
				}
			}
		}
		printf("Case %d: %lld\n", icase++, dp[(1<<n)-1][0]);
	}

	return 0;
}