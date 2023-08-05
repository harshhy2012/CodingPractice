#include<bits/stdc++.h>

using namespace std;

void genCombination(vector<string> &ans, string &digits, int index, string output, unordered_map<char, string>&keypad){     
    if(index>=digits.size()){
        ans.push_back(output);
        return;
    }
    char dig = digits[index];
    string values = keypad[dig];
    for(int i=0;i<values.size();i++){
        // output.push_back(values[i]);
        genCombination(ans, digits, index+1, output + values[i], keypad);
        // output.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> ans;
    if(digits.size()==0){
        return ans;
    }
    unordered_map<char, string> keypad = {
                                            {'2', "abc"},
                                            {'3', "def"},
                                            {'4', "ghi"},
                                            {'5', "jkl"},
                                            {'6', "mno"},
                                            {'7', "pqrs"},
                                            {'8', "tuv"},
                                            {'9', "wxyz"}
    };
    string output = "";
    int index = 0;
    genCombination(ans, digits, index, output, keypad);
    return ans;
}

int main(){
    string digits;
    cin>>digits;
    vector<string> ans = letterCombinations(digits);
    for(auto i: ans){
        cout<<i<<" ";    } 
    return 0;
}