#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;


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


void Swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}


void SortArray(vector<int> &arr) //2, 6, 1, 8, 12, 3
{
    int arrLength = arr.size();
    for (int i = arrLength - 1; i >= 1; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1]) Swap(arr[j], arr[j + 1]);

        }

    }
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
    list = { 2, 6, 7, 50, 12, 0 };

    SortArray(list);


    PrintOutArray(list);

	return 0;
}



