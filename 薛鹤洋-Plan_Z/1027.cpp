/*
��nΪ��������mΪ�ܳ���������
��һ�ξͳ���������������n/m
��һ����Ҫ��ƽ��ʱ��Ϊ��ʱ��/n
������Ϊ ��ʱ��/m
*/
#include<bits/stdc++.h>

#define inf 0x3f3f3f3f

//const int maxn=;

using namespace std;

int t,n,d,sum,cnt,flag;

int gcd(int a,int b) {
  return b?gcd(b,a%b):a;
}

int main()
{
    scanf("%d",&t);
    for(int h=1;h<=t;h++){
        sum=0,flag=0,cnt=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) {
                scanf("%d",&d);
                if(d>0) sum+=d,cnt++,flag=1;
                else sum+=abs(d);
        }
        if(!flag) {
                printf("Case %d: inf\n",h);
                continue;
        }
        int tem=gcd(sum,cnt);
        sum/=tem,cnt/=tem;
        printf("Case %d: %d/%d\n",h,sum,cnt);
    }
    return 0;
}
