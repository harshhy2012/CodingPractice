#include<bits/stdc++.h>

using namespace std;

int partition(vector<int> &arr, int s, int e){
    int part = s;
    int pivEle = arr[s];
    int count = 0;
    for(int i=s+1;i<=e;i++){
        if(arr[i]<=pivEle)
            count++;
    }
    
    swap(arr[part], arr[s+count]);
    part = s+count;

    int i=s, j=e;
    while(i<part && j>part){
        while(arr[i] <= pivEle){
            i++;
        }
        while(arr[j] > pivEle){
            j--;
        }
        if(i<part && j>part)
        swap(arr[i],arr[j]);
    }

    return part;
}

void quickSort(vector<int> &arr, int s, int e){
    if(s>=e){
        return;
    }
    int part = partition(arr, s, e);
    quickSort(arr, s, part-1);
    cout<<"RETURNED From s->part-1\n";
    quickSort(arr, part+1, e);
    cout<<"RETURNED From part+1->e\n";
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr){
        cin>>i;
    }
    quickSort(arr, 0, n-1);
    for(auto i: arr){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}