import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class b1 
{
    

    protected static Scanner input;
    public static void main(String[] args) 
    {
        input = new Scanner(System.in);

        int length = input.nextInt();
        ArrayList<Integer> intList = GetInputList(length);

        //ArrayList<Integer> intList = new ArrayList<>();
        //intList.addAll(Arrays.asList(5, 2, 4, 2, 2, 5, 2));

        int n = GetNumberOfPairs(intList);
        
        System.out.println(n);

        input.close();

    }


    protected static int GetNumberOfPairs(ArrayList<Integer> list)
    {
        int length = list.size();
        int count = 0;
        for (int i = 0; i < length - 1; i++)
        {
            int value = list.get(i);

            for (int j = i + 1; j < length; j++)
            {
                if (value == list.get(j)) count++;
            }
            
        }
        return count;

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

    protected static ArrayList<Integer> GetInputList(int arrLength)
    {
        ArrayList<Integer> temp = new ArrayList<>();
        
        for (int i = 0; i < arrLength; i++)
        {
            temp.add(input.nextInt());
        }

        return temp;
    }


    protected static void PrintOutList(ArrayList<Integer> list, String message)
    {
        int length = list.size();
        System.out.println(message);
        for (int i = 0; i < length; i++)
        {
            System.out.print(list.get(i) + " ");
        }
        System.out.println("");

    }  


}
