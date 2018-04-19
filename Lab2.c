#include<stdio.h>
#include<stdlib.h>
#include<math.h>




typedef struct Block
{
	int block_size; //# of bytes in the data section
	struct Block *next_block;//pointer to the next block 
	
}Block;


const int overhead_size = sizeof(Block); 
const int void_pointer = sizeof(void*);	

Block *free_head; //always pointing to the first element of the empty block


void my_initialize_heap(int size)
{
	free_head = malloc(size);
	free_head->block_size = size - overhead_size;
	free_head->next_block = NULL; 
		
}

int roundNumb(int size)  //checking the size and rounding if needed for the allocation of the blocks 
{ 	
	int remainder = size%8;
	
	if (size % void_pointer == 0)
		return size;
	else 
	   return size + void_pointer - remainder;
	
}

Block *get_first_block(int size)
{
	Block *current= free_head;//starting point
	
	
	while (current != NULL)
	{
		if (current->block_size >= size)
		{
			return current;
		}
		current = current->next_block;
	}
	
	return NULL;
}

void remove_block(Block *b)//this is a filled block that will be removed from the list 
{
	Block *prev = free_head;
	
	if(b == free_head)//if b is the first block
	{	
		free_head = b->next_block;
		
	}else{
		while (prev->next_block != b)//going through the list to check which one is the block to be removed
		{
			prev = prev->next_block;
		}
		prev->next_block = b->next_block;//relinking the list after removing b 
	}
}

void split(Block* block, int size) //block is the new block and b it is the rest
{
	Block *b = (void*)block + overhead_size + size; //setting the pointer to the new empty block (the rest of the list)
	
	
	b->block_size = block->block_size - size - overhead_size;//setting the size of the new block
	b->next_block = block->next_block;//setting the next block 
	block->next_block = b; //linking the list again
	block->block_size = size;//setting the new block allocated size
	
	
}


void* my_alloc(int size)
{
	size = roundNumb(size);
	Block *block = get_first_block(size);
	
	if(block->block_size > size + 2*overhead_size + void_pointer)
	{
		split(block,size);
	}
		
	remove_block(block);
	
	return (void*)(block) + overhead_size;
	
}
void my_free(void* p)
{
	Block *block = p  - overhead_size;
	
	if (free_head == NULL)
	{
		free_head = block;
		block->next_block = NULL;
	}
	else if (block < free_head)
	{
		block->next_block = free_head;
		free_head = block;
	}
	else
	{
		Block *curr = free_head; 
		
		while(curr->next_block < block)
		{
			curr = curr->next_block;
		}
		block->next_block = curr->next_block;
		curr->next_block = block;
			
	}
	

}

int main()
{
	my_initialize_heap(1000*sizeof(int));
	printf("initial free_head: %p \n", free_head);
	
	// ------ Test 1 -------
	
	printf("############### Test 1 ################# \n");
	int *pointer = my_alloc(sizeof(int));
	printf("pointer address: %p \n",pointer); //to print the address of a pointer 
	my_free(pointer);
	
	pointer = my_alloc(sizeof(int));
	printf("pointer2 address: %p \n",pointer);
	my_free(pointer);
	
	// --------- Test 2 ----------
	
	printf("############### Test 2 ################# \n");
	
	int *ptr1 = my_alloc(sizeof(int));
	printf("ptr1 address: %p \n",ptr1); 

	
	int *ptr2 = my_alloc(sizeof(int));
	printf("ptr2 address: %p \n",ptr2);
	
	my_free(ptr1);
	my_free(ptr2);
	
	//--------- Test 3 ---------
	
	printf("############### Test 3 ################# \n");
	
	int *intptr1 = my_alloc(sizeof(int));
	printf("ptr1 address: %p \n",intptr1); 
	
	int *intptr2 = my_alloc(sizeof(int));
	printf("ptr2 address: %p \n",intptr2);
	
	int *intptr3 = my_alloc(sizeof(int));
	printf("ptr3 address: %p \n",intptr3);
	
	my_free(intptr2);
	
	double *db_pointer = my_alloc(2*sizeof(double));
    printf("db address: %p \n",db_pointer);
	
	int *intptr4 = my_alloc(sizeof(int));
	printf("ptr4 address: %p \n",intptr4);
	
	my_free(intptr1);
	my_free(intptr3);
	my_free(db_pointer);
	my_free(intptr4);
	
	//-------- Test 4 ------------
	
	printf("############### Test 4 ################# \n");
	
	char *ptrchar = my_alloc(sizeof(char));
	printf("ptrchar address: %p \n",ptrchar); 
	
	int *intptr = my_alloc(sizeof(int));
	printf("ptrint address: %p \n",intptr); 
	
	my_free(ptrchar);
	my_free(intptr);
	
	//------------ Test 5 ------------
	free(free_head);
	my_initialize_heap(1000*sizeof(int));
	
	printf("############### Test 5 ################# \n");
	
	int *intarr = my_alloc(100*sizeof(int));
	printf("ptrintarr address: %p \n", intarr);
	
	int *pointer_int = my_alloc(sizeof(int));
	*pointer_int = 9;
	printf("intptr address: %p \n",pointer_int);
	printf("intptr value: %d \n",*pointer_int);
	
	my_free(intarr);
	
	printf("intptr address: %p \n",pointer_int);
	printf("intptr value: %d \n",*pointer_int);
	

	//------------ Test 6 ------------
	printf("############### Test 6 ################# \n");
	
	Block *block = my_alloc(sizeof(Block));
	printf("block address: %p \n", block);
	my_free(block);
	my_free(pointer_int);
	
	free(free_head);
	
	//--------- User Input -----------
	
	my_initialize_heap(1000);
	printf("Enter positive integer: ");
	int n;
	scanf("%d", &n);
	int i;
	double sum = 0;
	
	int *a = my_alloc(n*sizeof(int));
	
	for (i=0;i<n;i++)
	{
		printf("a[%d]: ", i);
		scanf("%d", &a[i]);//fills the array up, and '&' is to get address at value 
		sum = sum + a[i];
	}
	
	double average = sum/n;
	sum =0;
	
	for (i=0;i<n;i++)
	{
		sum = sum + pow((a[i] - average),2);
		
	}
	
	double deviation = sqrt(sum/n);
	
	printf("%f \n", deviation);
	
	my_free(a);
	free(free_head);
	
}


