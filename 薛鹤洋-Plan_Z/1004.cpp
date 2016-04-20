//数字三角形，水题。

#include<bits/stdc++.h>

#define inf 0x3f3f3f3f

const int maxn=100;

using namespace std;
int t,n,a[4*maxn+10][4*maxn+10],dp[4*maxn+10][4*maxn+10];
int main()
{
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        memset(a,0,sizeof(a));
        memset(dp,0,sizeof(dp));
        scanf("%d",&n);
        for(int j=1;j<=n;j++){
                for(int h=1;h<=j;h++){
                        scanf("%d",&a[j][h]);
                }
        }
        for(int j=n+1,k=1;j<=2*n-1;j++,k++){
                for(int h=1;h<=n-k;h++){
                        scanf("%d",&a[j][h]);
                }
        }
        for(int j=1;j<=2*n-1;j++){
                for(int h=1;h<=n;h++){
                        if(j<=n)
                        dp[j][h]=(max(dp[j-1][h],dp[j-1][h-1])+a[j][h]);
                        else dp[j][h]=(max(dp[j-1][h],dp[j-1][h+1])+a[j][h]);
                }
        }
        printf("Case %d: %d\n",i+1,dp[2*n-1][1]);
    }
    return 0;
}
