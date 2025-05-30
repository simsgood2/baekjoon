#include <bits/stdc++.h>
#define FastIO\
    ios_base::sync_with_stdio(false);\
    cin.tie(NULL);\
    cout.tie(NULL);
using namespace std;

int date[367];

int main(){
    FastIO;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int start, end;
        cin>>start>>end;
        for(int j=start; j<=end; j++){
            date[j]++;
        }
    }
    int area = 0;
    int height=0;
    int row=0;
    for(int i=1; i<=366; i++){
        if(date[i]==0){
            area += row*height;
            row=0;
            height=0;
            continue;
        }

        if(date[i]!=0){
            row++;
            height=max(date[i], height);
        }
    }

    cout<<area;
}
