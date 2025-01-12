#include<bits/stdc++.h>

using namespace std;

class TrieNode{
    public:
        char data;
        TrieNode*children[26];
        bool isTerminal;

        TrieNode(char d){
            this->data = d;
            for(int i=0;i<26;i++){
                children[26] = NULL;
            }
            this->isTerminal = false;
        }
};

void insertWord(TrieNode*&root, string word){
    if(word.size() == 0){
        root->isTerminal = true;
        return;
    } 
    char ch = word[0];
    int idx = ch-'a';
    TrieNode* child;
    if(root->children[idx] != NULL){
        child = root->children[idx];
    }
    else{
        child = new TrieNode(ch);
        root->children[idx] = child;
    }

    insertWord(child, word.substr(1));
}

bool searchWord(TrieNode*root, string word){
    if(word.size()==0){
       return root->isTerminal;
    }

    char ch = word[0];
    int idx = ch-'a';
    TrieNode* child;

    if(root->children[idx] !=NULL){
        child = root->children[idx];
    } else{
        return false;
    }

    return searchWord(child, word.substr(1));
}

void deleteWord(TrieNode*&root, string word){
    if(word.size()==0){
        root->isTerminal = false;
        return;
    }
    char ch = word[0];
    int idx = ch-'0';
    TrieNode* child = root->children[idx];

    deleteWord(child, word.substr(1));
}

int main(){
    TrieNode* root = new TrieNode('/0');
    
    insertWord(root, "coding");

    return 0;
}