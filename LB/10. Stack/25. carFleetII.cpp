#include <bits/stdc++.h>

using namespace std;


vector<double> getCollisionTimes(vector<vector<int>>& cars) {
    int n = cars.size();
    vector<double> answer(n, -1); // STORES COLLISION TIME WITH ITH CAR
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        // check if car is ahead of current car is faster
        while(!st.empty() && cars[i][1] <= cars[st.top()][1]){
            st.pop();
        }
        while(!st.empty()){
            double colTime =(double)(cars[st.top()][0] - cars[i][0])/(cars[i][1]-cars[st.top()][1]);
            if(answer[st.top()] == -1 || colTime <= answer[st.top()]){
                answer[i] = colTime;
                break;
            }
            st.pop();
        }
        
        st.push(i);
    }
    return answer;
}


int main()
{
    int n;
    cin >> n;
    vector<vector<int>> cars(n, vector<int> (2));
    for (auto &i : cars)
    {   
        for(auto &j: i){
            cin>>j;
        }
    }

    vector<double> ans = getCollisionTimes(cars);
    for(auto i: ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}