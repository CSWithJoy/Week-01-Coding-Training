//模拟一群人排队玩摩天轮，每个人要坐过所有位置，因为包含大量删除操作要用链表模拟
#include <iostream>
#include<list>
#include<cstdio>
#include<cstring>

using namespace std;
int man[21];
int seat[21];

int main()
{
    int T;
    cin >> T;
    int Case = 1;
    while(T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        list<int> q;
        for(int i=0;i<n;i++)
        {
            q.push_back(i);
        }
        memset(man,0,sizeof(man));
        memset(seat,-1,sizeof(seat));
        int i = 0;
        int sum = 0;
        while(1)
        {
            sum += 5;
            if(seat[i] != -1)
            {
                man[seat[i]] |= 1<<i;
                if(man[seat[i]] != (1<<m) - 1)
                {
                    q.push_back(seat[i]);
                }
                seat[i] = -1;
            }
            list < int > :: iterator it = q.begin();
            for(; it != q.end(); it++)
            {
                if(!(man[*it]&(1<<i)))
                {
                    seat[i] = *it;
                    q.erase(it);
                    break;
                }
            }
            if(q.empty())
            {
                int flag = 1;
                for(int i = 0;i < n;i++)
                {
                    if(man[i] != (1<<m)-1)
                    {
                        flag = 0;
                        break;
                    }
                }
                if(flag)
                {
                    break;
                }
            }
            i++;
            if(i == m)i=0;
        }
        printf("Case %d: %d\n",Case++,sum);
    }
    return 0;
}
