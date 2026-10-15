
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main()
{
    int n, e;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    vector<vector<int>> graph(n, vector<int>(n, 0));

    cout << "Enter edges (source destination weight):" << endl;

    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u][v] = w;
        graph[v][u] = w;
    }

    vector<bool> visited(n, false);
    visited[0] = true;

    int mstCost = 0;
    int edgesSelected = 0;

    cout << "\nEdges in Minimum Spanning Tree:" << endl;

    while (edgesSelected < n - 1)
    {
        int minimum = numeric_limits<int>::max();
        int x = -1, y = -1;

        for (int i = 0; i < n; i++)
        {
            if (visited[i])
            {
                for (int j = 0; j < n; j++)
                {
                    if (!visited[j] && graph[i][j] > 0)
                    {
                        if (graph[i][j] < minimum)
                        {
                            minimum = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        if (x == -1)
        {
            cout << "Graph is disconnected. MST is not possible." << endl;
            break;
        }

        cout << x << " - " << y
             << " : " << minimum << endl;

        mstCost += minimum;
        visited[y] = true;
        edgesSelected++;
    }

    if (edgesSelected == n - 1)
    {
        cout << "Minimum cost of MST: " << mstCost << endl;
    }

    return 0;
}
