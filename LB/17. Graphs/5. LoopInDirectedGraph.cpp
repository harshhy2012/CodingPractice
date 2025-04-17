#include <bits/stdc++.h>

using namespace std;

class Graph
{

public:
    unordered_map<int, list<int>> adjList;

    void addEdge(int u, int v, int directed)
    {
        adjList[u].push_back(v);
        if (!directed)
        {
            adjList[v].push_back(u);
        }
    }

    void printAdjList()
    {
        for (auto node : adjList)
        {
            cout << node.first << ": ";
            for (auto nbr : node.second)
            {
                cout << nbr << ", ";
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
                if (!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
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
            if (!visited[nbr])
            {
                dfsHelper(nbr, visited);
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
                if (!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = fNode;
                }
                else if (parent[fNode] != nbr)
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
            if (!visited[nbr])
            {
                bool nextAns = isLoopDfsHelper(nbr, src, visited);
                if (nextAns)
                    return true;
            }
            else if (parent != nbr)
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
            if (!visited[nbr])
            {
                bool nextAns = isLoopDirectedDfsHelper(nbr, visited, visitedDfs);
                if (nextAns)
                    return true;
            }
            else if (visitedDfs[nbr])
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
            if (!visited[nbr])
            {
                topologicalSortDfsHelper(nbr, visited, st);
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
                inDegree[nbr]++;
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
                inDegree[nbr]--;
                if (inDegree[nbr] == 0)
                {
                    q.push(nbr);
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
                inDegree[nbr]++;
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
                inDegree[nbr]--;
                count++;
                if (inDegree[nbr] == 0)
                {
                    q.push(nbr);
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
};

int main()
{
    Graph g;
    // g.addEdge(0,1,0);
    // g.addEdge(1,2,0);
    // g.addEdge(1,4,0);
    // g.addEdge(2,3,0);
    // g.addEdge(3,1,0);
    // g.addEdge(4,5,0);

    // g.addEdge(0,1,1);
    // g.addEdge(1,2,1);
    // g.addEdge(2,3,1);
    // g.addEdge(3,4,1);
    // g.addEdge(3,5,1);
    // g.addEdge(4,6,1);
    // g.addEdge(5,6,1);
    // g.addEdge(6,7,1);
    // g.addEdge(6,5,1);
    // g.addEdge(7,8,1);
    // g.addEdge(8,3,1);

    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(1, 3, 1);

    g.printAdjList();
    cout << endl;

    if (g.isLoopDirectedBfs(4))
        cout << "\nLooped hai mamla!\n";
    else
        cout << "\nNO LOOP FOUND\n";

    g.topologicalSortBfs(8);
    cout << endl;
    // if(g.isLoopBfs(6))
    //     cout<<"\nLooped hai mamla!\n";
    // else
    //     cout<<"NO LOOP FOUND";

    // cout<<endl;
    // if(g.isLoopDfs(6))
    //     cout<<"\nLooped hai mamla!\n";
    // else
    //     cout<<"NO LOOP FOUND";
}