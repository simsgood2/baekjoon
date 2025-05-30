#include <bits/stdc++.h>
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;

int main(void){
    FastIO;
    int T;
    cin>>T;
    for(int t=0; t<T; t++){
        int n, m;
        cin>>n>>m;
        queue<pair<int,int>> q;//프린터
        priority_queue<int> pq;//큰값 찾아주기
        int k;
        for(int i=0; i<n; i++){
        cin>>k;
            q.push(make_pair(k,i));
            pq.push(k);
        }
        int cnt=0;
        while(1){//m번째가 나올때까지
            if(q.front().second == m && q.front().first==pq.top()){
                cout<<cnt+1<<'\n';
                break;
            }

            if(pq.top()==q.front().first){//뽑아야함
                q.pop();
                pq.pop();
                cnt++;
            }
            else{//뒤로 보내야함
                pair<int,int> tmp = q.front();
                q.pop();
                q.push(tmp);
            }
        }

    }
}