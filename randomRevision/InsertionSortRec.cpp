#include<bits/stdc++.h>

using namespace std;

void insertionSort(vector<int> &arr){
    
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr){
        cin>>i;
    }

    insertionSort(arr);

    for(auto i: arr){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}