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

int GetMaxValueFromArray(vector<int> &arr, int arrLength)
{
    int maxValue = arr[0];

    if (arrLength == 1) return maxValue;
    for (int i = 1; i < arrLength; i++)
    {
        if (maxValue < arr[i]) maxValue = arr[i];
    }
    return maxValue;
}


int GetDigitNumber(int number, int digitPlace)
{

    //int k = (int)Math.pow(10, digitPlace);
    int k = pow(10, digitPlace);
    number %= k;
    //k = (int)Math.pow(10, digitPlace - 1);
    k = pow(10, digitPlace - 1);
    number /= k;

    return number;
}


int GetNumberOfDigits(int value)
{
    int numberOfDigits = 1;

    while (true)
    {
        //int k = (int)Math.pow(10, numberOfDigits);
        int k = pow(10, numberOfDigits);
        if (value / k > 0) numberOfDigits++;
        else break;
    }
    return numberOfDigits;

}

void SortArrayViaDigitPlace(vector<int> &arr, int digitPlace)
{
    // selection sort
    int arrLength = arr.size();
    int minPos;
    for (int i = 0; i < arrLength - 1; i++)
    {
        minPos = i;
        for (int j = i + 1; j < arrLength; j++)
        {

            if (GetDigitNumber(arr[j], digitPlace) < GetDigitNumber(arr[minPos], digitPlace)) minPos = j;
        }
        if (minPos != i) Swap(arr[minPos], arr[i]);
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





void SortArray(vector<int> &arr) //2, 6, 1, 8, 12, 3
{
    int arrLength = arr.size();
    

    int maxValue = GetMaxValueFromArray(arr, arrLength);

    int numberOfDigits = GetNumberOfDigits(maxValue);


    for (int digitCount = 1; digitCount <= numberOfDigits; digitCount++)
    {
        SortArrayViaDigitPlace(arr, digitCount);
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



