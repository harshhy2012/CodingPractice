#include <bits/stdc++.h>

using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isEndOfWord;
    TrieNode(char d){
        this->data = d;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isEndOfWord=false;
    }
};

void insertWord(TrieNode*&root, string word){
    if(word.size() == 0){
        root->isEndOfWord = true;
        return;
    }
    char ch = word[0];
    int idx = ch-'a';
    TrieNode*child;
    if(root->children[idx]){
        child = root->children[idx];
    } else{
        child = new TrieNode(ch);
        root->children[idx] = child;
    }
    insertWord(child, word.substr(1));  
}

bool searchWord(TrieNode*root, string word){
    if(word.size()==0){
        return root->isEndOfWord;
    }
    char ch = word[0];  
    int idx = ch-'a';   
    if(root->children[idx]){
        return searchWord(root->children[idx], word.substr(1));
    } else{
        return false;
    }
}

void deleteWord(TrieNode*&root, string word){
    if(word.size()==0){
        root->isEndOfWord = false;
        return;
    }
    char ch = word[0];
    int idx = ch-'a';
    if(root->children[idx]){
        deleteWord(root->children[idx], word.substr(1));
        if(root->children[idx]->isEndOfWord==false){
            delete root->children[idx];
            root->children[idx]=NULL;
        }
    }
}

void LCPHelper(TrieNode*root, string &ans){
    if(root->isEndOfWord){
        return;
    }
    int count=0;
    int idx;
    for(int i=0;i<26;i++){
        if(root->children[i]){
            count++;
            idx=i;
        }
    }
    if(count>1 || count==0){
        return;
    }
    ans.push_back('a'+idx);
    LCPHelper(root->children[idx], ans);
}

string longestCommonPrefix(vector<string>&v){
    TrieNode* root = new TrieNode('-');
    for(auto str: v){
        insertWord(root, str);
    }
    string ans = "";
    LCPHelper(root, ans);
    return ans;
}

int main()
{
    vector<string> v = {
        "apple",
        "app",
        "appil"
    };

    cout<<longestCommonPrefix(v)<<endl;

    return 0;
}