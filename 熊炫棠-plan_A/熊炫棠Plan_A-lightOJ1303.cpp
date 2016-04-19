#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<queue>
#include<list>
#include<cstring>
using namespace std;
int a[21][21];
int o;
typedef list<int> listint;
void pro(){
    int n,m,i;
    scanf("%d%d",&n,&m);
    listint l1,l2;
    for(i=1;i<=n;i++)   l1.push_back(i);
    for(i=1;i<=m;i++)   l2.push_back(0);
    memset(a,0,sizeof(a));
    listint::iterator dd;
    int ans=0,p=0,flag=0;
    while(flag!=m){
        for(i=1;i<=m;i++){
            for(dd=l1.begin();dd!=l1.end();dd++)
                if(!a[*dd][i]){p=1;/*printf("%d   %d\n",*dd,i);*/break;}
            if(!p){
                l2.push_back(0);
            }
            else{
                a[*dd][i]=1;
                l2.push_back(*dd);
                l1.remove(*dd);
            }
            if(l2.front()!=0)
                l1.push_back(l2.front());
            l2.pop_front();
            ans+=5;
 //           for(dd=l2.begin();dd!=l2.end();dd++)    printf("%d ",*dd);
 //           printf("\n");
            p=0;
        }
        int q=1;
        for(int i=1;i<=n&&q;i++)
            for(int j=1;j<=m&&q;j++)
            if(a[i][j]==0)  q=0;
        if(q==1)break;
    }
    while(l2.back()==0)   l2.pop_back();
    ans+=l2.size()*5;
 //   printf("%d\n",l2.size());
//    printf("%d %d    %d\n",n,m,ans);
    printf("Case %d: %d\n",o,ans);
}
int main(){
    int T;
    scanf("%d",&T);
    for(o=1;o<=T;o++)
        pro();
    return 0;
}
