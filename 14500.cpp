#include <bits/stdc++.h>
#define FastIO\
    ios_base::sync_with_stdio(false);\
    cin.tie(NULL);\
    cout.tie(NULL);
using namespace std;

int main(){
    int n,m;//n:세로, n:가로
    cin>>n>>m;
    vector<vector<int>> board(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>board[i][j];
        }
    }
    
}