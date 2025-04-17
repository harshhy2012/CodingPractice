#include<bits/stdc++.h>

using namespace std;
class Graph
{

public:
    unordered_map<int, list<pair<int,int>>> adjList;

    void addEdge(int u, int v, int wt, int directed)
    {
        adjList[u].push_back({v, wt});
        if (!directed)
        {
            adjList[v].push_back({u, wt});
        }
    }

    void printAdjList()
    {
        for (auto node : adjList)
        {
            cout << node.first << ": ";
            for (auto nbr : node.second)
            {
                cout << "("<<nbr.first << ", "<<nbr.second<<")";
                if(nbr != *prev(node.second.end()))
                    cout<<", ";
            }
            cout << endl;
        }
    }

    void bfsHelper(int src, unordered_map<int, bool> &visited)
    {
        queue<int> q;
        q.push(src);
        visited[src] = true;
        while (!q.empty())
        {
            int fNode = q.front();
            q.pop();
            cout << fNode << ", ";
            for (auto nbr : adjList[fNode])
            {
                if (!visited[nbr.first])
                {
                    q.push(nbr.first);
                    visited[nbr.first] = true;
                }
            }
        }
    }

    void bfs(int n)
    {
        unordered_map<int, bool> visited;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
                bfsHelper(i, visited);
        }
    }

    void dfsHelper(int src, unordered_map<int, bool> &visited)
    {
        visited[src] = true;
        cout << src << ", ";
        for (auto nbr : adjList[src])
        {
            if (!visited[nbr.first])
            {
                dfsHelper(nbr.first, visited);
            }
        }
    }

    void dfs(int n)
    {
        unordered_map<int, bool> visited;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfsHelper(i, visited);
            }
        }
    }

    bool isLoopBfsHelper(int src, unordered_map<int, bool> &visited, unordered_map<int, int> &parent)
    {
        queue<int> q;
        q.push(src);
        parent[src] = -1;
        visited[src] = true;
        while (!q.empty())
        {
            int fNode = q.front();
            q.pop();
            for (auto nbr : adjList[fNode])
            {
                if (!visited[nbr.first])
                {
                    q.push(nbr.first);
                    visited[nbr.first] = true;
                    parent[nbr.first] = fNode;
                }
                else if (parent[fNode] != nbr.first)
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool isLoopBfs(int n)
    {
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;
        bool ans = false;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                ans = isLoopBfsHelper(i, visited, parent);
                if (ans)
                    return true;
            }
        }
        return ans;
    }

    bool isLoopDfsHelper(int src, int parent, unordered_map<int, bool> &visited)
    {
        visited[src] = true;
        for (auto nbr : adjList[src])
        {
            if (!visited[nbr.first])
            {
                bool nextAns = isLoopDfsHelper(nbr.first, src, visited);
                if (nextAns)
                    return true;
            }
            else if (parent != nbr.first)
            {
                return true;
            }
        }
        return false;
    }

    bool isLoopDfs(int n)
    {
        unordered_map<int, bool> visited;

        int parent = -1;
        bool ans = false;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                ans = isLoopDfsHelper(i, parent, visited);
                if (ans)
                {
                    return true;
                }
            }
        }
        return ans;
    }

    bool isLoopDirectedDfsHelper(int src, unordered_map<int, bool> &visited, unordered_map<int, bool> &visitedDfs)
    {
        visited[src] = true;
        visitedDfs[src] = true;

        for (auto nbr : adjList[src])
        {
            if (!visited[nbr.first])
            {
                bool nextAns = isLoopDirectedDfsHelper(nbr.first, visited, visitedDfs);
                if (nextAns)
                    return true;
            }
            else if (visitedDfs[nbr.first])
            {
                return true;
            }
        }
        visitedDfs[src] = false;
        return false;
    }

    bool isLoopDirectedDfs(int n)
    {
        unordered_map<int, bool> visited;
        unordered_map<int, bool> visitedDfs;
        bool ans = false;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                ans = isLoopDirectedDfsHelper(i, visited, visitedDfs);
                if (ans)
                {
                    return ans;
                }
            }
        }
        return ans;
    }

    // topological sort
    // topological sort can be done only on directed acyclic graph.
    void topologicalSortDfsHelper(int src, unordered_map<int, bool> &visited, stack<int> &st)
    {
        visited[src] = true;

        for (auto nbr : adjList[src])
        {
            if (!visited[nbr.first])
            {
                topologicalSortDfsHelper(nbr.first, visited, st);
            }
        }
        st.push(src);
    }

    void topologicalSortDfs(int n)
    {
        unordered_map<int, bool> visited;
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                topologicalSortDfsHelper(i, visited, st);
            }
        }

        cout << "TS: ";
        while (!st.empty())
        {
            cout << st.top() << ", ";
            st.pop();
        }
        cout << endl;
    }

    void topologicalSortBfsHelper(int n)
    {
        queue<int> q;
        unordered_map<int, int> inDegree;

        for (auto node : adjList)
        {
            for (auto nbr : node.second)
            {
                inDegree[nbr.first]++;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int fNode = q.front();
            q.pop();

            cout << fNode << ", ";
            for (auto nbr : adjList[fNode])
            {
                inDegree[nbr.first]--;
                if (inDegree[nbr.first] == 0)
                {
                    q.push(nbr.first);
                }
            }
        }
    }

    void topologicalSortBfs(int n)
    {
        topologicalSortBfsHelper(n);
    }

    int isLoopDirectedBfsHelper(int n)
    {
        unordered_map<int, int> inDegree;
        queue<int> q;
        int count = 0;
        for (auto i : adjList)
        {
            for (auto nbr : i.second)
            {
                inDegree[nbr.first]++;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int fNode = q.front();
            q.pop();
            for (auto nbr : adjList[fNode])
            {
                inDegree[nbr.first]--;
                count++;
                if (inDegree[nbr.first] == 0)
                {
                    q.push(nbr.first);
                }
            }
        }
        return count;
    }

    bool isLoopDirectedBfs(int n)
    {
        int ans = isLoopDirectedBfsHelper(n);
        cout << "ANS: " << ans << endl;
        if (ans == n)
            return false;
        else
            return true;
    }
    void shortestPathBfs(int src, int dest){
        queue<int> q;
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;

        q.push(src);
        visited[src] = true;
        parent[src] = -1;
        while(!q.empty()){
            int fNode = q.front();
            q.pop();
            for(auto nbr: adjList[fNode]){
                if(!visited[nbr.first]){
                    parent[nbr.first] = fNode;
                    visited[nbr.first] = true;
                    q.push(nbr.first);
                }
            }
        }

        cout<<"PARENTS: \n";
        for(auto i: parent){
            cout<<i.first<<":> "<<i.second<<endl;
        }
        cout<<endl;

        vector<int> ans;
        int node = dest;
        while(parent[node]!=-1){
            ans.push_back(node);
            node = parent[node];
        }
        ans.push_back(src);
        reverse(ans.begin(), ans.end());
        cout<<"Shortest Path: ";
        for(auto i: ans){
            cout<<i;
            if(i!= *prev(ans.end())) cout<<"->";
        }
        cout<<endl;
    }

    stack<int> getTopology(int n){
        unordered_map<int, bool> visited;
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                topologicalSortDfsHelper(i, visited, st);
            }
        }

        return st;
    }

    void shortestPathDfs(int dest, int n){
        vector<int> dist(n, INT_MAX);
        stack<int> topoOrder = getTopology(n);
        int src = topoOrder.top();;
        dist[src] = 0;

        for(auto nbr: adjList[0]){
            if(dist[0] + nbr.second < dist[nbr.first]){
                dist[nbr.first] = dist[0] + nbr.second;
            }
        }

        while(!topoOrder.empty()){
            int topElement = topoOrder.top();
            topoOrder.pop();

            if(dist[topElement] != INT_MAX){
                for(auto nbr: adjList[topElement]){
                    if(dist[topElement] + nbr.second < dist[nbr.first]){
                        dist[nbr.first] = dist[topElement] + nbr.second;
                    }
                }
            }
        }
        cout<<"NODE: ";
        for(int i=0;i<n;i++){
            cout<<i;
            if(i!=n-1)cout<<" || ";
        }
        cout<<endl<<"Dist: ";
        for(auto i: dist){
            cout<<i;
            if(i!=*prev(dist.end()))cout<<" || ";
        }
        cout<<endl;
    }

    void dijkstra(int src, int n){
        vector<int> dist(n, INT_MAX);
        set<pair<int,int>> st;
        dist[src] = 0;
        st.insert({0,src});

        while(!st.empty()){
            auto topEle = *(st.begin());
            int nodeDist = topEle.first;
            int node = topEle.second;
            st.erase(st.begin());
            for(auto nbr: adjList[node]){
                if(dist[nbr.first] > nodeDist+nbr.second){
                    auto result = st.find({dist[nbr.first], nbr.first});
                    if(result != st.end())
                        st.erase(result);

                    dist[nbr.first] = nodeDist+nbr.second;
                    st.insert({dist[nbr.first], nbr.first});
                }
            }
        }
        cout<<"NODE: ";
        for(int i=0;i<n;i++){
            cout<<i;
            if(i!=n-1)cout<<" || ";
        }
        cout<<endl<<"Dist: ";
        for(auto i: dist){
            if(i==INT_MAX)
            cout<<"I";
            else
            cout<<i;
            if(i!=*prev(dist.end()))cout<<" || ";
        }
        cout<<endl;
    }
    
};



int main()
{
    Graph g;
    // g.addEdge(0,1,1,1);
    // g.addEdge(1,2,1,1);
    // g.addEdge(2,3,1,1);

    // g.addEdge(3,4,1,1);
    // g.addEdge(0,5,1,1);
    // g.addEdge(5,4,1,1);

    // g.addEdge(0,6,1,1);
    // g.addEdge(6,7,1,1);
    // g.addEdge(7,8,1,1);
    // g.addEdge(8,4,1,1);
    // g.addEdge(8,4,1,1);

    // g.addEdge(0,1,5,1);
    // g.addEdge(0,2,3,1);
    // g.addEdge(2,1,2,1);
    // g.addEdge(1,3,3,1);
    // g.addEdge(2,3,5,1);
    // g.addEdge(2,4,6,1);
    // g.addEdge(4,3,1,1);

    g.addEdge(6,3,2,0);
    g.addEdge(6,1,14,0);
    g.addEdge(3,1,9,0);
    g.addEdge(3,2,10,0);
    g.addEdge(1,2,7,0);
    g.addEdge(2,4,15,0);
    g.addEdge(4,3,11,0);
    g.addEdge(6,5,9,0);
    g.addEdge(4,5,6,0);
    

    g.printAdjList();
    cout << endl;

    int src = 6;
    int dest = 4;
    g.dijkstra(src, 7);

    // g.shortestPathDfs(dest,5);

    // if (g.isLoopDirectedBfs(4))
    //     cout << "\nLooped hai mamla!\n";
    // else
    //     cout << "\nNO LOOP FOUND\n";

    // g.topologicalSortBfs(8);
    // cout << endl;
    // if(g.isLoopBfs(6))
    //     cout<<"\nLooped hai mamla!\n";
    // else
    //     cout<<"NO LOOP FOUND";

    // cout<<endl;
    // if(g.isLoopDfs(6))
    //     cout<<"\nLooped hai mamla!\n";
    // else
    //     cout<<"NO LOOP FOUND";
    return 0;
}