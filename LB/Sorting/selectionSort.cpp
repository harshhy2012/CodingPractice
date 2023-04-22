#include<bits/stdc++.h>

using namespace std;

void selectionSort(vector<int>&arr){
    int n = arr.size();
    for(int i=0;i<n-1;i++){
        int minIdx = i;
        for(int j = i+1;j<n;j++){
            if(arr[j]<arr[minIdx]){
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr){
        cin>>i;
    }

    selectionSort(arr);

    for(auto i: arr){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}