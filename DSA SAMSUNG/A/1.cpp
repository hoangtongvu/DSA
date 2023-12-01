#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;


int main()
{

    int edge;
    cin >> edge;
    bool hasEulerCycle = true;

    vector<int> degree(edge, 0);

    for (int i = 0; i < edge; i++) 
    {
        int u, v;
        cin >> u >> v;

        degree[u]++;
        degree[v]++;
    }


    for (int i = 0; i < edge; i++) 
    {
        if (degree[i] % 2 == 0) hasEulerCycle = true;
    }


    if (hasEulerCycle) cout << "Euler" << endl;
    else cout << "Not Euler" << endl;


    return 0;
}
