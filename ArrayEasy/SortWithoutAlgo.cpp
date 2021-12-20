#include<bits/stdc++.h>

using namespace std;

void sortWithoutAlgo(vector<int>&arr){
    vector<int> sortedArr(100000,0);
    for(auto i:arr){
        sortedArr[i]++;
    }
    arr.clear();
    for(int i=0;i<sortedArr.size();i++){
        for(int j=0;j<sortedArr[i];j++)
            arr.push_back(i);
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i:arr){
        cin>>i;
    }
    sortWithoutAlgo(arr);
    for(auto i: arr){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}