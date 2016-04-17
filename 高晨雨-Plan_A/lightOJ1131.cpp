//开两个栈，根据题目要求入栈弹栈即可
#include <iostream>
#include <stdio.h>
#include <stack>
#include <string>
using namespace std;
int main()
{
	stack<string> Forward,Backward;
	string keywards,URL;
	int T;
	while(cin>>T)
	{
		for(int i=1;i<=T;i++)
		{
			printf("Case %d:\n",i);
			Backward.push("http://www.lightoj.com/");
			while(cin>>keywards)
			{
				if(keywards[0]=='Q') break;
				if(keywards[0]=='B')
				{
					if(Backward.size()>1)
					{
						Forward.push(Backward.top());
						Backward.pop();
						cout<<Backward.top()<<endl;
					}
					else
					{
						printf("Ignored\n");
					}
				}
				if(keywards[0]=='V')
				{
					cin>>URL;
					Backward.push(URL);
					cout<<URL<<endl;
					while(!Forward.empty())
					{
						Forward.pop();
					}
				}
				if(keywards[0]=='F')
				{
					if(!Forward.empty())
					{
						Backward.push(Forward.top());
						cout<<Forward.top()<<endl;
						Forward.pop();
					}
					else
					{
						printf("Ignored\n");
					}
				}
			}
			while (!Backward.empty()) Backward.pop();
			while (!Forward.empty()) Forward.pop();
		}
	}
	return 0;
}