#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Heap{

    public:
        int size;
        vector<int> v;

    Heap(){
        size = 0;
        v.resize(101);
        v[size] = -1;
    }
    void insert(int data){
        size++;
        int idx = size;
        v[idx] = data;
        while(idx > 1){
            int parentIdx = idx/2;
            if(v[idx] > v[parentIdx]){
                swap(v[idx], v[parentIdx]);
                idx = parentIdx;
            } else{
                break;
            }
        }
    }

    // we delete only the last lone in the tree ie rightmost node at the bottom-most level
    int deletionLast(){
        swap(v[1], v[size]);
        size--;
        int ans = v[1];
        int idx = 1;
        int replaceIdx = idx;
        int leftIdx = 2*idx;
        int rightIdx = (2*idx)+1;
        while(idx < size){
            if(v[leftIdx] > v[idx]){
                replaceIdx = leftIdx;
            }
            if(v[rightIdx] > v[idx]){
                replaceIdx = rightIdx;
            }
            if(replaceIdx == idx){
                break;
            } 
            else{
                swap(v[idx], v[replaceIdx]);
                idx = replaceIdx;
            }
        }

        return ans;
    }
};

void heapify(vector<int>&v, int size, int i){
    int idx = i;
    int leftIdx = 2*i;
    int rightIdx = (2*i)+1;
    int swapIdx = idx;

    if(idx > size){
        return;
    }

    if(leftIdx <= size && v[leftIdx] > v[idx]){
        swapIdx = leftIdx;
    }
    if(rightIdx <= size && v[rightIdx] > v[idx]){
        swapIdx = rightIdx;
    }
    if(swapIdx != idx){
        swap(v[i], v[swapIdx]);
        heapify(v, size, swapIdx);
    }   
    
}

void heapSort(vector<int>&v, int size){
    while(size != 1){
        swap(v[1], v[size]);
        size--;
        heapify(v, size, 1);
    }

}


int main(){
    vector<int> arr(100);

    Heap newHeap;

    newHeap.v[1] = (100);
    newHeap.v[2] = 50;
    newHeap.v[3] = 60;
    newHeap.v[4] = 40;
    newHeap.v[5] = 45;

    newHeap.size = 5;

    cout<<"HeapBeforeInsertion: ";
    for(int i=1;i<=newHeap.size; i++){
        cout<<newHeap.v[i]<<" ";
    }
    cout<<endl;

    newHeap.insert(110);


    cout<<"HeapAfterInsertion: ";
    for(int i=1;i<=newHeap.size; i++){
        cout<<newHeap.v[i]<<" ";
    }
    cout<<endl;


    return 0;
}