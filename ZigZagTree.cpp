#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(){
        val =0 ;
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
        right =right;
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
void swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}
void reverse(vector<int> &nums){
    for(int i =0;i<(nums.size()/2);i++){
        swap(nums[i],nums[nums.size()-i-1]);
    }
}
vector<vector<int>> zigzagLevelOrder(TreeNode* root){
    if(root ==NULL){
        return {};
    }
    queue<TreeNode*> q;
    vector<vector<int>> output;
    q.push(root);
    q.push(NULL);
    vector<int> temp;
    int parity = 0;
    while(!q.empty()){
        TreeNode* curr = q.front();
        q.pop();
        if(curr==NULL){
            if(parity==0){
                output.push_back(temp);
                parity =1;
            }else{
                reverse(temp);
                output.push_back(temp);
                parity = 0;
            }
            if(!q.empty()){
                //cout<<temp[0]<<"\n";
                temp = {};
                q.push(NULL);
                continue;
            }else{
                break;
            }
        }else{
            temp.push_back(curr->val);
            //cout<<curr->val<<" "; 
        }
        if(curr->left!= NULL){
            q.push(curr->left);
        }
        if(curr->right!= NULL){
            q.push(curr->right);
        }
    }
    return output;
}   

void testCase(vector<int> seq){
    int idx = -1;
    TreeNode* root = buildTree(seq,idx);
    vector<vector<int>> output = zigzagLevelOrder(root);
    for(vector<int> val:output){
        for(int val1: val){
            cout<<val1<<" ";
        }
        cout<<"|| ";
    }
    cout<<"\n";
}

int main(){
    testCase({3,9,-1,-1,20,15,-1,-1,7,-1,-1});
    testCase({1,-1,-1});
    testCase({-1,-1});
    return 0;
}