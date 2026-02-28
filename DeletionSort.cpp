#include <iostream>
#include <vector>
using namespace std;

int deleteSort(vector<int> &nums){
    for(int i =0;i<nums.size()-1;i++){
        if(nums[i+1]<nums[i]){
            return 1;
        }
    }
    return nums.size();
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
        int result = deleteSort(input);
        output.push_back(result);
    }

    for(int val:output){
        cout<<val<<"\n";
    }
}   