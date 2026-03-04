#include <iostream>
#include <vector>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(){
        val = 0;
        left = NULL;
        right = NULL;
    }
    TreeNode(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
    TreeNode(int x,TreeNode* left, TreeNode* right){
        val = x;
        left = left;
        right = right;
    }
};

TreeNode* buildTree(vector<int>& inorder,int &idx){
    idx++;
    if(inorder.size()==0){
        return NULL;
    }
    if(inorder[idx] ==-1){
        return NULL;
    }
    TreeNode* n = new TreeNode(inorder[idx]);
    n->left = buildTree(inorder,idx);
    n->right = buildTree(inorder,idx);
    return n;
}

TreeNode* findIP(TreeNode* root){
    TreeNode* n = root->left;
    TreeNode* ip = n;
    while(n->right != NULL){
        if(n->right == root){
            ip = n;
            break;
        }
        n = n->right;
        ip = n;
    }
    return ip;
}

vector<int> inorderTraversal(TreeNode* n){
    vector<int>output;
    if(n== NULL){
        return output;
    }
    while(n!=NULL){
        if(n->left == NULL){
            output.push_back(n->val);
            n = n->right;
        }else{
            TreeNode* ip = findIP(n);
            if(ip->right== NULL){
                ip->right = n;//thread created
                n = n->left;
            }else{
                ip->right = NULL;//thread deleted
                output.push_back(n->val);
                n = n->right;
            }
        }
    }
    return output;
}


void testCase(vector<int> inorder){
    int idx = -1;
    TreeNode* root = buildTree(inorder,idx);
    vector<int>output = inorderTraversal(root);
    for(int val:output){
        cout<<val<<" ";
    }
    cout<<"\n";
}

int main(){
    testCase({1,-1,2,3,-1,-1,-1});
    testCase({1,2,4,-1,-1,5,6,-1,-1,7,-1,-1,3,-1,8,9,-1,-1,-1});
    testCase({-1,-1});
    testCase({1,-1,-1});
    return 0;
}

