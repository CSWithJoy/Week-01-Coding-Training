/*
区间dp
dp[i][j]记录取i~j区间时，先手最多领先的点数。
转移时，dp[i][j]由它的一个子区间dp[i+k][j]或者dp[i][j-k]转移来
转移时先手变后手。所以取max(sum[一轮取走的点数]-dp[子区间])

dp[i, j]=max(dp[i, j], sum[i, k]-dp[k+1, j]);
dp[i, j]=max(dp[i, j], -dp[i, k-1]+sum[k, j]);
y=s-x
x-y=x-s+x

*/
#include <bits/stdc++.h>
using namespace std;
const int maxn=105;
int x[maxn], sum[maxn];
int dp[maxn][maxn];

int main() {
	int T, icase=1, n, ans;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		sum[0]=0;
		memset(dp, 0, sizeof(dp));
		for (int i=1;i<=n;++i) {
			scanf("%d", x+i);
			sum[i]=sum[i-1]+x[i];
			dp[i][i]=x[i];
		}
		for (int p=1;p<=n;++p) {
			for (int i=1;i<=n-p;++i) {
				int j=i+p;
				dp[i][j]=sum[j]-sum[i-1];
				for (int k=i;k<j;++k) {
					dp[i][j]=max(dp[i][j], sum[k]-sum[i-1]-dp[k+1][j]);
					dp[i][j]=max(dp[i][j], sum[j]-sum[k]-dp[i][k]);
				}
			}
		}
		printf("Case %d: %d\n", icase++, dp[1][n]);
	}
	return 0;
}

