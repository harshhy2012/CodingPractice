#include<bits/stdc++.h>

using namespace std;

void combinations(string inp, unordered_map<char, string> keypad){
    
}

int main(){
    ifstream cin("keypad.txt");
    if(cin.fail())
        cout<<"Input from file failed";
    string s;
    unordered_map<char, string> keypad = {
                                        {'1', ""},
                                        {'2', "abc"},
                                        {'3', "def"},
                                        {'4', "ghi"},
                                        {'5', "jkl"},
                                        {'6', "mno"},
                                        {'7', "pqrs"},
                                        {'8', "tuv"},
                                        {'9', "wxyz"},
                                        {'0', ""},
    };




    cin.close();
    return 0;
}