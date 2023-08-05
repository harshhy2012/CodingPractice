#include<bits/stdc++.h>

using namespace std;

void bubbleSort(vector<int> &arr){
    int n = arr.size();
    
    bool swapped;
    for(int i=1;i<n;i++){
        swapped = false;
        for(int j = 0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swapped = true;
                swap(arr[j],arr[j+1]);
            }
        }
        if(swapped = false){
            break;
        }
    }   
}

int main(){
    int n;  
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr){
        cin>>i;
    }

    bubbleSort(arr);

    for(auto i: arr){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}