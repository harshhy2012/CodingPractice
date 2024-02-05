#include<bits/stdc++.h>

using namespace std;

vector<int> nextSmallerEle(vector<int>&arr)
{
    int n = arr.size();
    stack<int> st;
    st.push(-1);
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() != -1 && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        if (st.top() == -1)
        {
            ans.push_back(arr.size());
        }
        else
        {
            ans.push_back(st.top());
        }
        st.push(i);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

vector<int> prevSmallerEle(vector<int>&arr)
{
    int n = arr.size();
    stack<int> st;
    st.push(-1);
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top() != -1 && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        ans.push_back(st.top());
        st.push(i);
    }
    return ans;
}

int histogramArea(vector<int>&hist){    
    vector<int> nextSmall = nextSmallerEle(hist);
    vector<int> prevSmall = prevSmallerEle(hist);

    int area = 0, maxArea = INT_MIN;
    for (int i = 0; i < hist.size(); i++)
    {
        area = hist[i] * (nextSmall[i] - prevSmall[i] - 1);
        maxArea = max(area, maxArea);
    }
    return maxArea;
}

void histGen(vector<vector<int>> &arr, vector<int> &hist, int i){
    int m = arr[0].size();
    for(int j = 0; j < m; j++){
        if(arr[i][j] == 1){
            hist[j]++;
        } else if(arr[i][j] == 0){
            hist[j] = 0;
        }
    }
}

int maxRectangle(vector<vector<int>>&arr){
    int n = arr.size();
    int m = arr[0].size();
    vector<int> hist(m, 0);
    int maxRowArea = 0, maxArea = INT_MIN;
    for(int i=0;i<n;i++){
        histGen(arr, hist, i);
        
        maxRowArea = histogramArea(hist);
        maxArea = max(maxRowArea, maxArea);
    }
    return maxArea;
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> arr(n, vector<int> (m));
    for(auto &i: arr){
        for(auto &j: i){
            cin>>j;
        }
    }

    cout<<maxRectangle(arr)<<endl;

    return 0;
}