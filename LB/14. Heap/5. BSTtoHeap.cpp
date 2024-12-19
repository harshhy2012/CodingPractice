#include<bits/stdc++.h>

using namespace std;

class TreeNode{
    public: 
        int val;
        TreeNode*left;
        TreeNode*right;

        TreeNode(int data){
            val = data;
            left = NULL;
            right = NULL;
        }

};


TreeNode* createBST(TreeNode*&root, int data){
    if(!root){
        root = new TreeNode(data);
        return root;
    }
    if(root->val > data){
        createBST(root->left, data);
    } else{
        createBST(root->right, data);
    }
    return root;
}

void inputData(TreeNode*&root){
    int data;
    cin>>data;
    while(data!=-1){
        root = createBST(root, data);
        cin>>data;
    }
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
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->val<<" ";
}

void levelOrder(TreeNode*root){
    if(!root)
        return;
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

int main(){
    TreeNode*root = NULL;
    inputData(root);

    cout<<endl;
    cout<<"PREORDER: ";
    preOrder(root);
    cout<<endl;
    cout<<"INORDER: ";
    inOrder(root);
    cout<<endl;
    cout<<"POSTORDER: ";
    postOrder(root);
    cout<<endl;
    cout<<"LevelOrder: ";
    levelOrder(root);
    cout<<endl;

    return 0;
}