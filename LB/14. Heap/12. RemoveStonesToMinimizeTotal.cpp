#include<bits/stdc++.h>

using namespace std;

int minStoneSum(vector<int>& piles, int k) {
    priority_queue<int> maxHeap;

    for(int i=0;i<piles.size();i++){
        maxHeap.push(piles[i]);
    }        

    while(k){
        int maxEle = maxHeap.top();
        maxHeap.pop();
        maxEle-= floor(maxEle/2);
        maxHeap.push(maxEle);
        k--;
    }
    int sum = 0;
    while(!maxHeap.empty()){
        int num = maxHeap.top();
        maxHeap.pop();
        sum+=num;
    }
    return sum;
}

int main(){
    int n;
    cin>>n;
    vector<int> piles(n);
    for(auto&i: piles){
        cin>>i;
    }
    int k;
    cin>>k;
    cout<<minStoneSum(piles, k)<<endl;
    return 0;
}