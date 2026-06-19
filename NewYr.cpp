#include <iostream>
#include <vector>
using namespace std;

class Graph{
public:
    int V;
    vector<int> l;

    Graph(int val){
        this->V = val;
        l.resize(V);
    }

    void addEdge(int u,int v){
        l[u] = v;
    }
};

void dfs(Graph &g, int curr, bool &flag,int t){
    if(curr == t){
        flag = true;
        return;
    }
    if(curr> t){
        return;
    }
    dfs(g,g.l[curr],flag,t);
}

bool isValid(int n,int t,vector<int>& portals){
    bool flag = false;
    Graph g = Graph(n+1);
    for(int i =0;i<n;i++){
        g.addEdge(i+1,i+1+portals[i]);
    }
    dfs(g,1,flag,t);
    return flag;
}

void testCase(int n,int t,vector<int> &portals){
    bool result = isValid(n,t,portals);
    if(result){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    cout<<endl;
}

int main(){
    // testCase(8,4,{1, 2, 1, 2, 1, 2, 1});
    // testCase(8,5,{1, 2, 1, 2, 1, 1, 1});
    int n,t;
    cin>>n>>t;
    vector<int> portals;
    for(int i=0;i<n-1;i++){
        int temp;
        cin>>temp;
        portals.push_back(temp);
    }
    testCase(n,t,portals);

    return 0;
}