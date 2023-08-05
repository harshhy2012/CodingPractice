#include<bits/stdc++.h>

using namespace std;

long merge(vector<int>&arr, vector<int> &temp, int s, int mid, int e){
    int i = s, j = mid+1, k = s;
    long c = 0;
    // inversions happen when j>i and arr[i] > arr[j]
    // so basically we need to know when a unsorted element is there
    while(i<=mid && j<=e){
        if(arr[i]<=arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
            c += mid-i+1;
        }
    }

    while(i<=mid)
        temp[k++] = arr[i++];
    while(j<=e)
        temp[k++] = arr[j++];

    for(int x = s;x<=e;x++){
        arr[x] = temp[x];
    }

    return c;
}

long mergerSort(vector<int>&arr, vector<int>& temp, int s, int e){
    if(s>=e)    return 0;
    
    int mid = s + (e-s)/2;
    long c = 0;
    c += mergerSort(arr, temp, s, mid);
    c += mergerSort(arr, temp, mid+1, e);
    c += merge(arr, temp, s, mid, e);    

    return c;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr){
        cin>>i;
    }
    long c = 0;
    vector<int> temp(n,0);
    c = mergerSort(arr, temp, 0, n-1);
    cout<<"Num of Inversions: "<<c;

    

    return 0;
}