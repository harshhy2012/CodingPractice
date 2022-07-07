#include<bits/stdc++.h>

using namespace std;

void bubbleSort(vector<int> &arr, int n){
    if(n==1)
        return;
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1])
            swap(arr[i],arr[i+1]);
    }
    return bubbleSort(arr, n-1);
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr){
        cin>>i;
    }

    bubbleSort(arr, n);

    for(auto i: arr){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}