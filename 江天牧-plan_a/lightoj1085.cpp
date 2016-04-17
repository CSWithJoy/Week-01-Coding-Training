//求上升子序列的和，以每个元素结尾的上升子序列数等于所有比它小并且排在它前面的元素的子序列和
//加一，用动态规划求解，并用线段树优化，因为数据范围很大还要用离散化的技巧。
#include <iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;
typedef long long LL;
const int maxn = 111111;
typedef struct yuans
{
    int value;
    int position;
}A;
const int mood = 1000000007;
A a[maxn];
int tree[maxn << 2];

bool cmp (A x, A y)
{
    if(x.value == y.value)
        return x.position > y.position;
    else
        return  x.value < y.value;
}
int sum(int p, int left, int right, int start, int finish)
{
    if(start <= left && right <= finish)
    {
        return tree[p];
    }
    int mid = (left + right) >> 1;
    LL temp = 0;
    if(left <= mid)
    {
        temp += sum(p<<1,left,mid,start,finish);
        temp%=mood;
    }
    if(finish > mid)
    {
        temp += sum(p<<1|1,mid+1,right,start,finish);
        temp%=mood;
    }
    return temp;
}
void inser(int p,int left,int right, int x, int num)
{
    if(left == right)
    {
        tree[p] = num;
        return;
    }
    int mid = (left+right)>>1;
    if(x<=mid)
    {
        inser(p<<1,left,mid,x,num);
    }else
    {
        inser(p<<1|1,mid+1,right,x,num);
    }
    tree[p] = (tree[p<<1] + tree[p<<1|1])%mood;
}


int main()
{
    int T;
    cin >> T;
    int Case = 1;
    while(T--)
    {

        int N;
        scanf("%d",&N);
        for(int i = 1;i<=N;i++)
        {
            scanf("%d",&a[i].value);
            a[i].position = i;
        }
        sort(a+1,a+1+N,cmp);
        memset(tree,0,sizeof(tree));
        int t;
        int allnum= 0;
        for(int i = 1;i<=N;i++)
        {
            t = sum(1,1,N,1,a[i].position)+1;
            t%=mood;
            inser(1,1,N,a[i].position,t);
            allnum += t;
            allnum%=mood;
        }
        printf("Case %d: ",Case++);
        printf("%d\n",allnum);
    }
    return 0;
}
