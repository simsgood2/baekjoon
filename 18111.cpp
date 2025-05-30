#include <bits/stdc++.h>
#define FastIO\
    ios_base::sync_with_stdio(false);\
    cin.tie(NULL);\
    cout.tie(NULL);
using namespace std;


int main(){
    FastIO;
    int n,m,b;//세로칸, 가로칸, 가방에 블록수
    cin>>n>>m>>b;

    //높이의 종류
    map<int, int> value;//높이의 개수 저장
    int max_height=-1;
    int min_height=257;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int height;
            cin>>height;
            value[height]++;
            if(height<min_height) min_height=height;
            if(height>max_height) max_height=height;
        }
    }
    int result_time=987654321;
    int result_height=-1;
    for(int i=min_height; i<=max_height; i++){//i는 목표 높이
        int time = 0;
        int bag = b;
        bool ok=true;
        for(auto j = value.rbegin(); j != value.rend(); ++j){//j->first: 현재높이
            if(j->first>i){//현재 높이가 목표보다 높으면
                int need = (j->second)*(j->first-i);//파낼 흙의 수
                bag+=need;
                time+=need*2;
            }
            else if(j->first < i){//현재 높이가 목표보다 낮으면
                if(bag >= j->second*(i-j->first)){//흙이 충분하면
                    bag -= j->second*(i-j->first);
                    time += j->second*(i-j->first);
                }
                else{//흙이 부족하면
                    ok=false;
                }
            }
        }
        if(ok){
            result_time=min(result_time, time);
            if(time==result_time){
                result_height=max(result_height, i);
            }
        }
    }
    cout<<result_time<<" "<<result_height;
    return 0;

}