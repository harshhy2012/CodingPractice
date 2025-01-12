#include<bits/stdc++.h>

using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode*children[26];
    bool isEndOfWord;

    TrieNode(char d){
        this->data = d;
        for(auto& child: this->children){
            child = NULL;
        }
        this->isEndOfWord = false;
    }
};

void insertWord(TrieNode*&root, string word){
    if(word.size()==0){
        root->isEndOfWord = true;
        return;
    }
    char ch = word[0];
    int idx = ch-'a';
    TrieNode* child;
    if(root->children[idx]){
        child = root->children[idx];
    } else{
        child = new TrieNode(ch);
        root->children[idx] = child; 
    }
    insertWord(child, word.substr(1));
}

bool searchWord(TrieNode*&root, string word){
    if(word.size()==0)
    {
        return root->isEndOfWord;
    }
    char ch = word[0];
    int idx = ch-'a';
    TrieNode*child;
    if(root->children[idx]){
        return searchWord(root->children[idx], word.substr(1));
    } else{
        return false;
    }
}

void deleteWord(TrieNode*&root, string word){
    if(word.size() == 0){
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

vector<vector<string>> getSuggestions(TrieNode*&root, string key){
    c   
}


int main(){
    TrieNode* root = new TrieNode('-');
    vector<string> strings = {
        "love", "lover", "loving", "lane", "last", "lost", "lord"
    };
    string key = "loved";
    for(auto str: strings){
        insertWord(root, str);
    }



    return 0;
}