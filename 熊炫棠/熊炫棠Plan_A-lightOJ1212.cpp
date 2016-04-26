/*就一个双端队列，按条件输入输出就好
*/
#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<cstdio>
using namespace std;
int o;
void pro(){
    printf("Case %d:\n",o);
    int n,m,i,nu;
    string co;
    scanf("%d%d",&n,&m);
    deque<int> q;
    while(m--){
        cin>>co;
        if(co[4]=='L'){
            scanf("%d",&nu);
            if(q.size()<n){
                q.push_back(nu);
                printf("Pushed in left: %d\n",nu);
            }
            else printf("The queue is full\n");
        }
        else if(co[4]=='R'){
            scanf("%d",&nu);
            if(q.size()<n){
                q.push_front(nu);
                printf("Pushed in right: %d\n",nu);
            }
            else printf("The queue is full\n");
        }
        else if(co[4]=='e'){
            if(!q.empty()){
                nu=q.back();
                printf("Popped from left: %d\n",nu);
                q.pop_back();
            }
            else
                printf("The queue is empty\n");
        }
        else if(co[4]=='i'){
            if(!q.empty()){
                nu=q.front();
                printf("Popped from right: %d\n",nu);
                q.pop_front();
            }
            else
                printf("The queue is empty\n");
        }
    }
    return;
}
int main(){
    int t;
    scanf("%d",&t);
    for(o=1;o<=t;o++) pro();
    return 0;
}
