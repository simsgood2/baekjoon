#include <bits/stdc++.h>
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;

long long cache[101];

long long p(int n){//구하고자하는 p(n)
    if(n==1|| n==2 || n==3)return 1;
    if(n==4||n==5) return 2;

    long long &ret = cache[n];
    if(ret!=-1){
        return ret;
    }
    ret = p(n-1) + p(n-5);
    cache[n] = ret;

    return ret; 
}

int main(void){
    FastIO;
    int T;
    cin>>T;
    memset(cache, -1, sizeof(cache));
    for(int i=0; i<T; i++){
        int n;
        cin>>n;
        cout<<p(n)<<"\n";
    }
}