#include <bits/stdc++.h>
#define FastIO\
    ios_base::sync_with_stdio(false);\
    cin.tie(NULL);\
    cout.tie(NULL);
using namespace std;
using ll =long long;

int main(){
    FastIO;
    int n;
    cin>>n;
    vector<ll> liquid(n);
    for(int i=0; i<n; i++){
        cin>>liquid[i];
    }
    ll low = 0;
    ll high = n-1;
    ll minAbs = abs(liquid[low]+liquid[high]);
    pair<int,int> minTime;
    while(low<high){
        ll sum = (liquid[low]+liquid[high]);
        ll absSum = abs(sum);
        
        if(absSum < minAbs){
            minAbs = absSum;
            minTime = {low, high};
        }
        if(sum==0){
            cout<<liquid[low]<<" "<<liquid[high];
            return 0;
        }
        else if(sum>0){
            high--;
        }
        else{
            low++;
        }
    }
    cout<<liquid[minTime.first]<<" "<<liquid[minTime.second];
    
}