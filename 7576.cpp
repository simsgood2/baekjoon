#include <bits/stdc++.h>
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;

int main()
{
    FastIO;

    int n, m; // m:가로칸수, n:세로칸수
    cin >> m >> n;
    vector<vector<int>> tomato(n, vector<int>(m)); // n개의 행이 m개의열로 0으로 초기화됨
    queue<pair<int, int>> full;
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            cin >> tomato[y][x];
            if (tomato[y][x] == 1)
            {
                full.push({y, x});
            }
        }
    }
    full.push({-1, -1}); // 플래그
    int days = 0;

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};
    while (!full.empty())
    {
        if (full.front() == make_pair(-1, -1))
        { // 플래그에 도달하면
            full.pop();
            full.push({-1, -1});
            // cout<<"days: "<<days<<"\n";
            // for(int i=0; i<n; i++){
            //     for(int j=0; j<m; j++){
            //         cout<<tomato[i][j]<<" ";
            //     }
            //     cout<<"\n";
            // }
            // cout<<"\n";

            if (full.front() == make_pair(-1, -1))
            { // 플래그가 연속되면 더이상 익을게 없는걸로
                break;
            }
            days += 1;
        }
        pair<int, int> start = full.front();
        full.pop();
        int x, y;
        for (int i = 0; i < 4; i++)
        {
            x = start.second + dx[i];
            y = start.first + dy[i];
            if (x <= m - 1 && y <= n - 1 && 0 <= x && 0 <= y)
            { // 상자 범위 안에 있으면
                if (tomato[y][x] == -1 || tomato[y][x] == 1)
                { // 들어있지 않거나 이미 익었으면 넘어가기
                    continue;
                }
                else
                { // 안익은 토마토 자리면
                    full.push({y, x});
                    tomato[y][x] = 1;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (tomato[i][j] == 0)
            {
                cout << -1;
                return 0;
            }
        }
    }
    cout << days;
}