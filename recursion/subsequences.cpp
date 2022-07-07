#include<bits/stdc++.h>

using namespace std;

void subsequences(string inp, string out){
    if(inp.empty()){
        cout<<out<<endl;
        return;
    }
    subsequences(inp.substr(1), out + inp[0]);
    subsequences(inp.substr(1), out);
}


int main(){
    string inp, out = "";
    cin>>inp;
    subsequences(inp, out);
    return 0;
}