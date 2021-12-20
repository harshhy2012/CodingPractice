#include<bits/stdc++.h>

using namespace std;

void linerSearch(vector<int> arr, int n, int key){
    if(n==0 && arr[n]!=key){
        cout<<"NO ELEMENT FOUND\n";
        return;
    }
    if(arr[n]==key){
        cout<<"ELEMENT FOUND AT IDX: "<<n<<"\n";
        return;
    }
    linerSearch (arr, n-1, key);
}

int main(){
    ifstream cin("linearSearchRec.txt");
    if(cin.fail())
        cout<<"Input from file failed";
    int n, key;
    cin>>n>>key;
    vector<int> arr(n);
    for(auto &i: arr){
        cin>>i;
    }
    for(auto i: arr){
        cout<<i<<" ";
    }
    cout<<endl;
    linerSearch(arr,arr.size()-1,key);
    cin.close();
    return 0;
}