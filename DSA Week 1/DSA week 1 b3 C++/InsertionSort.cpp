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
    int key;
    for (int keyPos = 1; keyPos < arrLength; keyPos++)
    {
        key = arr[keyPos];

        if (key <= arr[0])
        {
            int insertPos = 0;
            for (int k = keyPos; k >= insertPos + 1; k--)
            {
                Swap(arr[k], arr[k - 1]);
            }
            arr[insertPos] = key;
            continue;

        }



        for (int j = keyPos - 1; j >= 0; j--)
        {
            if (key >= arr[j])
            {
                //Insert key into j + 1 position
                int insertPos = j + 1;
                if (insertPos == keyPos) break;
                //move elements to right 
                for (int k = keyPos; k >= insertPos + 1; k--)
                {
                    arr[k] = arr[k - 1];
                }
                arr[insertPos] = key;
                break;
            }
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



