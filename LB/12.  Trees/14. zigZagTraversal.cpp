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

void zigzagTraversal(TreeNode*root){
    if(!root){
        return;
    }
    int lvl = 0;
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    stack<TreeNode*> st;
    while(!q.empty()){
        TreeNode* temp = q.front();
        TreeNode* temp2 = st.top();
        q.pop();
        if(!temp){
            cout<<endl;
            lvl++;
            if(!q.empty())
                q.push(NULL);
        }   else{
           
            if(lvl%2==0){
                cout<<temp->val<<" ";
                if(temp->left){
                    
                    q.push(temp->left);
                }
                if(temp->right){
                    st.push(temp->right);
                    q.push(temp->right);
                }
                    
            } else{
                cout<<temp2->val<<" ";
                st.pop();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            
        } 
    }
}

int main(){
    TreeNode * root = buildTree();
    cout<<"PreORDER: ";preOrder(root);cout<<endl;
    cout<<"InORDER: ";inOrder(root);cout<<endl;
    cout<<"PostORDER: ";preOrder(root);cout<<endl;
    cout<<"LevelORDER: \n";levelOrderTraversal(root);cout<<endl;
    cout<<"ZIGZAGORDER: \n";zigzagTraversal(root);cout<<endl;
    return 0;
}