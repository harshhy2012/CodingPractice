#include<bits/stdc++.h>

using namespace std;

void printDigits(string s, unordered_map<char,string> words){
    if(s.empty()){
        return;
    }

    cout<<words[s[0]]<<" ";
    printDigits(s.substr(1,s.size()-1), words);
    
}

int main(){
    unordered_map<char, string> words = {
        {'0', "zero"},
        {'1', "one"},
        {'2', "two"},
        {'3', "three"},
        {'4', "four"},
        {'5', "five"},
        {'6', "six"},
        {'7', "seven"},
        {'8', "eight"},
        {'9', "nine"}
    };
    string s;
    cin>>s;

    printDigits(s, words);


    return 0;
}