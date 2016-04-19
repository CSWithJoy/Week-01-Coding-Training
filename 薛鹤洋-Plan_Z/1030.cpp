/*
先算出每个位置的概率，乘每个位置的值。
*/
#include<bits/stdc++.h>

#define inf 0x3f3f3f3f

const int maxn=100;

using namespace std;

int t,n,a[maxn+10];

double ans,dp[maxn+10];

int main()
{
    scanf("%d",&t);
    for(int h=1;h<=t;h++){
        scanf("%d",&n);
        memset(dp,0,sizeof(dp)),dp[1]=1.0,ans=0;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=2;i<=n;i++){
             if(i<=6) {
                for(int j=1;j<i;j++) {
                        if(n-j>6)
                        dp[i]+=dp[j]/6;
                        else dp[i]+=dp[j]/(n-j);
                }
             }   else {
                     for(int j=i-1;j>=i-6;j--) {
                        if(n-j>6)
                        dp[i]+=dp[j]/6;
                        else dp[i]+=dp[j]/(n-j);
                     }
             }
        }
        for(int i=1;i<=n;i++) {
                       // printf("%f ",dp[i]);
                        ans+=dp[i]*a[i];
        }
        printf("Case %d: %f\n",h,ans);
    }
    return 0;
}
