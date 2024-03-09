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

void solve(TreeNode*&root, int&targetSum, int&sum,  vector<int>&temp, vector<vector<int>>&ans){
    if(!root){
        return;
    }
    sum+=root->val;
    temp.push_back(root->val);
    // cout<<"SUM: "<<sum<<endl;
    // cout<<"temp: ";
    // for(auto i: temp){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    if(!root->right && !root->left){
        if(sum==targetSum){
            ans.push_back(temp);
        }
    }
    solve(root->left, targetSum, sum, temp, ans);
    solve(root->right, targetSum, sum, temp, ans);
    sum-=root->val;
    temp.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

    vector<vector<int>> ans;
    int sum = 0;
    vector<int> temp;
    solve(root, targetSum, sum, temp, ans);
    return ans;
}

int main(){
    TreeNode* root = buildTree();
    int targetSum = 22;
    vector<vector<int>> ans = pathSum(root, targetSum);
    for(auto i: ans){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}