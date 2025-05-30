#include <bits/stdc++.h>
#define FastIO\
    ios_base::sync_with_stdio(false);\
    cin.tie(NULL);\
    cout.tie(NULL);
using namespace std;

int white=0, blue=0;

bool check_paper(int x1, int x2, int y1, int y2, const vector<vector<int>>& color){
    int first_color=color[y1][x1];
    for(int i=y1; i<=y2; i++){
        for(int j=x1; j<=x2; j++){
            if(color[i][j]!=first_color){
                return false;
            }
        }
    }
    return true;
}

void split_square(int x1, int x2, int y1, int y2, const vector<vector<int>>& color){//검사 영역
    if(check_paper(x1, x2, y1, y2, color)){//다 같은 색이면
        color[y1][x1] == 0 ? white++ : blue++;
    }
    else{
        split_square(x1, (x2+x1)/2, y1, (y2+y1)/2, color);
        split_square((x2+x1)/2+1, x2, y1, (y2+y1)/2, color);
        split_square(x1, (x2+x1)/2, (y2+y1)/2+1, y2, color);
        split_square((x2+x1)/2+1, x2, (y2+y1)/2+1,y2, color);
    }
    return;
}

int main(){
    FastIO;
    int n;
    cin>>n;
    vector<vector<int>> color(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>color[i][j];
        }
    }
    split_square(0, n-1, 0, n-1, color);

    cout<<white<<"\n"<<blue;

    return 0;
}