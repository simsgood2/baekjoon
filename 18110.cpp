#include <bits/stdc++.h>
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;

int main(void){
    FastIO;
    int n, sum=0;
    cin>>n;
    if(n==0){
        cout<<0;
        return 0;
    }
    int deleteNum = round(n*15.0/100);//앞뒤로 삭제해야하는 수
    deque<int> Num;
    for(int i=0; i<n; i++){
        int m;
        cin>>m;
        Num.push_back(m);
    }
    sort(Num.begin(), Num.end());// 오름차순
    for(int i=0; i<deleteNum; i++){
        Num.pop_back();
        Num.pop_front();
    }
    for(int num: Num){
        sum+=num;
    }
    int avg = round(static_cast<double>(sum)/(n-deleteNum*2));
    cout<<avg;
    return 0;
}