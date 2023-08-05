#include<bits/stdc++.h>

using namespace std;

int mountainPeak(vector<int> arr){
    int beg = 0;
    int end = arr.size()-1;
    int mid;
    int ans=-1;
    while(beg<end){
        mid = beg+(end-beg)/2;
        if(arr[mid]<=arr[mid+1]){
            beg = mid+1;
        }
        else{
            end = mid;
            ans = mid;
        }
    }
    return arr[ans];
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto&i: arr){
        cin>>i;
    }

    cout<<mountainPeak(arr)<<endl;

    return 0;
}