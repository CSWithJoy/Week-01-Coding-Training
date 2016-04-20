/*
求一个最短的串的长度，同时是给定两个串的母串和方案数。
第一个先求LCS然后两个串长度加起来减去LCS的长度
第二个考虑当两个串对应的字符相等时，只能选该字符，不相同，选两个都可以。
*/
#include<bits/stdc++.h>

#define inf 0x3f3f3f3f

const int maxn=100;

using namespace std;

int t,dp[maxn+10][maxn+10];

char a[maxn+10],b[maxn+10];

long long dp1[maxn+10][maxn+10];

int main()
{
    scanf("%d",&t);
    for(int h=1;h<=t;h++){
        memset(dp,0,sizeof(dp));
        memset(dp1,0,sizeof(dp1));
        scanf("%s%s",a,b);
        int lena=strlen(a),lenb=strlen(b);
        for(int i=0;i<=lena;i++) dp1[i][0]=1;
        for(int j=0;j<=lenb;j++) dp1[0][j]=1;
        for(int i=0;i<lena;i++){
                for(int j=0;j<lenb;j++){
                        if(a[i]==b[j]) {
                        dp[i+1][j+1]=dp[i][j]+1;
                        } else {
                           dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
                        }

                }
        }
        for(int i=0;i<lena;i++){
                for(int j=0;j<lenb;j++){
                        if(a[i]==b[j]){
                                dp1[i+1][j+1]=dp1[i][j];
                        } else{
                            if(dp[i+1][j+1]==dp[i+1][j]&&dp[i+1][j+1]!=dp[i][j+1]) dp1[i+1][j+1]=dp1[i+1][j];
                            if(dp[i+1][j+1]==dp[i][j+1]&&dp[i+1][j+1]!=dp[i+1][j]) dp1[i+1][j+1]=dp1[i][j+1];
                            if(dp[i+1][j+1]==dp[i][j+1]&&dp[i+1][j+1]==dp[i+1][j]) dp1[i+1][j+1]=(dp1[i+1][j]+dp1[i][j+1]);
                        }
                }
        }
        printf("Case %d: %d %lld\n",h,lena+lenb-dp[lena][lenb],dp1[lena][lenb]);
    }
    return 0;
}
