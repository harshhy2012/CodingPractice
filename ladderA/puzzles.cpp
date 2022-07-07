#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> puzzles(m);
    for(auto &i: puzzles){
        cin>>i;
    }

    sort(puzzles.begin(), puzzles.end());
    
    int minGap = puzzles[n-1] - puzzles[0];
    for(int i=1;i<m-n+1;++i){
        if(puzzles[i+n-1]-puzzles[i] < minGap){
            minGap = puzzles[i+n-1] - puzzles[i];
        }
         //cout<<"start: "<<puzzles[i]<<", end: "<<puzzles[i+n-1]<<endl;
    }
    cout<<minGap<<endl;
    return 0;
}