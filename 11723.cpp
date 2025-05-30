#include <bits/stdc++.h>
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;

int main(void){
    FastIO;
    int m;//연산의 수
    cin>>m;
    int ret=0;
    for(int i=0; i<m; i++){
        string s;
        cin>>s;
        if(s=="add"||s=="remove"||s=="check"||s=="toggle"){
            int p;
            cin>>p;
            p-=1;
            if (s == "add") {//p번째 비트를 1로
                ret = ret | (1<<p);
            } else if (s == "remove") {//p번째 비트를 0으로
                ret = ret & ~(1<<p);
            } else if (s == "check") {//있으면1출력 없으면 0 출력
                cout<<((ret&(1<<p)) ? 1 : 0)<<'\n';
            } else if (s == "toggle") {
                ret = ret ^ (1<<p);
            }
        }
        else{
            if(s=="all"){
                ret = (1<<20)-1;
            }
            else{//empty
                ret = 0;
            }
        }
    }
    return 0;
}