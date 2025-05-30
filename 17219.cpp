#include <bits/stdc++.h>
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;

int main(void){
    FastIO;
    int n,m;//사이트 수, 찾으려는 수
    cin>>n>>m;
    unordered_map<string,string> site;
    for(int i=0; i<n; i++){
        string name, pswd;
        cin>>name>>pswd;
        site[name]=pswd;
    }
    for(int i=0; i<m; i++){
        string find;
        cin>>find;
        cout<<site.at(find)<<'\n';
    }
}