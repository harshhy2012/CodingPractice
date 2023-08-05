#include<bits/stdc++.h>

using namespace std;

int findPivot(vector<int> arr){
    int s = 0, e = arr.size()-1;
    int mid;
    while(s<=e){
        mid = s+(e-s)/2;
        if(arr[mid-1]>arr[mid] && mid-1>=0){
            return mid-1;
        }
        else if(arr[mid]>arr[mid+1] && mid+1<=arr.size()){
            return mid;
        }
        else if(arr[s]<arr[mid]){
            s = mid+1;
        }
        else{
            e = mid-1;
        }
    }
    return -1;
}

bool binarySearch(vector<int> arr, int key, int s, int e){
    int mid;
    while(s<=e){
        mid = s+(e-s)/2;
        if(arr[mid]==key){
            return true;
        }
        else if(key<arr[mid]){
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    return false;
}

bool binarySearchRotatedArray(vector<int> arr, int key){
    int s = 0, e = arr.size()-1;
    int mid, pivot;
    pivot = findPivot(arr);
    s = 0, e = pivot;
    bool isFound = binarySearch(arr,key,0,pivot) || binarySearch(arr,key,pivot+1, arr.size()-1);
    return isFound;
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

    if(binarySearchRotatedArray(arr, key))
        cout<<"FOUND\n";
    else    
        cout<<"NOT FOUND\n";
    return 0;
}