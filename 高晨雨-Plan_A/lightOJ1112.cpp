//树状数组的查询，修改操作，类似于敌兵布阵的基础题
#include<iostream>
#include<stdio.h>
#include<memory.h>
using namespace std;
#define MAX 100005
int n,a[MAX];

int lowbit(int i)
{
	return i&(-i);
}
void update(int i,int val)
{
	while(i<=n)
	{
		a[i]+=val;
		i+=lowbit(i);
	}
}
int sum(int i)
{
	int sum=0;
	while(i>0)
	{
		sum+=a[i];
		i-=lowbit(i);
	}
	return sum;
}
int main()
{
	int T,m,val,check,a,b;
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		memset(a, 0, sizeof(a));
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&val);
			update(i,val);
		}
		printf("Case %d:\n",t);
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&check);
			if(check==1)
			{
				scanf("%d",&a);
				int k=sum(a+1)-sum(a);
				update(a+1,-k);
				printf("%d\n",k);
			}
			if(check==2)
			{
				scanf("%d%d",&a,&b);
				update(a+1,b);
			}
			if(check==3)
			{
				scanf("%d%d",&a,&b);
				printf("%d\n",sum(b+1)-sum(a));
			}
		}
	}
	return 0;
}
