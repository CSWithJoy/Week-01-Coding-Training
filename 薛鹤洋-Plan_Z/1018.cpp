/*
���⣺n���㣬����һ�����ʱ�������ⷽ�����ѡ����ѡ�����ϵ����е㱻��ȥ�������β��ܴ������е㡣
�ο��ı��˵�˼·��
��Ԥ����i���j��ֱ���ϵ����е㣬��Ϊn<=16������ѹ��״̬��0��ʾij����ֱ��û�иõ㣬1��֮��
��Ϊ������е㶼Ҫ��ȥ����������ѡ����Щ���ֱ��û�й�ϵ��
��ʼ��״̬��1<<n-1,���е㶼δ����������״̬��0
ת�Ʒ��̣�dp[s]=min(dp[s],(dfs(s^(s&line[i][j]))+1))
*/
#include<bits/stdc++.h>

#define inf 0x3f3f3f3f

const int maxn=100;

using namespace std;

int t,n,dp[(1<<16)+10],line[maxn+10][maxn+10];

struct point{
  int x,y;
}a[maxn+10];

int one_line(point a,point b,point c){
      return(b.x-a.x)*(c.y-a.y)==(c.x-a.x)*(b.y-a.y);
}

int dfs(int s){
     if(dp[s]!=inf) return dp[s];
     int cnt=0;
     for(int i=0;i<n;i++) if(s&(1<<i)) cnt++;
     if(cnt==0||cnt==1) return dp[s]=cnt;
     if(cnt==2) return dp[s]=1;
     for(int i=0;i<n;i++){
        if(!(s&(1<<i))) continue;
        for(int j=i+1;j<n;j++){
                if(!(s&(1<<j))) continue;
                dp[s]=min(dp[s],(dfs(s^(s&line[i][j]))+1));
        }
        break;
     }
     return dp[s];
}

int main()
{
    scanf("%d",&t);
    for(int h=1;h<=t;h++){
        memset(dp,inf,sizeof(dp));
        memset(line,0,sizeof(line));
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        scanf("%d%d",&a[i].x,&a[i].y);
        for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                        line[i][j]=(1<<i)+(1<<j);
                        for(int k=0;k<n;k++){
                                if(one_line(a[i],a[j],a[k])) line[i][j]|=(1<<k);
                        }
                }
        }
        printf("Case %d: %d\n",h,dfs((1<<n)-1));
    }
    return 0;
}
