#include<bits/stdc++.h>

using namespace std;

string zigzag(string s, int numRows){
    if(numRows>=s.size() || numRows == 1){
        return s;
    }
    vector<string> zig(numRows); 
    string ans = "";
    int row = 0;
    int i = 0;
    bool rev = false;
    while(row<numRows && i<s.size()){
        zig[row].push_back(s[i]);
        if(!rev)
            row++;
        else
            row--;
        if(row==numRows-1){
            rev = true;
        }
        if(row==0){
            rev = false;
        }
        i++;
    }

    for(auto str: zig){
        ans+=str;
    }    
    return ans;
}

int main(){
    int numRows;
    string s;
    cin>>s>>numRows;
    cout<<zigzag(s, numRows)<<endl;
    return 0;
}