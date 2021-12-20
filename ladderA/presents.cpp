#include<bits/stdc++.h>

using namespace std;

int main(){
//     ifstream cin("presents.txt");
//     if(cin.fail())
//     cout<<"Input from file failed";
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr){
        cin>>i;
    }
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        ans[arr[i]-1] = i+1;
    }
    for(auto i: ans){
        cout<<i<<" ";
    }
    cout<<endl;
    //cin.close();
    return 0;
}