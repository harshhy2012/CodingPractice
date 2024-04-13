#include<bits/stdc++.h>

using namespace std;

void printSubArr(vector<int> arr){
    int n = arr.size();
    for(int i=0;i<n;i++){
        for(int j = i;j<n;j++){
            for(int k = i;k<=j;k++){
                cout<<arr[k]<<" ";
            }
            cout<<endl;
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

    printSubArr(arr);

    return 0;
}