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
    stack<int> st;
    st.push(0);
    int cnt=0;
    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        if(!st.empty()&&y<st.top()){ 
            while(!st.empty()&&y<st.top()){
                st.pop();
                cnt++;
            }
            
            
        }
        if(y>st.top()){
            st.push(y);
        }
    }
    while(!st.empty()&&st.top()>0){
        st.pop();
        cnt++;
    }
    cout<<cnt;

}