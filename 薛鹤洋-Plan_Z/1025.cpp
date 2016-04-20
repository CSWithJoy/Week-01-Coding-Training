/*
���⣺��һ�����г�ȥ�����ַ�ʹ���ɻ��Ĵ��ķ�����
��ô��Ļ�����������������
dp[i][j]�����[i,j]�����ڻ��������е�����
���a[i]==a[j] ��dp[i][j]=dp[i][j-1]+dp[i+1][j]+1
��֮ dp[i][j]=dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1]
*/
#include<bits/stdc++.h>

#define inf 0x3f3f3f3f

const int maxn=100;

using namespace std;

int t,len;
long long dp[maxn+10][maxn+10];

char a[maxn+10];

int judge(char a[],int len){
    for(int i=0;i<len/2;i++){
        if(a[i]==a[len-i-1]) continue;
        else return 0;
    }
    return 1;
}

int main()
{
    scanf("%d",&t);
    for(int h=1;h<=t;h++){
        memset(dp,0,sizeof(dp));
        scanf("%s",a);
        len=strlen(a);
       // if(judge(a,len)) {
       //       printf("Case %d: 0\n",h);
      //        continue;
       // }
        for(int i=0;i<len;i++){
                for(int j=i;j>=0;j--){
                        if(i==j) {
                                dp[j][i]=1;
                                continue;
                        } else {
                            if(a[i]==a[j]) {
                                dp[j][i]=dp[j][i-1]+dp[j+1][i]+1;
                            } else {
                               dp[j][i]=dp[j][i-1]+dp[j+1][i]-dp[j+1][i-1];
                            }
                        }
                }
        }
        printf("Case %d: %lld\n",h,dp[0][len-1]);
    }
    return 0;
}
