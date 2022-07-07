#include<bits/stdc++.h>

using namespace std;

void randomShuffle(vector<int>&arr){
    srand(time(NULL));
    int j;
    for(int i=0;i<arr.size();i++){
        j = rand()%(i+1);
        swap(arr[i],arr[j]);
    }
}

int partitionArr(vector<int>&arr, int low, int high){
    int pivot = arr[high];
    int i = low-1;                                                                    
    for(int j = low;j<high;j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[i],arr[j]);  
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}


void quicksort(vector<int>&arr, int low, int high){
    if(low<high){
        int pivot = partitionArr(arr, low, high);
        quicksort(arr, low, pivot-1);
        quicksort(arr, pivot+1, high);
    }
    else
        return;
}



int main(){
    ifstream cin("randomizedQuickSort.txt");
    if(cin.fail())
        cout<<"Input from file failed";
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto&i:arr){
        cin>>i;
    }
    randomShuffle(arr);

    cout<<"Unsorted: ";
    for(auto i: arr){
        cout<<i<<" ";
    }

    quicksort(arr, 0, n-1);
    
    cout<<"\nSorted:   ";
    for(auto i: arr){
        cout<<i<<" ";
    }

    cout<<endl;

    cin.close();
    return 0;
}