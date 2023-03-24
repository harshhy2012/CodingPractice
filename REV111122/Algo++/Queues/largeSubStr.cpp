#include<bits/stdc++.h>

using namespace std;

int largestSubStr(string s){
    int n = s.size();
    vector<int> visited(256,-1);
    int curSize, maxSize;
    curSize = maxSize = 0;

    visited[s[0]] = 0;
    for(int i=1;i<n;i++){
        int lastOcc = visited[s[i]];

        if(lastOcc==-1 || lastOcc < i-curSize){
            curSize++;
            maxSize = max(curSize, maxSize);
        } else{
            maxSize = max(curSize, maxSize);
            curSize = i-lastOcc;
        }
        visited[s[i]] = i;
        maxSize = max(curSize, maxSize);
    }
    return maxSize;
}

int main(){
    string s;
    cin>>s;

    cout<<largestSubStr(s)<<endl;

    return 0;
}