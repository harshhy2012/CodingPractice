#include<bits/stdc++.h>

using namespace std;

int histogramArea(vector<int> arr){
    int n = arr.size();
    stack<int> stk;
    int isStackEmp = stk.empty();
    int area, maxArea;
    area = maxArea = INT_MIN;
    
    for(int i=0;i<n;i++){
        if(stk.empty()){
            stk.push(i);
        }
        while(!(arr[stk.top()] >= arr[i]) || stk.empty()){
            int t = stk.top();
            stk.pop();
            if(stk.empty()){
                area = arr[t]*i;
            }
            else{
                area = arr[t]*(i-stk.top()-1);
            }
            if(!stk.empty()){
                t = stk.top();
            }
        }
            maxArea = max(area, maxArea);
            stk.push(i);
    }
        
    return maxArea;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr){
        cin>>i;
    }

    cout<<histogramArea(arr)<<endl;
    return 0;
}