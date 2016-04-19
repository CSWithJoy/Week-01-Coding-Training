/*水题吧就是用一下stack，注意清零什么的
*/
#include<iostream>
#include<string>
#include<stack>
#include<cstdio>
using namespace std;
int i;
void pro(){
    printf("Case %d:\n",i);
    stack<string> ba,fo;
    ba.push("http://www.lightoj.com/");
    string a,url;
    while(cin>>a){
        if(a[0]=='Q')
            break;
        else if(a[0]=='V'){
            cin>>url;
            ba.push(url);
            cout<<url<<endl;
            while(!fo.empty())  fo.pop();
        }
        else if(a[0]=='B'){
            if(ba.size()>1){
                fo.push(ba.top());
                ba.pop();
                cout<<ba.top()<<endl;
            }
            else printf("Ignored\n");
        }
        else if(a[0]=='F'){
            if(!fo.empty()){
                ba.push(fo.top());
                fo.pop();
                cout<<ba.top()<<endl;
            }
            else printf("Ignored\n");
        }
    }
    return;
}
int main(){
    int t;
    scanf("%d",&t);
    for(i=1;i<=t;i++) pro();
    return 0;
}
