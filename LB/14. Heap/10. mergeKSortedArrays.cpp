#include<bits/stdc++.h>

using namespace std;

class Info{
    public:
        int data;
        int row;
        int col;

        Info(int val, int r, int c){
            this->data = val;
            this->row = r;
            this->col = c;
        }
};

class compare{
    public: 
        bool operator()(Info*a, Info*b){
            return a->data > b->data;
        }
};

vector<int> mergeKSortedArr(vector<vector<int>>&arr, int k, int n){
    priority_queue<Info*, vector<Info*>, compare> minHeap;
    for(int i = 0;i<k;i++){
        Info* newInfo = new Info(arr[i][0], i, 0);
        minHeap.push(newInfo);
        
    }
    vector<int> ans;
    while(!minHeap.empty()){
        Info* smallNode = minHeap.top();
        minHeap.pop();
        int topEle = smallNode->data;
        int topRow = smallNode->row;
        int topCol = smallNode->col;
        ans.push_back(topEle);

        if(topCol + 1 < n){
            Info* newInfo = new Info(arr[topRow][topCol+1], topRow, topCol+1);
            minHeap.push(newInfo);
        } 
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<vector<int>> kArr(k, vector<int>(n));
    vector<int> arr;
    for(auto&i: kArr){
        for(auto &j: i){
            cin>>j;
        }
    }

    vector<int> ans = mergeKSortedArr(kArr, k, n);

    cout<<"\nANS: ";
    for(auto i: ans){
        cout<<i<<" ";
    }
    
    return 0;
}