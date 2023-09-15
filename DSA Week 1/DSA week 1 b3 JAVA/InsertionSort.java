import java.util.Scanner;


public class InsertionSort 
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
        int key;
        for (int keyPos = 1; keyPos < arrLength; keyPos++)
        {
            key = arr[keyPos];

            if (key <= arr[0])
            {
                int insertPos = 0;
                for (int k = keyPos; k >= insertPos + 1; k--)
                {
                    Swap(arr, k, k - 1);
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