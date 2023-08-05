#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(n, vector<int> (m));
    for(auto &i: arr){
        for(auto &j: i){
            cin>>j;
        }
    }

    for(int i=0;i<m;i++){
        if(i%2==0){
            for(int j=0;j<n;j++){
                cout<<arr[j][i]<<" ";
            }
        }
        else{
            for(int j=n-1;j>=0;j--){
                cout<<arr[j][i]<<" ";
            }
        }
        cout<<endl;
    }

    return 0;
}