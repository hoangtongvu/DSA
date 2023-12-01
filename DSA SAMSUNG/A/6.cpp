#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;


void DFS(int vertex, vector<vector<int>>& graph, vector<bool>& visited) 
{

    visited[vertex] = true;

    for (int v : graph[vertex]) 
    {
        if (!visited[v]) DFS(v, graph, visited);
    }
}



bool IsConnectedEdge(vector<vector<int>>& graph) 
{

    int n = graph.size();

    bool res = true;


    for (int i = 0; i < n; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {

            if (graph[i][j] > 0) 
            {
                // delete (i, j) store it in temp.
                int temp = graph[i][j];
                graph[i][j] = 0;
                graph[j][i] = 0;

                //init visited vector.
                vector<bool> visited(n, false);
                DFS(i, graph, visited);

                // Check if all vertexes are visited, if not, it is not connected graph.
                for (int k = 0; k < n; k++) 
                {
                    if (!visited[k]) 
                    {
                        res = false;
                        break;
                    }
                }

                // restore back (i, j).
                graph[i][j] = temp;
                graph[j][i] = temp;

                if (res == false) return res;
            }
        }
    }


    return res;
}



int main() 
{

    vector<vector<int>> graph = { {0, 1, 0, 1, 0}, {1, 0, 1, 0, 1}, {0, 1, 0, 1, 0}, {1, 0, 1, 0, 1}, {0, 1, 0, 1, 0} };

    if (IsConnectedEdge(graph)) cout << "YES";
    else cout << "NO";


    return 0;
}