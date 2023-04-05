#include<bits/stdc++.h>

using namespace std;

pair<int, bool> binarySearchNS(vector<int> arr, int key){
    int s=0,e=arr.size()-1;
    int mid;
    while(s<=e){
        mid = s+(e-s)/2;
        if(arr[mid]==key){
            return {mid,true};
        }
        else if(mid-1>=0 && arr[mid-1]==key){
            return {mid-1, true};
        }
        else if(mid+1<arr.size() && arr[mid+1]==key){
            return {mid+1, true};
        }
        else if(key<arr[mid]){
            e = mid-1;
        }
        else{
            s = mid+1;
        }
        cout<<"s: "<<s<<" || e: "<<e<<" || mid: "<<mid<<" || arr[mid]: "<<arr[mid]<<endl;
    }
    return {-1, false};
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
    pair<int, bool> ans = binarySearchNS(arr, key);
    if(ans.second){
        cout<<"KEY found at: "<<ans.first<<" index.\n";
    }
    else{
        cout<<"NOT FOUND!\n";
    }
    return 0;
}