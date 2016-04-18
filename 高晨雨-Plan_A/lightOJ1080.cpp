//使用树状数组维护区间被改的次数，最后是奇数01取反，偶数次原样输出
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
#define MAX 110005
int T[MAX],len;
int lowbit(int x)
{
	return (-x)&x;
}
int Query(int x)
{
	int ret=0;
	while(x>0)
	{
		ret+=T[x];
		x-=lowbit(x);
	}
	return ret;
}
void Insert(int x,int d)
{
	while(x<=len)
	{
		T[x]+=d;
		x+=lowbit(x);
	}
}
int main()
{
	int Ti,t=0;
	char s[MAX];
	scanf("%d",&Ti);
	while(Ti--)
	{
		memset(T,0,sizeof(T));
		scanf("%s",s+1);
		len=strlen(s+1);
		int n;
		scanf("%d",&n);
		printf("Case %d:\n",++t);
		while(n--)
		{
			char a[2];
			scanf("%s",a);
			if(a[0]=='I')
			{
				int x,y;
				cin>>x>>y;
				Insert(x,1);
				Insert(y+1,-1);
			}
			else
			{
				int x;
				cin>>x;
				int k=Query(x);
				if(k&1)
				{
					if(s[x]=='1')
						printf("0\n");
					else
						printf("1\n");
				}
				else printf("%c\n",s[x]);
			}
		}
	}
	return 0;
}