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

void getStringWithChar(TrieNode*&root, vector<string>&charStrings, string&charString){
    if(root->isEndOfWord){
        charStrings.push_back(charString);
    }
    for(char ch='a'; ch <= 'z';ch++){
        int idx = ch-'a';
        if(root->children[idx]){
            charString.push_back(ch);
            getStringWithChar(root->children[idx], charStrings, charString);
            charString.pop_back();
        }
    }
}

vector<vector<string>> getSuggestions(TrieNode*&root, string key){
    TrieNode* prev = root;
    vector<vector<string>> ans; 
    string charString = "";

    for(int i=0;i<key.size();i++){
        char lastCh = key[i];

        int idx = lastCh-'a';
        TrieNode*curr = prev->children[idx];
            
        if(!curr){
            break;
        }
        else{
            vector<string> charStrings;
            charString.push_back(lastCh);
            getStringWithChar(curr, charStrings, charString);
            ans.push_back(charStrings);
            prev = curr;
        }
    }
    return ans;
}


int main(){
    TrieNode* root = new TrieNode('-');
    vector<string> strings = {
        "love", "lover", "loving", "lane", "lost", "lord"
    };
    string key = "loved";
    for(auto str: strings){
        insertWord(root, str);
    }

    vector<vector<string>> ans = getSuggestions(root, key);
    cout<<"\nChala\n";
    for(auto i: ans){
        cout<<"answers: \n";
        for(auto j:i){
            cout<<j<<", ";
        }
        cout<<endl;
    }


    return 0;
}