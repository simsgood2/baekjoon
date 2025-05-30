#include <bits/stdc++.h>
#define FastIO\
    ios_base::sync_with_stdio(false);\
    cin.tie(NULL);\
    cout.tie(NULL);
using namespace std;

int main(){
    FastIO;
    int n,m;
    cin>>n>>m;//n:사다리, m:뱀
    map<int,int> adj;
    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        adj[x]=y;//x에서 y로
    }
    for(int i=0; i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u]=v;
    }
    queue<int> q;
    vector<bool> visited(101, false);
    q.push(1);
    visited[1]=true;
    int cnt=0;
    int dx[6]={1,2,3,4,5,6};
    while(!q.empty()){
        int size=q.size();
        queue<int> qq(q);
        // for(int i=0; i<size; i++){
        //     cout<<qq.front()<<" ";
        //     qq.pop();
        // }
        // cout<<"\n";
        for(int i=0; i<size; i++){
            int now = q.front();
            if(now==100){
                cout<<cnt;
                return 0;
            }
            q.pop();
            for(int j=0;j<6; j++){
                int next = now+dx[j];
                if(next>100) continue;

                if(adj.find(next)!=adj.end()){//사다리
                    if(!visited[adj[next]]){
                        q.push(adj[next]);
                        visited[adj[next]]=true;
                        visited[next]=true;
                    }
                }
                else if(!visited[next]){
                    q.push(next);
                    visited[next]=true;
                }
                
            }
        }
        cnt++;
    }

}