// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
void bfs(int n, vector<vector<int>> &adj)
{
    vector<bool> vis(n + 1, false);
    queue<int> q;
    q.push(1);
    vis[1] = true;
    while (q.empty() == false)
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            auto curr = q.front();
            q.pop();
            cout << curr << " ";
            for (auto x : adj[curr])
            {
                if (vis[x] == false)
                {
                    q.push(x);
                    vis[x] = true;
                }
            }
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> edges = {{1, 2}, {2, 3}, {3, 1}, {1, 4}};
    int n = 4;
    vector<vector<int>> adj(n + 1); // list;
    for (int i = 0; i < edges.size(); i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]); // only when undirected
    }

    vector<vector<int>> mat(n + 1, vector<int>(n + 1, 0)); // matrix;
    for (int i = 0; i < edges.size(); i++)
    {
        mat[edges[i][0]][edges[i][1]] = 1;
        mat[edges[i][1]][edges[i][0]] = 1;
    }

    int node = 2;
    for (auto x : adj[node]) // list
    {
        cout << x << endl; // node which has edges with other nodes
    }

    // for (auto x : mat[node])
    // {
    //     cout << x << endl;
    // }

    // for (int i = 0; i <= n; i++) // mat representaion
    // {
    //     if (mat[node][i] == 1)
    //     {
    //         cout << i << endl;
    //     }
    // }
    bfs(n, adj);
}
//CODE BY PRAGYA
