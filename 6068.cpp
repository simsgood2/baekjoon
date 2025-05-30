#include <bits/stdc++.h>
#define FastIO\
    ios_base::sync_with_stdio(false);\
    cin.tie(NULL);\
    cout.tie(NULL);
using namespace std;

int main(void){
    int n;
    cin>>n;
    vector<pair<int,int>> vec;//제한시간, 사용시간
    int end=-1;
    for(int i=0; i<n; i++){
        int useTime, limit;
        cin>>useTime>>limit;
        end = max(end, limit);
        vec.emplace_back(limit, useTime);
    }
    sort(vec.rbegin(), vec.rend());
    for(auto i: vec){
        if(end>i.first){
            end=i.first-i.second;
        }
        else{
            end-=i.second;
        }
        if(end<0){
            cout<<-1;
            return 0;
        }
    }
    cout<<end;
    return 0;
}