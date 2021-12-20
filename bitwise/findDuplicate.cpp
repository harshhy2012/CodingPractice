#include<bits/stdc++.h>

using namespace std;

int findDuplicate(vector<int> &arr){
    int x=0;
    for(int i=0;i<arr.size()-1;i++){
        if((arr[i]^arr[i+1]) == 0){
            cout<<arr[i]<<" "<<arr[i+1];
            return arr[i];
    }
    }
    return -1;
}

int main(){
    ifstream cin("findDuplicate.txt");
    if(cin.fail())
    cout<<"Input from file failed";
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr){
        cin>>i;
    }
    cout<<"DUPLICATE NUM: "<<findDuplicate(arr)<<endl;
    cin.close();
    return 0;
}