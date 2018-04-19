using System;
using System.Collections.Generic;
using System.Linq;

namespace permcomb
{
    public class PermAndComb
    {

        public List<int> copy = new List<int>();

        public void MakePermutation(List<int> entry, int number)
        {
            List<List<int>> result = new List<List<int>>();
            Permute(entry, 0, result);

            Print(result);
            PrintComb(result, number);


        }
        private void Permute(List<int> num, int start, List<List<int>> result)
        {
            if (start >= num.Count())
            {
                copy = Copy(num);
                result.Add(copy);
                return;
            }

            for (int j = start; j < num.Count(); j++)
            {
                Swap(num, start, j);
                Permute(num, start + 1, result);
                Swap(num, start, j);
            }

        }
        private List<int> Copy(List<int> num)
        {
            List<int> item = new List<int>();
            for (int i = 0; i < num.Count(); i++)
            {
                item.Add(num[i]);
            }
            return item;
        }


        private void Swap(List<int> num, int i, int j)
        {
            int temp = num[i];
            num[i] = num[j];
            num[j] = temp;
        }

        public void Print(List<List<int>> n)
        {
            foreach (List<int> l in n)
            {
                Console.Write("[ ");
                foreach (int num in l)
                {
                    Console.Write(num);
                    Console.Write(" ");
                }
                Console.WriteLine(" ]");
            }
        }
        public void PrintComb(List<List<int>> n, int number)
        {
            if (number != 0)
            {
                foreach (List<int> l in n)
                {
                    Console.Write("[ ");
                    foreach (int num in l.Take(number))
                    {
                        Console.Write(num);
                        Console.Write(" ");
                    }
                    Console.WriteLine(" ]");
                }
            }
            else
            {
                Print(n);
            }

        }
    
      
        public static void Main(string[] args)
        {
            int i;
            PermAndComb p = new PermAndComb();
            List<int> numbers = new List<int>();


            Console.WriteLine("Enter n:");
            int value = int.Parse(Console.ReadLine());

            Console.WriteLine("Enter number for the combination:");
            int comb = int.Parse(Console.ReadLine());


            for (i = 1; i <= value; i++) //filling the list
            {
                numbers.Add(i);
            }

            p.MakePermutation(numbers, comb);

        }

    }
}
