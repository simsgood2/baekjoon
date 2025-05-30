#include <bits/stdc++.h>
#define FastIO\
    ios_base::sync_with_stdio(false);\
    cin.tie(NULL);\
    cout.tie(NULL);
using namespace std;

// int main(){
//     FastIO;
//     int n;
//     cin>>n;
//     priority_queue<int, vector<int>, greater<int>> num;
//     for(int i=0; i<n; i++){
//         int temp;
//         cin>>temp;
//         if(temp==0){
//             if(num.empty()){
//                 cout<<0<<"\n";
//             }
//             else{
//                 cout<<num.top()<<"\n";
//                 num.pop();
//             }
//         }
//         else if(temp>0){
//             num.push(temp);
//         }
//     }
// }

int main(){
    FastIO;
    int n;
    cin>>n;
    priority_queue<int> num;
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        if(temp==0){
            if(num.empty()){
                cout<<0<<"\n";
            }
            else{
                cout<<num.top()<<"\n";
                num.pop();
            }
        }
        else if(temp>0){
            num.push(temp);
        }
    }
}

