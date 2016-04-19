/*
给一个base进制的数字，求这个数字各个数位的全排列有多少个可以被k整除。
因为各个数位上的数字不同，0-F的话最多16位，可以压缩状态。
dp[i][j]表示当前选数状态为i时,模k为j时的方案数。
转移方程：dp[i|(1<<l)][(j*base+b[l])%k]+=dp[i][j]
代表将l代表的数字加入i最后一位时，mod k的结果为 (j*base+b[l])%k
因为(num*base+b[l])%k的话 num%k=j
*/
#include<bits/stdc++.h>

#define inf 0x3f3f3f3f

const int maxn=1<<16;

using namespace std;

int t,base,k,len,b[maxn+10];

long long dp[maxn+10][20];

char a[maxn+10];

int main()
{
    scanf("%d",&t);
    for(int h=1;h<=t;h++){
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        scanf("%d%d",&base,&k);
        scanf("%s",a);
        len=strlen(a);
        for(int i=0;i<len;i++){
                if(a[i]>='0'&&a[i]<='9') b[i]=a[i]-'0';
                else b[i]=a[i]-'A'+10;
        }
        for(int i=0;i<(1<<len);i++){
                for(int j=0;j<k;j++){
                        if(!dp[i][j]) continue;
                        for(int l=0;l<len;l++){
                                if(i&(1<<l)) continue;
                                dp[i|(1<<l)][(j*base+b[l])%k]+=dp[i][j];
                        }
                }
        }
        printf("Case %d: %lld\n",h,dp[(1<<len)-1][0]);
    }
    return 0;
}
