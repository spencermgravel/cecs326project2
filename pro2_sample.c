/**
 * Project 2
 */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_barrier_t barrier1 ;
int arr[20];
int arrFinal[20];
int thread_pos = 0; 
void *sorter(void *params); /* thread that performs basic sorting algorithm */
void *merger(void *params);	/* thread that performs merging of results */


//main function
int main (int argc, const char * argv[]) 
{
	//output of ungenerated numbers
	printf("UNSORTED :");
	for (int i = 0; i<20; i++)
	{
		arr[i] = rand() % 100;
		printf(" %d " , arr[i]);
	}
	printf("\n");
	pthread_mutex_init(&mutex1, NULL);
	pthread_t arr_of_threads[3];
	for (int i = 0; i < 2; i++)
	{
		pthread_create(&arr_of_threads[i], NULL, sorter, (void*) NULL);
	
	}
	
	for (int i = 0; i < 2; i++)
	{
		pthread_join(arr_of_threads[i],NULL);
	}
	
	//output of sorting the threads separately
	printf("%s", "SORTED #1: ");
	for (int z = 0; z < 20; z++)
	{
		printf("%d ", arr[z]);
		if (z == 9){
			printf("\n%s", "SORTED #2: ");
		}
	}
	
	//output of merger of the threads
	printf("\n%s", "COMBINED: ");
	pthread_t thread;
	pthread_create(&thread, NULL, merger, (void*) NULL);
	pthread_join(thread,NULL);
	for (int z = 0; z < 20; z++)
	{
		printf("%d ", arrFinal[z]);
	}

}
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
/**
 * Sorting thread.
 */

void *sorter(void *params)
{	
	int pos = thread_pos;
	thread_pos++;
	int n, istart, jstart; 
	if(pos == 0)
	{
		istart = 0;
		n = 10;
		jstart = 0;
	}
	else
	{
		istart = 10;
		n = 20;
		jstart = 10;
	}


	for (int i = istart ; i < n-1; i++)
	{
		for (int j = jstart; j < n - 1; j++)
		{
			pthread_mutex_lock(&mutex1);
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
			pthread_mutex_unlock(&mutex1);
		} 
	}
} 

/**
 * Merge thread
 */

void *merger(void *params)
{

	int left[10];
	int right[10];
	int i;
	int j;
	int k = 0;
	
	for (i = 0; i < 10; i++) 
        	left[i] = arr[i]; 
  
    // storing values in right part 
    	for (i = 10; i < 20; i++) 
        	right[k++] = arr[i]; 
  	
  	int count = 0;
    	i = j = 0; 
  
    // merge left and right in ascending order 
    	while (i < 10 && j < 20) { 
        	if (left[i] <= right[j]) 
            		arrFinal[count++] = left[i++]; 
        	else
            		arrFinal[count++] = right[j++];
     	}
}

