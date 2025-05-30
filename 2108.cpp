#include <bits/stdc++.h>
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;

unordered_map<int,int> um;//최빈값찾기

int main()
{
    FastIO;
    int N, ma=-(1<<31),mi=(1<<31)-1;
    cin>>N;
    double sum=0, avg;
    vector<int> vec;//중앙값찾기
    for(int i=0; i<N; i++){
        int k;
        cin>>k;
        sum+=k;
        vec.push_back(k);
        um[k]+=1;
        if(ma<k)ma=k;
        if(mi>k)mi=k;
    }
    vector<int> maxfreq;
    
    int max_freq=0;
    for(auto i=um.begin(); i!=um.end(); i++){//값,빈도 해시맵을 돌려서 
        if(max_freq<i->second){//더자주나오는값이 있다면
            max_freq=i->second;
            maxfreq.clear();
            maxfreq.push_back(i->first);
        }
        else if(max_freq==i->second){ //빈도가 같은게있으면
            maxfreq.push_back(i->first);
        }
    }
    sort(maxfreq.begin(), maxfreq.end());//오름차순
    sort(vec.begin(),vec.end());
    avg = static_cast<int>(round(sum/N));
    cout<<avg<<"\n"<<vec[N/2]<<'\n';
    if(maxfreq.size()==1){
        cout<<maxfreq.front()<<'\n';
    }
    else{
        cout<<maxfreq[1]<<'\n';
    }
    cout<<ma-mi;

}