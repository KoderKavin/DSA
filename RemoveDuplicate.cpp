#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <vector>
#include <stack>
using namespace std;

string removeDuplicateLetters(string s) {
    unordered_map<char,pair<int,bool>> map;
    stack <int> box;
    for(char c:s){
        if(map.count(c)==0){
            map.insert({c,{1,false}});
        }else{
            map.at(c).first +=1;
        }
    }

    for(int i =0;i<s.size();i++){
        char c= s[i];
        if(box.empty()){
            box.push(c);
            map.at(c).first -=1; //reduce the count
            map.at(c).second = true;// tracked usage
            continue;
        }
        if(map.at(c).second == true){
            //cout<<c<<endl;
            map.at(c).first -=1;
            continue;
        }
        if(box.top()<c){//correct order
            if(map.at(c).first>0){//first and only c
                //cout<<"test2"<<endl;
                box.push(c);
                map.at(c).first -=1; //reduce the count
                map.at(c).second = true;// tracked usage
            }// else continue
        }else{//incorrect order
            if(map.at(box.top()).first>0){//if box.top exists ahead
                //cout<<"test3"<<endl;
                map.at(box.top()).second = false;//reset usage after removal
                //cout<<map.at(box.top()).first<<" ";
                box.pop();
                i--;
                continue;
            }else{//last box.top
                //cout<<"test4"<<endl;
                box.push(c);//no other option
                map.at(c).first -=1;
                map.at(c).second = true;
            }
        }
    }
    string snew(box.size(),'z');
    int j =box.size()-1;
    while(!box.empty()){
        //cout<<"test5"<<endl;
        //cout<<(char)box.top()<<" ";
        snew[j] = (char)box.top();
        box.pop();
        j--;
    }
    
    return snew;
}

void testCase(string s){
    string result = removeDuplicateLetters(s);
    cout<<result<<endl;
}

int main(){

    // testCase("bcabc");
    // testCase("cbacdcbc");
    // testCase("cdadabcc");
    // testCase("ecbacba");
    testCase("bbcaac");
    return 0;
}