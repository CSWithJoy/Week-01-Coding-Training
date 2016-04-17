//双向队列，用list实现
#include<iostream>
#include<list>
#include<stdio.h>
#include<string>
using namespace std;
int main()
{
	int T;
	string done;
	list <int> Q;
	int n,cnt,flag,a;
	while(cin>>T)
	{
		for(int i=1;i<=T;i++)
		{
			cin>>n>>cnt;
			printf("Case %d:\n",i);
			flag=0;
			while(cnt--)
			{
				cin>>done;
				if(done=="pushLeft")
				{
					cin>>a;
					if(flag<n)
					{
						Q.push_back(a);
						flag++;
						printf("Pushed in left: %d\n",a);
					}
					else printf("The queue is full\n");
				}
				if(done=="pushRight")
				{
					cin>>a;
					if(flag<n)
					{
						Q.push_front(a);
						flag++;
						printf("Pushed in right: %d\n",a);
					}
					else printf("The queue is full\n");
				}
				if(done=="popLeft")
				{
					if(flag>0)
					{
						printf("Popped from left: %d\n",Q.back());
						Q.pop_back();
						flag--;
					}
					else printf("The queue is empty\n");
				}
				if(done=="popRight")
				{
					if(flag>0)
					{
						printf("Popped from right: %d\n",Q.front());
						Q.pop_front();
						flag--;
					}
					else printf("The queue is empty\n");
				}
			}
			while(!Q.empty()) Q.pop_back();
		}
	}
	return 0;
}