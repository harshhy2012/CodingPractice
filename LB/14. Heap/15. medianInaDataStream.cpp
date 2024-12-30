#include<bits/stdc++.h>

using namespace std;

void callMedian(int&median, priority_queue<int>&maxHeap, priority_queue<int, vector<int>, greater<int>>&minHeap, int&element){
    if(minHeap.size() == maxHeap.size()){
        if(element > median){
            minHeap.push(element);
            median = minHeap.top();
        } else{
            maxHeap.push(element);
            median = maxHeap.top();
        }
    }
    else if(maxHeap.size() < minHeap.size()){
        if(element > median){
            int smallFront = minHeap.top();
            minHeap.pop();
            maxHeap.push(smallFront);
            minHeap.push(element);    
            median = (maxHeap.top()+minHeap.top())/2;
        } else{
            minHeap.push(element);
            median = (maxHeap.top()+minHeap.top())/2;
        }
    }
    else {
        if(element > median){
            minHeap.push(element);
            median = (maxHeap.top()+minHeap.top())/2;
        } else{
            int bigFront = maxHeap.top();
            maxHeap.pop();
            minHeap.push(bigFront);
            maxHeap.push(element);  
            median = (maxHeap.top()+minHeap.top())/2;
        }
    }
}

int main(){
    

    int arr[6] = {5,7,2,9,3,8};

    int median = 0;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for(int i=0;i<6;i++){
        int element = arr[i];
        callMedian(median, maxHeap, minHeap, element);
        cout<<"-> " << median << " ";
    }cout<<endl;

    return 0;
}