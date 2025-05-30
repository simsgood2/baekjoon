#include <bits/stdc++.h>
#define FastIO\
    ios_base::sync_with_stdio(false);\
    cin.tie(NULL);\
    cout.tie(NULL);
using namespace std;

int main(){
    FastIO;
    int T;
    cin>>T;

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};

    for(int t=0; t<T; t++){
        int m,n,k;
        cin>>m>>n>>k;
        vector<vector<int>> cabbage(n, vector<int>(m, 0));
        for(int i=0; i<k; i++){
            int x,y;
            cin>>x>>y;
            cabbage[y][x]=1;
        }

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int,int>> q;
        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(visited[i][j]==true) continue;//방문했었다면 넘어가기
                else{
                    if(cabbage[i][j]==0){//새로갔는데 양배추가 없으면 방문처리하고 넘어가기
                        visited[i][j]=true;
                        continue;
                    }
                    else{   
                        q.push({j, i});// {x,y}
                        visited[i][j]=true;
                        cnt++;//새로운 배추단지를 만나면

                        int x,y;
                        while(!q.empty()){
                            pair<int,int> start = q.front();
                            q.pop();
                            for(int l =0; l<4; l++){
                                x = start.first +dx[l];
                                y = start.second +dy[l];
                                if(x <= m-1 && y <= n-1 && 0 <= x && 0 <= y ){//범위안에있고
                                    if(!visited[y][x]){//방문안했던 곳이라면
                                        visited[y][x]=true;
                                        if(cabbage[y][x]==1){//양배추가 있으면
                                            q.push({x,y});
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<cnt<<"\n";
    }
}