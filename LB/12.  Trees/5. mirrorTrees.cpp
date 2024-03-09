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

bool isSymmetric(Node* root) {
    if(!root){
        return true;
    }
    return check(root->left, root->right);
}

bool check(Node* root1, Node* root2){
    bool leftMirror;
    bool rightMirror;
    if(!root1 && !root2){
        return true;
    }
    if(!root1 || !root2){
        return false;
    }
    if(root1->val == root2->val){
        leftMirror = check(root1->left, root2->right);
        rightMirror = check(root1->right, root2->left);
    } else{
        return false;
    }
    
    return leftMirror && rightMirror;
}

int main(){
    Node* root = buildTree();

    
    if(isSymmetric(root)){
        cout<<"MIRROR TREE :) !\n";
    } else{
        cout<<"NOT A MIRROR TREE :( !\n";
    }

    return 0;
}