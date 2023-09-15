#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;


void Merge2ArrayWithPivot(vector<int> &mainArr, vector<int> &smallerArr, vector<int> &greaterArr, int pivot)
{
    int length1 = smallerArr.size();
    int length2 = greaterArr.size();
    int count = 0;

    for (int i = 0; i < length1; i++)
    {
        mainArr[count] = smallerArr[i];
        count++;
    }

    mainArr[count] = pivot;
    count++;

    for (int i = 0; i < length2; i++)
    {
        mainArr[count] = greaterArr[i];
        count++;
    }


}

vector<int> GetSmallerArray(vector<int> &mainArr, int mainArrLength, int pivot, int newLength)
{
    vector<int> newArr;

    for (int i = 0; i < mainArrLength - 1; i++)
    {
        if (mainArr[i] <= pivot)
        {
            newArr.push_back(mainArr[i]);
        }
    }

    return newArr;
}


vector<int> GetGreaterArray(vector<int> &mainArr, int mainArrLength, int pivot, int newLength)
{
    vector<int> newArr;

    for (int i = 0; i < mainArrLength - 1; i++)
    {
        if (mainArr[i] > pivot)
        {
            newArr.push_back(mainArr[i]);
        }
    }

    return newArr;
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
    

    if (arrLength == 0) return;
    if (arrLength == 1) return;


    int pivot = arr[arrLength - 1];


    int length1 = 0;
    int length2 = 0;

    for (int i = 0; i < arrLength - 1; i++)
    {
        if (arr[i] <= pivot) length1++;
        else length2++;
    }

    vector<int> arr1 = GetSmallerArray(arr, arrLength, pivot, length1);
    vector<int> arr2 = GetGreaterArray(arr, arrLength, pivot, length2);

    //PrintOutArray(arr1, length1);
    //PrintOutArray(arr2, length2);

    SortArray(arr1);
    SortArray(arr2);

    Merge2ArrayWithPivot(arr, arr1, arr2, pivot);
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



