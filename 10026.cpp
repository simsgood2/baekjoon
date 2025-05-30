#include <bits/stdc++.h>
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0 ,1};
int n;
char color[101][101];
bool visited[101][101]={false};


void bfs1(int i, int j){
    queue<pair<int,int>> q;
    q.push({i,j});
    visited[i][j]=true;

    while(!q.empty()){
        pair<int,int> start = q.front();
        q.pop();
        for(int t=0; t<4; t++){
            int y = start.first + dy[t];
            int x = start.second + dx[t];
            if(x>=0&& x<=n-1&&y>=0&&y<=n-1){
                if(!visited[y][x]&&(color[y][x]==color[i][j])){
                    q.push({y,x});
                    visited[y][x]=true;
                }
            }
        }
    }
}
void bfs2(int i, int j){
    queue<pair<int,int>> q;
    q.push({i,j});
    visited[i][j]=true;

    while(!q.empty()){
        pair<int,int> start = q.front();
        q.pop();
        for(int t=0; t<4; t++){
            int y = start.first + dy[t];
            int x = start.second + dx[t];
            if(x>=0&& x<=n-1&&y>=0&&y<=n-1){
                if(!visited[y][x]){
                    if(color[y][x]==color[i][j]){
                        q.push({y,x});
                        visited[y][x]=true;
                    }
                    else if((color[i][j]=='R'||color[i][j]=='G')&&(color[y][x]=='R'||color[y][x]=='G')){
                            q.push({y,x});
                            visited[y][x]=true;
                    }
                }
                
            }
        }
    }
}

int main()
{
    FastIO;
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>color[i][j];
        }
    }
    int area1 =0;
    int area2 =0;//색맹

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(visited[i][j]){//방문했었으면 넘어가기
                continue;
            }
            else{
                area1++;//구역 추가
                bfs1(i, j);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            visited[i][j] = false;
        }
    }    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(visited[i][j]){//방문했었으면 넘어가기
                continue;
            }
            else{
                area2++;//구역 추가
                bfs2(i, j);
            }
        }
    }
    
    cout<<area1<<" "<<area2;

}