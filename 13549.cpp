    #include <bits/stdc++.h>
#define FastIO\
    ios_base::sync_with_stdio(false);\
    cin.tie(NULL);\
    cout.tie(NULL);
using namespace std;
#define INF ((1LL<<31)-1)
#define PQ priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>>

int dx[2]={ 1, -1};

void process_current(PQ& pq, vector<int>& dist, int now, int cost){
    int next = now*2;
    if(next<=100000&&cost<dist[next]){
        dist[next]=cost;
        pq.push({cost, next});
    }
    int next_cost = cost+1;
    for(int i=0; i<2; i++){
        next = now+ dx[i];
        if(next<0||next>100000){
            continue;
        }
        if(next_cost<dist[next]){
            dist[next]=next_cost;
            pq.push({next_cost, next});
        }
    }
}

void find_k(int n, int k){
    PQ pq;// (걸리는초, 좌표)
    vector<int> dist(100003, INF);
    dist[n]=0;
    pq.push({0, n});//초 좌표
    
    while(!pq.empty()){
        auto [cost, now] = pq.top();
        pq.pop();

        if(now==k){
            cout<<cost;
            return;
        }

        //더 빠른 길이있었으면
        if(dist[now]<cost ) continue;

        process_current(pq, dist, now, cost);
    }
    return;
}

int main(){
    FastIO;
    int n,k;//n: 현재점, k: 가야하는점
    cin>>n>>k;
    find_k(n,k);
}