#include<bits/stdc++.h>

using namespace std;

pair<bool, int> isCelebrity(vector<vector<int>> arr){
    int n = arr.size();
    stack<int> st;
    for(int i=0;i<n;i++){
        st.push(i);
    }
    while(st.size()>1){
        int personA = st.top(); st.pop();
        int personB = st.top(); st.pop();
        if(arr[personA][personB]){
            st.push(personB);
        } else if(arr[personB][personA]){
            st.push(personA);
        }
    }
    if(st.empty()){
        return {false, -1};
    }
    int zeroCnt=0, oneCnt=0;
    for(int i=0;i<n;i++){
        if(!arr[st.top()][i]){
           zeroCnt++;
        }
    }
    if(zeroCnt!=n){
        return {false, -1};
    }
    for(int i=0;i<n;i++){
        if(arr[i][st.top()]){
            oneCnt++;
        }
    }
    if(oneCnt!=n-1){
        return {false, -1};
    }
    
    return {true, st.top()+1};
}

int main(){
    int n ;
    cin>>n;
    vector<vector<int>> arr(n, vector<int> (n));
    for(auto &i: arr){
        for(auto &j: i){
            cin>>j;
        }
    }

    pair<bool, int> ans = isCelebrity(arr);
    if(!ans.first){
        cout<<"FALSE";
    } else{
        cout<<"TRUE";
    }
    cout<<" || celeb: "<<ans.second;

    return 0;
}