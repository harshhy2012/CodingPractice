#include<bits/stdc++.h>

using namespace std;

int lowerBound(vector<int> arr, int key){
    int beg = 0, end = arr.size();

    while(beg<=end){
        int mid = (beg+end)/2;
        if(arr[mid] == key){
            //1. this is first element
            while(arr[mid-1] == key){
                mid--;
            }
            return mid;
        }
        else if(arr[mid]>key){
            end = mid-1;
        }
        else{
            beg = mid+1;
        }
    }
    
}

int upperBound(vector<int> arr, int key){
    int beg = 0, end = arr.size();

    while(beg<=end){
        int mid = (beg+end)/2;
        if(arr[mid] == key){
            //1. this is first element
            while(arr[mid+1] == key){
                mid++;
            }
            return mid;
        }
        else if(arr[mid]>key){
            end = mid-1;
        }
        else{
            beg = mid+1;
        }
    }
}

int main(){
    ifstream cin("lowerAndUpperBound.txt");
    if(cin.fail())
    cout<<"Input from file failed";
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr){
        cin>>i;
    }
    int key;
    cin>>key;
    cout<<"LOWER BOUND AT INDEX: "<<lowerBound(arr, key)<<endl;
    cout<<"UPPER BOUND AT INDEX: "<<upperBound(arr, key)<<endl;
    cin.close();
    return 0;
}