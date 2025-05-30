#include <bits/stdc++.h>
#define FastIO\
    ios_base::sync_with_stdio(false);\
    cin.tie(NULL);\
    cout.tie(NULL);
using namespace std;

int main(){
    FastIO;
    int m,n,h;
    cin>>m>>n>>h;//가로칸, 세로칸, 높이
    vector<vector<vector<int>>> tomato(h, vector<vector<int>>(n, vector<int>(m)));
    queue<vector<int>> full;
    for(int i=0; i<h; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                cin>>tomato[i][j][k];
                if(tomato[i][j][k]==1){
                    full.push({i, j, k});
                }
            }
        }
    }
    int days =0;

    int dx[6] = {1, 0, -1, 0, 0, 0};
    int dy[6] = {0, -1, 0, 1, 0, 0};
    int dz[6] = {0, 0, 0, 0, 1, -1};

    while(!full.empty()){
        int size = full.size();
        for(int t=0; t<size; t++){
            int z = full.front()[0];
            int y = full.front()[1];
            int x = full.front()[2];
            full.pop();
            for(int i=0; i<6; i++){
                int newX = x+dx[i];
                int newY = y+dy[i];
                int newZ = z+dz[i];
                if(newX>=0&&newX<=m-1&&newY>=0&&newY<=n-1&&newZ>=0&&newZ<=h-1){//범위안에 들어가면
                    if(tomato[newZ][newY][newX]==1||tomato[newZ][newY][newX]==-1){//이미 익었거나 토마토가 없으면
                        continue;
                    }
                    else{
                        tomato[newZ][newY][newX]=1;
                        full.push({newZ,newY,newX});
                    }
                }
            }
        }
        if(!full.empty()){
            days++;
        }
    }
    for(int i=0; i<h; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                if(tomato[i][j][k]==0){
                    cout<<-1;
                    return 0;
                }
            }
        }
    }
    cout<<days;


}