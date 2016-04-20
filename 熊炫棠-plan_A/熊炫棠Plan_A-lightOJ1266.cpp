#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
bool p[1205][1205];
int a[1205][1205],o;
int lowbit(int x){
    return  (x&(-x));
}
void change(int x,int y){
    p[x][y]=0;
    for(int i=x;i<=1200;i+=lowbit(i))
        for(int j=y;j<=1200;j+=lowbit(j))
        a[i][j]+=1;
}
int sum(int x,int y){
 //   if(x<0||y<0)    return 0;
    int ans=0;
    for(int i=x;i>0;i-=lowbit(i))
        for(int j=y;j>0;j-=lowbit(j))
        ans+=a[i][j];
    return ans;
}
void pro(){
    printf("Case %d:\n",o);
    memset(a,0,sizeof(a));
    memset(p,true,sizeof(p));
    int q;
    scanf("%d",&q);
    for(int i=1;i<=q;i++){
        int m,x,y,xx,yy;
        scanf("%d%d%d",&m,&x,&y);
        if(m==0&&p[x+1][y+1])    change(x+1,y+1);
        if(m==1){
            scanf("%d%d",&xx,&yy);
            printf("%d\n",sum(xx+1,yy+1)-sum(xx+1,y)-sum(x,yy+1)+sum(x,y));
        }
  /*      for(x=1;x<=10;x++)
            for(y=1;y<=10;y++)
            printf("%d%c",a[x][y],y==10?'\n':' ');
        printf("\n");*/
    }
    return;
}
int main(){
    int t;
    scanf("%d",&t);
    for(o=1;o<=t;o++)   pro();
    return 0;
}
