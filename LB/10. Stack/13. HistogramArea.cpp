#include<bits/stdc++.h>

using namespace std;

vector<int> smallestNextEle(vector<int> &arr){
    int n = arr.size();
    stack<int> st;
    st.push(-1);
    vector<int> ans;
    for(int i=n-1;i>=0;i--){
        
        while( st.top()!=arr[st.top()]>arr[i]){
            st.pop();
        }
        ans.push_back(st.top());
        st.push(i);
    }        
    
    reverse(ans.begin(), ans.end());

    return ans;
}

vector<int> smallestPrevEle(vector<int> &arr){
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

    vector<int> nextSmall = smallestNextEle(arr);
    vector<int> prevSmall = smallestPrevEle(arr);

    int area = 0, maxArea = INT_MIN;
    for(int i = 0;i<n;i++){

    }
    cout<<endl;
    return 0;
}