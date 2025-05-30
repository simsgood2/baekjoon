#include <bits/stdc++.h>
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
    using namespace std;
    
int n,m;

int bacon(int i, const vector<vector<int>>& adj){
    vector<int> visited(n+1, -1);
    queue<int> q;
    q.push(i);
    visited[i]=0;
    int cnt=1;
    while(!q.empty()){
        int size = q.size();
        for(int j=0; j<size; j++){
            int start = q.front();
            q.pop();
            for(int k : adj[start]){
                if(visited[k]==-1){
                    q.push(k);
                    visited[k]=cnt;
                }
            }
        }
        cnt++;
    }
    int result=0;
    for(int k=1; k<=n; k++){
        if(k==i) continue;
        result+=visited[k];
    }
    return result;
}


int main(){
    FastIO;
    cin>>n>>m;//n:사람수, m:관계수
    vector<int> baecon(n+1);
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1; i<=n;i++){
        baecon[i]=bacon(i, adj);//i:시작
    }
    
    int min=(1LL<<31)-1;
    int min_num=0;
    for(int i=1; i<=n; i++){
        if(baecon[i]<min){
            min=baecon[i];
            min_num=i;
        }
    }
    cout<<min_num;
    return 0;
    
}