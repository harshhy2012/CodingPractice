#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> passangers(n);
    for(auto &i: passangers){
        cin>>i.first>>i.second;
    }

    int ans = 0, finalAns = INT_MIN;
    ans = passangers[0].second - passangers[0].first;
    finalAns = ans;
    for(int i = 1;i<n;i++){
        ans = ans + passangers[i].second - passangers[i].first;
        finalAns = max(ans, finalAns);
    }

    cout<<finalAns<<endl;

    return 0;   
}