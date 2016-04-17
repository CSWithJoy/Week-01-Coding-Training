/*
dp记录到达该点的概率，转移时，如果剩余的空间大于六个格子，那么下面六个位子分别加上1/6。
如果只有k<6个格子，接下来k个格子中各加入1/k。
最后计算期望e=sigma(dp[i]*x[i])
*/

#include <bits/stdc++.h>
using namespace std;
const int maxn=105;
int x[maxn];
double p[maxn], ans;


int main() {
	int T, icase=1, n;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i=0;i<n;++i) {
			p[i]=0.0;
			scanf("%d", x+i);
		}
		printf("Case %d: ", icase++);
		ans=0.0;
		p[0]=1.0;
		for (int i=0;i<n;++i)
		{
			for (int j=1;j<=6&&i+j<n;++j)
			{
				int divide=min(6, n-i-1);
				p[i+j]+=p[i]/(double)divide;
			}
			ans+=p[i]*(double)x[i];
		}
		printf("%.6lf\n", ans);

	}
	return 0;
}