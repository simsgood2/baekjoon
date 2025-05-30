#include <bits/stdc++.h>
#define FastIO\
    ios_base::sync_with_stdio(false);\
    cin.tie(NULL);\
    cout.tie(NULL);
using namespace std;

int main(){
    FastIO;
    int n,k;
    cin>>n>>k;
    vector<int> value;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        value.push_back(a);
    }
    auto it = value.rbegin();
    int cnt=0;
    while(k&& it !=value.rend()){
        if(k>=*it){
            cnt += k/(*it);
            k %= (*it);
        }
        it++;
    }
    cout<<cnt;
    return 0;
}