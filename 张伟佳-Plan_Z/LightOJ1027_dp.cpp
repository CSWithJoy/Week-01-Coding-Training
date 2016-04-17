/*
计算数学期望。可以推算出公式

ei=1/n*xi 								能送出迷宫
ei=1/n*(|xi|+e)							不能送出迷宫
e=1/n*xi+1/n*(|xi|+e)+...+1/n*(|xi|+e)		
e=sum(1/n*|xi|)/(1-sum(1/n))			分子分母同时乘n
 => e=sum(|xi|)/numOfValidDoors

最后约分。
*/
#include <bits/stdc++.h>
using namespace std;
const int maxn=105;
typedef long long ll;
int n;

int gcd(int a, int b)
{
	return b==0?a:gcd(b, a%b);
}

int main()
{
	int T, icase=1, p, q, d;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		p=q=0;
		for (int i=0;i<n;++i)
		{
			int x;
			scanf("%d", &x);
			if (x>0) ++q;
			p+=(x>0?x:-x);
		}
		printf("Case %d: ", icase++);
		if (q==0)
		{
			printf("inf\n");
			continue;
		}
		d=gcd(p, q);
		p/=d;
		q/=d;
		printf("%d/%d\n", p, q);
	}
	return 0;
}


