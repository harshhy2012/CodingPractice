#include<bits/stdc++.h>

using namespace std;

bool canDistributeHelper(vector<int>&quantity, vector<int>&counts, int ithCust){
    if(ithCust == quantity.size()){
        return true;
    }
    for(int i=0;i<counts.size();i++){
        if(counts[i]>=quantity[ithCust]){
            counts[i]-=quantity[ithCust];
            if(canDistributeHelper(quantity, counts, i+1)){
                return true;
            }
            counts[i]+=quantity[ithCust];
        }
    }
    return false;
}

bool canDistribute(vector<int>& nums, vector<int>& quantity) {
    unordered_map<int, int> invFreq;
    for(auto num: nums){
        invFreq[num]++;
    }
    vector<int> counts;
    for(auto i: invFreq){
        counts.push_back(i.second);
    }
    sort(quantity.begin(), quantity.end());
    return canDistributeHelper(quantity, counts, 0);
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> nums(n), qauntity(m);
    for(auto &i: nums){
        cin>>i;
    }
    for(auto &i: qauntity){
        cin>>i;
    }



    return 0;
} 