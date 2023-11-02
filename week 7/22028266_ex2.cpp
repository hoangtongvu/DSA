#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;







int main()
{
	int V[5] = { 0, 1, 2, 5, 6 };
	int wt[5] = { 0, 2, 3, 4, 5 };
	int bagW = 8, numberOfItems = 4;
	int K[5][9];

	for (int i = 0; i <= numberOfItems; i++)
	{
		for (int w = 0; w <= bagW; w++)
		{
			if (i == 0 || w == 0)
			{
				K[i][w] = 0;
			}
			else if (wt[i] <= w)
			{
				K[i][w] = max(K[i - 1][w], V[i] + K[i - 1][w - wt[i]]);
			}
			else
			{
				K[i][w] = K[i - 1][w];
			}
		}
	}

	for (int i = 0; i <= numberOfItems; i++)
	{
		for (int w = 0; w <= bagW; w++)
		{
			cout << K[i][w] << " ";
		}
		cout << endl;
	}

    return 0;
}


/*
6
4
1 3
2 3
5 7
3 4
*/