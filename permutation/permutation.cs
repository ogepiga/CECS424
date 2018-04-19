Class Permutation{

  public int Factorial(int n){
    if (n==0)
      return 0;
    if (n == 1)
      return 1;
    else
      return Factorial(n)*Factorial(n-1);
  }



}
