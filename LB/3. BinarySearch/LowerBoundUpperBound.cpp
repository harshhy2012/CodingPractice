#include<bits/stdc++.h>

using namespace std;

int upperBound(vector<int> arr, int key){
    int s = 0, e = arr.size()-1;
    int mid=0;
    int ans=-1;
    while(s<=e){
        mid = s+(e-s)/2;
        if(arr[mid]==key){
            ans = mid;
            s = mid+1;
        }
        else if(arr[mid]<key){
            s = mid+1;
        }
        else{
            e = mid-1;
        }
    }
    return ans;
}

int lowerBound(vector<int> arr, int key){
    int s = 0, e = arr.size()-1;
    int mid;
    int ans;
    while(s<e){
        mid = s+(e-s)/2;
        if(arr[mid]==key){
            ans = mid;
            e = mid-1;
        }
        else if(arr[mid]<key){
            s = mid+1;
        }
        else{
            e = mid-1;
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
    int key;
    cin>>key;
    cout<<"UPPER BOUND AT INDEX: "<<upperBound(arr, key)<<endl;
    cout<<"LOWER BOUND AT INDEX: "<<lowerBound(arr, key)<<endl;


    return 0;
}