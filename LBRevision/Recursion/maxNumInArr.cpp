#include<bits/stdc++.h>

using namespace std;

int maxEle(vector<int>& arr, int&n, int i, int&maxEl){
    if(i==n){
        return maxEl;
    }
    maxEl = max(arr[i], maxEl);
    return maxEle(arr, n, i+1, maxEl);
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr){
        cin>>i;
    }
    int maxEl = INT_MIN;
    cout<<"MAX ELEMENT: "<<maxEle(arr, n, 0, maxEl)<<endl;

    return 0;
}