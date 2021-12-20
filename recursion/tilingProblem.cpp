#include<bits/stdc++.h>

using namespace std;

int tilingSol(int n){
    if(n<=0)
        return 0;
    if(n<4)
        return 1;
    if(n==4){
        return 2;
    }
    
    return tilingSol(n-1)+tilingSol(n-4);

}

int main(){
    ifstream cin("tilingProblem.txt");
    if(cin.fail())
        cout<<"Input from file failed";
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<tilingSol(n)<<endl;
    }
    cin.close();
    return 0;
}