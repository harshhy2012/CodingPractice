#include<bits/stdc++.h>

#define ll long long
using namespace std;


long long minimumDifference(vector<int>& nums) {
    int n = nums.size();
    vector<int> prefix(n, -1), suffix(n, -1);
    priority_queue<int> maxHeap;
    priority_queue<ll, vector<ll>, greater<ll>> minHeap;    
    int nBy3 = n/3;
    int sum = 0;
    for(int i=0;i<n;i++){
        sum+=nums[i];
        maxHeap.push(nums[i]);
        
        if(maxHeap.size()>nBy3){
            sum-=maxHeap.top();
            maxHeap.pop();
        }
        if(maxHeap.size() == nBy3)
            prefix[i] = sum;
    }
    sum = 0;
    for(int i=n-1;i>=0;i--){
        sum+=nums[i];
        minHeap.push(nums[i]);
        
        if(minHeap.size()>nBy3){
            sum-=minHeap.top();
            minHeap.pop();
        }
        if(minHeap.size() == nBy3)
            suffix[i] = sum;
        
    }

    // cout<<"PREFIX: ";
    // for(auto i: prefix){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    // cout<<"SUFFIX: ";
    // for(auto &i: suffix){
    //     cout<<i<<" ";
    // } 
    // cout<<endl;

    int ans = 0, minAns = LONG_LONG_MAX;

    for(int i=nBy3-1;i<2*nBy3;i++){
        ans = prefix[i]-suffix[i+1];
        minAns = min(minAns, ans);
    }

    return minAns;
}

int main(){
    int n;
    cin>>n;

    vector<int> arr(n);

    for(auto &i: arr){
        cin>>i;
    }

    cout<<"ANS: "<<minimumDifference(arr);

    return 0;
}