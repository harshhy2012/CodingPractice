#include<bits/stdc++.h>

using namespace std;

vector<int> stockSpan(vector<int> prices){
    int n = prices.size();
    stack<int> st1, st2;
    vector<int> ans(n);
    st1.push(prices[0]); ans[0]=1;
    for(int i=1;i<n;i++){
        int span = 1;
        cout<<"prices[i]: "<<prices[i]<<" | st1.top(): "<<st1.top()<<endl;
        if(prices[i]>st1.top()){
            //Scout<<"prices[i]: "<<prices[i]<<" | st1.top(): "<<st1.top()<<endl;
            while(!st1.empty() && prices[i] > st1.top()){
                span++;
                int x = st1.top();
                st1.pop();
                st2.push(x);
            }
            while(!st2.empty()){
                int x = st2.top();
                st2.pop();
                st1.push(x);
            }
        }
        st1.push(prices[i]);
        ans[i] = span;
    }//100 80 60 70 60 75 85
    return ans;
}

stack<pair<int,int>> st;

int next(int price){
    int span = 1;
    while(!st.empty() && st.top().first <= price){
        span+=st.top().second;
        st.pop();
    }
    st.push({price, span});
    return span;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr){
        cin>>i;
    }
    vector<int> ans = stockSpan(arr);
    for(auto i: ans){
        cout<<i<<" ";
    }
    cout<<endl;
    
    for(auto price: arr){
        cout<<next(price)<<" ";
    }
    cout<<endl;

    return 0;
}