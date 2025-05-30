#include <bits/stdc++.h>
#define FastIO\
    ios_base::sync_with_stdio(false);\
    cin.tie(NULL);\
    cout.tie(NULL);
using namespace std;

int main(){
    FastIO;
    int n;
    cin>>n;
    vector<int> score;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        score.push_back(a);
    }
    int des=0;
    if(n==1){
        cout<<0;
        return 0;
    }
    for(int i = n-2; i>=0; i--){
        if(score[i+1]<=score[i]){
            des+=score[i]-score[i+1]+1;
            score[i]=score[i+1]-1;
        }
    }
    cout<<des;
    return 0;
}