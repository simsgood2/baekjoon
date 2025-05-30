#include <bits/stdc++.h>
#define FastIO\
    ios_base::sync_with_stdio(false);\
    cin.tie(NULL);\
    cout.tie(NULL);
using namespace std;

int main(){
    FastIO;
    int n,m,k;//세로칸, 가로칸, 시간
    cin>>n>>m>>k;
    vector<vector<int>> maze(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>maze[i][j];//0은 갈수있고, 1은 벽이고, 2는 검
        }
    }
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int dx[4]={1,0,-1,0};
    int dy[4]={0,-1,0,1};

    queue<pair<int,int>> q;
    q.push({0,0});
    visited[0][0]=true;
    int time=0;
    int findTime=-1;
    int useSwordTime=-1;
    while(!q.empty()){
        int size = q.size();
        time++;
        for(int i=0; i<size; i++){
            pair<int,int> start = q.front();
            q.pop();
            for(int j=0; j<4; j++){
                int nx = start.second + dx[j];
                int ny = start.first + dy[j];
                
                if(nx<0||ny<0||nx>=m||ny>=n){
                    continue;
                }
                else{
                    if(!visited[ny][nx]){
                        if(nx==m-1&&ny==n-1){//직접 만났을때
                            if(time<=k){
                                findTime=time;
                            }
                        }
                        if(maze[ny][nx]==0||maze[ny][nx]==2){//길 또는 검이면
                            q.push({ny,nx});
                            if(maze[ny][nx]==2){
                                if(time + n-1-ny + m-1-nx<=k){
                                    useSwordTime = time + n-1-ny + m-1-nx;
                                }
                            }
                        }
                        visited[ny][nx]=true;
                    }
                }
            }
        }
    }
    if(findTime!=-1&&useSwordTime!=-1){
        cout<<min(findTime, useSwordTime);
    }
    else if(findTime!=-1&&useSwordTime==-1){
        cout<<findTime;
    }
    else if(findTime==-1&&useSwordTime!=-1){
        cout<<useSwordTime;
    }
    else{
        cout<<"Fail";
    }
    return 0;
}