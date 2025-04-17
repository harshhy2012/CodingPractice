#include<bits/stdc++.h>

using namespace std;

int fibDPTopDownHelper(int n, vector<int>&dp){
    if(dp[n] != -1){
        return dp[n];
    }

    if(dp[n]==-1){
        dp[n] = fibDPTopDownHelper(n-1, dp)+fibDPTopDownHelper(n-2, dp);
    }

    return dp[n];
}

int fibDPTopDown(int n){
    vector<int> dp(n+1, -1);
    dp[0] = 0;
    if(n>1){
        dp[1] = 1;
    }

    return fibDPTopDownHelper(n, dp);
}


int fibDPBottomUp(int n){
    vector<int> dp(n+1, -1);
    
    dp[0] = 0;
    if(n>=1)
        dp[1] = 1;

    for(int i=2;i<n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}


int fibDPBottomUpOptimized(int n){
    int prev, next, curr;
        
    prev = 0;
    next = 1;

    if(n<=1)
        return n;

    for(int i=2;i<=n;i++){
        curr = prev + next;
        prev = next;
        next = curr;
    }

    return curr;
}

int fibonacciRec(int n){
    if(n==0 || n==1){
        return n;
    }
    return fibonacciRec(n-1) + fibonacciRec(n-2);
}



int main(){
    int n;
    cin>>n;
    cout<<"ANS: "<<fibDPTopDown(n)<<endl;
    return 0;
}