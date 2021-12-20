#include<bits/stdc++.h>

using namespace std;

int uniqueNum(vector<int>&arr){
    
    vector<int> bitSum(arr.size());
    for(int i =0;i<arr.size();i++){
        int j=0;
        while(arr[i]){
            if(arr[i]&1)
                bitSum[j]++;
            arr[i]>>=1;
            j++;
        }
    }
    for(auto &i: bitSum){
        i%=3;
    }
    int ans = 0;
    for(int i=0;i<bitSum.size();i++){
        ans+=bitSum[i]<<i;
    }   
    return ans;
}

int main(){
    ifstream cin("findUniqueIn3Pair.txt");
    if(cin.fail())
    cout<<"Input from file failed";
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr){
        cin>>i; 
    }
    cout<<uniqueNum(arr);
    cin.close();
    return 0;
}