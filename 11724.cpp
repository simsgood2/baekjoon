#include <bits/stdc++.h>
#define FastIO\
    ios_base::sync_with_stdio(false);\
    cin.tie(NULL);\
    cout.tie(NULL);
using namespace std;

int main(){
    FastIO;
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    int cnt=0;
    queue<int> q;
    vector<bool> visited(n,false);
    for(int i=0; i<n; i++){
        if(visited[i]){
            continue;
        }
        else{
            q.push(i);
            visited[i] = true;
            cnt++;
            while(!q.empty()){
                int start = q.front();
                q.pop();
                for(auto i : adj[start]){
                    if(visited[i]){
                        continue;
                    }
                    else{
                        q.push(i);
                        visited[i]=true;
                    }
                }
            }
        }
    }
    cout<<cnt;
}