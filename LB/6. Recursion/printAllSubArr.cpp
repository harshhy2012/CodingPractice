#include<bits/stdc++.h>

using namespace std;

void printAllSubArr(vector<int>&arr, int beg, int end){
    if(beg>end){
        return;
    }
    for(int i=beg;i<=end;i++){
        for(int j=i;j<=end;j++){
            cout<<arr[j]<<" ";
        }
        cout<<endl;
    }
    cout<<"--------------------\n";
    // cout<<endl;
    printAllSubArr(arr, beg+1, end);
}



int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr){
        cin>>i;
    }
    printAllSubArr(arr, 0, arr.size()-1);

    // for(int i=0;i<n;i++){
    //     for(int j=i;j<n;j++){
    //         for(int k=i;k<=j;k++){
    //             cout<<arr[k]<<" ";
    //         }
    //         cout<<endl;
    //     }
    //     cout<<endl;
    // }

    return 0;
}