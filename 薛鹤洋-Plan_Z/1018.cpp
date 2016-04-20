/*
题意：n个点，处理一个点的时候有任意方向可以选，则选择方向上的所有点被出去，求处理几次才能处理所有点。
参考的别人的思路：
先预处理i点和j点直线上的所有点，因为n<=16，可以压缩状态，0表示ij所在直线没有该点，1反之。
因为最后所有点都要被去除，所以先选择哪些点和直线没有关系。
开始的状态是1<<n-1,所有点都未被处理，最后的状态是0
转移方程：dp[s]=min(dp[s],(dfs(s^(s&line[i][j]))+1))
*/
#include<bits/stdc++.h>

#define inf 0x3f3f3f3f

const int maxn=100;

using namespace std;

int t,n,dp[(1<<16)+10],line[maxn+10][maxn+10];

struct point{
  int x,y;
}a[maxn+10];

int one_line(point a,point b,point c){
      return(b.x-a.x)*(c.y-a.y)==(c.x-a.x)*(b.y-a.y);
}

int dfs(int s){
     if(dp[s]!=inf) return dp[s];
     int cnt=0;
     for(int i=0;i<n;i++) if(s&(1<<i)) cnt++;
     if(cnt==0||cnt==1) return dp[s]=cnt;
     if(cnt==2) return dp[s]=1;
     for(int i=0;i<n;i++){
        if(!(s&(1<<i))) continue;
        for(int j=i+1;j<n;j++){
                if(!(s&(1<<j))) continue;
                dp[s]=min(dp[s],(dfs(s^(s&line[i][j]))+1));
        }
        break;
     }
     return dp[s];
}

int main()
{
    scanf("%d",&t);
    for(int h=1;h<=t;h++){
        memset(dp,inf,sizeof(dp));
        memset(line,0,sizeof(line));
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        scanf("%d%d",&a[i].x,&a[i].y);
        for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                        line[i][j]=(1<<i)+(1<<j);
                        for(int k=0;k<n;k++){
                                if(one_line(a[i],a[j],a[k])) line[i][j]|=(1<<k);
                        }
                }
        }
        printf("Case %d: %d\n",h,dfs((1<<n)-1));
    }
    return 0;
}
