#include <bits/stdc++.h>
#define FastIO\
    ios_base::sync_with_stdio(false);\
    cin.tie(NULL);\
    cout.tie(NULL);
using namespace std;
using ll = long long;

int main(){
    FastIO;
    int T;
    cin>>T;
    int dx[8]={1,2,2,1,-1,-2,-2,-1};
    int dy[8]={2,1,-1,-2,-2,-1,1,2};
    for(int t=0; t<T; t++){
        int n;
        cin>>n;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        int startx, starty,endx,endy;
        cin>>starty>>startx>>endy>>endx;
        if(startx==endx&&starty==endy){
            cout<<0<<"\n";
            continue;
        }
        queue<pair<int,int>> q;
        q.push({starty, startx});
        visited[starty][startx]=true;
        int cnt=0;
        while(!q.empty()){
            int size = q.size();
            cnt++;
            for(int i=0; i<size; i++){
                pair<int,int> start = q.front();
                q.pop();
                for(int j=0; j<8; j++){
                    int nx = start.second+dx[j];
                    int ny = start.first+dy[j];
                    if(nx==endx&&ny==endy) {
                        cout<<cnt<<"\n";
                        while(!q.empty()){
                            q.pop();
                        }
                        i=size;
                        break;
                    }
    
                    if(nx<0||ny<0||nx>=n||ny>=n){
                        continue;
                    }
                    else{
                        if(!visited[ny][nx]){
                            q.push({ny,nx});
                            visited[ny][nx]=true;
                        }
                    }
                }
            }


        }
    }
    
}