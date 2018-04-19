#include<stdio.h>

void swap (int *a, int x, int y) /*swap method it will be used by qSortHelper 
								and takes as parameters an array and two integers that 
								will be used as indexes for the swap*/
{
	int temp=a[x]; //setting the value of temp to the first number to be swapped, so the value is not lost
	a[x]=a[y];//setting the value of that same position to the number that it is being swapped with 
	a[y]=temp;//setting the value of the second position to the first position's old value
}

void print (int *a, int n)/*print method is responsible to print the values of an array
						  and receives as parameters an array and its size*/
{
	for (int i=0; i<n; i++){ //for loop to go through all the arrays positions
		printf("%d ",a[i]);	//printing each element of the array
	}
	printf("\n");//skipping to the next line
}

void qSortHelper(int *a, int left, int right, int n) /*qSortHelper is method that essentially sorts the array trhough quicksort
													and receives as parameters an array and three integers that corresopond respectively to
													where the partition should start, where should it finish and the size of the array*/ 
{
	if (right <= left) return;//base case when the two indices cross each other the array is sorted
	
	int pivot = a[left];//setting the pivot 
	int l = left+1;// setting the index of the the left subarray
	int r = right;//setting the index of the right subarray
	
	while(l<=r){ /*inside this loop the subarrays are formed*/
	
		while(a[l]<=pivot){//left subarray
			l++;
		}
		
		if(l>r) break;//exit condition in which the array is already sorted
		
		while(a[r]>pivot){//right subarray
			r--;
		}
		
		if(l>r) break;//exit condition in which the array is already sorted
		
		swap(a,l,r);//makes the swap when necessary	
	}
	
	swap(a,left,r);//put the pivot in the right place
	print(a,n);//prints the iteractions
	
	qSortHelper(a,left,r-1, n);//calls qSortHelper recursively with the left subarray
	qSortHelper(a,l,right, n);//calls qSortHelper recursively with the right subarray
}

void qSort (int *a, int n)//quicksort method
{ 	
	qSortHelper(a, 0, n-1, n);//calls qSortHelper offering and array, the initial position, the end position and the size.
}

int main()
{
	
	int a[] = {4, 65, 2, -31, 0, 99, 2, 83, 782, 1};//declaring the array a
	qSort(a,10);//calling the method qSort with array a and its size
	
	printf("sorted:\n");
	print(a,10);//prints the sorted array
}
