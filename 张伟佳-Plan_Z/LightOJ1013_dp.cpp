/*
f记录最短的能使两个字符串为它的子序列的串长，dp记录方案数。
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
char a[35], b[35];
int f[35][35];
ll dp[35][35];

int main()
{
	int T, cnt=1;
	int la, lb;
	ll ans;
	scanf("%d", &T);
	while (T--)
	{
        scanf("%s%s", a, b);
        la=strlen(a);
        lb=strlen(b);
        memset(f, 0x3f, sizeof(f));
        memset(dp, 0, sizeof(dp));
        for (int i=0;i<=la;++i)
		{
			dp[i][0]=1;
			f[i][0]=i;
		}
		for (int i=1;i<=lb;++i)
		{
			dp[0][i]=1;
			f[0][i]=i;
		}
		for (int i=1;i<=la;++i)
		{
			for (int j=1;j<=lb;++j)
			{
                f[i][j]=min(f[i][j], f[i-1][j]+1);
                f[i][j]=min(f[i][j], f[i][j-1]+1);
                if (a[i-1]==b[j-1])
				{
					f[i][j]=min(f[i][j], f[i-1][j-1]+1);
				}
                if (a[i-1]!=b[j-1])
				{
					if (f[i][j]==f[i-1][j]+1) dp[i][j]+=dp[i-1][j];
					if (f[i][j]==f[i][j-1]+1) dp[i][j]+=dp[i][j-1];
				}
				if (a[i-1]==b[j-1] && f[i][j]==f[i-1][j-1]+1)
				{
					dp[i][j]+=dp[i-1][j-1];
				}
			}
		}
		printf("Case %d: %d %lld\n", cnt++, f[la][lb], dp[la][lb]);
	}

	return 0;
}


/*
USA
USSR

USASR
USSAR
USSRA

*/
