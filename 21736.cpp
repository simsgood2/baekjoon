#include <bits/stdc++.h>
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;

int n,m;//n:세로칸수, m:가로칸수
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};

int bfs(int y, int x, const vector<vector<char>>& board){
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int,int>> q;
    q.push({y,x});
    visited[y][x]=true;
    int cnt=0;
    while(!q.empty()){
        pair<int,int> start = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int nx = start.second+dx[i];
            int ny = start.first+dy[i];
            if(nx<0||ny<0||ny>=n||nx>=m) continue;

            if(!visited[ny][nx]){
                if(board[ny][nx]=='O'){
                    q.push({ny,nx});
                }
                else if(board[ny][nx]=='P'){
                    q.push({ny,nx});
                    cnt++;
                }
                visited[ny][nx]=true;
            }
        }
    }
    return cnt;
}

int main(){
    cin>>n>>m;
    vector<vector<char>> board(n, vector<char>(m));
    pair<int,int> start;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        for(int j=0; j<m; j++){
            board[i][j]=s[j];
            if(s[j]=='I'){
                start.first=i;
                start.second=j;
            }
        }
    }
    int cnt = bfs(start.first, start.second, board);
    if(cnt==0){
        cout<<"TT";
    }
    else{
        cout<<cnt;
    }
    return 0;


}