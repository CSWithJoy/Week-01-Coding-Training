/*
dp[i][j]��ʾ ����[i,j]������ȡ���˿����õ����ٷ�
��Ϊֻ�ܴ�һͷ����ȡ���������������һ���ҵ���С�ģ�Ȼ�����ø�������ֵ��ȥ����
������� dp[i][j]-(sum[n]-dp[i][j])
*/
#include<bits/stdc++.h>

#define inf 0x3f3f3f3f

const int maxn=100;

using namespace std;

int t,n,a[maxn+10],sum[maxn+10],dp[maxn+10][maxn+10],flag[maxn+10][maxn+10];

int dfs(int l,int r){
    if(flag[l][r]) return dp[l][r];
    flag[l][r]=1;
    for(int i=l+1;i<=r;i++) dp[l][r]=min(dp[l][r],dfs(i,r));
    for(int i=r-1;i>=l;i--) dp[l][r]=min(dp[l][r],dfs(l,i));
    return dp[l][r]=sum[r]-sum[l-1]-dp[l][r];
}

int main()
{
    scanf("%d",&t);
    for(int h=1;h<=t;h++){
        memset(dp,0,sizeof(dp));
        memset(sum,0,sizeof(sum));
        memset(flag,0,sizeof(flag));
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
        for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) dfs(i,j);
        printf("Case %d: %d\n",h,2*dp[1][n]-sum[n]);
    }
    return 0;
}
