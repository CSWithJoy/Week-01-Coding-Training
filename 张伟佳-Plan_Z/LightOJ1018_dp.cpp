/*
dp[i][j]记录了与点i和点j共线的点的集合。
f记录某一系列点所需最少的清理次数。先对数据预处理，统计共线的点。
然后记忆化搜索，计算所有点被取得的时候最少的清理次数。
*/
#include <bits/stdc++.h>
using namespace std;
const int maxn=20;
const int inf=0x3f3f3f3f;
int x[maxn], y[maxn];
int dp[maxn][maxn], n, f[1<<16];
 
bool iscol(int i, int j, int k)
{
    return (x[j]-x[i])*(y[k]-y[i])-(y[j]-y[i])*(x[k]-x[i])==0;
}
 
void init()
{
    memset(dp, 0, sizeof(dp));
    for (int i=0;i<n-1;++i)
    {
        for (int j=i+1;j<n;++j)
        {
            for (int k=0;k<n;++k)
            {
                if (iscol(i, j, k))
                    dp[i][j]+=1<<k;
            }
        }
    }
}
 
int dfs(int state)
{
    if (f[state]<inf) return f[state];
    int cnt=0;
    for (int i=0;i<n;++i) if (state&(1<<i)) ++cnt;
    if (cnt==0) return f[state]=0;
    if (cnt<=2) return f[state]=1;
    for (int i=0;i<n-1;++i)
    {
        if (!(state&(1<<i))) continue;
        for (int j=i+1;j<n;++j)
        {
            if (state&(1<<j))
            {
                f[state]=min(f[state], dfs(state-(state&dp[i][j]))+1);
            }
        }
        break;
    }
    return f[state];
}
 
int main()
{
    int T, icase=1;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i=0;i<n;++i) scanf("%d%d", x+i, y+i);
        init();
        memset(f, 0x3f, sizeof(f));
        printf("Case %d: %d\n", icase++, dfs((1<<n)-1));
    }
    return 0;
}