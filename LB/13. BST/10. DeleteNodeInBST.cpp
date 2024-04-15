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
    while(data != -1){
        root = createBST(root, data);
        cin>>data;

    }
}

TreeNode* findElement(TreeNode*root, int key){
    if(!root){
        return NULL;
    }
    if(root->val == key){
        return root;
    }
    findElement(root->left, key);
    findElement(root->right, key);
}

int maxVal(TreeNode*root){
    if(!root){
        return NULL;
    }
    TreeNode*temp = root;
    while(temp->right){
        temp = temp->right;
    }
    return temp->val;
}

TreeNode* deleteNode(TreeNode*&root, int key){
       if(!root){
        return NULL;
       }
       if(root->val == key){
        if(!root->left && !root->right){
            TreeNode*temp = root;
            delete temp;
            return NULL;
        }
        else if(!root->left && root->right){
            TreeNode*temp = root;
            TreeNode*child = root->right;
            delete temp;
            return child;    
        }
        else if(root->left && !root->right){
            TreeNode*temp = root;
            TreeNode*child = root->left;
            delete temp;
            return child;  
        } else{
            int inOrderPre = maxVal(root->left);
            root->val = inOrderPre;
            root->left = deleteNode(root->left, inOrderPre);
            return root;
        }
    } else if(root->val>key){
        if(root->left)
            root->left = deleteNode(root->left, key);
        else
            return NULL;
    } else if(root->val<key){
        if(root->right)
            root->right = deleteNode(root->right, key);
        else    
            return NULL;
    }
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

int main(){
    TreeNode* root = NULL;
    inputData(root);
    cout<<endl;
    cout<<"Level order: \n";levelOrderTraversal(root);
    cout<<endl;
    cout<<"PreOrder: ";preOrder(root);
    cout<<endl;
    cout<<"InOrder: ";inOrder(root);
    cout<<endl;
    cout<<"PostOrder: ";postOrder(root);
    cout<<endl;
    int key = 100;
    cout<<endl;
    cout<<"Deleteing Node: "<<key<<endl;
    deleteNode(root, key);
    cout<<"NODE DELETED!\n";
    cout<<"Level order: \n";levelOrderTraversal(root);
    cout<<endl;
    cout<<"PreOrder: ";preOrder(root);
    cout<<endl;
    cout<<"InOrder: ";inOrder(root);
    cout<<endl;
    cout<<"PostOrder: ";postOrder(root);
    cout<<endl;
    return 0;
}