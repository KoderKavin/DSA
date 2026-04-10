#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
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
        l[v].push_back(u);
    }
};
void dfs(vector<vector<int>>& image,int i,int j,int oc,int nc){
    if(i<0 ||j<0||i>=image.size()||j>=image[0].size()){
        return ;
    }else if(image[i][j]!= oc){
        return;
    }
    image[i][j] = nc;   
    dfs(image,i-1,j,oc,nc);
    dfs(image,i,j-1,oc,nc);
    dfs(image,i+1,j,oc,nc);
    dfs(image,i,j+1,oc,nc);
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    if(image[sr][sc]==color){
        return image;
    }
    dfs(image,sr,sc,image[sr][sc],color);
    return image;
}

void testCase(vector<vector<int>> image,int sr,int sc,int color){
    vector<vector<int>> output = floodFill(image,sr,sc,color);
    for(vector<int> val:output){
        for(int val1:val){
            cout<<val1<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<endl;
}

int main(){
    testCase({{1,1,1},{1,1,0},{1,0,1}},1,1,2);
    testCase({{0,0,0},{0,0,0}},0,0,0);
    return 0;
}