#include<bits/stdc++.h>

using namespace std;

class Node{
  public: 
    int data;
    Node*left;
    Node*right;


    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree(){
    int data;
    cin>>data;
    if(data == -1){
        return NULL;
    }
    Node* root = new Node(data);

    root->left = buildTree();
    root->right = buildTree();

    return root;
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node*temp = q.front();

        cout<<temp->data<<" ";
        q.pop();

        if(temp==NULL){
            cout<<endl;
            if(!q.empty())
                q.push(NULL);
        }
        if(temp->left){
            q.push(temp->left);
        } 
        if(temp->right){
            q.push(temp->right);
        }
     
    }
}

Node* inOrder(Node* root){
    //LNR
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

Node* preOrder(Node* root){
    //NLR
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    inOrder(root->left);
    inOrder(root->right);
}

Node* postOrder(Node* root){
    //LRN
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    inOrder(root->right);
    cout<<root->data<<" ";
}

int height(Node*root){
    if(!root){
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    int maxHeight = 1+max(leftHeight, rightHeight);
    return maxHeight;  
}

int diameter(Node*root){
    if(!root){
        return 0;
    }

    int op1 = diameter(root->left);
    int op2 = diameter(root->left);
    int op3 = height(root->left)+1+height(root->right);

    int ans = max(op1, max(op2, op3));

    return ans-1;
}

int main(){
    Node *root = NULL;
    root = buildTree();
    levelOrderTraversal(root);
    return 0;
}