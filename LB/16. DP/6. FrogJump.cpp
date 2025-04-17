#include<bits/stdc++.h>

using namespace std;

int frogJumpBottomUp(vector<int>&height){
    int n = height.size();
    vector<int> dp(n+1, 0);
    dp[n] = 0;

    for(int i=n-1;i>0;i--){
        int oneStep = abs(height[i-1]-height[i]) + dp[i+1];
        int twoStep = INT_MAX;
        if(i+2<height.size())
            twoStep = abs(height[i-1]-height[i+1]) + dp[i+2];
        dp[i] = min(oneStep, twoStep);
    }
    cout<<"DP ARR: ";
    for(auto i: dp){
        cout<<i<<" ";
    }
    cout<<endl;
    return dp[1];
}

int frogJumpTopDownHelper(vector<int>&height, int i, vector<int>&dp){
    if(i>=height.size()-1){
        return 0;
    }
    if(dp[i] != -1){
        return dp[i];
    }

    int oneStep = abs(height[i]-height[i+1]) + frogJumpTopDownHelper(height, i+1, dp);
    int twoStep = INT_MAX;
    if(i+2<height.size())
    twoStep = abs(height[i]-height[i+2]) + frogJumpTopDownHelper(height, i+2, dp);

    dp[i] = min(oneStep, twoStep);

    return dp[i];
}


int frogJumpTopDown(vector<int>&height){
    int n = height.size();
    vector<int> dp(n+1, -1);
    return frogJumpTopDownHelper(height,0, dp);
}

int frogJumpHelper(vector<int>&height, int i){
    if(i>=height.size()-1){
        return 0;
    }

    int oneStep = abs(height[i]-height[i+1]) + frogJumpHelper(height, i+1);
    int twoStep = INT_MAX;
    if(i+2<height.size())
    twoStep = abs(height[i]-height[i+2]) + frogJumpHelper(height, i+2);

    return min(oneStep, twoStep);
}


int frogJump(vector<int>&height){
    int ans = INT_MAX;
    ans = frogJumpHelper(height,0);
    return ans;
}

int main(){
    vector<int> heights = {2,1,3,5,4};
    cout<<"ANS: "<<frogJumpBottomUp(heights);
    return 0;
}