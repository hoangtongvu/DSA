import java.util.Scanner;


public class MergeSort 
{
    protected static Scanner input;
    public static void main(String[] args) 
    {
        input = new Scanner(System.in);

        // int length = input.nextInt();
        // int arr[] = GetInputArray(length);
        
        int length = 7;
        int arr[] = {12, 6, 8, 19, 30, 0, 2};//12, 6, 8, 19, 30, 0

        SortArray(arr, length);
        
        PrintOutArray(arr, length);
        
        //TestMergedArray();
        
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
        if (arrLength == 1) return;
        if (arrLength == 2)
        {
            if (arr[0] > arr[1]) Swap(arr, 0, 1);
            return;
        }

        int length1 = arrLength / 2;
        int length2 = arrLength - length1;
        int arr1[] = GetSubArray(arr, 0, length1 - 1);
        int arr2[] = GetSubArray(arr, length1, length2 + length1 - 1);

        SortArray(arr1, length1);
        SortArray(arr2, length2);
        MergeSortedArray(arr1, arr2, arr);
        

        
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



    
    protected static void PrintOutArray(int arr[], int length)
    {
        System.out.println("array after sorting: ");
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

        PrintOutArray(newArr, newArr.length);
    }



}