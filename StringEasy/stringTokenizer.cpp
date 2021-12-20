#include<bits/stdc++.h>
#include<unordered_set>

using namespace std;
/*
a string tokenizer breaks the string into an array of strings 
based on a delimiting character.
*/

vector<string> tokenizer(string str, string delim){
    unordered_set<char> delimSet;
    for(auto i: delim){
        delimSet.insert(i);
    }
    for(auto i: delimSet){
        cout<<"Delim SET: "<<i<<endl;
    }
    int startPtr = 0;
    vector<string> res;
    for(int i=0;i<str.size();i++){
       if(delimSet.find(str[i])!=delimSet.end()){
            string token = str.substr(startPtr,i-startPtr);
            if(!token.empty())
                res.push_back(token);
            startPtr = i+1;
            
       }
   }
   if(!str.substr(startPtr,str.size()-startPtr).empty())
    res.push_back(str.substr(startPtr,str.size()-startPtr));

   return res;
}

// H e l l o ,   h o w    a  r  e     y  o  u  ,     i  s     e  v  e  r  y  t  h  i  n  g     o  k  a  y  ?
// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38
int main(){
    ifstream cin("stringTokenizer.txt");    
    if(cin.fail())
    cout<<"Input from file failed";
    string str;
    getline(cin,str);
    string delim = ",";
    vector<string> ans = tokenizer(str,delim);
    for(auto i: ans){
        cout<<i<<endl;
    }
    cin.close();
    return 0;
}