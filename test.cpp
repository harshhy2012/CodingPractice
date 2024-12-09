#include<bits/stdc++.h>

using namespace std;

void combinationSumHelper(int idx, int k, int target, vector<int> &sol, vector<vector<int>> &ans){

    if(target == 0 && sol.size() == k){
        ans.push_back(sol);
        return;
    }
    if(target<0 || sol.size() > k){
        return;
    }
    for(int i=idx;i<=9;i++){
        if(i<=target){
            sol.push_back(i);
            combinationSumHelper(i+1, k, target-i, sol, ans);
            sol.pop_back();    
        } else{
            break;
        }
    }
}



vector<vector<int> > combinationSum3(int k, int n) {
    vector<vector<int>> ans; 
    //your code goes here
    vector<int> sol;

    combinationSumHelper(1, k, n, sol, ans);
    return ans;
    
}

int main(){
    int k;
    cin>>k;
    int n;
    cin>>n;
    
    vector<vector<int>> ans = combinationSum3(k, n);

    for(auto sub: ans){
        for(auto i: sub){
            cout<<i<<" ";
        }
        cout<<endl;
    }

    return 0;
}