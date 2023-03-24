#include<bits/stdc++.h>

using namespace std;

int rightMostLowest(vector<int> arr){
    int low = INT_MAX, lowIdx=-1;
    for(int i=0;i<arr.size();i++){
        if(arr[i]<=low){
            low = arr[i];
            lowIdx = i;
        }
    }
    return lowIdx;
}

int leftMostHighest(vector<int> arr){
    int high = INT_MIN, highIdx=-1;
    for(int i=0;i<arr.size();i++){
        if(arr[i]>high){
            high = arr[i];
            highIdx = i;
        }
    }
    return highIdx;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr){
        cin>>i;
    }

    int high = leftMostHighest(arr);
    int low = rightMostLowest(arr);
    int ans = 0;
    if(high < low){
        ans = n-low+high-1;
    }
    else{
        ans = n-low+high-2;
    }
    cout<<ans<<endl;
    return 0;
}
