#include <bits/stdc++.h>
#define FastIO\
    ios_base::sync_with_stdio(false);\
    cin.tie(NULL);\
    cout.tie(NULL);
using namespace std;

int maxResult=-1;//최종결과
int n;//받는 수
vector<pair<int,int>> arr;//여기에 입력받고
vector<int> assignArr;//여기에 경우의수 만들기

int calc(){
    int result=0;
    for(int i=0; i<n-1; i++){
        result+=abs(assignArr[i]-assignArr[i+1]);
    }
    return result;
}

void backTrack(int idx){// 현재 위치
    if(idx == n){//마지막 자리를 고를때가 오면
        maxResult = max(maxResult, calc());
        return;
    }
    for(int i=0; i<n; i++){
        if(arr[i].second==1) {
            continue;
        }
        else{
            assignArr.push_back(arr[i].first);
            arr[i].second=1;

            backTrack(idx+1);
            
            assignArr.pop_back();
            arr[i].second=0;
        }
    }
}

int main(){
    FastIO;
    cin>>n;
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        arr.emplace_back(temp,0);
    }
    backTrack(0);
    cout<<maxResult;
}