/*
��n���㣬��ĳ���㴦��һ�ο���ȥ�����Լ��������������Ϸ����·�֮�ڵ������㣬��k�β�����ȥ�����ٵ�
�ȶ�n�����������������ÿ��������Ϊ��׼��������Ԥ����ÿ��������w�ܹ����Ƕ��ٵ㣬��Ϊcnt[i].
��i�������ѡ������߲���������Ļ���״̬��i-cnt[i]ת�ƹ������������i-1ת�ƹ�����
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
