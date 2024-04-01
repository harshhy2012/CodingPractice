#include <bits/stdc++.h>

using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        this->val = data;
        this->left = NULL;
        this->right = NULL;
    }
};

TreeNode *buildTree()
{
    int d;
    cin >> d;
    if (d == -1)
    {
        return NULL;
    }
    TreeNode *root = new TreeNode(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void preOrder(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

void postOrder(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    cout << root->val << " ";
    postOrder(root->left);
    postOrder(root->right);
}

void levelOrderTraversal(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();
        if (!temp)
        {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << temp->val << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void topView(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    map<int, int> topNode;
    queue<pair<TreeNode *, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<TreeNode *, int> temp = q.front();
        q.pop();

        TreeNode *frontNode = temp.first;
        int hd = temp.second;
        if (topNode.find(hd) == topNode.end())
        {
            topNode.insert(make_pair(hd, frontNode->val));
        }

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, hd - 1));
        }
        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, hd + 1));
        }
    }

    for (auto i : topNode)
    {
        cout << i.second << " ";
    }
    cout << endl;
}

void bottomView(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    map<int, int> bottomNode;
    queue<pair<TreeNode *, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<TreeNode *, int> temp = q.front();
        q.pop();

        TreeNode *frontNode = temp.first;
        int hd = temp.second;

        bottomNode[hd] = frontNode->val;

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, hd - 1));
        }
        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, hd + 1));
        }
    }

    for (auto i : bottomNode)
    {
        cout << i.second << " ";
    }
    cout << endl;
}

void leftHelper(TreeNode* root, vector<int>& ans, int lvl){
    if(!root){
        return;
    }
    if(lvl == ans.size()){
        ans.push_back(root->val);
    }
    leftHelper(root->left, ans, lvl+1);
    leftHelper(root->right, ans, lvl+1);
    
}

void rightHelper(TreeNode* root, vector<int>& ans, int lvl){
    if(!root){
        return;
    }
    if(lvl == ans.size()){
        ans.push_back(root->val);
    }
    rightHelper(root->right, ans, lvl+1);
    rightHelper(root->left, ans, lvl+1);
    
}

void leftView(TreeNode *root)
{
    if(!root){
        return;
    }
    vector<int> ans;
    leftHelper(root, ans, 0);
    for(auto i: ans){
        cout<<i<<" ";
    }
}



void rightView(TreeNode *root)
{
     if(!root){
        return;
    }
    vector<int> ans;
    rightHelper(root, ans, 0);
    for(auto i: ans){
        cout<<i<<" ";
    }
}

int main()
{
    TreeNode *root = buildTree();
    cout << "PreORDER: ";
    preOrder(root);
    cout << endl;
    cout << "InORDER: ";
    inOrder(root);
    cout << endl;
    cout << "PostORDER: ";
    preOrder(root);
    cout << endl;

    cout << "TOPVIEW: ";
    topView(root);
    cout << endl;
    cout << "BottomVIEW: ";
    bottomView(root);
    cout << endl;
    cout << "LeftVIEW: ";
    leftView(root);
    cout << endl;
    cout << "RightVIEW: ";
    rightView(root);
    cout << endl;

    cout << "LevelORDER: \n";
    levelOrderTraversal(root);
    cout << endl;

    return 0;
}