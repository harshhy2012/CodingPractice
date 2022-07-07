#include<bits/stdc++.h>

using namespace std;

vector<int>  merge(vector<int>&arr, int s, int e){
    vector<int> res;
    int mid = (s+e)/2;
    int i=0, j = mid+1;
    while(i<=mid&&j<=e){
        if(arr[i]<arr[j]){
            res.push_back(arr[i]);
            i++;
        }
            
        else{
            res.push_back(arr[j]);
            j++;
        }
            

        while(i<=mid){
            res.push_back(arr[i]);
            i++;
        }
        while(j<=e){
            res.push_back(arr[j]);
            j++;
        }
    }
   
    for(int i=s;i<=e;i++){
        arr[i] = res[i-s];
    }
}

void mergeSort(vector<int>&arr, int beg, int end){
    if(beg+1>=end)
        return;
   
    int mid = (beg+end)/2;
    mergeSort(arr, beg, mid);
    mergeSort(arr, mid+1, end);
   
    merge(arr, beg, end);
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr){
        cin>>i;
    }

    mergeSort(arr, 0, n-1);
    for(auto i: arr){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}