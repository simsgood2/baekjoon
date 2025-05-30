#include <bits/stdc++.h>
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;

int dot[100001];

int binary_search(int left, int right, int target){//lower
    if(left>right){//1 3 5 7 에서 target 4를 찾을때 결국 left=2,right=1이된다.
        return left;
    }
    int mid = (left+right)/2;
    if(dot[mid]==target){
        return mid;
    }
    else if(target<dot[mid]){
        return binary_search(left, mid-1, target);
    }
    else{//target>dot[mid]
        return binary_search(mid+1, right, target);
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
        a=binary_search(0, n-1, x);//0부터 n-1구간에서 x의 인덱스값 찾기
        b=binary_search(a, n-1, y);//a부터 n-1구간에서 y의 인덱스값 찾기
        if(dot[b]==y)b++;//lower_bound로 구한 dot[b]가 y랑 같을경우 index+1

        cout<<b-a<<"\n";
    }
}