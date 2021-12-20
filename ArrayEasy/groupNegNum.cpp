#include<bits/stdc++.h>

using namespace std;

void groupNegNum(vector<int> &arr){
    int n = arr.size();
    int x = 0;
    for(int i=0;i<n;i++){
        if(arr[i]<0&&x<i){
            swap(arr[i],arr[x]);
            x++;
        }
        if(arr[i]<0){
            x++;
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
    groupNegNum(arr);
    for(auto i:arr){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}