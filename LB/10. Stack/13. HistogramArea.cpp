#include <bits/stdc++.h>

using namespace std;

vector<int> smallestNextEle(vector<int> arr)
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

vector<int> smallestPrevEle(vector<int> arr)
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

int maxHistArea(vector<int> &arr)
{
    vector<int> nextSmall = smallestNextEle(arr);
    vector<int> prevSmall = smallestPrevEle(arr);

    int area = 0, maxArea = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        area = arr[i] * (nextSmall[i] - prevSmall[i] - 1);
        maxArea = max(area, maxArea);
    }
    return maxArea;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &i : arr)
    {
        cin >> i;
    }
    int maxArea = maxHistArea(arr);
    cout << "MAX AREA: " << maxArea << endl;
    cout << endl;
    return 0;
}