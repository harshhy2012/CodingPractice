#include<bits/stdc++.h>

using namespace std;

bool binarySearch2D(vector<vector<int>> arr, int key){
    int n = arr.size(), m = arr[0].size();
    int s = 0, e = n*m-1;
    int mid;
    while(s<=e){
        mid = s+(e-s)/2;
        int r = mid/m;
        int c = mid%m;

        if(arr[r][c] == key){
            return true;
        }
        else if(key<arr[r][c]){
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    return false;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(n, vector<int> (m));
    for(auto &i: arr){
        for(auto &j: i){
            cin>>j;
        }
    }
    int key;
    cin>>key;
    if(binarySearch2D(arr,key)){
        cout<<"FOUND\n";
    }
    else{
        cout<<"NOT FOUND\n";
    }

    return 0;
}