#include<bits/stdc++.h>

using namespace std;

bool binarySearch(vector<int> arr, int key){
    int s = 0;
    int e = arr.size()-1;
    int mid;
    while(s<=e){
        mid = s+(e-s)/2;
        if(arr[mid]==key){
            return true;
        }
        else if(arr[mid]>key){
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    return false;
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

    if(binarySearch(arr, key))  
        cout<<"FOUND!\n";
    else
        cout<<"NOT FOUND\n";


    return 0;
}