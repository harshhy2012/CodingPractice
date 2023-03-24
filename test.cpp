#include<bits/stdc++.h>

using namespace std;

vector<vector<int> > prettyPrint(int A) {
    int n = A+(A-1);
    vector<vector<int>> arr(n, vector<int> (n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j] = n-i;
        }
    }
    return arr;
}

int main(){
    int A = 4;
    vector<vector<int>> ans = prettyPrint(A);

    for(auto i:ans){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}