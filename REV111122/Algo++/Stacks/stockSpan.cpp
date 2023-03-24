#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>stock(n);
    for(auto &i:stock){
        cin>>i;
    }
    // 100 80 60 70 60 75 85
    stack<pair<int,int>> span;
    vector<int> ans(n); 
    span.push({0,stock[0]});
    ans[0] = 0;

    for(int i=1;i<n;i++){
        while(!span.empty() && span.top().second <= stock[i]){
            span.pop();
        }
        ans[i] = abs(span.top().first-i); 
        span.push({i,stock[i]});
    }

    for(auto i: ans){
        cout<<i<<" ";
    }

    return 0;
}