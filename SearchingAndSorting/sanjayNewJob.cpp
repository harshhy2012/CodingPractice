#include<bits/stdc++.h>

using namespace std;

const bool myCompare(pair<string, int> a, pair<string, int> b){
    if(a.second!=b.second)
        return a.second>b.second;
    else
        return a.first>b.first;
}

int main(){
    ifstream cin("sanjayNewJob.txt");
    if(cin.fail())
    cout<<"Input from file failed";
    int tSal,n;
    cin>>tSal>>n;
    vector<pair<string, int>> arr(n);
    for(auto &i:arr){
        cin>>i.first>>i.second;
    }
    sort(arr.begin(),arr.end(),myCompare);
    for(auto i: arr){
        if(i.second>=tSal)
        cout<<i.first<<" "<<i.second<<endl;
    }
    cin.close();
    return 0;
}