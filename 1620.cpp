#include <bits/stdc++.h>
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;



int main(void){
    FastIO;
    int n,m;
    cin>>n>>m;// n:포켓몬수, m: 문제수
    map<string, int> pocketmon1;
    map<int,string> pocketmon2;
    for(int i=1; i<=n; i++){
        string s;
        cin>>s;
        pocketmon1[s]=i;
        pocketmon2[i]=s;
    }
    
    for(int i=1; i<=m; i++){
        string a;
        cin >> a;
        if(isdigit(a[0])){//숫자이면
            cout<<pocketmon2[stoi(a)]<<"\n";
        }
        else{//문자열이면
            cout<<pocketmon1[a]<<"\n";
        }
    }

}