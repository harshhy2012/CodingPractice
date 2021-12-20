#include<bits/stdc++.h>

using namespace std;

int notDup(vector<int> &arr){
    int x = 0;
    for(auto i: arr){
        x^=i;
    }
    return x;
}

int main(){
    ifstream cin("notFindDuplicate.txt");
    if(cin.fail())
    cout<<"Input from file failed";
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr){
        cin>>i;
    }
    cout<<"NOT DIPLICATE DIGIT: "<<notDup(arr)<<endl;
    cin.close();
    return 0;
}