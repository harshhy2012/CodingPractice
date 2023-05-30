#include<bits/stdc++.h>

using namespace std;

void removeAllSubStr(string& str, string &sub){
    if(str.size()<sub.size())
        return;

    int start = str.find(sub);
    cout<<"1st if done\n";

    if(start == string::npos)
        return;
    
    cout<<"2st if done\n";
    
    string left = str.substr(0, start);
    string right = str.substr(start+sub.size(), str.size());
    cout<<"LEFT: "<<left<<" || RIGHT: "<<right<<endl;
    cout<<"STR BEFORE ERASE: "<<str<<endl;
    str.erase(start, sub.size());
    cout<<"STR AFTER ERASE: "<<str<<endl;
    cout<<"SUB.size(): "<<sub.size()<<endl;
    removeAllSubStr(str, sub);
}


int main(){
    string str, sub;
    cin>>str>>sub;
    removeAllSubStr(str, sub);
    cout<<str<<endl;

    return 0;
}