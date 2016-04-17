//二维的树状数组的查询和修改操作，注意修改一次后应标记避免重复修改
#include<stdio.h>
#include<iostream>
#include<memory.h>
using namespace std;
#define Max 1600
int a[Max+5][Max+5];
int visit[Max+5][Max+5];
int lowbit(int i)
{
	return (i&(-i));
}
void update (int x, int y, int val)
{
    while (x <= Max)
    {
        int temp = y;
        while (temp <= Max)
        {
            a[x][temp] += val;
            temp += lowbit (temp);
        }
        x += lowbit (x);
    }
}

int sum (int x, int y)
{
    int sum = 0;
    while (x > 0)
    {
        int temp = y;
        while (temp > 0)
        {
            sum += a[x][temp];
            temp -= lowbit (temp);
        }
        x -= lowbit (x);
    }

return sum;
}


int main()
{
    int T,m,flag,x,y,xx,yy;
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
	{
        printf("Case %d:\n",t);
		memset(a,0,sizeof(a));
		memset(visit,0,sizeof(visit));
		scanf("%d",&m);
		while(m--)
		{
			scanf("%d",&flag);
			if(flag==0)
			{
				scanf("%d%d",&x,&y);
				if(!visit[x+1][y+1])
				{
					visit[x+1][y+1]=1;
					update(x+1,y+1,1);
				}
			}
			else{
				scanf("%d%d%d%d",&x,&y,&xx,&yy);
				printf("%d\n",sum(xx+1,yy+1)-sum(xx+1,y)-sum(x,yy+1)+sum(x,y));
			}
		}
	}
	return 0;
}