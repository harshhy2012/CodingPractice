#include<bits/stdc++.h>

using namespace std;


vector<int> smallestNextEle(vector<int> arr){
    int n = arr.size();
    stack<int> st;
    st.push(-1);
    vector<int> ans;
    for(int i=n-1;i>=0;i--){
        while(st.top()>arr[i]){
            st.pop();
        }
        ans.push_back(st.top());
        st.push(arr[i]);
    }        
    reverse(ans.begin(), ans.end());
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