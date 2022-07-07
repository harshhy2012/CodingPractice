#include<bits/stdc++.h>

using namespace std;

int arraySum(vector<int> arr,int n){
    if(n==0)
        return 0;
    if(n==1)
        return arr[0];

    return arr[n-1]+arraySum(arr, n-1);
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr){
        cin>>i;
    }
    cout<<arraySum(arr, n);
    return 0;
}