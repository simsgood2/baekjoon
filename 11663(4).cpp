#include <bits/stdc++.h>
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;
using namespace std;

int dot[100001];

int lower_bound_search(int left, int right, int target){
    if(left>right){
        return left;
    }
    int mid = (left+right)/2;
    if(dot[mid]>=target){//mid값이 target보다 크거나 같으면 right=mid-1    
        return lower_bound_search(left, mid-1, target);
    }
    else{//mid값이 target보다 작으면 left= mid+1      
        return lower_bound_search(mid+1, right, target);
    }
}

int upper_bound_search(int left, int right, int target){
    if(left>right){
        return left;
    }
    int mid = (left+right)/2;
    if(dot[mid]>target){
        return upper_bound_search(left,mid-1,target);
    }
    else{
        return upper_bound_search(mid+1, right, target);
    }
}

int main(void){
    FastIO;
    int n,m;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>dot[i];
    }
    sort(dot,dot+n);//점들 오름차순으로 정렬
    for(int t=0; t<m; t++){
        int x,y;
        cin>>x>>y;

        //두점 오름차순으로 정렬
        int tmp=x;
        if(x>y){
            x=y;
            y=tmp;
        }
        int a,b;
        a=lower_bound_search(0, n-1, x);//0부터 n-1구간에서 x의 인덱스값 찾기 lower_bound
        b=upper_bound_search(a, n-1, y);//a부터 n-1구간에서 y의 인덱스값 찾기 upper_bound
        
        
        cout<<b-a<<"\n";
    }
}