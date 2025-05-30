#include <bits/stdc++.h>
#define FastIO\
    ios_base::sync_with_stdio(false);\
    cin.tie(NULL);\
    cout.tie(NULL);
using namespace std;

int main(void){
    int T;
    cin>>T;//테스트케이스
    for(int t=0; t<T; t++){
        int n;
        cin>>n;//의상의 수
        if(n==0){
            cout<<0<<"\n";
            continue;
        }
        map<string, vector<string>> cloth;
        map<string, int> cnt; 
        for(int i=0; i<n; i++){
            string name, kind;
            cin>>name>>kind;
            if(find(cloth[kind].begin(), cloth[kind].end(), name)==cloth[kind].end()){//못찾았다면
                cloth[kind].push_back(name);
                cnt[kind]+=1;
            }
        }
        int combination = 1;
        for(auto i : cnt){
            combination*=(i.second+1);
        }
        cout<<combination-1<<"\n";


    }
}