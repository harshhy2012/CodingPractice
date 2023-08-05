#include<bits/stdc++.h>

using namespace std;

int pivotElement(vector<int> arr){
    int s = 0, e = arr.size()-1;
    int mid;
    while(s<=e){
        mid = s+(e-s)/2;
        if(arr[mid+1]<arr[mid]){
            return arr[mid];
        }
        else if(arr[mid-1]>arr[mid]){
            return arr[mid-1];
        }
        else if(arr[s] >= arr[mid]){
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    return arr[mid];
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr){
        cin>>i;
    }

    cout<<pivotElement(arr)<<endl;

    return 0;
}