#include<bits/stdc++.h>

using namespace std;

int find(int idx, vector<int>& arr, int key){
    if(idx == arr.size())
        return -1;

    if(arr[idx] == key)
        return idx;

    return find(idx+1, arr, key);

}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr){
        cin>>i;
    }
    int key;
    cin>>key;

    int foundIdx = find(0, arr, key);
    
    if(foundIdx!=-1)
        cout<<"FOUND AT: "<<foundIdx<<endl;
    else
        cout<<"NOT Found\n";

    return 0;
}