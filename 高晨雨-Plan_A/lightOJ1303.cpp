//摩天轮的题，本来想推导公式，最后只实现了一半，就是位置多人少的时候，后一半公式不太吻合，就模拟了
#include<bits/stdc++.h>
using namespace std;

int vis[25][25];//[people][seat number]

struct wheel
{
	int person;
	int pos;
}temp;

int main()
{
	int t;
	cin>>t;
	for(int z=1;z<=t;z++)
	{
		long long n,m,time=0;
		cin>>n>>m;
		if(n<=m)
		{
			time=m*m+m+n-1;
		}
		else
		{
			memset(vis,0,sizeof(vis));
		queue<int>pro;
		queue<wheel>seat;

		for(int i=1;i<=n;i++)
		{
			pro.push(i);
		}
		for(int i=1;i<=m;i++)
		{
			temp.person=0;
			temp.pos=i;
			seat.push(temp);
		}

		int subn=n;

		while(subn)
		{
			if(vis[0][seat.front().pos]==n||pro.empty())//所有人都做过||没人排队
			{
				if(seat.front().person!=0)//有人in seat
				{
					//座中人出
					if(vis [seat.front().person] [0]!=m)
					{
						pro.push(seat.front().person);
						seat.front().person=0;
					}
					else if(vis [seat.front().person] [0]==m)//是否出队
					{
						subn--;
						seat.front().person=0;
					}
				}
				seat.push(seat.front());
				seat.pop();
				time++;

				continue;
			}

			//有人没做过&&有人排队
			if(vis [pro.front()] [seat.front().pos] ==0)//队首没做过这个座
			{
				if(seat.front().person!=0)//有人in seat
				{
					//座中人出
					if(vis [seat.front().person] [0]!=m)
					{
						pro.push(seat.front().person);
						seat.front().person=0;
					}
					else if(vis [seat.front().person] [0]==m)//是否出队
					{
						subn--;
						seat.front().person=0;
					}
				}
				//排队人入
				seat.front().person=pro.front();
				//记录
					vis [0] [seat.front().pos]++;
					vis [seat.front().person] [0]++;
					vis [seat.front().person] [seat.front().pos]=1;
				pro.pop();
				//摩天轮转
				seat.push(seat.front());
				seat.pop();
				time++;//消耗
			}

			else if(vis [pro.front()] [seat.front().pos] ==1)//队首做过******ke优化
			{
				//座中人出
				if(seat.front().person!=0)//有人in seat
				{
					//座中人出
					if(vis [seat.front().person] [0]!=m)
					{
						pro.push(seat.front().person);
						seat.front().person=0;
					}
					else if(vis [seat.front().person] [0]==m)
					{
						subn--;
						seat.front().person=0;
					}
				}
				//记下队首的值
				int queue_top=pro.front();
				//队首放队尾
				pro.push(pro.front());
				pro.pop();
				//队列转一圈
				int flag=0;
				while(pro.front()!=queue_top)
				{
					if(flag==0&&vis[pro.front()] [seat.front().pos]==0)//队首可以做了
					{
						//队首入座
						seat.front().person=pro.front();
							vis [0] [seat.front().pos]++;
							vis [seat.front().person] [0]++;
							vis [seat.front().person] [seat.front().pos]=1;
						pro.pop();
						flag=1;
					}
					pro.push(pro.front());
					pro.pop();
				}
				//摩天轮转
				seat.push(seat.front());
				seat.pop();
				time++;
			}

		}
		}
		cout<<"Case "<<z<<": "<<time*5<<endl;

	}
	return 0;
}