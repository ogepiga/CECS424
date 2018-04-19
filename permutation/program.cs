Class Program{

    static void Main(){
        Permutation p = new Permutation();

        Console.WriteLine("Enter a number to get the permutation:");
        int value = int.Parse(Console.ReadLine());
        int result = p.Factorial(value);

    Console.WriteLine(result);
    }


}
