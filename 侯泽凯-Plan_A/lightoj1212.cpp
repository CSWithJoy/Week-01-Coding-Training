//题解：要仔细！！！要仔细！！！要仔细！！！重要的事要说三遍！！！！！！！！
水题竟然wa3次！！！！！！！！！！

#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int z=1;z<=t;z++)
	{
		cout<<"Case "<<z<<":"<<endl;

		deque<int>q;

		int n,m,num,sum=0;
		string op;

		cin>>n>>m;

		for(int i=0;i<m;i++)
		{
			cin>>op;

			if(op=="pushLeft")
			{
				cin>>num;

				if(sum<n)
				{
					q.push_front(num);
					sum++;
					cout<<"Pushed in left: "<<num<<endl;
				}

				else
				{
					cout<<"The queue is full"<<endl;
				}
			}
			else if(op=="pushRight")
			{
				cin>>num;

				if(sum<n)
				{

					q.push_back(num);
					sum++;
					cout<<"Pushed in right: "<<num<<endl;
				}

				else
				{
					cout<<"The queue is full"<<endl;
				}
			}
			else if(op=="popLeft")
			{
				if(!q.empty())
				{
					cout<<"Popped from left: "<<q.front()<<endl;
					q.pop_front();
					sum--;
				}
				else
				{
					cout<<"The queue is empty"<<endl;
				}
			}
			else if(op=="popRight")
			{
				if(!q.empty())
				{
					cout<<"Popped from right: "<<q.back()<<endl;
					q.pop_back();
					sum--;
				}
				else
				{
					cout<<"The queue is empty"<<endl;
				}
			}
		}
	}
	return 0;
}