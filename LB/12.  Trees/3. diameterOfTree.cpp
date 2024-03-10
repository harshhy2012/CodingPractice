#include<bits/stdc++.h>

using namespace std;

class Node{
  public: 
    int data;
    Node*left;
    Node*right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void preOrder(Node*root){
    if(!root){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node*root){
    if(!root){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void postOrder(Node*root){
    if(!root){
        return;
    }
    postOrder(root->left);
    cout<<root->data<<" ";
    postOrder(root->right);
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
// void levelOrderTraversal(Node*root){
//     queue<Node*> q;
//     q.push(root);
//     q.push(NULL);
//     while(!q.empty()){
//         Node* temp = q.front();
//         cout<<q.front()->data<<" ";
//         q.pop();
//         if(temp==NULL){
//             cout<<endl;
//             if(!q.empty()){
//                 q.push(NULL);
//             }
//         }
//         if(root->left){
//             q.push(root->left);
//         }
//         if(root->right){
//             q.push(root->right);
//         }

//     }
// }

Node* buildTree(){
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    Node* root = new Node(data);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

int main(){
    Node* root = buildTree();
    cout<<"BUILD hogya \n";
    preOrder(root);
    cout<<endl;
    inOrder(root);
    cout<<endl;
    postOrder(root);
    cout<<endl;
    levelOrderTraversal(root);
    cout<<"ye ni chalra\n";

    return 0;
}