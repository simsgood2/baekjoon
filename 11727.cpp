#include <bits/stdc++.h>
#define FastIO\
    ios_base::sync_with_stdio(false);\
    cin.tie(NULL);\
    cout.tie(NULL);
using namespace std;

int n;// 2*n직사각형
int cache[1002];//n길이 만큼의 가지수

int dp(int rest){//남은 가로길이
    if(rest == 0) return 0;
    if(rest == 1) return 1;
    if(rest == 2) return 3;

    int &ret = cache[rest];
    if(ret != -1){
        return ret;
    }
    ret  = dp(rest -1) + 2*dp(rest -2);
    ret%=10007;
    
    return ret;
}


int main(void){
    FastIO;
    cin>>n;
    memset(cache,-1, sizeof(cache));
    cout<<dp(n);
}