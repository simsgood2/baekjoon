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
    deque<int> arr(n+1);
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }
    int left=1;
    int max_length=0;
    map<int,int> kind;
    
    for(int right=1; right<=n; right++){//오른쪽으로 한칸식
        kind[arr[right]]++;
        while(kind.size()>2){//종류가 2개가 넘어가면
            kind[arr[left]]--;
            if(kind[arr[left]]==0){
                kind.erase(arr[left]);
            }
            left++;
        }
        max_length=max(max_length, right-left+1);
    }


    cout<<max_length;
    
}