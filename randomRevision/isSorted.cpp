#include<bits/stdc++.h>

using namespace std;

bool isSorted(vector<int> arr){
    // base
    if(arr.size()==1 || arr.empty()){
        return true;
    }
    auto s = arr.begin()+1;
    auto e = arr.begin()+arr.size();
    vector<int> x = arr;
    x.erase(x.begin());
    bool ans = (arr[0]<=arr[1]) && isSorted(x);
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i:arr){
        cin>>i;
    }
    if(isSorted(arr))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}