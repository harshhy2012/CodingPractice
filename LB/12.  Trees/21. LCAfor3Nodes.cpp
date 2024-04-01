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

TreeNode* lowestCommonAncestor(TreeNode* root, int node1, int node2, int node3) {
    if(!root){
        return NULL;
    }
    if(root->val == node1){
        return root;
    }
    if(root->val == node2){
        return root;
    }
    if(root->val == node2){
        return root;
    }
    
    TreeNode* leftAns = lowestCommonAncestor(root->left, node1, node2, node3);
    TreeNode* rightAns = lowestCommonAncestor(root->right, node1, node2, node3);

    if(!rightAns && leftAns){
        return leftAns;
    } else if(rightAns && !leftAns){
        return rightAns;
    } else if(leftAns && rightAns){
        return leftAns;
    } else{
        return NULL;
    }
}

int main(){
    TreeNode* root = buildTree();
    return 0;
}