#include<bits/stdc++.h>

using namespace std;

int robBottomUp(vector<int>&nums){
    int n = nums.size();
    if(n==0) return 0;
    if(n==1) return nums[0];

    vector<int> dp(n+1, 0);

    dp[n] = 0;
    dp[n-1] = nums[n-1];

    for(int i=n-2;i>=0;i--){
        dp[i] = max(nums[i] + dp[i+2], dp[i+1]);
    }
    return dp[0];

}

int robBottomUpSpaceOptimized(vector<int>&nums){
    int n = nums.size();
    if(n==0) return 0;
    if(n==1) return nums[0];

    int curr = 0, prev1 = nums[n-1], prev2 = 0;    
    // dp[n] = 0;
    // dp[n-1] = nums[n-1];

    for(int i=n-2;i>=0;i--){
        curr = max(nums[i] + prev2, prev1);
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;

}


int robTopDownHelper(vector<int>&homes, int i, vector<int>&dp){
    if(i >= homes.size()){
        return 0;
    }
    if(dp[i] != -1) return dp[i];

    int inc = homes[i] + robTopDownHelper(homes, i+2, dp);
    int exc = robTopDownHelper(homes, i+1, dp);
    dp[i] = max(inc, exc);
    return dp[i];
}

int robTopDown(vector<int>&homes){
    int n = homes.size();
    vector<int> dp(n+1, -1);
    return robTopDownHelper(homes, 0, dp);
}

int robRecHelper(vector<int>&homes, int i, int amount){
    if(i>=homes.size()){
        return amount;
    }
    int inc = robRecHelper(homes, i+2, amount+homes[i]);
    int exc = robRecHelper(homes, i+1, amount);
    return max(inc, exc);
}

int robRec(vector<int>&nums){
    int i = 0, amount = 0;
    return robRecHelper(nums, i, amount);
}

int main(){
    int n;
    cin>>n;
    vector<int> homes(n);
    for(auto &home: homes){
        cin>>home;
    }

    cout<<"ANS: "<<robTopDown(homes)<<endl;

    return 0;
}