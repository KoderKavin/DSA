#include <iostream>
#include <vector>
using namespace std;

class Node{
public: 
    int curr;
    Node* next;

    Node(int x){
        this->curr = x;
        this->next = NULL;
    }

    Node(int x,Node* next){
        this->curr = x;
        this->next = next;
    }


};

class Stack{
public: 
    Node* head;

    Stack(){
        this->head=NULL;
    }

    Node* top(){
        return head;
    }

    void push(int x){
        Node* second = head;
        Node* n = new Node(x,second);
        this->head = n;
    }

    void pop(){
        Node* second = head->next;
        this->head = second;
    }
};

void testStack(vector<int>& nums){
    Stack* s = new Stack();
    for(int val:nums){
        s->push(val);
    }
    while(s->top()!= NULL){
        cout<<s->top()->curr<<" ";
        s->pop();
    }
    cout<<endl;
}

void testCase(vector<int> nums){
    testStack(nums);
}

int main(){
    testCase({1,2,3,4});
    testCase({4,3,2,1});
    testCase({0,0,0,1});
    testCase({0,1,0,-1});
    return 0;
}
