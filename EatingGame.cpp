#include <iostream>
#include <vector>
using namespace std;

int max(vector<int>& nums){
    int result = nums[0];
    for(int i =0;i<nums.size();i++){
        if(result<nums[i]){
            result = nums[i];
        }
    }
    return result;
}

int count(vector<int>& nums,int target){
    int count = 0;
    for(int i =0;i<nums.size();i++){
        if(nums[i]==target){
            count++;
        }
    }
    return count;
}

int eatingGame(vector<int>& nums){
    int final_count = -1;
    int target = max(nums);
    final_count = count(nums,target);
    return final_count;
}

int main(){
    int t;
    cin>>t;
    vector<int>output;
    for(int i =0;i<t;i++){
        int n;
        vector<int> input;
        cin>>n;
        for(int j=0;j<n;j++){
            int temp;
            cin>>temp;
            input.push_back(temp);
        }
        int result = eatingGame(input);
        output.push_back(result);
    }

    for(int val:output){
        cout<<val<<"\n";
    }
}