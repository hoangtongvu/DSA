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


void Heapify(vector<int> &arr, int arrLength, int i)
{
    int largestPos = i; // init largestPos = root
    int leftPos = 2 * i + 1;
    int rightPos = 2 * i + 2;


    if (leftPos < arrLength) // if leftChild exist
        if (arr[leftPos] > arr[largestPos])
            largestPos = leftPos;

    if (rightPos < arrLength) // if rightChild exist
        if (arr[rightPos] > arr[largestPos])
            largestPos = rightPos;

    if (largestPos == i) return;//if largestPos = root then do nothing

    Swap(arr[largestPos], arr[i]);
    Heapify(arr, arrLength, largestPos);// heapify the changed sub-tree

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
    

    for (int i = arrLength / 2 - 1; i >= 0; i--)
    {
        Heapify(arr, arrLength, i);
    }


    for (int i = arrLength - 1; i > 0; i--)
    {
        Swap(arr[0], arr[i]); //move root to end of array
        Heapify(arr, i, 0);// call heapify on reduced array
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



