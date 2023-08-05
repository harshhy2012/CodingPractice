#include<bits/stdc++.h>

using namespace std;

int numRollsToTarget(int n, int k, int target) {
    if(target<0)    return 0;
    if(n == 0 && target == 0)   return 1;
    if(n == 0 && target != 0)    return 0;
    if(n != 0 && target == 0)    return 0;
    
    int ans = 0;
    for(int i=1;i<=k;i++){
        ans += numRollsToTarget(n-1, k, target-i);
    }
    return ans;
}

int main(){
    int n,k,t;
    cin>>n>>k>>t;    

    cout<<numRollsToTarget(n,k,t);

    return 0;
}