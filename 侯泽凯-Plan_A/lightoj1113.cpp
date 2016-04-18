//题解：注意一个坑点：The browser initially loads the web page at the URL 'http://www.lightoj.com/'，我第一次读题不仔细，程序直接变木马。。。。。。。
#include<iostream>
#include<stack>
#include<string>

using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int z=1;z<=t;z++)
	{
		cout<<"Case "<<z<<":"<<endl;
		stack<string>cur;
		stack<string>last;

		string op;
		string url;

		cur.push("http://www.lightoj.com/");

		while(cin>>op)
		{
			 if(op=="QUIT")
				break;

			 if(op=="VISIT")
			 {
			 	cin>>url;
			 	cout<<url<<endl;
			 	cur.push(url);
			 	while(!last.empty())
				{
					last.pop();
				}
			 }
			 else if(op=="BACK")
			 {
			 	if(cur.top()!="http://www.lightoj.com/")
				{
					last.push(cur.top());
					cur.pop();
					cout<<cur.top()<<endl;
				}
			 	else
				{
					cout<<"Ignored"<<endl;
				}
			 }
			 else if(op=="FORWARD")
			 {
			 	if(!last.empty())
				{
					cur.push(last.top());
					cout<<cur.top()<<endl;
					last.pop();
				}
			 	else
				{
					cout<<"Ignored"<<endl;
				}
			 }
		}
	}
	return 0;
}
