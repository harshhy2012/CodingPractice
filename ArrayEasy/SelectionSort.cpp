#include<bits/stdc++.h>

using namespace std;

void selectionSort(vector<int> &arr){
    int n = arr.size();
    
    for(int i=0;i<n;i++){
        int min_idx = i;
        int j=i+1;
        for(;j<n;j++){
            if(arr[min_idx]>arr[j])
                min_idx=j;
        }
        swap(arr[min_idx], arr[i]);
    }

}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i:arr){
        cin>>i;
    }
    selectionSort(arr);
    for(auto i: arr){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}