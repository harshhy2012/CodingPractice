#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<string> commands(n);
    for(auto &com: commands){
        cin>>com;
    }
    int ans = 0;
    string neg = "--";
    string pos = "++";
    for(int i=0;i<n;i++){
        if(commands[i].find(neg) != std::string::npos){
            ans--;
        }
        else if(commands[i].find(pos) != std::string::npos){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}