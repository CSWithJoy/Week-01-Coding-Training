/*
先对数据预处理，忽略横坐标，只关注y行上的dust的数量。
dp记录以i为bottom，已经刷第j次的清扫最多灰尘的数量。
转移的时候注意刷子有宽度，最优解一定存在于每一行最多被刷一次的情况里。
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
const int maxn=105;
int cnt[maxn], sz;
int dp[maxn][maxn];
map<int, int> mp;
struct P
{
    int y, cnt;
    P(){}
    bool operator<(const P &rhs) const
    {
        return y>rhs.y;
    }
} y[maxn];
 
int main()
{
    int T, n, w, k, icase=1;
    scanf("%d", &T);
    while (T--)
    {
        mp.clear();
        scanf("%d%d%d", &n, &w, &k);
        for (int i=0;i<n;++i)
        {
            int cx, cy;
            scanf("%d%d", &cx, &cy);
            ++mp[cy];
        }
        sz=0;
        for (map<int, int>::iterator it=mp.begin(); it!=mp.end();++it)
        {
            y[++sz].y=it->first;
            y[sz].cnt=it->second;
        }
        sort(y+1, y+sz+1);
        memset(dp, 0, sizeof(dp));
        for (int i=1;i<=sz;++i)
        {
            for (int j=1;j<=k;++j)
            {
                dp[i][j]=dp[i-1][j];
                int cnt=0;
                for (int m=i;m>=1 && y[m].y<=y[i].y+w;--m)
                {
                    cnt+=y[m].cnt;
                    dp[i][j]=max(dp[i][j], dp[m-1][j-1]+cnt);
                }
            }
        }
        printf("Case %d: %d\n", icase++, dp[sz][k]);
    }
    return 0;
}