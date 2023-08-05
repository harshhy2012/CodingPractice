#include<bits/stdc++.h>

using namespace std;

void maxSum(vector<int>&arr, int i, int sum, int& maxi){
    if(i>=arr.size()){
        maxi = max(sum, maxi);
        return;
    }
    maxSum(arr, i+2, sum+arr[i], maxi);
    maxSum(arr, i+1, sum, maxi);    
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr){
        cin>>i;
    }
    int sum = 0;
    int maxi = INT_MIN;
    maxSum(arr,0,sum,maxi);
    cout<<maxi<<endl;
    return 0;
}