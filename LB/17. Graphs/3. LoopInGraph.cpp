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
            for(auto neighbor: node.second){
                cout<<neighbor<<", ";
            }
            cout<<endl;
        }
    }

    void bfsHelper(int src, unordered_map<int, bool>& visited){
        queue<int> q;
        q.push(src);
        visited[src] = true;
        while(!q.empty()){
            int top = q.front();
            q.pop();
            cout<<top<<", ";
            for(auto neighbor: adjList[top]){
                if(!visited[neighbor]){
                    visited[neighbor] = true;
                    q.push(neighbor);

                }
            }
        }
    }

    void bfs(int n){
        unordered_map<int, bool> visited;
        for(int i=0;i<n;i++){
            if(!visited[i])
                bfsHelper(i, visited);
        }
    }

    void dfsHelper(int src, unordered_map<int, bool>& visited){
        if(!visited[src])
            cout<<src<<", ";
        visited[src] = true;
        for(auto neighbor: adjList[src]){
            if(!visited[neighbor]){
                dfsHelper(neighbor, visited);
            }
        }
    }

    void dfs(int n){
        unordered_map<int, bool> visited;
        for(int i=0;i<n;i++){
            dfsHelper(i, visited);
        }
    }

    bool IsLoopBfsHelper(int src, unordered_map<int,bool>&visited, unordered_map<int, int>&parent){
        queue<int> q;
        q.push(src);
        visited[src] = true;
        parent[src] = -1;
        while(!q.empty()){
            int top = q.front();
            q.pop();
            for(auto neighbor: adjList[top]){
                if(visited[neighbor]){
                    if(parent[top]!=neighbor){
                        return true;
                    }
                }
                if(!visited[neighbor]){
                    visited[neighbor] = true;
                    parent[neighbor] = top;
                    q.push(neighbor);
                }
            }
        }
        return false;
    }

    bool IsLoopBfs(int n){
        unordered_map<int, int> parent;
        unordered_map<int, bool> visited;
        bool ans;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                ans = IsLoopBfsHelper(i, visited, parent);
                if(ans){
                    return true;
                }
            }
        }
        return false;
    }

    bool IsLoopDfsHelper(int src, unordered_map<int,bool>&visited, int parent){
        visited[src] = true;

        for(auto neighbor: adjList[src]){

            if(!visited[neighbor]){
                bool aageKaAns = IsLoopDfsHelper(neighbor, visited, src);
                if(aageKaAns){
                    return true;
                }
            }
            else if (neighbor != parent) {
                // Found a visited neighbor that is not the parent, indicating a cycle
                return true;
            }
        }
        cout<<"S: "<<src<<"P: "<<parent<<endl;
        return false;
    }

    bool IsLoopDfs(int n){
        bool ans;
        unordered_map<int, int> parent;
        unordered_map<int, bool> visited;
        parent[0] = -1;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                ans = IsLoopDfsHelper(i, visited, -1);
                if(ans){
                    return true;
                }
            }
        }
        return false;
    }

    bool IsLoopDfsDirectedHelper(int src, unordered_map<int,bool>&visited, unordered_map<int,bool>&visitedDfs){
        visited[src] = true;
        visitedDfs[src] = true;
        for(auto neighbor: adjList[src]){
    
            if(!visited[neighbor]){
                bool aageKaAns = IsLoopDfsDirectedHelper(neighbor, visited, visitedDfs);
                if(aageKaAns){
                    return true;
                }
            }
            else if (visitedDfs[src]) {
                // Found a visited neighbor that is not the parent, indicating a cycle
                return true;
            }
        }
        visitedDfs[src] = false;
        return false;
    }
    
    bool IsLoopDirectedDfs(int n){
        bool ans;
        unordered_map<int, int> parent;
        unordered_map<int, bool> visited;
        unordered_map<int, bool> visitedDfs;
        parent[0] = -1;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                ans = IsLoopDfsDirectedHelper(i, visited,  visitedDfs);
                if(ans){
                    return true;
                }
            }
        }
        return false;
    }
};



int main(){
    Graph g;
    g.addEdge(0,1,1);
    g.addEdge(1,5,1);
    g.addEdge(1,6,1);
    g.addEdge(1,2,1); 
    g.addEdge(2,3,1); 
    g.addEdge(3,7,1);
    g.addEdge(3,4,1);
    g.addEdge(3,8,1);
    g.addEdge(6,5,1); 
    g.addEdge(7,8,1); 
    // g.addEdge(8,3,1); 

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
    if(g.IsLoopDirectedDfs(9))
        cout<<"\nLooped hai mamla!\n";
    else
        cout<<"NO LOOP FOUND";


    return 0;
}