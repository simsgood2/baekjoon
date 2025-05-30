#include <bits/stdc++.h>
#define FastIO                 \
    ios_base::sync_with_stdio; \
    cin.tie(NULL);             \
    cout.tie(NULL);
using namespace std;

int n; //계단의 개수
int stairs[301];//전역이므로 0으로 초기화됨
int cache[301][3];

int up(int now, int con){//현재 위치, 연속으로 밟은 수
    if(now==n){//마지막 계단을 밝으면
        return stairs[now];
    }
    if(now>n){//마지막 계단을 넘어가면
        return -987654321;
    }
    int &ret = cache[now][con];
    if(ret != -1){//이미 계산된 값이 있으면
        return ret;
    }
    ret = -987654321;
    
    if(con<2){//0, 1일때만 1칸을 올라갈수있다.
        ret = max(ret, up(now+1, con+1)+stairs[now]);
    }
    //항상 두칸 올라갈수있다.
    ret = max(ret, up(now+2, 1)+stairs[now]);

    return ret;
}

int main(void){
    FastIO;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>stairs[i];
    }
    memset(cache, -1, sizeof(cache));// -1로 초기화
    cout<<up(0,0);
}