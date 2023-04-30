#include<bits/stdc++.h>

using namespace std;


bool isAns(vector<long long> arr, long long m, long long height){
    long long wood = 0;
    for(int i=0;i<arr.size();i++){
        if(height<=arr[i]){
            // cout<<"arr["<<i<<"]: "<<arr[i];
            wood+=(arr[i]-height);
        }
        if(wood>=m){
            return true;
        }
        // cout<<" || wood: "<<wood<<endl;
    }
    return false;
}

long long maxHeight(vector<long long> arr, long long m){
    long long s = 0, e = *max_element(arr.begin(), arr.end()); 
    long long mid;
    long long ans = 0;
    while(s<=e){
        mid=s+(e-s)/2;
        // 1cout<<"s: "<<s<<" || e: "<<e<<" || mid: "<<mid<<endl;
        if(isAns(arr, m, mid)){
            ans = mid;
            s = mid+1;
        } 
        else{
            e = mid-1;
        }
        // cout<<"ANS: "<<ans<<endl;
    }
    return (int)ans;
}

int main(){
    long long n;
    long long m;
    cin>>n>>m;
    vector<long long> arr(n);
    for(auto &i: arr){
        cin>>i;
    }
   

    cout<<maxHeight(arr, m)<<endl;

    return 0;
}