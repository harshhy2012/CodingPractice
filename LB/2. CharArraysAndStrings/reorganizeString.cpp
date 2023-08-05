#include<bits/stdc++.h>

using namespace std;

bool cmp(pair<char, int>& a,pair<char, int>& b)
{
    return a.second > b.second;
}


string reorganize(string s){
    string ans;
    int n = s.size();
    if(n<=1){
        return s;
    }
    for(int i=0;i<n;i++){
        ans.push_back(' ');
    }
    vector<int> arr(26);
    for(int i=0;i<n;i++){
        arr[s[i]-'a']++;
    }
    cout<<endl;
    vector<pair<char, int>> hash;
    for(int i=0;i<26;i++){
        if(arr[i]!=0)
        hash.push_back({char(i+97), arr[i]});
    }
    sort(hash.begin(), hash.end(), cmp);
    int j = 0;
    for (int i = 0; i <hash.size();i++){
        while(hash[i].second>0 && j<s.size()){
            ans[j] = hash[i].first;
           //  cout<<"ans[j]: "<<ans[j]<<" || char(i): "<<char(i)<<endl;
            hash[i].second--;
            j+=2;
        }
        cout<<ans<<endl;
        if(j>=s.size()){
            j=1;
            i--;
        }
    }
    for(int i=0;i<n-1;i++){
        if(ans[i] == ans[i+1]){
            return "";
        }
    }
    return ans;
}

int main(){
    string s;
    cin>>s;
    cout<<reorganize(s)<<endl;
    return 0;
}