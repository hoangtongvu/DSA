import java.util.Scanner;


public class BubbleSort 
{
    protected static Scanner input;
    public static void main(String[] args) 
    {
        input = new Scanner(System.in);

        int length = input.nextInt();
        int arr[] = GetInputArray(length);
        
        // int length = 6;
        // int arr[] = {2, 6, 7, 50, 12, 0};//12, 6, 8, 19, 30, 0

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

    protected static void SortArray(int[] arr, int arrLength) //2, 6, 1, 8, 12, 3
    {
        for (int i = arrLength - 1; i >= 1; i--)
        {
            for (int j = 0; j < i; j++)
            {
                if (arr[j] > arr[j+1]) Swap(arr, j, j + 1);

            }

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
}