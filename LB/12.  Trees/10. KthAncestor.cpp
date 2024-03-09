#include<bits/stdc++.h>

using namespace std;

class TreeNode{
  public:
    int val;
    TreeNode*left;
    TreeNode*right;

    TreeNode(int d){
        this->val = d;
        this->left = NULL;
        this->right = NULL;
    }
};

TreeNode* buildTree(){
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    } 
    TreeNode* root = new TreeNode(data);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}


void levelOrderTraversal(TreeNode*root){
    if(!root){
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        TreeNode* temp = q.front();
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

bool KthAncestor(TreeNode* root, int p, int&k) {
    if(!root){
        return false;
    }
    if(root->val == p){
        return true;
    }
    int leftAns = KthAncestor(root->left, p, k);
    int rightAns = KthAncestor(root->right, p, k);

    if(leftAns || rightAns){
        k--;
    }

    if(k==0){
        cout<<root->val;
        k=-1;
    }
    return leftAns || rightAns;
}

int main(){
    TreeNode* root = buildTree();
    int p = 4;
    int k = 1;
    KthAncestor(root, p,k);
    return 0;
}