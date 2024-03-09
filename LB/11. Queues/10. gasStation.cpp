#include<bits/stdc++.h>

using namespace std;

int canCompleteCircuitn2(vector<int>& gas, vector<int>& cost) {
    bool canComplete = false;
    int bal = 0, ans = -1;
    int n = gas.size();
    for(int i=0;i<n-1;i++){
        bal+=gas[i]; bal-=cost[i];
        if(bal<0){
            i++;
        }
        cout<<"I: "<<i<<endl;
        cout<<"GAS: "<<gas[i]<<" || COST: "<<cost[i]<<" || BALANCE: "<< bal<<endl;
        canComplete = true;
        for(int j=i+1;i!=j;j=(j+1)%n){
           
            cout<<"GAS: "<<gas[j]<<" || COST: "<<cost[j]<<" || BALANCE: "<< bal<<endl;
            bal+=gas[j]; bal-=cost[j];
            if(bal<0){
                canComplete = false;
                bal = 0;
                break;
            }
        }
        if(canComplete){
            ans = i;
            return ans;
        }
    }
    return ans;
}

int canCompleteCircuitn(vector<int>& gas, vector<int>& cost) {
// start then if for some i we have bal 0 at some j, we can say that any i < j will also not be the answer so for next iteration we start with i = j and j = i+1;

}

int canCompleteCircuitBest(vector<int>& gas, vector<int>& cost) {
int deficit = 0;
int bal = 0;
int start = 0;
for(int i=0;i<gas.size();i++){
    bal+= gas[i]-cost[i];
    if(bal<0){
        deficit += bal;
        start = i+1;
        bal = 0;
    }
}

if(bal+deficit >= 0){
    return start;
} else{
    return -1;
}

}

int main(){
    int n;
    cin>>n;
    vector<int> gas(n), cost(n);
    for(auto &i: gas){
        cin>>i;
    }
    for(auto &i: cost){
        cin>>i;
    }

    cout<<canCompleteCircuitBest(gas, cost)<<endl;

    return 0;
}