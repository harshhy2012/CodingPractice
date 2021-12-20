#include<bits/stdc++.h>

using namespace std;

bool binarySearch(vector<int>arr, int s, int e, int key){
    if(s<=e){
        int mid = (s+e)/2;
        if(arr[mid] == key){
            return true;
        }
        if(key>=arr[mid]){
            return binarySearch(arr, mid+1, e, key);
        }
        else{
            return binarySearch(arr, 0, mid-1, key);
        }
    }
    else
        return false;
}

int main(){
    ifstream cin("binarySearch.txt");
    if(cin.fail())
        cout<<"Input from file failed";
    int n, key;
    cin>>n>>key;
    vector<int> arr(n);
    for(auto &i: arr){
        cin>>i;
    }
    for(auto i: arr){
        cout<<i<<" ";
    }
    cout<<endl;
    if(binarySearch(arr, 0, arr.size(), key))
        cout<<"FOUND\n";
    else
        cout<<"NOT FOUND\n";

    cin.close();
    return 0;
}