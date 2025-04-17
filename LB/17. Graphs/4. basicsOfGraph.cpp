#include<bits/stdc++.h>

using namespace std;

class Graph{
    public: 
    
    unordered_map<int, list<int>> adjList;

    void addEdge(int u, int v, bool directed){
        adjList[u].push_back(v);
        if(!directed){
            adjList[v].push_back(u);
        }
    }

    void printAdjList(){
        for(auto node: adjList){
            cout<<node.first<<": ";
            for(auto nbr: node.second){
                cout<<nbr<<", ";
            }
            cout<<endl;
        }
    }

    void bfsHelper(int src, unordered_map<int, bool>&visited){
        queue<int> q;
        q.push(src);
        visited[src] = true;
        while(!q.empty()){
            int fNode = q.front();
            q.pop();
            cout<<fNode<<", ";
            for(auto nbr: adjList[fNode]){
                if(!visited[nbr]){
                    visited[nbr] = true;
                    q.push(nbr);
                    
                }
            }
        }
    }

    void bfs(int n){
        unordered_map<int, bool> visited;
        for(int i=0;i<n;i++){
            if(!visited[n]){
                if(!visited[i]){
                    bfsHelper(i, visited);
                }
            }
        }
    }


    void dfsHelper(int src, unordered_map<int, bool>&visited){
        if(!visited[src])
        cout<<src<<", ";
        visited[src] = true;
        for(auto nbr: adjList[src]){
            if(!visited[nbr]){
                dfsHelper(nbr, visited);
            }
        }       
    }

    void dfs(int n){
        unordered_map<int, bool> visited;
        for(int i=0;i<n;i++){
            if(!visited[n]){
                dfsHelper(i, visited);
            }
        }
    }

    // find loop in undirected graph
    bool IsLoopBfsHelper(int src, unordered_map<int, int>&parent, unordered_map<int, bool>&visited){
        queue<int> q;
        q.push(src);
        visited[src] = true;
        parent[src] = -1;
        while(!q.empty()){
            int fNode = q.front();
            q.pop();
            for(auto nbr: adjList[fNode]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = fNode;
                }
                else if(parent[fNode] != nbr){
                    return true;
                }
            }
        }
        return false;
    }

    bool IsLoopBfs(int n){
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;

        bool ans = false;

        for(int i=0;i<n;i++){
            if(!visited[i]){
                ans = IsLoopBfsHelper(i, parent, visited);
                if(ans){
                    return true;
                }
            }
        }
        return ans;
    }


        // find loop in undirected graph
        bool IsLoopDfsHelper(int src, unordered_map<int, bool>&visited, int parent){
            visited[src] = true;

            for(auto nbr: adjList[src]){

                if(!visited[nbr]){
                   bool nextAns = IsLoopDfsHelper(nbr, visited, src);
                   if(nextAns){
                    return true;
                   }
                }
                else if(visited[src]){
                    if(nbr != parent){
                        return true;                    
                    }
                }
                    
            }
            return false;
        }
    
        bool IsLoopDfs(int n){
            unordered_map<int, bool> visited;

            bool ans;
            int parent = -1;
            for(int i=0;i<n;i++){
                if(!visited[i]){
                    ans = IsLoopDfsHelper(i, visited, parent);
                    if(ans){
                        return true;
                    }
                }
            }
            return ans;
        }
    
        bool IsLoopDfsDirectedHelper(int src, unordered_map<int, bool>&visited, unordered_map<int, bool>&visitedDfs){
            visited[src] = true;
            visitedDfs[src] = true;

            for(auto nbr: adjList[src]){
                if(!visited[nbr]){
                    bool nextAns = IsLoopDfsDirectedHelper(nbr, visited, visitedDfs);
                    if(nextAns){
                        return true;
                    }
                }
                else if(visitedDfs[nbr]){
                    return true;
                }
            }
            visitedDfs[src] = false;
            return false;
        }

        bool IsLoopDfsDirected(int n){
            unordered_map<int, bool> visited;
            unordered_map<int, bool> visitedDfs;
            bool ans = false;
            for(int i=0;i<n;i++){
                if(!visited[i]){
                    ans = IsLoopDfsDirectedHelper(i, visited, visitedDfs);
                    if(ans){
                        return true;
                    }
                }
            }
            return ans;
        }



};

int main(){
    Graph g;
    // g.addEdge(0,1,1);
    // g.addEdge(1,2,1);
    // g.addEdge(1,4,1);
    // g.addEdge(2,3,1);
    // g.addEdge(3,1,1);
    // g.addEdge(4,5,1);

    g.addEdge(0,1,1);
    g.addEdge(1,5,1);
    g.addEdge(1,6,1);
    g.addEdge(1,2,1); 
    g.addEdge(2,3,1); 
    g.addEdge(3,7,1);
    g.addEdge(3,4,1);
    // g.addEdge(3,8,1);
    g.addEdge(6,5,1); 
    g.addEdge(7,8,1); 
    g.addEdge(8,3,1);

    // g.addEdge(3,4,0);
    cout<<endl;

    g.printAdjList();
    cout<<endl;

    cout<<"DFS: ";
    g.dfs(5);
    cout<<endl;
    cout<<"BFS: ";
    g.bfs(5);
    cout<<endl;
    // if(g.IsLoopBfs(5))
    //     cout<<"\nLooped hai mamla!\n";
    // else
    //     cout<<"NO LOOP FOUND";

    // cout<<endl;
    // if(g.IsLoopDfs(5))
    //     cout<<"\nLooped hai mamla!\n";
    // else
    //     cout<<"NO LOOP FOUND";

        cout<<endl;
    if(g.IsLoopDfsDirected(9))
        cout<<"\nLooped hai mamla!\n";
    else
        cout<<"NO LOOP FOUND";


    return 0;
}