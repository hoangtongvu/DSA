#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;


void Swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}


int GetNumberOfPairs(vector<int> &list)
{
    int length = list.size();
    int count = 0;
    for (int i = 0; i < length - 1; i++)
    {
        int value = list[i];

        for (int j = i + 1; j < length; j++)
        {
            if (value == list[j]) count++;
        }

    }
    return count;

}


vector<int> GetInputArray(int length)
{
    vector<int> temp;
    for (int i = 0; i < length; i++)
    {
        int k;
        cin >> k;
        temp.push_back(k);
    }
    return temp;
}


void PrintOutArray(vector<int> arr)
{
    int length = arr.size();
    cout << "array after sorting: " << endl;
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main()
{
    /*int n;
    cin >> n;
    vector<int> list = GetInputArray(n);*/

    vector<int> list;
    list = { 5, 2, 4, 2, 2, 5, 2 };

    int n = GetNumberOfPairs(list);

    cout << n;
    //PrintOutArray(list);

	return 0;
}



