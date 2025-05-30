#include <bits/stdc++.h>
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;

int main(void){
    FastIO;
    int M,N;
    cin>>M>>N;
    for(int i=M; i<=N; i++){//M부터 N까지
        if(i==1)continue;
        if(i%2==0){
            if(i==2){
                cout<<i<<'\n';
                continue;
            }
            continue;
        }
        else{
            bool check =1;
            for(int j=3; j*j<=i; j++){
                if(i%j==0){
                    check=0;
                    break;
                }
            }
            if(check)
            cout<<i<<'\n';
        }
        
        
    }
}