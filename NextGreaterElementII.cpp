#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    int max_index = 0;
    int n = nums.size();
    stack<int> s;
    vector<int> output(n,-1);
    for(int i =0;i<n;i++){
        //cout<<"test1"<<endl;
        if(nums[i]>nums[max_index]){
            max_index = i;
        }
    }
    int i = max_index-1;
    int j = (i+n)%n;
    s.push(max_index);
    while(j!=max_index){
        //cout<<"test2: "<<i<<" "<<j<<endl;
        while(!s.empty()){
            //cout<<"test3"<<endl;
            if(nums[s.top()]>nums[j]){
                output[j] = nums[s.top()];
                break;
            }else{
                s.pop();
            }
        }
        s.push(j);
        i--;
        j = (i+n)%n;
    }
    return output;
}

void testCase(vector<int> nums){
    vector<int> result = nextGreaterElements(nums);
    for(int val:result){
        cout<<val<<" ";
    }
    cout<<endl;
}

int main(){
    testCase({1,2,1});
    testCase({1,2,3,4,3});

    return 0;
}