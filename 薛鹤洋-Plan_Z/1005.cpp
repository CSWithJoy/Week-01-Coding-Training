/*
可以注意到，对于n*n的矩阵，选了一个点之后，剩下的点为(n-1)*(n-1).
依次类推下去可得 dp[n][k]=dp[n-1][1]*dp[n-2][1]*.../k!;
因为先后顺序不影响最后结果 所以要除以k!
化简之后可得 dp[n][k]=dp[n][1]*dp[n-1][k-1]/k;
*/
#include<bits/stdc++.h>

#define inf 0x3f3f3f3f

const int maxn=30;

using namespace std;
int t,n,k;
long long dp[maxn*4+10][maxn*maxn+10];
int main()
{
    for(int i=1;i<=maxn;i++){
        dp[i][1]=i*i;
        dp[i][0]=1;
    }
    for(int j=2;j<=maxn;j++){
                for(int h=2;h<=j;h++){
                        dp[j][h]=dp[j][1]*dp[j-1][h-1]/h;
                }
        }
        //for(int i=0;i<=maxn;i++){
        //       for(int j=i+1;j<=maxn*maxn;j++){
        //              dp[i][j]=0;
            //    }
        //}
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%d%d",&n,&k);
        if(k>n) {printf("Case %d: 0\n",i+1);continue;}
        printf("Case %d: %lld\n",i+1,dp[n][k]);
    }
    return 0;
}
