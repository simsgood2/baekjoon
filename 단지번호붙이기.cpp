#include <bits/stdc++.h>
#define FastIO\
    ios_base::sync_with_stdio(false);\
    cin.tie(NULL);\
    cout.tie(NULL);
using namespace std;

int n;
vector<int> village;

void bfs(int i, int j, const vector<vector<int>>& home, vector<vector<bool>>& visited){
    queue<pair<int,int>> q;
    q.push(make_pair(i,j));
    visited[i][j]=true;
    village.back()+=1;

    while(!q.empty()){//q가 빌때까지
        pair<int,int> start = q.front();
        q.pop();
        //갈수있는 이웃 q에 저장
        if(j+1<=n-1){
            if(!visited[i][j+1]){//방문하지 않았다면
                if(home[i][j+1]==1){//집이라면
                    q.push({i,j+1});
                    visited[i][j+1]=true;
                    village.back()+=1;
                }
            }
        }
        if(i+1<=n-1){
            if(!visited[i+1][j]){
                if(home[i+1][j]==1){
                    q.push({i+1, j});
                    visited[i+1][j]=true;
                    village.back()+=1;
                }
            }
        }
        if(0<=j-1){
            if(!visited[i][j-1]){
                if(home[i][j-1]==1){
                    q.push({i,j-1});
                    visited[i][j-1]=true;
                    village.back()+=1;
                }
            }
        }
        if(0<=i-1){
            if(!visited[i-1][j]){
                if(home[i-1][j]==1){
                    q.push({i-1, j});
                    visited[i-1][j]=true;
                    village.back()+=1;
                }
            }
        }
    }
}

int main(){
    cin>>n;
    vector<vector<int>> home(n);
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        for(char c : s){
            home[i].push_back(c-'0');
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(home[i][j]==0) continue;//집이 아니면 넘어가기
            else{
                //확인했던 집이면 넘어가기
                if(visited[i][j]) continue;
                else{//확인 안한집일경우
                    village.push_back(0);//마을 하나 추가
                    bfs(i, j, home, visited);
                }
            }
        }
    }
    cout<<village.size()<<"\n";
    for(auto i : village){
        cout<<i<<"\n";
    }
    
    
}