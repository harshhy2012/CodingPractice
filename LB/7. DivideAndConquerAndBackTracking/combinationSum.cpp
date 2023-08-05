#include<bits/stdc++.h>

using namespace std;


void combinationSumHelper(vector<int>&candidates, int target, vector<int> &ans, vector<vector<int>> &finAns, int index){
    if(target==0){
        finAns.push_back(ans);
        return;
    }
    if(target<0){
        return;
    }
    for(int i = index; i<candidates.size();i++){
        ans.push_back(candidates[i]);
        combinationSumHelper(candidates, target-candidates[i], ans, finAns, i);
        ans.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> finAns;
    vector<int> ans;
    combinationSumHelper(candidates, target, ans, finAns, 0);
    return finAns;
}

int main(){
    int n;
    cin>>n;
    vector<int> candidates(n);
    for(auto &i: candidates){
        cin>>i;
    }
    int target;
    cin>>target;
     
    vector<vector<int>> ans = combinationSum(candidates, target);

    for(auto comb: ans){
        for(auto i: comb){
            cout<<i<<" ";
        }
        cout<<endl;
    }

    return 0;
}