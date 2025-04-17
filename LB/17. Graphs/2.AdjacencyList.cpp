#include<bits/stdc++.h>

using namespace std;

class Graph
{
    public:
    unordered_map<int, list<int>> adjList;
   
    void addEdge(int u, int v, bool direction){
        adjList[u].push_back(v);
        if(!direction){
            adjList[v].push_back(u);
        }
    }

    void printAdjList(){
        for(auto node: adjList){
            cout<<node.first<<": ";
            for(auto neighbor: node.second){
                cout<<neighbor<<", ";
            }
            cout<<endl;
        }
    }

    void bfsHelper(int src, unordered_map<int ,bool>&visited){ 
        queue<int> q;
        
        q.push(src);
        visited[src] = true;
        while(!q.empty()){
            int top = q.front();
            cout<<top<<", ";
            q.pop();
            for(auto neighbor: adjList[top]){
                if(!visited[neighbor]){
                    q.push(neighbor);
                    visited[neighbor] = true;
                }   
            }
        }
    }

    void bfs(int numOfNodes){
        unordered_map<int, bool> visited;
        for(int i=0;i<numOfNodes;i++){
            if(!visited[i])
                bfsHelper(i, visited);
        }
    }

    void dfsHelper(int src, unordered_map<int, bool>& visited){
        cout<<src<<", ";
        visited[src] = true;
        for(auto  neighbor: adjList[src]){
            if(!visited[neighbor])
                dfsHelper(neighbor, visited);
        }
    }

    void dfs(int numOfNodes){
        unordered_map<int, bool> visited;
        for(int i=0;i<numOfNodes;i++){
            if(!visited[i])
                dfsHelper(i, visited);
        }
    }
    

};


int main(){
    Graph g;
    g.addEdge(0,1,0);
    g.addEdge(1,3,0);
    g.addEdge(0,2,0);
    g.addEdge(2,4,0);
    
    cout<<endl;

    g.printAdjList();
    cout<<endl;

    cout<<"DFS: ";
    g.dfs(5);
    cout<<endl;
    cout<<"BFS: ";
    g.bfs(5);
    return 0;
}

