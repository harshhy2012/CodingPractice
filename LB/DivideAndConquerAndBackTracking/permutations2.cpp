#include<bits/stdc++.h>

using namespace std;

void permutations(vector<vector<int>>&ans, vector<int> &arr, int i){
    if(i>=arr.size()){
        ans.push_back(arr);
        return;
    }
    unordered_map<int, bool> visited;
    for(int j=i;j<arr.size();j++){
        if(visited.find(arr[i]) != visited.end()){
            continue;
        }
        visited[arr[i]] = true;
        swap(arr[i],arr[j]);
        permutations(ans, arr, i+1);
        swap(arr[i],arr[j]);
    }
}

 vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> ans;
    permutations(ans, nums, 0);
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i:arr){
        cin>>i;
    }

    vector<vector<int>> ans = permuteUnique(arr);

    for(auto &i:ans){
        for(auto &j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}