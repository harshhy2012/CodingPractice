#include<bits/stdc++.h>

using namespace std;

int numOcc(vector<int> arr, int k){
    int n = arr.size();
    int ans=0;
    for(int i=0;i<n;i++){
        if(k==arr[i])
            ans++;
    }
    return ans;
}

int main(){
    int n,k;
    cin>>n;
    vector<int> arr(n);
    for(auto &i:arr){
        cin>>i;
    }
    cin>>k;
    cout<<numOcc(arr,k)<<endl;
    return 0;
}