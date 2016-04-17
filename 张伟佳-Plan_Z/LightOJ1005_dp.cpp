/*dp[i][j]记录第i行已经选择了j个的时候时总的方案数，本行可以有放和不放两种状态，
从dp[i-1][j-1]和dp[i-1][j]转移过来。*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=32;
typedef long long ll;
ll dp[maxn][maxn];

int main()
{
	int n, k, T, cnt=1;
	ll ans;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &k);
		printf("Case %d: ", cnt++);
		if (k>n)
		{
			printf("0\n");
			continue;
		}

		memset(dp, 0, sizeof(dp));
		dp[0][0]=1; dp[0][1]=n;
		for (int i=1;i<n;++i)
		{
			dp[i][0]=1;
			for (int j=1;j<=n;++j)
			{
				dp[i][j]=dp[i-1][j-1]*(n-j+1)+dp[i-1][j];
			}
		}
		printf("%lld\n", dp[n-1][k]);
	}
	return 0;
}