#include<bits/stdc++.h>

using namespace std;

pair<bool, int> binarySearch(vector<int> arr, int start, int end, int key){
    int mid;
    while(start<=end){  
        mid = start+(end-start)/2;
        if(arr[mid] == key){
            cout<<"arr[mid]: "<<arr[mid]<<endl; 
            return {true, mid};
        }
        else if(key < arr[mid]){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
        cout<<"Start: "<<start<<" || mid: "<<mid<<" || END: "<<end<<endl;
    }
    return {false, -1};
}

pair<bool, int> expSearch(vector<int> arr, int key){
    int i=0,j=1;
    while(j<arr.size() && arr[j]<key){
        cout<<"I: "<<i<<" || J: "<<j<<endl;
        i = j;
        j*=2;
    }
    if(j>arr.size())
        j = arr.size()-1;
    cout<<"I: "<<i<<" || J: "<<j<<endl;
    return binarySearch(arr,i,j,key);
}

void createData(){
    ofstream myFile("C:/Users/Harshit Yadav/Desktop/CodingPractice/LB/BinarySearch/exponentialSearch.txt");
    myFile<<"100000\n";
    myFile.flush();
    for(int i=1;i<=100000;i++){
        myFile<<i<<" ";
        myFile.flush();
    }
    myFile<<"\n97888"<<endl;
    myFile.flush();
    myFile.close();
}

int main(){
    //createData();
    // ifstream cin("exponentialSearch");
    // if(cin.fail())
    //     cout<<"Input from file failed";
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr){
        cin>>i;
    }
    int key;
    cin>>key;
    pair<bool, int> ans = expSearch(arr, key);

    if(ans.first){
        cout<<"Key Found at "<<ans.second<<" index.\n";
    }
    else{
        cout<<"ELEMENT NOT FOUND!";
    }
    // cin.close();
    return 0;
}