/*
��������n*n�ľ�������һ���ӵ�һ�е����һ�е����·����������ÿ�е��в����ظ���
n<=16,ѹ��״̬��1�������û�б���ѡ��0��֮��
*/
#include<bits/stdc++.h>

#define inf 0x3f3f3f3f

const int maxn=100;

using namespace std;

int t,n,a[maxn+10][maxn+10],dp[maxn+10][7*maxn*maxn+10];

int count_one(unsigned x){
    int count=0;
    while(x){
        count++;
        x=x&(x-1);
    }
    return count;
}

int main()
{
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        scanf("%d",&n);
        memset(dp,0,sizeof(dp));
        memset(a,0,sizeof(a));
        for(int j=1;j<=n;j++){
                for(int h=1;h<=n;h++){
                        scanf("%d",&a[j][h]);
                }
        }
        for(int j=1;j<=n;j++){
                for(int h=0;h<(1<<n);h++){
                       if(count_one(h)!=j-1) continue;
                        for (int k=0;k<n;k++) {
                        if (h&(1<<k)) continue;
                    dp[j][h|(1<<k)]=max(dp[j][h|(1<<k)],dp[j-1][h]+a[j][k+1]);
                }
        }
    }
        printf("Case %d: %d\n",i,dp[n][(1<<n)-1]);
    }
}
