#include <bits/stdc++.h>
#define FastIO\
    ios_base::sync_with_stdio(false);\
    cin.tie(NULL);\
    cout.tie(NULL);
using namespace std;

int dj[4] = {1, 0, -1, 0};
int di[4] = {0, -1, 0, 1};
int n, m;//m:가로칸수, n:세로칸수

pair<int,int> spreadLocation(int i, int j, int k){
    int newi = i + di[k];
    int newj = j + dj[k];
    return {newi, newj};
}
bool isInArea(int i, int j){
    if(i>=0&& i<=n-1&&j>=0&&j<=m-1){
        return true;
    }
    return false;
}
void tomatoCtrl(int i, int j, vector<vector<int>>& tomato, deque<pair<int,int>>& full){
    if(tomato[i][j]==1||tomato[i][j]==-1){
        return;
    }
    else{
        full.push_back({i,j});
        tomato[i][j]=1;
    }
    return;
}

int main(){
    FastIO;
    cin>>m>>n;
    vector<vector<int>> tomato(n, vector<int>(m));//n개의 행이 m개의열로 0으로 초기화됨
    deque<pair<int,int>> full;

    for(int y=0; y<n; y++){
        for(int x=0; x<m; x++){
            cin>>tomato[y][x];
            if(tomato[y][x]==1){
                full.push_back({y,x});
            }
        }
    }
    
    int days=0;
    while(!full.empty()){
        int size = full.size();
        for(int i=0; i<size; i++){
            pair<int,int> start = full.front();
            full.pop_front();
        
            for(int j=0; j<4; j++){
                pair<int,int> receive = spreadLocation(start.first, start.second, j);
                if(!isInArea(receive.first, receive.second)){
                    continue;
                }
                tomatoCtrl(receive.first, receive.second, tomato, full);
            }
        }

        if(!full.empty()){
            days++;
        }
        
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(tomato[i][j]==0){
                cout<<-1;
                return 0;
            }
        }
    }
    cout<<days;
}