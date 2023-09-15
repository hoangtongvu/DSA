import java.util.Scanner;
import java.lang.Math;


public class HeapSort 
{
    protected static Scanner input;
    public static void main(String[] args) 
    {
        input = new Scanner(System.in);

        // int length = input.nextInt();
        // int arr[] = GetInputArray(length);
        
        int length = 9;
        int arr[] = {50, 25, 2, 7, 109, 234, 2, 1009, 56234};//12, 6, 8, 19, 30, 0

        SortArray(arr, length);

        PrintOutArray(arr, length, "Array after sorting: ");
        
        
        input.close();

    }


    protected static int[] GetInputArray(int arrLength)
    {
        int arr[] = new int[arrLength];
        
        for (int i = 0; i < arrLength; i++)
        {
            arr[i] = input.nextInt();
        }

        return arr;
    }

    protected static void SortArray(int[] arr, int arrLength) //2, 6, 1, 8, 12, 3
    {
        
        for (int i = arrLength / 2 - 1; i >= 0; i--)
        {
            Heapify(arr, arrLength, i);
        }


        for (int i = arrLength - 1; i > 0; i--)
        {
            Swap(arr, 0, i); //move root to end of array
            Heapify(arr, i, 0);// call heapify on reduced array
        }
        
        
    }

    protected static void Heapify(int[] arr, int arrLength, int i)
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
        
        Swap(arr, largestPos, i);
        Heapify(arr, arrLength, largestPos);// heapify the changed sub-tree

    }


    protected static void SortArrayViaDigitPlace(int[] arr, int digitPlace)
    {
        // selection sort
        int arrLength = arr.length;
        int minPos;
        for (int i = 0; i < arrLength - 1; i++)
        {
            minPos = i;
            for (int j = i + 1; j < arrLength; j++)
            {

                if (GetDigitNumber(arr[j], digitPlace) < GetDigitNumber(arr[minPos], digitPlace)) minPos = j;
            }
            if (minPos != i) Swap(arr, minPos, i);
        }
    }


    protected static void CountingSort(int[] arr)
    {
        int length = arr.length;
        int maxValue = GetMaxValueFromArray(arr, length);

        //copy all value from arr to tempMainArr
        int tempMainArray[] = new int[length];
        for (int i = 0; i < length; i++)
        {
            tempMainArray[i] = arr[i];
        }

        int countingArray[] = new int[maxValue + 1];

        for (int i = 0; i < length; i++)
        {
            countingArray[arr[i]]++;
        }

        
        //Adding previous count
        for (int i = 1; i < maxValue + 1; i++)
        {
            countingArray[i] += countingArray[i - 1];
        }

        //use tempMainArray
        for (int i = 0; i < length; i++)
        {
            int k = countingArray[tempMainArray[i]];
            arr[k - 1] = tempMainArray[i];
            countingArray[tempMainArray[i]]--;
        }



    }


    protected static void CountingSortViaDigitPlace(int[] arr, int digitPlace)
    {
        int length = arr.length;
        int maxValue = GetDigitNumber(arr[0], digitPlace);
        for (int i = 1; i < length; i++)
        {
            int temp = GetDigitNumber(arr[i], digitPlace);
            if (maxValue < temp) maxValue = temp;
        }

        //copy all value from arr to tempMainArr
        int tempMainArray[] = new int[length];
        for (int i = 0; i < length; i++)
        {
            tempMainArray[i] = arr[i];
        }


        //initialize countingArray
        int countingArray[] = new int[maxValue + 1];

        for (int i = 0; i < length; i++)
        {
            int pos = GetDigitNumber(arr[i], digitPlace);
            countingArray[pos]++;
        }

        
        //Adding previous count
        for (int i = 1; i < maxValue + 1; i++)
        {
            countingArray[i] += countingArray[i - 1];
        }

        //use tempMainArray
        for (int i = 0; i < length; i++)
        {
            int pos = GetDigitNumber(tempMainArray[i], digitPlace);
            int k = countingArray[pos];
            arr[k - 1] = tempMainArray[i];
            countingArray[pos]--;
        }



    }



    protected static int GetDigitNumber(int number, int digitPlace)
    {

        int k = (int)Math.pow(10, digitPlace);
        number %= k;
        k = (int)Math.pow(10, digitPlace - 1);
        number /= k;

        return number;
    }


    protected static int GetNumberOfDigits(int value)
    {
        int numberOfDigits = 1;

        while (true)
        {
            int k = (int) Math.pow(10, numberOfDigits);
            if (value / k > 0) numberOfDigits++;
            else break;
        }
        return numberOfDigits;

    }


    protected static int GetMaxValueFromArray(int[] arr, int arrLength)
    {
        int maxValue = arr[0];

        if (arrLength == 1) return maxValue;
        for (int i = 1; i < arrLength; i++)
        {
            if (maxValue < arr[i]) maxValue = arr[i];
        }
        return maxValue;
    }

    protected static void Merge2ArrayWithPivot(int[] mainArr, int[] smallerArr, int[] greaterArr, int pivot)
    {
        int length1 = smallerArr.length;
        int length2 = greaterArr.length;
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

    protected static int[] GetSmallerArray(int[] mainArr, int mainArrLength, int pivot, int newLength)
    {
        int newArr[] = new int[newLength];
        
        int count = 0;
        for (int i = 0; i < mainArrLength - 1; i++)
        {
            if (mainArr[i] <= pivot)
            {
                newArr[count] = mainArr[i];
                count++;
            }
        }
        
        return newArr;
    }


    protected static int[] GetGreaterArray(int[] mainArr, int mainArrLength, int pivot, int newLength)
    {
        int newArr[] = new int[newLength];
        
        int count = 0;
        for (int i = 0; i < mainArrLength - 1; i++)
        {
            if (mainArr[i] > pivot)
            {
                newArr[count] = mainArr[i];
                count++;
            }
        }
        
        return newArr;
    }

    protected static int[] GetSubArray(int[] mainArr, int startPos, int endPos)
    {
        int newLength = endPos - startPos + 1;
        int newArr[] = new int[newLength];

        int newCount = 0;
        for (int i = startPos; i <= endPos; i++)
        {
            newArr[newCount] = mainArr[i];
            newCount++;
        }

        return newArr;
    }

    protected static void MergeSortedArray(int[] arr1, int[] arr2, int[] newArr)
    {
        int length1 = arr1.length;
        int length2 = arr2.length;

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

    protected static void Swap(int[] arr, int a, int b)
    {
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }



    
    protected static void PrintOutArray(int arr[], int length, String message)
    {
        System.out.println("");
        System.out.println(message);
        for (int i = 0; i < length; i++)
        {
            System.out.print(arr[i] + " ");
        }

    }   


    protected static void TestMergedArray()
    {
        int arr1[] = {5, 8, 9, 15};
        int arr2[] = {3, 4, 7, 8, 22, 100};

        int newArr[] = new int[arr1.length + arr2.length];

        MergeSortedArray(arr1, arr2, newArr);

        PrintOutArray(newArr, newArr.length, "");
    }



}