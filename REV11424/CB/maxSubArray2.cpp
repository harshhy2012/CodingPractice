#include<bits/stdc++.h>

using namespace std;

int maxSubArrSum(vector<int> arr){
    int sum = 0, maxSum = INT_MIN;
    int n = arr.size();
    vector<int> cumSum (n);
    cumSum[0] = arr[0];
    for(int i = 1;i<n;i++){
        cumSum[i] = cumSum[i-1]+arr[i];
    }


    for(int i=0;i<n;i++){
        for(int j = i;j<n;j++){
            sum = cumSum[j]-cumSum[i];
            maxSum = max(sum, maxSum);
        }
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