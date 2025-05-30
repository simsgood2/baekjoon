#include <bits/stdc++.h>
#define FastIO\
    ios_base::sync_with_stdio(false);\
    cin.tie(NULL);\
    cout.tie(NULL);
using namespace std;

int main(){
    FastIO;
    int n,k;
    cin>>n>>k;
    if(k==n){
        cout<<0;
        return 0;
    }
    queue<pair<int,int>> q;//점, 시간
    bool visited[100001] ={};//false로 초기화  {false}도 가능
    q.push({n,0});
    visited[n] = true;
    while(!q.empty()){
        pair<int,int> start = q.front();
        if(start.first==k){
            cout<<start.second;
            return 0;
        }
        q.pop();
        //걷는경우
        if(start.first+1<=100000){
            if(!visited[start.first+1]){
                q.push({start.first+1, start.second+1});
                visited[start.first+1] = true;

                if(start.first+1 == k){
                    cout<<start.second+1;
                    return 0;
                }
            }
        }
        if(start.first-1>=0){
            if(!visited[start.first-1]){
                q.push({start.first-1, start.second+1});
                visited[start.first-1] = true;

                if(start.first-1 == k){
                    cout<<start.second+1;
                    return 0;
                }
            }
        }

        //순간이동하는 경우
        if(start.first*2<=100000){
            if(!visited[start.first*2]){
                q.push({start.first*2, start.second+1});
                visited[start.first*2] = true;

                if(start.first*2 == k){
                    cout<<start.second+1;
                    return 0;
                }
            }
        }
    }
}