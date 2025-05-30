#include <bits/stdc++.h>
#define FastIO\
    ios_base::sync_with_stdio(false);\
    cin.tie(NULL);\
    cout.tie(NULL);
    using namespace std;
    
int n,m;//세로칸수, 가로칸수
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int bfs(int i, int j, const vector<vector<int>> &maze, vector<vector<bool>> &visited)
{
    int cnt = 1;
    queue<pair<int, int>> q;
    q.push({i, j});
    visited[i][j] = true;
    while (!q.empty())
    {
        int size = q.size();
        cnt++;

        for (int k = 0; k < size; k++)
        {
            pair<int, int> start = q.front();
            q.pop();
            for (int l = 0; l < 4; l++)
            {
                int x = start.second + dx[l];
                int y = start.first + dy[l];
                if (y == n - 1 && x == m - 1)
                    return cnt;
                if (x >= 0 && x <= m - 1 && y >= 0 && y <= n - 1)
                {
                    if (visited[y][x])
                        continue;
                    else
                    {
                        if (maze[y][x] == 1)
                        {
                            q.push({y, x});
                            visited[y][x] = true;
                        }
                    }
                }
            }
        }
    }
    return cnt;
}

int main(){
    FastIO;
    cin>>n>>m;
    vector<vector<int>> maze(n, vector<int>(m,0));
    for(int i=0; i<n; i++){
        string row;
        cin>>row;
        for(int j=0; j<m; j++){
            maze[i][j]=row[j]-'0';
        }
        
    }
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    cout<<bfs(0,0, maze, visited);

    return 0;
}