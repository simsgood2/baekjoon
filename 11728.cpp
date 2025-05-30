#include <bits/stdc++.h>
#define FastIO\
    ios_base::sync_with_stdio(false);\
    cin.tie(NULL);\
    cout.tie(NULL);

using namespace std;

int main(){
    FastIO;
    int n,m;
    cin>>n>>m;
    vector<int> arr1(n),arr2(m);
    for(int i=0; i<n; i++){
        cin>>arr1[i];
    }
    for(int i=0; i<m; i++){
        cin>>arr2[i];
    }
    arr1.insert(arr1.end(), arr2.begin(), arr2.end());
    sort(arr1.begin(), arr1.end());
    for(auto i : arr1){
        cout<<i<<" ";
    }
}