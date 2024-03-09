#include<bits/stdc++.h>

using namespace std;

class Node{
  public:
    int val;
    Node*left;
    Node*right;

    Node(int d){
        this->val = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree(){
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    } 
    Node* root = new Node(data);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

bool identical(Node* root1, Node* root2){
    bool leftIdentical;
    bool rightIdentical;
    if(!root1 && !root2){
        return true;
    }
    if((!root1 && root2) || (root1 && !root2)){
        return false;
    }
    if(root1->val == root2->val){
        leftIdentical = identical(root1->left, root2->left);
        rightIdentical = identical(root1->right, root2->right);
    } else{
        return false;
    }
    
    return true && leftIdentical && rightIdentical;
}

int main(){
    Node* root1 = buildTree();
    Node* root2 = buildTree();
    
    if(identical(root1, root2)){
        cout<<"INDENTICAL :) !\n";
    } else{
        cout<<"NOT IDENTICAL :( !\n";
    }

    return 0;
}