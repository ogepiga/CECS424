using System;
using System.Collections.Generic;

namespace permcomb
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int i;
            Permutation p = new Permutation();
            List<int> numbers = new List<int>();
         
           
            Console.WriteLine("Enter n:");
            int value = int.Parse(Console.ReadLine());

            Console.WriteLine("Enter number for the combination:");
            int comb = int.Parse(Console.ReadLine());


            for (i = 1; i <= value;i++) //filling the list
            {
                numbers.Add(i);
            }

            p.MakePermutation (numbers, comb);

         

         
           
        }
    }
}
