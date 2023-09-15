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



void SortArray(vector<int> &arr) //2, 6, 1, 8, 12, 3
{
    int arrLength = arr.size();
    

    int minPos;
    for (int i = 0; i < arrLength - 1; i++)
    {
        minPos = i;
        for (int j = i + 1; j < arrLength; j++)
        {
            if (arr[j] < arr[minPos]) minPos = j;
        }
        if (minPos != i) Swap(arr[minPos], arr[i]);
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



