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

int height(Node* root){
    if(!root){
        return 0;
    }
    int lH = height(root->left);
    int rH = height(root->right);

    return 1+max(lH,rH);
}

bool  balancedTree(Node* root) {

    if(!root){
        return true;
    }
    int lH = height(root->right);
    int rH = height(root->right);
    bool ans1 = abs(lH-rH)<=1;
    
    bool leftBal = balancedTree(root->left);
    bool rightBal = balancedTree(root->right);

    return ans1 && leftBal && rightBal;
}


int main(){
    Node* root = buildTree();

    
    if(balancedTree(root)){
        cout<<"BALANCED TREE :) !\n";
    } else{
        cout<<"UNBALANCED TREE :( !\n";
    }

    return 0;
}