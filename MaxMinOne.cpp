#include <iostream>
#include <vector>
#include <string>
using namespace std;

int maxOnes(vector<int> &st){
    int i =0;
    while(i<st.size()-2){
        if(st[i]==1 && st[i+1]==0 && st[i+2]==1){
            st[i+1] =1;
            i += 2;
        }else{
            i++;
        }
        
    }
    int count = 0;
    for(int j= 0;j<st.size();j++){
        //cout<<st[j]<<"\n";
        if(st[j]==1){
            count++;
        }
    }
    return count;
}

int minOnes(vector<int> &st){
    // for(int val:st){
    //     cout<<val<<" ";
    // }
    // cout<<"\n";
    int i =0;
    while(i<st.size()-2){
        //cout<<st[i]<<" ";
        if(st[i]==1 && st[i+1]==1 && st[i+2]==1){
            st[i+1]=0;
            i += 2;
        }else{
            i++;
        }
    }
    int count = 0;
    for(int j =0;j<st.size();j++){
        //cout<<st[j]<<" ";
        if(st[j]==1){
            count++;
        }
    }
    return count;
}

vector<int> solve(string s){
    vector<int> st;
    for(int i =0;i<s.size();i++){
       // cout<<s[i]<<" ";
        int temp = s[i];
        st.push_back(temp-48);
        //cout<<st[i]<<" ";
    }
    int max = maxOnes(st);  
    int min = minOnes(st);
    return {min,max};
}

// void testCase(string s){
//     vector<int> result = solve(s);
//     cout<<result[0]<<" "<<result[1]<<"\n";
// }

// int main(){
//     testCase("111");
//     testCase("011011");
//     testCase("1011101");
//     testCase("100101101");
// }

int main(){
    int t;
    cin>>t;
    vector<vector<int>>output;
    for(int i =0;i<t;i++){
        int n;
        string s;
        cin>>n;
        cin>>s;
        vector<int> temp = solve(s);
        output.push_back(temp);
    }
    for(vector<int>val:output){
        cout<<val[0]<<" "<<val[1]<<"\n";
    }
    return 0;
}