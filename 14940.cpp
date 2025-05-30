#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<vector<int>> board(n, vector<int>(m));
    pair<int,int> start;
    vector<vector<int>> time(n, vector<int>(m,-1));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int,int>> q;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>board[i][j];
            if(board[i][j]==2){
                start={i,j};
                time[i][j]=0;
                q.push({i,j});
                visited[i][j]=true;
            }
            if(board[i][j]==0){
                time[i][j]=0;
            }
        }
    }

    int cnt=0;
    int dx[4]={1,0,-1,0};
    int dy[4]={0,-1,0,1};
    while(!q.empty()){
        int size = q.size();
        cnt++;
        for(int i=0; i<size; i++){
            start=q.front();
            q.pop();
            for(int j=0; j<4; j++){
                int nx = start.second+dx[j];
                int ny = start.first+dy[j];
                if(nx<0||ny<0||nx>=m||ny>=n){
                    continue;
                }
                if(!visited[ny][nx]){
                    if(board[ny][nx]==1){
                        q.push({ny,nx});
                        visited[ny][nx]=true;
                        time[ny][nx]=cnt;
                    }
                    visited[ny][nx]=true;
                }
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<time[i][j]<<" ";
        }
        cout<<"\n";
    }


}