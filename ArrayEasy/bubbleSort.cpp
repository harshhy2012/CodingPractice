#include<bits/stdc++.h>

using namespace std;

void bubbleSort(vector<int> &arr){
    int n = arr.size();

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j])
                swap(arr[i],arr[j]);
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto &i: v)
        cin>>i;

    bubbleSort(v);
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}