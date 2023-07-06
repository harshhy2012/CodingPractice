#include<bits/stdc++.h>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> map;
    int n = nums.size();
    for(int i=0;i<n;i++){
        map[nums[i]] = i;
    }

    for(int i=0;i<n;i++){
        int comp = target-nums[i];
        if(map.count(comp) && map[comp]!=i){
            return{i,map[comp]};
        }
    }
    return {};
}

vector<int> twoSumSinglePass(vector<int>&nums, int target){
    unordered_map<int, int> numsMap;
    int n = nums.size();
    for(int i=0;i<n;i++){
        int comp = target-nums[i];
        if(numsMap.count(comp)){
            return {numsMap[comp], i};
        }
        else{
            numsMap[nums[i]] = i;
        }
    }
    return {};
}


int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr){
        cin>>i;
    }
    int target;
    cin>>target;
    vector<int> ans1 = twoSum(arr, target);
    vector<int> ans2 = twoSumSinglePass(arr, target);
    cout<<"ANS1: { ";
    for(auto i: ans1){
        cout<<i<<" ";
    }
    cout<<"}\n";

    cout<<"ANS2: { ";
    for(auto i: ans2){
        cout<<i<<" ";
    }
    cout<<"}\n";
    

    return 0;
}