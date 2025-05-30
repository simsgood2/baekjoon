#include <bits/stdc++.h>
#define FastIO\
    ios_base::sync_with_stdio(false);\
    cin.tie(NULL);\
    cout.tie(NULL);
using namespace std;

int num;
int cache[50001];//idx의 최소 개수

int dp(int n){//n을 만드는 최소개수 구하기
    int a = sqrt(n);
    if(pow(a,2)==n){
        return 1;
    }

    int &ret = cache[n];
    if(ret != -1) return ret;
    ret = 987654321;
    for(int i=a; i>=1; i--){
        ret = min(ret, dp(pow(i,2))+dp(n-pow(i,2)));
    }

    return ret;    
}

int main(){
    FastIO;
    cin>>num;
    memset(cache,-1,sizeof(cache));

    cout<<dp(num);
}