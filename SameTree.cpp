#include <iostream>
#include <vector>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

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

    TreeNode(int x, TreeNode* left, TreeNode* right){
        left = left;
        right = right;
    }
};

TreeNode* buildTree(vector<int>& preorder,int& idx){
    idx++;
    if(preorder[idx] ==-1){
        return NULL;
    }
    TreeNode* n = new TreeNode(preorder[idx]);
    n->left = buildTree(preorder,idx);
    n->right = buildTree(preorder,idx);

    return n;
}

void traverse(TreeNode* p,TreeNode* q,int &ans){
    if(ans == 0){
        return ;
    }
    if(p == NULL && q == NULL){
        return;
    }else if(p==NULL && q!= NULL){
        ans =0;
        //cout<<"q has a value but p doesnt :"<<q->val<<"\n";
        return;
    }else if(p!= NULL && q==NULL){
        ans = 0;
        //cout<<"p has a value but q doesnt :"<<p->val<<"\n";
        return;
    }
    if(p->val == q->val){
        traverse(p->left,q->left,ans);
        traverse(p->right,q->right,ans);
    }else{
        ans = 0;
        return;
    }
}

bool isSameTree(TreeNode* p ,TreeNode* q){
    int ans = 1;
    //cout<<p->val<<" "<<q->val<<"\n";
    traverse(p,q,ans);
    if(ans==1){
        return true;
    }else{
        return false;
    }
}

void testCase(vector<int> a,vector<int>b){
    int a_idx = -1;
    int b_idx = -1;
    TreeNode* p = buildTree(a,a_idx);
    TreeNode* q = buildTree(b,b_idx);
    bool result = isSameTree(p,q);
    cout<<result<<"\n";
}

int main(){
    testCase({1,2,-1,-1,3,-1,-1},{1,2,-1,-1,3,-1,-1});
    testCase({1,2,-1,-1,-1},{1,-1,2,-1,-1});
    testCase({1,2,-1,-1,1,-1,-1},{1,1,-1,-1,2,-1,-1});
    return 0;
}

