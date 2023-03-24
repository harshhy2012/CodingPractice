#include<bits/stdc++.h>

using namespace std;

int firstDuplicate(vector<int> arr){
    int n = arr.size();
    int max = *max_element(arr.begin(), arr.end());
    vector<int> hash(max+1);
    
    for(int i=0;i<n;i++){
        hash[arr[i]]++;
    }
    for(int i=0;i<n;i++){
        if(hash[arr[i]]>1){
            return arr[i];
        }
    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr){
        cin>>i;
    }

    cout<<firstDuplicate(arr)<<endl;

    return 0;
}