#include <bits/stdc++.h>
#define FastIO\
    ios_base::sync_with_stdio(false);\
    cin.tie(NULL);\
    cout.tie(NULL);
using namespace std;

int n,m;//세로 가로
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};

int bfs(int x, int y, const vector<vector<int>>& board, vector<vector<vector<bool>>>& visited){
    queue<pair<int,pair<int,int>>> q;
    q.push({0,{y,x}});
    visited[0][y][x]=true;
    int cnt=1;
    while(!q.empty()){
        int size = q.size();

        for(int i=0; i<size; i++){
            pair<int,int> start = q.front().second;//좌표
            int use = q.front().first;//횟수 목적이 아니라 어느 분기인지

            if(start.first==n-1&&start.second==m-1){
                return cnt;
            }
            q.pop();
            
            for(int j=0; j<4; j++){
                int nx = start.second+dx[j];
                int ny = start.first+dy[j];
                if(nx<0||ny<0||nx>=m||ny>=n) continue;

                if(!visited[use][ny][nx]){//방문안했으면
                    if(board[ny][nx]==0){
                        if(!visited[0][ny][nx]){//망치안썻을때 방문안했으면
                            q.push({use, {ny,nx}});
                        }
                    }
                    if(board[ny][nx]==1){
                        if(use==0){//망치 사용안했으면
                            q.push({1, {ny,nx}});
                            visited[1][ny][nx]=true;
                        }
                    }
                    visited[use][ny][nx]=true;
                }
            }
        }
        cnt++;
    }
    return -1;
}


int main(){
    FastIO;
    cin>>n>>m;
    vector<vector<int>> board(n, vector<int>(m));
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        for(int j=0; j<m; j++){
            board[i][j]=s[j]-'0';
        }
    }
    
    vector<vector<vector<bool>>> visited(2, vector<vector<bool>>(n, vector<bool>(m,false)));
    int cnt=-1;
    cnt = bfs(0,0,board, visited);
    cout<<cnt;
    return 0;
}