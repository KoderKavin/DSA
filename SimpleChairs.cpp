#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

//O(2^n) 
int chairs(vector<int> &nums,int idx,unordered_set<int> &marks){
    if(idx >=nums.size() || marks.find(idx)!=marks.end()){
        return 0;
    }   
    if(nums[idx]-1<=idx){
        return 1 + chairs(nums,idx+1,marks);
    }else{
        marks.insert(nums[idx]-1);
        int y = 1+ chairs(nums,idx+1,marks);
        //cout<<y<<" ";
        marks.erase(nums[idx]-1);
        int x = chairs(nums,idx+1,marks);
        //cout<<x<<" ";
        return max(x,y); 
    }   
} 


int helper(vector<int> &nums){
    unordered_set<int>marks;
    int result = chairs(nums,0,marks);
    return result;
}

//O(n)
int singlePass(vector<int> &nums){
    int sum = 0;
    for(int i =0;i<nums.size();i++){
        if(nums[i]-1<=i){
            sum++;
        }
    }
    return sum;
}
// void testCase(vector<int> nums){
//     unordered_set<int>marks;
//     int result = chairs(nums,0,marks);
//     cout<<result<<endl;
// }

int main(){
    // testCase({3,2,1});
    //testCase({4,3,2,5,1});
    // testCase({4,2,1,3});
    // testCase({2,3,4,1});
    int t;
    cin>>t;
    vector<int>output;
    for(int i =0;i<t;i++){
        int n;
        cin>>n;
        vector<int>input;
        for(int j = 0;j<n;j++){
            int temp;
            cin>>temp;
            input.push_back(temp);
        }
        int result = singlePass(input);
        output.push_back(result);
    }
    for(int val:output){
        cout<<val<<endl;
    }
}
