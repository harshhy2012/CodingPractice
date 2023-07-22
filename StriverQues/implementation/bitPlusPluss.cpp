#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<string> ins(n);
    for(auto &str: ins){
        cin>>str;
    }
    int x = 0;
    for(int i=0;i<n;i++){
        if(ins[i][1] == '+'){
            x++;
        }
        else{
            x--;
        }
    }

    cout<<x<<endl;

    return 0;
}