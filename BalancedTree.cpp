#include <iostream>
#include <vector>
using namespace std;

class TreeNode{
public :
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
    TreeNode(int x,TreeNode* left,TreeNode* right){
        val = x;
        left = left;
        right = right;
    }  
};

TreeNode* buildTree(vector<int> seq,int &idx){
    idx++;
    if(seq[idx]==-1){
        return NULL;
    }
    TreeNode* n = new TreeNode(seq[idx]);
    n->left = buildTree(seq,idx);
    n->right = buildTree(seq,idx);
    return n;
}
int max(int a,int b){
    if(a>=b){
        return a;
    }else{
        return b;
    }
}
int height(TreeNode* n,int &ans){
    if(n==NULL){
        return 0;
    }
    int l = height(n->left,ans);
    int r = height(n->right,ans);
    int h = 1 + max(l,r);
    if(l>r+1 || r>l+1){
        ans = 0;
    }
    return h;
}

bool isBalanced(TreeNode* root){
    int ans = 1;
    int root_height = height(root,ans);
    if(ans==1){
        return true;
    }else{
        return false;
    }
}

void testCase(vector<int> seq){
    int idx = -1;
    TreeNode* root = buildTree(seq,idx);
    bool result = isBalanced(root); 
    cout<<result<<"\n";
}

int main(){
    testCase({3,9,-1,-1,20,15,-1,-1,7,-1,-1});
    testCase({1,2,3,4,-1,-1,4,-1,-1,3,-1,-1,2,-1,-1});
    return 0;   
}