import java.util.Scanner;


public class SelectionSort 
{
    protected static Scanner input;
    public static void main(String[] args) 
    {
        input = new Scanner(System.in);
        int length = input.nextInt();
        int arr[] = GetInputArray(length);
        

        SortArray(arr, length);

        PrintOutArray(arr, length);
        
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

    protected static void SortArray(int[] arr, int arrLength)
    {
        int minPos;
        for (int i = 0; i < arrLength - 1; i++)
        {
            minPos = i;
            for (int j = i + 1; j < arrLength; j++)
            {
                if (arr[j] < arr[minPos]) minPos = j;
            }
            if (minPos != i) Swap(arr, minPos, i);
        }

        //return arr;
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
}