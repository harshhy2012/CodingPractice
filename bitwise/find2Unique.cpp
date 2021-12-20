#include<bits/stdc++.h>

using namespace std;

int main(){
    ifstream cin("find2Unique.txt");
    if(cin.fail())
    cout<<"Input from file failed";
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr){
        cin>>i;
    }
    int num1 = 0;
    // XOR all elements
    for(int i=0;i<arr.size();i++){
        num1^=arr[i];
    }
    //find 1st set bit of XOR result;
    int x = 0;
    int temp = num1;
    
    while(temp){
        if(temp&1){
            break;
        }
        x++;
        temp>>=1;
    }
    int mask = 1<<x;
    int num2=0;
    for(int i=0;i<arr.size();i++){
        if(mask&arr[i])
            num2^=arr[i]; 
    }
    int res = num1;
    num1 = num1^num2;
    num2 = temp^num1;

    cout<<num1<<", "<<num2<<endl;


    cin.close();
    return 0;
}