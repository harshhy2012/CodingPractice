#include<bits/stdc++.h>

using namespace std;

class TreeNode{
  public: 
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){
        this->val = data;
        this->left = NULL;
        this->right = NULL;
    }
};

TreeNode* buildTree(){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }
    TreeNode* root = new TreeNode(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void preOrder(TreeNode* root){
    if(!root){
        return;
    }
    cout<<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(TreeNode* root){
    if(!root){
        return;
    }
    inOrder(root->left);
    cout<<root->val<<" ";
    inOrder(root->right);
}

void postOrder(TreeNode* root){
    if(!root){
        return;
    }
    cout<<root->val<<" ";
    postOrder(root->left);
    postOrder(root->right);
}

void levelOrderTraversal(TreeNode* root){
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
            cout<<endl;
            if(!q.empty())
                q.push(NULL);
        } else{
            cout<<temp->val<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

void helper(TreeNode* root, int b, map<int, vector<int>>& m){
    if(!root){
        return;
    }
    if(m.find(b) == m.end()){
        m.insert({b, {root->val}});
    } else{
        m[b].push_back(root->val);
    }
    
    helper(root->left, b-1, m);
    helper(root->right, b+1, m);
}

map<int, vector<int>> verticalTraversal(TreeNode*root){
    map<int, vector<int>> ans;
    helper(root, 0, ans);
    return ans;
}



int main(){
    TreeNode * root = buildTree();
    cout<<"PreORDER: ";preOrder(root);cout<<endl;
    cout<<"InORDER: ";inOrder(root);cout<<endl;
    cout<<"PostORDER: ";preOrder(root);cout<<endl;
    cout<<"LevelORDER: \n";levelOrderTraversal(root);cout<<endl;
    map<int, vector<int>> ans = verticalTraversal(root);
    cout<<"VerticalORDER: \n";
    for(auto i: ans){
        cout<<i.first<<": ";
        for(auto j: i.second){
            cout<<j<<" ";
        }
    }
    return 0;
}