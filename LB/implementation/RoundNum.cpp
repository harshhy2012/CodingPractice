#include<bits/stdc++.h>

using namespace std;

pair<int, vector<int>> RoundNums(int n){
    int nums = 0;
    vector<int> ans;
    int powOfTen = 1;
    while(n){
        int dig = n%10;
        if(dig!=0){
            ans.push_back(dig*powOfTen);
            nums++;
        }
        powOfTen*=10;
        n/=10;
    }

    return {nums, ans};
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        pair<int, vector<int>> roundNums = RoundNums(n);

        cout<<roundNums.first<<endl;
        for(auto i: roundNums.second){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}