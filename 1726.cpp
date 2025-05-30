#include <bits/stdc++.h>
using namespace std;

int main(){
    int m,n;//세로칸수, 가로칸수
    cin>>m>>n;
    vector<vector<int>> board(m, vector<int>(n));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>board[i][j];
        }
    }
    int y,x,f;
    cin>>y>>x>>f;
    y--,x--;
    int yy,xx,ff;
    cin>>yy>>xx>>ff;
    yy--,xx--;
    vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(5, false)));//좌표,방향
    queue<pair<int,pair<int,int>>> q;//바라보는 방향, 좌표
    q.push({f, {y,x}});
    visited[y][x][f]=true;
    int cnt=0;
    int d[5] = {0,0,1,2,3};
    while(!q.empty()){
        int size = q.size();

        for(int i=0; i<size; i++){
            pair<int,pair<int,int>> start = q.front();//방향, 좌표
            q.pop();
            if(start.first==ff&&start.second.first==yy&&start.second.second==xx){
                cout<<cnt;
                return 0;
            }
            
            for(int j=0; j<5; j++){
                int faceNow = start.first;
                int nx = start.second.second;
                int ny = start.second.first;
                if(j==0){//좌로 돌기
                    if(faceNow==1)faceNow=4;
                    else if(faceNow==2)faceNow=3;
                    else if(faceNow==3)faceNow=1;
                    else if(faceNow==4)faceNow=2;
                }
                else if(j==1){//우로 돌기
                    if(faceNow==1)faceNow=3;
                    else if(faceNow==2)faceNow=4;
                    else if(faceNow==3)faceNow=2;
                    else if(faceNow==4)faceNow=1;
                }
                else{
                    if(faceNow==1){
                        if(j==4||j==3){
                            if(j==3){
                                if(nx+1>=n) break;
                                if(board[ny][nx+1]==1)break;
                            }
                            if(j==4){
                                if(nx+2>=n)break;
                                if(board[ny][nx+2]==1)break;
                            }
                        }
                        nx+=d[j];
                    }
                    else if(faceNow==2){
                        if(j==4||j==3){
                            if(j==3){
                                if(nx-1<0) break;
                                if(board[ny][nx-1]==1)break;
                            }
                            if(j==4){
                                if(nx-2<0)break;
                                if(board[ny][nx-2]==1)break;
                            }
                        }
                        nx-=d[j];
                    }
                    else if(faceNow==3){
                        if(j==4||j==3){
                            if(j==3){
                                if(ny+1>=m) break;
                                if(board[ny+1][nx]==1)break;
                            }
                            if(j==4){
                                if(ny+2>=m)break;
                                if(board[ny+2][nx]==1)break;
                            }
                        }
                        ny+=d[j];
                    }
                    else if (faceNow==4){
                        if(j==4||j==3){
                            if(j==3){
                                if(ny-1<0) break;
                                if(board[ny-1][nx]==1)break;
                            }
                            if(j==4){
                                if(ny-2<0)break;
                                if(board[ny-2][nx]==1)break;
                            }
                        }
                        ny-=d[j];
                    }
                    
                }
                if(nx<0||ny<0||ny>=m||nx>=n){
                    continue;
                }
                if(!visited[ny][nx][faceNow]){
                    if(board[ny][nx]==0){
                        q.push({faceNow,{ny,nx}});
                    }
                    visited[ny][nx][faceNow]=true;
                }
            }
        }
        cnt++;

    }
}