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

int lineSum(TreeNode* n,int &maxSum){
    if(n==NULL){
        return 0;
    }
    int left = lineSum(n->left,maxSum);
    int right = lineSum(n->right,maxSum);
    int m = max(left,right);
    int curr;
    if(m>=0){
        curr = n->val + m;
    }else{
        curr = n->val;
    }
    int sum = n->val;
    vector<int> temp = {left,right};
    for(int i = 0;i<temp.size();i++){
        if(temp[i]>0){
            sum+= temp[i];
        }
    }
    if(sum>maxSum){
        maxSum = sum;
    }
    return curr;
}

int maxPathSum(TreeNode* root){
    int maxSum = root->val;
    int line = lineSum(root,maxSum);
    return maxSum;
}

void testCase(vector<int> seq){
    int idx = -1;
    TreeNode* root = buildTree(seq,idx);
    int result = maxPathSum(root);
    cout<<result<<"\n";
}

int main(){
    testCase({1,2,-1,-1,3,-1,-1});
    testCase({-10,9,-1,-1,20,15,-1,-1,7,-1,-1});
    testCase({-3,-1,-1});
    testCase({1,-2,-1,-1,3,-1,-1});
    testCase({9,6,-1,-1,-3,-6,-1,-1,2,2,-6,-6,-1,-1,-1,-6,-1,-1,-1});
    return 0;
}

