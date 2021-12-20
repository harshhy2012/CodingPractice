#include<bits/stdc++.h>

using namespace std;

int KthMax(vector<int> arr, int k){
    sort(arr.begin(),arr.end());
    return arr[arr.size()-k];
}

int KthMin(vector<int> arr, int k){
    sort(arr.begin(),arr.end());
    return arr[k-1];
}

int main(){
    int n,k;
    cin>>n;
    vector<int> arr(n);
    for(auto &i:arr){
        cin>>i;
    }
    cin>>k;
    cout<<"Kth Max: "<<KthMax(arr,k)<<endl;
    cout<<"Kth Min: "<<KthMin(arr,k)<<endl;
    return 0;
}