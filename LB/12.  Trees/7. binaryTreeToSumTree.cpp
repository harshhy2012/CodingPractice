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

int buildSumTree(Node*&root){
    if(!root){
        return 0;
    }
    int leftVal = buildSumTree(root->left);
    int rightVal = buildSumTree(root->right);
    root->val += leftVal+rightVal;
    return root->val; 
}

void levelOrderTraversal(Node*root){
    if(!root){
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(!temp){
            cout<<"\n";
            if(!q.empty()){
                q.push(NULL);
            }
        } else{
            cout<<temp->val<<" ";
            if(temp->left)
             q.push(temp->left);
            
            if(temp->right)
                q.push(temp->right);
        }
    }
}

int main(){
    Node* root = buildTree();   
    levelOrderTraversal(root);
    cout<<endl;
    buildSumTree(root);
    levelOrderTraversal(root);
    cout<<endl;
    return 0;
}