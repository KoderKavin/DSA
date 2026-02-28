#include <iostream>
#include <vector>
using namespace std;

void push(vector<int>& nums,int index,int side,int &x,int &y){
    if(side ==0){
        int key = nums[index];
        for(int i = index;i<y-1;i++){
            nums[i] = nums[i+1];
        }
        nums[y-1] = key;
        if(index==x-1){
            x--;
            y--;
        }
    }else{
        int key = nums[index];
        for(int i = index;i>x;i--){
            nums[i] = nums[i-1];
        }
        nums[x] = key;
        if(index == y){
            x++;
            y++;
        }
    }
}

vector<int> portal(vector<int>& nums,int n ,int x,int y){
    int flag =0;
    while(true){
        if(x>0 && nums[x-1]>nums[x]){
            push(nums,x-1,0,x,y);
            flag=1;
        }
        if(x<n-1 && nums[x]>nums[x+1]){
            push(nums,x,0,x,y);
            flag =1;
        }
        if(y>1 && nums[y-1]<nums[y-2]){
            push(nums,y-1,1,x,y);
            flag = 1;
        }
        if(y>0 && nums[y]<nums[y-1]){
            push(nums,y,1,x,y);
            flag = 1;
        }

        if(flag ==0){
            return nums;
        }
    }
    return nums;
}

int main(){
    int t;
    cin>>t;
    vector<vector<int>>output;
    for(int i =0;i<t;i++){
        int n,x,y;
        cin>>n;
        cin>>x;
        cin>>y;
        vector<int>input;
        for(int j = 0;j<n;j++){
            int temp;
            cin>>temp;
            input.push_back(temp);
        }
        vector<int> result = portal(input,n,x,y);
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