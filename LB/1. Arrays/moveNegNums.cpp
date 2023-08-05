#include<bits/stdc++.h>

using namespace std;

void moveNeg(vector<int>& arr){
    int l = 0, r = arr.size()-1;
    while(l<=r){
        if(arr[l]<0){
            l++;
        }
        else if(arr[r]>0){
            r--;
        }
        else{
            swap(arr[l], arr[r]);l++;r--;
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto &i: arr){
        cin>>i;
    }
    moveNeg(arr);

    for(auto i: arr){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}