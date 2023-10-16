using System;

public static class SumDig {

    public static List<int> FillList(int value, List<int> values){


        int remainder = 0;
        while(value > 0){
            remainder = value %  10;
            value = value / 10;
            values.Add(remainder);

        }

        return values;
    }

    public static int ListProduct(List<int> numbers){

        int value = 1;
        for(int k = 0; k < numbers.Count; k++){
       
                value *= numbers[k];
            
        }

        return value;
    }

    public static int SumProduct(int x, int y){

        int value = 1;
        int sum = x + y;
        List<int> digitsList = new List<int>(); /*wtf verbose*/
        
        digitsList = SumDig.FillList(sum, digitsList);
        value = SumDig.ListProduct(digitsList);
        digitsList.Clear();
        digitsList = SumDig.FillList(value, digitsList);
        value = SumDig.ListProduct(digitsList);
        return value;
        
    }
}


class Program {


    static void Main(){


        Console.WriteLine(SumDig.SumProduct(16,28));
        
}

}