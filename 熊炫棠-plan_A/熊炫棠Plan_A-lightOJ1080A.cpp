/*线段树改区间。。不知道正常的应该怎么弄，想起来上次涂气球的题，，就用1到x的和表示改变的次数吧
*/
#include<iostream>
#include<list>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
int o;
int tree[400100];
char a[100010];
void change(int p,int l,int r,int x,int num){
    if(l==r){tree[p]+=num;return;}
    int mid=(l+r)/2;
    if(x<=mid) change(p*2,l,mid,x,num);
    else change(p*2+1,mid+1,r,x,num);
    tree[p]=tree[p*2]+tree[p*2+1];
}
int query(int p,int l,int r,int x,int y){
    if(x<=l&&r<=y)  return tree[p];
    int mid=(l+r)/2;
    if(y<=mid)  return query(p*2,l,mid,x,y);
    if(x>mid)   return query(p*2+1,mid+1,r,x,y);
    return query(p*2,l,mid,x,mid)+query(p*2+1,mid+1,r,mid+1,y);
}
void pro(){
    printf("Case %d:\n",o);
    scanf("%s",a);
    int q,s=strlen(a);
    char w;
    scanf("%d",&q);
    memset(tree,0,sizeof(tree));
    for(int i=1;i<=q;i++){
        scanf("%c",&w);
        while(w!='I'&&w!='Q')       //char玩的太烂，感觉输出都会被他读0 0，强行这样写。
        scanf("%c",&w);
 //       printf("%c\n",w);
        if(w=='I'){
            int x,y;
            scanf("%d%d",&x,&y);
            change(1,1,s,x,1);
            if(y!=s)
                change(1,1,s,y+1,-1);   //注意x到y改变所以应该在y+1处开始记上-1
 //           for(int j=1;j<=s;j++)   printf("%d ",query(1,1,s,j,j));
 //           printf("\n");
        }
        if(w=='Q'){
            int x,ans;
            scanf("%d",&x);
//            printf("%d  %d\n",(a[x-1]-'0'),query(1,1,s,1,x));
            ans=((a[x-1]-'0')+query(1,1,s,1,x))%2;
            printf("%d\n",ans);
        }
    }
    return;
}
int main(){
    int T;
    scanf("%d",&T);
    for(o=1;o<=T;o++)
        pro();
    return 0;
}
