#include<bits/stdc++.h>

using namespace std;

int maxSubArrSum(vector<int> arr){
    int n = arr.size();    
    int curSum = 0, maxSum = INT_MIN;

    for(int i=0;i<n;i++){
        curSum+=arr[i];
        if(curSum<0)
            curSum = 0;
        maxSum = max(curSum, maxSum);
    }

    return maxSum;

}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);

    for(auto &i: arr){
        cin>>i;
    }

    cout<<maxSubArrSum(arr)<<endl;

    return 0;
}