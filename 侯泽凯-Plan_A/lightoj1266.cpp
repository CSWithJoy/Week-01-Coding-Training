//二维树状数组模板提
#include<stdio.h>
#include<string.h>

int C[1605][1605];
int A[1605][1605];
int n;

int lowbit(int i)
{
	return i&(-i);
}

int sum (int x, int y)
{
    int sum = 0;
    while (x > 0)
    {
        int temp = y;
        while (temp > 0)
        {
            sum += C[x][temp];
            temp -= lowbit (temp);
        }
        x -= lowbit (x);
    }

return sum;
}


void update (int x, int y, int val)
{
    while (x <= 1600)
    {
        int temp = y;
        while (temp <= 1600)
        {
            C[x][temp] += val;
            temp += lowbit (temp);
        }
        x += lowbit (x);
    }
}



int main()
{
	int t,x1,y1,x2,y2,x,y,q;
	scanf("%d",&t);
	for(int z=1;z<=t;z++)
	{
		printf("Case %d:\n",z);

		memset(A,0,sizeof(A));
		memset(C,0,sizeof(C));

		scanf("%d",&q);

		while(q--)
		{
			int op;
			scanf("%d",&op);
			if(op==0)
			{
				scanf("%d%d",&x,&y);
				if(!A[x+1][y+1])
				{
					A[x+1][y+1]=1;
					update(x+1, y+1, 1);
				}
			}
			else
			{
				scanf("%d%d%d%d",&x1,&y1,&x2,&y2);

				printf("%d\n",sum(x2+1,y2+1) - sum(x2+1,y1) - sum(x1,y2+1)+ sum(x1,y1));
			}
		}
	}
	return 0;
}
