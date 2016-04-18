//树状数组的典型例题，
//注意：1.树状数组是从1开始计数的。
       //2.计算区间和的时候的左闭右开原则

#include<bits/stdc++.h>
using namespace std;

int sack[100005];
int bit[100005];
int n;

int lowbit(int x)
{
	return x&(-x);
}

int sum(int i)
{
	int s=0;
	while(i>0)
	{
		s+=bit[i];
		i=i-lowbit(i);
	}
	return s;
}

void updata(int i,int val)
{
	while(i<=n)
	{
		bit[i]=bit[i]+val;
		i=i+lowbit(i);
	}
	/*for(int i=1;i<=n;i++)
		{
			cout<<bit[i]<<" ";
		}
	cout<<endl;*/
}

int main()
{
	int t;
	cin>>t;
	for(int z=1;z<=t;z++)
	{
		printf("Case %d:\n",z);
		int q;
		scanf("%d%d",&n,&q);

		memset(bit,0,sizeof(bit));

		for(int i=1;i<=n;i++)
		{
			scanf("%d",&sack[i]);
			updata(i,sack[i]);
		}

		/*for(int i=1;i<=n;i++)
		{
			cout<<bit[i]<<" ";
		}
		cout<<endl;*/

		for(int i=1;i<=q;i++)
		{
			int type;
			scanf("%d",&type);
			if(type==1)
			{
				int k;
				scanf("%d",&k);
				printf("%d\n",sack[k+1]);

				int tep=sack[k+1]*(-1);
				//cout<<endl<<tep<<endl;
				updata(k+1,tep);
				sack[k+1]=0;
			}
			else if(type==2)
			{
				int k,v;
				scanf("%d%d",&k,&v);
				updata(k+1,v);
				sack[k+1]+=v;
			}
			else if(type==3)
			{
				int l,r;
				scanf("%d%d",&l,&r);
				printf("%d\n",sum(r+1)-sum(l));
			}
		}
	}
	return 0;
}
