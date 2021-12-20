#include<bits/stdc++.h>

using namespace std;

bool binarySearchIter(vector<int> arr, int key){
    int beg = 0, end = arr.size();
    while(beg<=end){
        cout<<beg<<" "<<end<<endl;
        int mid = (beg+end)/2;
        if(arr[mid] == key)
            return true;
        else if(arr[mid]>key)
            end = mid-1;
        else
            beg = mid+1;
    }
    return false;
}

bool binarySearchRec(vector<int> arr, int key, int beg, int end){
    if(beg<=end){
        int mid = (beg+end)/2;
    
        cout<<beg<<" "<<end<<endl;
    
        if(arr[mid] == key)
            return true;
    
        if(arr[mid]>key)
            return binarySearchRec(arr, key, beg, mid-1);
        else
            return binarySearchRec(arr, key, mid+1, end);
    }
    return false;
}


int main(){
    ifstream cin("binarySearch.txt");
    if(cin.fail())
    cout<<"Input from file failed";
    int n, key;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr){
        cin>>i;
    }
    cin>>key;
    // if(binarySearchIter(arr, key))
    //     cout<<"FOUND\n";
    // else
    //     cout<<"NOT FOUND\n";
    int beg = 0, end = arr.size();
    if(binarySearchRec(arr, key, beg, end))
        cout<<"FOUND\n";
    else
        cout<<"NOT FOUND\n";

    cin.close();
    return 0;
}