/*
区间跟新的问题，给一串01串，翻转一些区间上的点，每次翻转在对应区间上打上翻转的标记即可
*/
#include <iostream>
#include<cstdio>
#include<cstring>
#include<string>

using namespace std;
const int maxn = 111111;
char s[maxn];
bool tree[maxn<<1];
void build_tree(int p, int left, int right)
{
    if(left == right)
    {
        tree[p] = (s[left] == '1')? 1 : 0;
        return;
    }
    int mid = (left + right)>>1;
    build_tree(p<<1,left,mid);
    build_tree(p<<1|1,mid+1,right);
    tree[p] = false;
}
void query(int p,int left,int right, int x,bool wei)
{
    if(left == right)
    {
        printf("%d\n",wei^tree[p]);
        return;
    }
    int mid = (left +right)>>1;
    if(x<=mid)
    {
        query(p<<1,left,mid,x,wei^tree[p]);
    }
    else
    {
        query(p<<1|1,mid+1,right,x,wei^tree[p]);
    }
}
void update(int p,int left,int right,int start,int finish)
{
    if(start <= left && right <= finish)
    {
        tree[p] = !tree[p];
        return;
    }
    int mid = (left + right)>>1;
    if(start<=mid)
    {
        update(p<<1,left,mid,start,finish);
    }
    if(finish > mid)
    {
        update(p<<1|1,mid+1,right,start,finish);
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    int Case = 1;
    while(T--)
    {
        printf("Case %d:\n",Case++);
        scanf("%s",s+1);
        int length = strlen(s+1);
        build_tree(1,1,length);
        //cout << length <<endl;
        int num;
        scanf("%d",&num);
        char command[7];
        while(num--)
        {
            //cout << "asd"<<endl;
            scanf("%s",command);
            if(command[0] == 'I')
            {
                int start,finish;
                scanf("%d%d",&start,&finish);
                update(1,1,length,start,finish);
            }
            else
            {
                int x;
                scanf("%d",&x);
                query(1,1,length,x,0);
            }
        }
    }
    return 0;
}
