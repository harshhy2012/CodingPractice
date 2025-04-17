#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int e;
    cin>>e;
    int u,v;
    vector<vector<int>> adjMat(n, vector<int>(n));
    for(int i=0;i<e;i++){
        cin>>u>>v;
        adjMat[u][v] = 1;
    }
    cout<<"   ";
    for(int i=0;i<n;i++){
        cout<<i<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<"-----";
    }
    cout<<endl;
    int x = 0;
    for(auto i: adjMat){
        cout<<x<<": ";
        for(auto j: i){
            cout<<j<<" ";
        }
        x++;
        cout<<endl;
    }

    return 0;
}