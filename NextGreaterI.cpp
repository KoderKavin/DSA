#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1,vector<int> &nums2){
    stack<int> s;
    unordered_map<int,int> map;
    vector<int> output;
    int i = nums2.size();
    while(i>0){
        i--;
        while(s.size()>0){
            if(nums2[i]<nums2[s.top()]){
                map.insert({nums2[i],nums2[s.top()]});
                s.push(i);
                break;
            }else{
                s.pop();
            }
        }
        if(s.size()==0){
            map.insert({nums2[i],-1});
            s.push(i);
        }
    }
    for(int val:nums1){
        output.push_back(map.at(val));
    }
    return output;
}

void testCase(vector<int> nums1,vector<int> nums2){
    vector output = nextGreaterElement(nums1,nums2);
    for(int val: output){
        cout<<val<<" ";
    }
    cout<<endl;
}

int main(){
    testCase({4,1,2},{1,3,4,2});
    testCase({2,4},{1,2,3,4});

    return 0;
}