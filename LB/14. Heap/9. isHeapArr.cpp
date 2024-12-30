#include<bits/stdc++.h>

using namespace std;

void insertInHeap(vector<int>&arr, int data, int size){
    size++;
    int n = arr.size();
    if(size>n) return;
    int idx = size;
    arr[idx] = data;
    while(idx > 1){
        int parentIdx = idx/2;
        if(arr[parentIdx] < arr[idx]){
            swap(arr[parentIdx], arr[idx]);
            idx = parentIdx;
        } else{
            break;
        }
    }
}

int deleteFromHeap(vector<int>&arr, int size){
    int popIt = arr[size];
    swap(arr[1], arr[size]);
    
    size--;
    int idx = 1;
    int leftIdx = 2*idx;
    int rightIdx = (2*idx)+1;
    int swapIdx = idx;

    while(idx < size){
        if(arr[idx] < arr[leftIdx]){
            swapIdx = leftIdx;
        }
        if(arr[swapIdx] < arr[rightIdx]){
            swapIdx = rightIdx;
        }
        if(swapIdx != idx){
            swap(idx, swapIdx);
            idx = swapIdx;
        } else{
            break;
        }
    }
    return popIt;
}

void heapify(vector<int>&arr, int i){
    int n = arr.size();
    if(i>n) return;
    int idx = i, swapIdx = i;
    int leftIdx = 2*i;
    int rightIdx = (2*i)+1;
    
    if(leftIdx<n && arr[idx] < arr[leftIdx]){
        swapIdx = leftIdx;
    }
    if(rightIdx<n && arr[swapIdx] < arr[rightIdx] ){
        swapIdx = rightIdx;
    }
    if(swapIdx != idx){
        swap(arr[idx], arr[swapIdx]);
        heapify(arr, swapIdx);
    }
}

void createHeap(vector<int> arr, int size){
    for(int i = size;i>=size/2;i--){
        heapify(arr, i);
    }
}

void heapSort(vector<int>& arr, int size){
    while(size!=1){
        swap(arr[1], arr[size]);
        size--;
        heapify(arr, 1);
    }
}

bool isCompleteTree(vector<int> arr){
    int size = arr.size()-1;
    
}


int main(){
    vector<int> arr;


    return 0;
} 