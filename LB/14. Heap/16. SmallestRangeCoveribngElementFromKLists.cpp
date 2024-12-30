#include<bits/stdc++.h>

using namespace std;

class Node{
    public: 
        int data;
        int row;
        int col;

        Node(int data, int row, int col){
            this->data = data;
            this->row = row;
            this->col = col;
        }
};

class compare{
    public:
        bool operator()(Node*a, Node*b){
            return a->data > b->data;
        }
};

vector<int> smallestRange(vector<vector<int>>& nums) {
    int k = nums.size();
    priority_queue<Node*, vector<Node*>, compare> minHeap;

    vector<int> ans;
    int mini = INT_MAX, maxi = INT_MIN, minStart = INT_MAX,  minEnd= INT_MIN;

    for(int i=0;i<k;i++){
        Node* newNode = new Node(nums[i][0], i, 0);
        minHeap.push(newNode);
        maxi = max(maxi, nums[i][0]);
        mini = min(mini, nums[i][0]);
    }

    minStart = mini;
    minEnd = maxi;

    while(!minHeap.empty()){
        Node* currNode = minHeap.top();
        minHeap.pop();
        int currData = currNode->data;
        int currRow = currNode->row;
        int currCol = currNode->col;

        mini = currData;

        int currRange = maxi-mini;
        int ansRange = minEnd-minStart;

        if(currRange<ansRange){
            minEnd = maxi;
            minStart = mini;
        }


        if(currCol+1< nums[currRow].size()){
            maxi = max(maxi, nums[currRow][currCol+1]);
            Node*newNode = new Node(nums[currRow][currCol+1], currRow, currCol+1);
            minHeap.push(newNode);
        } else{
            break;
        }
    }
    
    ans = {minStart, minEnd};

    return ans;
}

int main(){
    vector<vector<int>> nums;
    nums = {
        {4,10,15,24,26},
        {0,9,12,20},
        {5,18,22,30},
    };

    vector<int> ans = smallestRange(nums);
    for(auto i: ans){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}