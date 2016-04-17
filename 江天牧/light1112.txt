//简单线段树问题有三种操作：定点清空，定点跟新，和区间查询
#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
const int Maxn = 111111;
int tree[Maxn<<2];

using namespace std;
void buid(int p,int L,int R)
{
    if(L == R)
    {
        int t;
        scanf("%d",&t);
        tree[p] = t;
        return;
    }
    int mid =(L+R)>>1;
    buid(p<<1,L,mid);
    buid(p<<1|1,mid+1,R);
    tree[p] = tree[p<<1] + tree[p<<1|1];
}
void Give(int p,int L,int R,int x)
{
    if(L == R)
    {
        printf("%d\n",tree[p]);
        tree[p] = 0;
        return;
    }
    int mid =(L+R)>>1;
    if(x<=mid)
    {
        Give(p<<1,L,mid,x);
    }
    else
    {
        Give(p<<1|1,mid+1,R,x);
    }
    tree[p] = tree[p<<1] + tree[p<<1|1];
}
int Query(int p,int L,int R,int S,int F)
{
    if(S<=L&&R<=F)
    {
        return tree[p];
    }
    int temp = 0;
    int mid =(L+R)>>1;
    if(S<=mid)
    {
        temp+= Query(p<<1,L,mid,S,F);
    }
    if(F>mid)
    {
        temp+=Query(p<<1|1,mid+1,R,S,F);
    }
    return temp;
}
void Add(int p,int L,int R,int x,int v)
{
    if(L==R)
    {
        tree[p]+= v;
        return;
    }
    int mid =(L+R)>>1;
    if(x<=mid)
    {
        Add(p<<1,L,mid,x,v);
    }
    else
    {
        Add(p<<1|1,mid+1,R,x,v);
    }
    tree[p] = tree[p<<1] + tree[p<<1|1];
}

int main()
{
    int T;
    int Case = 1;
    cin >> T;
    while(T--)
    {
        memset(tree,0,sizeof(tree));
        int n,q;
        scanf("%d%d",&n,&q);
        buid(1,0,n-1);
        printf("Case %d:\n",Case++);
        int command;
        while(q--)
        {
            scanf("%d",&command);
            if(command == 1)
            {
                int i;
                scanf("%d",&i);
                Give(1,0,n-1,i);
            }
            else if(command == 2)
            {
                int i,v;
                scanf("%d%d",&i,&v);
                Add(1,0,n-1,i,v);
            }
            else
            {
                int i,j;
                scanf("%d%d",&i,&j);
                printf("%d\n",Query(1,0,n-1,i,j));
            }
        }
    }
    return 0;
}
