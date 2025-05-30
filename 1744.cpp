#include <bits/stdc++.h>
#define FastIO\
    ios_base::sync_with_stdio(false);\
    cin.tie(NULL);\
    cout.tie(NULL);
using namespace std;
using ll = long long;

int main(){
    FastIO;
    ll n;
    cin>>n;
    vector<ll> negativeNum, positiveNum, zero;
    for(ll i=0; i<n; i++){
        ll temp;
        cin>>temp;
        if(temp>0) positiveNum.push_back(temp);
        else if(temp<0) negativeNum.push_back(temp);
        else zero.push_back(temp);
    }
    sort(positiveNum.rbegin(), positiveNum.rend());
    sort(negativeNum.begin(), negativeNum.end());

    ll result = 0;
    
    //음수
    if(negativeNum.size()%2==0){
        for(ll i=0; i<negativeNum.size(); i+=2){
            result += negativeNum[i]*negativeNum[i+1];
        }
    }
    else{
        if(zero.empty()){
            result +=negativeNum.back(); 
        }
        for(ll i=0; i<negativeNum.size()-1; i+=2){
            result += negativeNum[i]*negativeNum[i+1];
        }
    }

    //양수
    //1 처리
    while(!positiveNum.empty()&&positiveNum.back()==1){
        result+=1;
        positiveNum.pop_back();
    }
    if(positiveNum.size()%2==0){
        for(ll i=0; i<positiveNum.size(); i+=2){
            result += positiveNum[i]*positiveNum[i+1];
        }
    }
    else{
        for(ll i=0; i<positiveNum.size()-1; i+=2){
            result += positiveNum[i]*positiveNum[i+1];
        }
        result+=positiveNum.back();
    }

    cout<<result;
    return 0;

}