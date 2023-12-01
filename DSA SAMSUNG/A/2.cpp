#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int GetFactorial(int n)
{
    int res = 1;
    for (int i = 2; i < n; i++)
    {
        res *= i;
    }
    return res;
}

int GetCombination(int n, int r)
{
    return GetFactorial(n) / (GetFactorial(r) * GetFactorial(n - r));
}


int main()
{
    int v, e;
    cin >> v >> e;

    //find maximium edges possible.
    int maxEdges = GetCombination(v, 2);

    //find number of Graph possible.
    int possibleGraphs = GetCombination(maxEdges, e);

    cout << possibleGraphs << endl;


    return 0;
}
