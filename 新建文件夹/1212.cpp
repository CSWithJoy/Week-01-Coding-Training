//模拟双端队列的操作，用stl的deque实现
#include <iostream>
#include<cstdio>
#include<deque>

using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    for(int Case = 1; Case <= T; Case++)
    {
        printf("Case %d:\n",Case);
        int n,m;
        scanf("%d%d",&n,&m);
        deque<int> QUE;
        char command[10];
        while(m--)
        {
            scanf("%s",command);
            if(command[1] == 'u')
            {
                int number;
                scanf("%d",&number);
                if(QUE.size() == n)
                    printf("The queue is full\n");
                else
                {
                    if(command[4] == 'L'){
                        QUE.push_front(number);
                        printf("Pushed in left: %d\n",number);
                    }
                    else{
                        QUE.push_back(number);
                        printf("Pushed in right: %d\n",number);
                    }
                }
            }
            else
            {
                if(QUE.empty())
                {
                    printf("The queue is empty\n");

                }
                else
                {
                    if(command[3] == 'L')
                    {
                        printf("Popped from left: %d\n",QUE.front());
                        QUE.pop_front();
                    }
                    else
                    {
                        printf("Popped from right: %d\n",QUE.back());
                        QUE.pop_back();
                    }
                }

            }
        }
    }
    return 0;
}
