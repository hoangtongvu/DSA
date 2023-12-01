#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>

using namespace std;


// BFS from (0, 0).
// return pixels traveled by BFS.
vector<pair<int, int>> BFS(vector<vector<int>>& image) 
{

    vector<pair<int, int>> res;

    queue<pair<int, int>> queue;
    queue.push({ 0, 0 });

    int rootColor = image[0][0];

    //loop until queue is empty.
    while (!queue.empty()) 
    {

        pair<int, int> p = queue.front();
        queue.pop();
        int u = p.first;
        int v = p.second;

        res.push_back({ u, v });

        // Travel through neighbors of (u, v).
        vector<pair<int, int>> neighbors = { {u - 1, v}, {u + 1, v}, {u, v - 1}, {u, v + 1} };

        for (pair<int, int> q : neighbors) 
        {
            int i = q.first;
            int j = q.second;

            if (i < 0 || i >= 4 || j < 0 || j >= 4) continue;
       
            //check if (i, j) has same color as rootColor.
            if (image[i][j] == rootColor) 
            {
                //check if q is not visited.
                if (find(res.begin(), res.end(), q) == res.end())
                {
                    queue.push({ i, j });
                }
            }
            
        }
    }


    return res;
}


int main() 
{

    vector<vector<int>> image = { {0, 0, 1, 1}, {0, 0, 1, 1}, {0, 1, 1, 1}, {0, 1, 1, 1} };

    vector<pair<int, int>> result = BFS(image);
    for (pair<int, int> p : result) cout << p.first << " " << p.second << endl;

    return 0;
}