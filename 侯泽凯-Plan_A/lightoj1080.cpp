//题解：因为每扫一次，数值只会+1。虽然树状数组只会记录从1到n的和，
   //    不过可以把a之前的再还原一次。
//注意：格式化输入的问题。

#include<bits/stdc++.h>
using namespace std;

int c[100005];
int str[100005];
int f;

int lowbit(int x)
{
    return x&(-x);
}

void update(int x,int val)   //向前修改
{
    while(x>0)
    {
       c[x]=c[x]+val;
        x=x-lowbit(x);
    }
}

int sum(int x)              //求和即为修改次数
{
    int res=0;
    while(x<=f)
    {
        res=res+c[x];
        x=x+lowbit(x);
    }
    return res;
}

int main()
{
    int t;
	scanf("%d",&t);

    for(int z=1;z<=t;z++)
    {
    	printf("Case %d:\n",z);
        memset(c,0,sizeof(c));

        int n,i=1;
        int x,y,s;
        char bitnum;

		string bit="2";
		string temp;

		cin>>temp;
		bit+=temp;

		f=bit.length();

        scanf("%d",&n);
		getchar();

        for(int k=0;k<n;k++)
        {
        	char op[5];//技巧
        	scanf("%s",&op);
        	getchar();

        	if(op[0]=='I')//技巧
			{
				scanf("%d%d",&x,&y);
				update(y,1);            //从右区间向前修改
				update(x-1,-1);         //从左区间向前修改，恢复那些不需要修改的值
			}
            else if(op[0]=='Q')
			{
				scanf("%d",&s);
				int cishu=sum(s);

				if(cishu%2==0)
				{
					printf("%c\n",bit[s]);
				}
				else
				{
					if(bit[s]=='1')
						printf("0\n");
					else if(bit[s]=='0')
						printf("1\n");
				}
			}
        }
    }
    return 0;
}
