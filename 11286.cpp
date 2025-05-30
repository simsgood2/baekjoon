#include <bits/stdc++.h>
#define FastIO\
    ios_base::sync_with_stdio(false);\
    cin.tie(NULL);\
    cout.tie(NULL);
using namespace std;

int main(){
    FastIO;
    int n;
    cin>>n;
    priority_queue<int, vector<int>, greater<int>> pq;//양수 오름차순
    priority_queue<int> pq2;//음수 내림차순
    vector<int> vec;
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        if(temp==0){
            if(pq.empty()&&pq2.empty()){
                vec.push_back(0);
            }
            else{
                if(pq.empty()){
                    vec.push_back(pq2.top());
                    pq2.pop();
                }
                else if(pq2.empty()){
                    vec.push_back(pq.top());
                    pq.pop();
                }
                else if(pq.top()>=abs(pq2.top())){
                    vec.push_back(pq2.top());
                    pq2.pop();
                }
                else{
                    vec.push_back(pq.top());
                    pq.pop();
                }
            }
        }
        else if(temp>0){
            pq.push(temp);
        }
        else{
            pq2.push(temp);
        }
    }
    for(auto i : vec){
        cout<<i<<"\n";
    }
    
}