#include <bits/stdc++.h>
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;

int n,m;
int binary_search(int arr[], int target, int left, int right){
    if(left>=right) return left;
    int mid;
        mid = (left+right)/2;
        if(target ==arr[mid])return mid;
        else if(target<arr[mid]){
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    return binary_search(arr,target, left,right);
}

int main(void){
    FastIO;
    cin>>n>>m;
    int dot[n];
    for(int i=0; i<n; i++){
        cin>>dot[i];
    }
    sort(dot,dot+n);
    for(int t=0; t<m; t++){
        int x,y;
        cin>>x>>y;
        int tmp=x;
        if(x>y){
            x=y;
            y=tmp;
        }
        int start,end;
        start=binary_search(dot,x,0,n-1);
        end=binary_search(dot,y,start,n-1);

        int ans = end-start+1;
        if(dot[end]>y)ans-=1;
        if(dot[start]<x)ans-=1;
        cout<<ans<<"\n";

    }
}