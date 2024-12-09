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

TreeNode* createTree(){
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    TreeNode*root = new TreeNode(data);
    root->left = createTree();
    root->right = createTree();
    return root;
}

void levelOrderTraversal(TreeNode* root){
    if(!root)
        return;
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        TreeNode*temp = q.front();
        q.pop();
        if(!temp){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
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

void preOrder(TreeNode*root){
    if(!root){
        return;
    }
    cout<<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(TreeNode*root){
    if(!root){
        return;
    }
    inOrder(root->left);
    cout<<root->val<<" ";
    inOrder(root->right);
}

void postOrder(TreeNode*root){
    if(!root){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->val<<" ";
}

pair<int, int> maxSumofNonAdjacentNodesHelper(TreeNode*&root){
    if(!root){
        return {0, 0};
    }
    pair<int, int> left = maxSumofNonAdjacentNodesHelper(root->left);
    pair<int, int> right = maxSumofNonAdjacentNodesHelper(root->right);
    int ans1 = root->val+left.second+right.second;
    int ans2 = left.first+right.first;

    cout<<"PAIR: {"<<ans1<<", "<<ans2<<"}\n";
    return {ans1, ans2};
}

int maxSumofNonAdjacentNodes(TreeNode*&root){
    pair<int, int> ans = maxSumofNonAdjacentNodesHelper(root);
    return max(ans.first, ans.second);
}

int main(){
    TreeNode* root = createTree();

    cout << "PreORDER: ";
    preOrder(root);
    cout << endl;
    cout << "InORDER: ";
    inOrder(root);
    cout << endl;
    cout << "PostORDER: ";
    preOrder(root);
    cout << endl;
    cout << "LevelORDER: \n";
    levelOrderTraversal(root);
    cout << endl;
    cout<<"MAXSUM of Non Adjacent nodes: "<<maxSumofNonAdjacentNodes(root);
    return 0;
}