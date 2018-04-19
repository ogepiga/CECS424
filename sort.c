#include <stdio.h>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void qsort(int *a, int n)
{
  if (n < 2) return;

  int pivot = a[0];
  int start = 1;
  int end = n-1;
 
  while (start <= end)
  {
    while (a[start] <= pivot) start++;
    if (end < start) break;
    while (a[end] > pivot) end--;
    if (end < start) break;
    swap(&a[start], &a[end]);
  }

  swap(a, &a[end]);
  qsort(a, end);
  qsort(&a[start], n-start);
}


void print (int *a, int n)/*print method is responsible to print the values of an array
						  and receives as parameters an array and its size*/
{
	for (int i=0; i<n; i++){ //for loop to go through all the arrays positions
		printf("%d ",a[i]);	//printing each element of the array
	}
	printf("\n");//skipping to the next line
}

int main()
{
	
	int a[] = {4, 65, 2, -31, 0, 99, 2, 83, 782, 1};//declaring the array a
	qsort(a,10);//calling the method qSort with array a and its size
	
	printf("sorted:\n");
	print(a,10);//prints the sorted array
}
