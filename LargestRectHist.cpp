#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    //cout<<"test1"<<endl;
    int n = heights.size();
    vector<int> r(n,n);
    vector<int> l(n,-1);
    stack<int> s,stemp;
    for(int i =n-1;i>=0;i--){
        //cout<<"test3"<<heights[i]<<endl;
        while(!s.empty()){
            if(heights[s.top()]<heights[i]){
                r[i] = s.top();
                break;
            }else{
                s.pop();
            }
        }
        s.push(i);
    }
    s = stemp;
    //cout<<"test2"<<endl;
    for(int i = 0;i<n;i++){
        while(!s.empty()){
            if(heights[s.top()]<heights[i]){
                l[i] = s.top();
                break;
            }else{
                s.pop();
            }
        }
        s.push(i);
    }
    int max = 0;
    int w,a;
    for(int i =0;i<n;i++){
        w = r[i]-l[i]-1;
        a = heights[i]*w;
        //cout<<a<<endl;
        if(a>max){
            max = a;
        }
    }
    return max;
}

void testCase(vector<int> heights){
    int result = largestRectangleArea(heights);
    cout<<result<<endl;
}

int main(){
    testCase({2,1,5,6,2,3});
    testCase({2,4});

    return 0;
}