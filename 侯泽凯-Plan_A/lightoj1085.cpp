//离散化数据+树状数组统计每个之前出现在该数之前的子序列数
#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define maxn (100000 + 50)
#define lowbit(x) (x & (-x))

int a[maxn];
int ac[maxn];
int c[maxn];

void add(int x,int ad,int n)
{
	while(x<=n)
	{
		c[x] = (c[x] + ad) % mod;
		x = x + lowbit(x);
	}
}

int sum(int n)
{
	int s=0;
	while(n>0)
	{
		s=(s+c[n])%mod;
		n=n-lowbit(n);
	}
	return s%mod;
}

int main()
{
	int t,n;
	scanf("%d",&t);

	for(int z=1;z<=t;z++)
	{
		scanf("%d",&n);

		memset(c,0,sizeof(c));

		for(int i = 1; i <= n; i ++)
        {
            scanf("%d",&a[i]);
            ac[i] = a[i];
        }

		sort(ac+1 , ac+n+1);

		int np = unique (ac+1 , ac+n+1) - ac;

		for(int i=1;i<=n;i++)
		{
			int pos = lower_bound(ac+1 , ac + np, a[i]) - ac;
            add(pos , sum(pos - 1)+1 , np - 1);
		}
		printf("Case %d: %d\n",z,sum(np-1));
	}
	return 0;
}
