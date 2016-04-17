//模拟网页操作，用两个栈模拟，有一个表示之前看过的网页的栈还有因为后退操作产生的“前栈”,按要求操作就可以了
#include <iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<stack>
#include<vector>

using namespace std;
typedef struct URL
{
    string a;
    //URL(const char *s):a(s){}
}url;

int main()
{
    int T;
    cin >> T;
    int Case = 1;


    while(T--)
    {
        stack<url> backstack;
        stack<url> forwardstack;
        //struct URL firsturl;


        printf("Case %d:\n",Case++);
        char command[10];
        url nowurl;
        nowurl.a = "http://www.lightoj.com/";
        //backstack.push(nowurl);
        while(scanf("%s",command) && command[0] != 'Q')
        {
            if(command[0] == 'V')
            {
                char temp[50];

                backstack.push(nowurl);

                scanf("%s",temp);
                //cout <<"asd"<<endl;
                nowurl.a = temp;

                while(!forwardstack.empty())
                {
                    forwardstack.pop();
                }
                printf("%s\n",temp);
            }
            else if(command[0] == 'B')
            {
                if(backstack.empty())
                    printf("Ignored\n");
                else
                {
                    forwardstack.push(nowurl);
                    nowurl = backstack.top();
                    backstack.pop();
                    printf("%s\n",nowurl.a.c_str());
                }
            }
            else if(command[0] == 'F')
            {
                if(forwardstack.empty())
                {
                    printf("Ignored\n");
                }
                else
                {
                    backstack.push(nowurl);
                    nowurl = forwardstack.top();
                    forwardstack.pop();
                    printf("%s\n",nowurl.a.c_str());
                }
            }
        }
    }
    return 0;
}