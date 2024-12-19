#include<bits/stdc++.h>

using namespace std;

class TreeNode{
    public: 
        int val;
        TreeNode*left;
        TreeNode*right;

        TreeNode(int data){
            this->val = data;
            this->left = NULL;
            this->right = NULL;
        }
};

TreeNode* buildTree(){
    int data;
    cin>>data;
    if(data == -1){
        return NULL;
    } else{
        TreeNode* newNode = new TreeNode(data);
        newNode->left = buildTree();
        newNode->right = buildTree();
        return newNode;
    }
}

int height(TreeNode* root){
    if(!root){
        return 0;
    }
    return 1+max(height(root->left), height(root->right));
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

pair<int, bool> isHeap(TreeNode* root){
    if(!root){
        return {INT_MIN,true};
    }
    if(!root->left && !root->right){
        return {root->val, true};
    }

    pair<int, bool> left = isHeap(root->left);
    pair<int, bool> right = isHeap(root->right);

    bool curr = left.first < root->val && right.first < root->val;
    return {root->val, left.second && right.second && curr};
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
    TreeNode* root = NULL;
    root = buildTree();

    cout<<"Height of Tree: "<< height(root) << endl;

    heapify(root);

    cout<<"Level order Traversal: \n";
    levelOrderTraversal(root);
    cout<<endl;


    pair<int, bool> ans = isHeap(root);    

    if(ans.second){
        cout<<" the tree is a heap \n";
    } else{
        cout<<" not a heap! \n";
    }


    return 0;
}