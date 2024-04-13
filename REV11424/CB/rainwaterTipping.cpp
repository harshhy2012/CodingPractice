#include<bits/stdc++.h>

using namespace std;

int rainWaterHarvesting(vector<int> arr){
    int n = arr.size();
    vector<int> rightmax(n), leftmax(n);
    rightmax[0] = arr[0];
    leftmax[n-1] = arr[n-1];
    int i = 1, j = n-2;
    while(1<n && j>=0){
        rightmax[i] = max(rightmax[i-1], arr[i]);
        leftmax[i] = max(leftmax[j+1], arr[j]);
        i++;j--;
    }
    cout<<"rightmax: ";
    for(auto i:rightmax){
        cout<<i<<" ";
    }
    cout<<"\n\nleftmax: ";
    for(auto i:leftmax){
        cout<<i<<" ";
    }
    cout<<endl;
    int ans = 0;
    for(int i=0;i<n;i++){
        ans += min(leftmax[i], rightmax[i]) - arr[i];
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr){
        cin>>i;
    }
    cout<<rainWaterHarvesting(arr);
    return 0;
}