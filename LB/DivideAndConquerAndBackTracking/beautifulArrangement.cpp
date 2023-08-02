#include<bits/stdc++.h>

using namespace std;

void countArrangementHelper(vector<int>&arr, int &ans, int&n, int curNum){
    if(curNum==n+1){
        ans++;
        for(int i=1;i<=n;i++){
            cout<<arr[i]<<" ";
        }        
        cout<<endl;
        return;
    }
    for(int i=1;i<=n;i++){
        if(arr[i]==0 && (curNum % i == 0 || i % curNum == 0)){
            arr[i] = curNum;
            countArrangementHelper(arr, ans, n, curNum+1);
            arr[i]  = 0;
        }
    }
}

int countArrangement(int n) {
    vector<int> arr(n+1);
    int ans = 0;
    countArrangementHelper(arr, ans, n, 1);
    return ans;
}

int main(){
    int n;
    cin>>n;
    cout<<countArrangement(n);
    return 0;
}