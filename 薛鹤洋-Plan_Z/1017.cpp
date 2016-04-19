/*
有n个点，对某个点处理一次可以去掉它以及距离它纵坐标上方或下方之内的其他点，求k次操作能去除多少点
先对n个点的纵坐标排序，以每个点往下为标准做，并且预处理每个点往下w能够覆盖多少点，记为cnt[i].
第i个点可以选择处理或者不处理，处理的话，状态从i-cnt[i]转移过来，不处理从i-1转移过来。
dp[i][j]=max(dp[i-1][j],dp[i-cnt[i]][j-1]+cnt[i]);
*/
#include<bits/stdc++.h>

#define inf 0x3f3f3f3f

const int maxn=100;

using namespace std;

int t,n,w,k,dp[maxn+10][maxn+10],cnt[maxn+10],flag[maxn+10];

struct point{
   int x,y,cnt;
}a[maxn+10];

int cmp(point a,point b){
     return a.y<b.y;
}

int main()
{
    scanf("%d",&t);
    for(int h=1;h<=t;h++){
        memset(dp,0,sizeof(dp));
        memset(cnt,0,sizeof(cnt));
        memset(a,0,sizeof(a));
    //    memset(cnt2,0,sizeof(cnt2));
      //  memset(flag,0,sizeof(flag));
        scanf("%d%d%d",&n,&w,&k);
        for(int i=1;i<=n;i++){
                scanf("%d%d",&a[i].x,&a[i].y);
        }
        sort(a,a+n,cmp);
       // for(int i=1;i<=n;i++) cnt2[i]=1;
        for(int i=n;i>=1;i--){
                //if(flag[i]) continue;
                for(int j=i;j>=1;j--){
                       if(a[i].y-w<=a[j].y) {
                        cnt[i]++;
                        //flag[j]=1;
                       }
                       else break;
                }
        }
        for(int i=1;i<=n;i++){
                for(int j=1;j<=k;j++){
                        if(i>=cnt[i])
                        dp[i][j]=max(dp[i-1][j],dp[i-cnt[i]][j-1]+cnt[i]);
                        else dp[i][j]=max(dp[i-1][j],cnt[i]);
                }
        }
    printf("Case %d: %d\n",h,dp[n][k]);
    }
    return 0;
}
