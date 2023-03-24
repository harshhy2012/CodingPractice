#include<bits/stdc++.h>

using namespace std;

int minDiff(int n, int m, vector<int> arr){
    
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> arr(m);
    for(auto &i: arr){
        cin>>i;
    }

    cout<<minDiff(n,m,arr)<<endl;

    return 0;
}