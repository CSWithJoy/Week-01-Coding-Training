/*就线段树咯
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int o;
int tree[400005],ans;
void built(int p,int l,int r){
    if(l==r){scanf("%d",&tree[p]);return;}
    int mid=(r+l)>>1;
    built(p<<1,l,mid);
    built(p<<1|1,mid+1,r);
    tree[p]=tree[p<<1]+tree[p<<1|1];
    return;
}
void change(int p,int l,int r,int x,int num){
    if(l==r)
        if(num==-99999)
            {printf("%d\n",tree[p]);tree[p]=0;return;}
        else
            {tree[p]+=num;return;}
    int mid=(l+r)>>1;
    if(x<=mid) change(p<<1,l,mid,x,num);
    else    change(p<<1|1,mid+1,r,x,num);
    tree[p]=tree[p<<1]+tree[p<<1|1];
    return;
}
void query(int p,int l,int r,int x,int y){
    if(x<=l&&r<=y){ans+=tree[p];return;}
    int mid=(l+r)>>1;
    if(x<=mid) query(p<<1,l,mid,x,y);
    if(mid<y)query(p<<1|1,mid+1,r,x,y);
    return;
}
void pro(){
    printf("Case %d:\n",o);
    int n,q,i;
    scanf("%d%d",&n,&q);
    built(1,0,n-1);
    for(i=1;i<=q;i++){
  //      for(int j=1;j<=9;j++)    printf("%d   ",tree[j]);
 //       printf("\n");
        int c,x,y;
        scanf("%d%d",&c,&x);
        if(c==1)    change(1,0,n-1,x,-99999);
        else{
            scanf("%d",&y);
            if(c==2)change(1,0,n-1,x,y);
            if(c==3){
                ans=0;
                query(1,0,n-1,x,y);
                printf("%d\n",ans);
            }
        }
    }
    return;
}
int main(){
    int T;
    scanf("%d",&T);
    for(o=1;o<=T;o++)   pro();
    return 0;
}
