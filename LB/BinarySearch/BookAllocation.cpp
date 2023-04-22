#include<bits/stdc++.h>

using namespace std;

bool isPossible(vector<int> arr, int n, int m, int mid){
    int sum = 0;
    int c = 1;
    // cout<<"MID: "<<mid<<endl;
    for(int i=0;i<n;i++){
        if(arr[i]>mid){
            return false;
        }
        if(sum+arr[i]>mid){
            c++;
            sum=arr[i];
            if(c>m){
                return false;
            }
            
        }
        else{
                sum+=arr[i]; 
            } 
        
    }
    // cout<<"M: "<<m<<endl<<endl;
    return true;
}

int bookAllocation(vector<int> arr, int m){
    int n = arr.size();
    if(m>n){
        return -1;
    }
    if(m==1){
        return accumulate(arr.begin(), arr.end(), 0);
    }
    if(m==n){
        return *max_element(arr.begin(), arr.end());
    }
    int s = arr[0], e = accumulate(arr.begin(),arr.end(), 0)-arr[0];
    int ans = INT_MAX;
    while(s<=e){
        int mid = (s+e)/2;
        if(isPossible(arr, n, m, mid)){
            ans = mid;
            e = mid-1;
        }
        else{
            s = mid+1;
        }
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
    int m;
    cin>>m;

    cout<<bookAllocation(arr,m);

    return 0;
}