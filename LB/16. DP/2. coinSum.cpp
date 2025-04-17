#include<bits/stdc++.h>

using namespace std;

int numOfCoinsRec(vector<int>&coins, int amount){
    if(amount < 0){
        return -1;
    }
    if(amount == 0){
        return 0;
    }
    int finAns = INT_MAX;
    for(int i=0;i<coins.size();i++){
        int ans = numOfCoinsRec(coins, amount-coins[i]);
        if(ans!=-1)
            finAns = min(1+ans, finAns);
    }
    if(finAns == INT_MAX)
        return -1;
    else
        return finAns;
}

int numOfCoinsDPBottomUp(vector<int>&coins, int amount){
    if(amount<0) return -1;
    vector<int>dp(amount+1, INT_MAX);
    dp[0] = 0;
    
    for(int target=1;target<=amount;target++){
        for(int j=0;j <coins.size();j++){
            if(target-coins[j]>=0){
                int ans = dp[target-coins[j]];
                if(ans!= INT_MAX){
                    dp[target] = min(dp[target], 1+ans);
                }
            }
        }
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int numOfCoinsDPTopDownHelper(vector<int>&coins, int amount, vector<int>&dp){
    if(amount < 0){
        return INT_MAX;
    }
    
    if(dp[amount] != -1){
        return dp[amount];
    } 
    
    int minAns = INT_MAX;
    for(int i=0;i<coins.size();i++){
        int ans = numOfCoinsDPTopDownHelper(coins, amount-coins[i], dp);
        if(ans!=INT_MAX)
            minAns = min(minAns, 1+ans);
    }
    dp[amount] = minAns;
    return dp[amount];
}

int numOfCoinsDPTopDown(vector<int>&coins, int amount){
    if(amount<0) return -1;
    vector<int> dp(amount+1, -1);
    dp[0] = 0;
    int result = numOfCoinsDPTopDownHelper(coins, amount, dp);
    return (result == INT_MAX) ? -1 : result;
}

int main(){
    int n;
    cin>>n;
    vector<int> coins(n);
    for(auto &coin: coins){
        cin>>coin;
    }
    int amount;
    cin>>amount;

    cout<<"ANS: "<<numOfCoinsDPBottomUp(coins, amount)<<endl;

    return 0;
}