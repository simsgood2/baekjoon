#include <bits/stdc++.h>
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;

int n[10001];

int main(void){
    FastIO;
    for(int i=1; i<=10000; i++){
        int sum=0;
        int j=i;
        sum+=i;
        while(j>0){
            sum +=j%10;
            j/=10;
        }
        if(sum<=10000){
        n[sum]=1;
        }
    }
    for(int i=1; i<=10000; i++){
        if(n[i]==0){
            cout<<i<<"\n";
        }
    }
}