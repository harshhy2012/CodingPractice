#include<bits/stdc++.h>

using namespace std;

int maxSubArrSum(vector<int> arr){
    int sum = 0, maxSum = INT_MIN;
    int n = arr.size();
    for(int i=0;i<n;i++){
        for(int j = i;j<n;j++){
            for(int k = i;k<=j;k++){
                sum+=arr[k];
            }
            maxSum = max(sum, maxSum);
            sum = 0;
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

    maxSubArrSum(arr);

    return 0;
}