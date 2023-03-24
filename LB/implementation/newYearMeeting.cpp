#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<int> X(3);
    for(auto &x: X){
        cin>>x;
    }
    int mid;
    int greatest = max(X[0],max(X[1],X[2]));
    int lowest = min(X[0],min(X[1],X[2]));
    for(int i=0;i<3;i++){
        if(X[i]!=greatest && X[i]!=lowest){
            mid = X[i];
        }
    }
    int ans = abs(greatest-mid)+abs(mid-lowest);
    cout<<ans<<endl;
    
    return 0;
}