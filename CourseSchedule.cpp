#include <iostream>
#include <stack>
#include <vector>
#include <unordered_set>
using namespace std;

class Graph{
public: 
    int V;
    vector<vector<int>> l;

    Graph(int V){
        this->V = V;
        l.resize(V);
    }

    void addEdge(int u,int v){
        l[u].push_back(v);
    }
};

void buildGraph(vector<vector<int>>& edges,Graph &g){
    for(vector<int> val:edges){
        g.addEdge(val[1],val[0]);
    }
}

void dfs(int curr,stack<int> &s,vector<bool> &vis,Graph &g,bool &flag,unordered_set<int> &collection){
    vis[curr] = true;
    collection.insert(curr);
    for(int v:g.l[curr]){
        if(collection.count(v)==1){
            //cout<<curr<<" "<<v<<" ";
            flag = true;
            return;
        }
        if(!vis[v]){
            dfs(v,s,vis,g,flag,collection);
        }
    }
    s.push(curr);
    collection.erase(curr);
}


bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
    Graph g(numCourses);
    buildGraph(prerequisites,g);
    stack <int> s;
    vector<bool> vis(numCourses,0);
    bool flag = 0;
    unordered_set<int> set;
    for(int i = 0;i<numCourses;i++){
        if(!vis[i]){
            dfs(i,s,vis,g,flag,set);
            set.clear();
        }
    }
    int n = s.size();
    // while(s.size()>0){
    //     cout<<s.top();
    //     s.pop();
    // }
    if(flag){
        return false;
    }
    if(n==numCourses){
        return true;
    }else{
        return false;
    }
}

void testCase(int V,vector<vector<int>>edges){
    bool result = canFinish(V,edges);
    cout<<result<<endl;
}

int main(){

    testCase(2,{{1,0}});
    testCase(2,{{0,1}});
    testCase(2,{{1,0},{0,1}});
    testCase(4,{{1,0},{2,0},{3,1},{3,2}});
    testCase(3,{{1,0},{2,0},{0,2}});

    return 0;
}