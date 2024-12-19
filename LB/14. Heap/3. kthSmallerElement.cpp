#include<bits/stdc++.h>

using namespace std;

int kthSmallest(vector<int>&arr, int k){
    priority_queue<int> maxHeap;
    int n = arr.size();

    // insert first k elements, 
    int i = 0;
    for(;i<k;i++){
        maxHeap.push(arr[i]);
    }

    // for next n-k element 
    // we will check if arr[i] < maxHeap.top() if yes we pop from maxHeap and insert the arr[i]
    for(;i<n;i++){
        if(arr[i] < maxHeap.top()){
            maxHeap.pop();
            maxHeap.push(arr[i]);
        }
    }

    return maxHeap.top();
}


int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr){
        cin>>i;
    }

    int k;
    cin>>k;

    cout<<"ANS: "<<kthSmallest(arr, k);
    cout<<endl;
    return 0;
}