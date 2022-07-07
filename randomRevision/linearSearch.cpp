#include<bits/stdc++.h>

using namespace std;

bool search(vector<int>arr, int n, int key){
    if(n==0){
        return false;
    }
    if(arr[n-1] == key)
        return true;

    return search(arr,n-1,key);

}

int main(){
    int n,key;
    cin>>n;
    vector<int> arr(n);
    
    for(auto&i:arr){
        cin>>i;
    }

    cin>>key;

    bool ans = search(arr, n, key);
    if(ans){
        cout<<"FOUND"<<endl;
    }
    else{
        cout<<"NOT FOUND"<<endl;
    }

    return 0;
}