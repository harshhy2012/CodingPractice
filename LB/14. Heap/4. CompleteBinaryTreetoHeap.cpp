#include<bits/stdc++.h>

using namespace std;

class TreeNode{

    public: 
    int val;
    TreeNode*left;
    TreeNode*right;

    TreeNode(){
        val = 0;
        left = NULL;
        right = NULL;
    }

    TreeNode(int data){
        val = data;
        left = NULL;
        right = NULL;
    }

};

TreeNode* BuildTree(){
    int data;
    cin>>data;
    TreeNode* newNode;
    if(data == -1)
        return NULL;
    else{
        newNode = new TreeNode(data);
        newNode->left = BuildTree();
        newNode->right = BuildTree();
        return newNode;
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
    preOrder(root->left);
    cout<<root->val<<" ";
    preOrder(root->right);
}

void postOrder(TreeNode*root){
    if(!root){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->val<<" ";
}

int heightOfTree(TreeNode*root){
    if(!root){
        return 0;
    }
    return heightOfTree(root->left) + heightOfTree(root->right) + 1;
}

void levelOrderTraversal(TreeNode* root){
    if(!root){
        return;
    }
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
        }  else{
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

void heapify(TreeNode*&root){
        
        if(!root || (!root->right && !root->left)){
            return;
        }

        

        heapify(root->left);
        
        heapify(root->right);

        int left = root->left ? root->left->val : INT_MIN;
        int right = root->right ? root->right->val : INT_MIN;
        TreeNode* maxNode = root;
        int maxNum = root->val;
        if(left > maxNum){
            maxNum = left;
            maxNode = root->left;
        }
        if(right > maxNum){
            maxNum = right;
            maxNode = root->right;
        }
        if(maxNum == root->val){
            return;
        }
        if(maxNum == left){
            swap(root->val, root->left->val);
            heapify(maxNode);
        } else{
            swap(root->val, root->right->val);
            heapify(maxNode);
        }

    }

int main(){
    TreeNode* root;
    root = BuildTree();

    cout<<endl;
    levelOrderTraversal(root);
    cout<<endl;
    heapify(root);
    levelOrderTraversal(root);
    cout<<endl;
      
    return 0;
}