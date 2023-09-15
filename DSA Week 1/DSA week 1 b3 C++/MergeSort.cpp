#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;


vector<int> GetSubArray(vector<int> mainArr, int startPos, int endPos)
{
    int newLength = endPos - startPos + 1;
    vector<int> newArr;

    for (int i = startPos; i <= endPos; i++)
    {
        newArr.push_back(mainArr[i]);
    }

    return newArr;
}

void MergeSortedArray(vector<int> &arr1, vector<int> &arr2, vector<int> &newArr)
{
    int length1 = arr1.size();
    int length2 = arr2.size();

    int i = 0, j = 0, k = 0;

    while (i < length1 && j < length2)
    {

        if (arr1[i] <= arr2[j])
        {
            newArr[k] = arr1[i];
            k++;
            i++;
        }
        else
        {
            newArr[k] = arr2[j];
            k++;
            j++;
        }

    }


    while (i < length1)
    {
        newArr[k] = arr1[i];
        k++;
        i++;
    }

    while (j < length2)
    {
        newArr[k] = arr2[j];
        k++;
        j++;
    }


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


void Swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}


void SortArray(vector<int> &arr) //2, 6, 1, 8, 12, 3
{
    int arrLength = arr.size();
    

    if (arrLength == 1) return;
    if (arrLength == 2)
    {
        if (arr[0] > arr[1]) Swap(arr[0], arr[1]);
        return;
    }

    int length1 = arrLength / 2;
    int length2 = arrLength - length1;
    vector<int> arr1 = GetSubArray(arr, 0, length1 - 1);
    vector<int> arr2 = GetSubArray(arr, length1, length2 + length1 - 1);

    SortArray(arr1);
    SortArray(arr2);
    MergeSortedArray(arr1, arr2, arr);
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



