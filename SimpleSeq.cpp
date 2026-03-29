#include <iostream>
#include <vector>
using namespace std;

vector<int> func(int n){
    vector<int> output;
    for(int i = n;i>0;i--){
        output.push_back(i);
    }
    return output;
}

int main(){
    int t;
    cin>>t;
    vector<vector<int>>output;
    for(int i =0;i<t;i++){
        int n;
        cin>>n;
        vector<int>result = func(n);
        output.push_back(result);
    }
    for(vector<int> val:output){
        for(int val1:val){
            cout<<val1<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
