#include <bits/stdc++.h>
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;

int dot[100001];

int binary_search(int start, int end, int target){
    if(start>=end)return start;
    int mid = (start+end)/2;
    if(dot[mid]==target){
        return mid;
    }
    else if(dot[mid]>target){
        end=mid-1;
    }
    else{
        start=mid+1;
    }
    return binary_search(start, end, target);
}


int main(void){
    FastIO;
    int n,m;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>dot[i];
    }
    sort(dot,dot+n);
    for(int t=0; t<m; t++){
        int first,second;
        cin>>first>>second;
        int tmp = first;
        if(first>second){
            first=second;
            second=tmp;
        }
        int firstIndex,secondIndex;
        firstIndex=binary_search(0,n-1, first);
        secondIndex=binary_search(firstIndex, n-1, second);
        if(dot[firstIndex]<first)firstIndex+=1;
        if(dot[secondIndex]>second)secondIndex-=1;
        if(firstIndex==secondIndex){
            cout<<0<<"\n";
            continue;
        }
        cout<<secondIndex-firstIndex<<"\n";
    }
}