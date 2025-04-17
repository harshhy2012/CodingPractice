#include<bits/stdc++.h>

using namespace std;

int numOfWaysRec(int n, int k){
    if(n==1){
        return k;
    }
    if(n==2){
        return k*k;
    }
    int pt1 = numOfWaysRec(n-1, k)*(k-1);
    int pt2 = numOfWaysRec(n-2, k)*(k-1);
    return pt1+pt2;
}

int numOfWaysTopDownHelper(int n, int k, vector<int>&dp){
    if(n==1||n==2){
        return dp[n];
    }
    if(dp[n]!=-1){
        return dp[n];
    }

    dp[n] = (numOfWaysTopDownHelper(n-1, k, dp) + numOfWaysTopDownHelper(n-2, k, dp))*(k-1);  
    return dp[n];
}

int numOfWaysBottomUp(int n, int k){
    vector<int>dp(n+1, 0);
    dp[1] = k;
    dp[2] = k*k;
    for(int i=3;i<=n;i++){
        dp[i] = (dp[i-1] + dp[i-2])*(k-1); 
    }
    return dp[n];
}

int numofWaysBottomUpSO(int n, int k){
    if (n == 1) return k;
    if (n == 2) return k*k;
    
    int prev1 = k;
    int prev2 = k*k;

    for(int i=3;i<=n;i++){
        int curr = (prev1+prev2)*(k-1);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int numOfWaysTopDown(int n, int k){
    vector<int> dp(n+1, -1);
    dp[0] = 0;
    dp[1] = k;
    dp[2] = k*k;

    return numOfWaysTopDownHelper(n, k, dp);
}

int main(){
    int n, k;
    cin>>n>>k;
    cout<<"ANS: "<<numofWaysBottomUpSO(n,k)<<endl;
    return 0;
}