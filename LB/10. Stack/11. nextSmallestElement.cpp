#include<bits/stdc++.h>

using namespace std;


vector<int> smallestNextEle(vector<int> arr){
    int n = arr.size();
    stack<int> st;
    st.push(-1);
    vector<int> ans;
    for(int i=0;i<n;i++){
        while(st.top()>arr[i]){
            st.pop();
        }
        ans.push_back(st.top());
        st.push(arr[i]);
    }        
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr){
        cin>>i;
    }

    for(auto i: smallestNextEle(arr)){
        cout<<i<<" ";
    }
    cout<<endl;
    
    return 0;
}