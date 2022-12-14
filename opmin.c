// C++ program for implementation of Heap Sort
#include<stdio.h>

void swap(int *a,int *b){
   int temp=*a;
   *a=*b;
   *b=temp;
}
// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++){
	    printf("%d\t",arr[i]);
	}
	printf("\n");
	
}
void heapify(int arr[], int n, int i)
{
	int smallest = i; // Initialize smallest as root
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2

	// If left child is smaller than root
	if (l < n && arr[l] < arr[smallest])
		smallest = l;

	// If right child is smaller than smallest so far
	if (r < n && arr[r] < arr[smallest])
		smallest = r;

	// If smallest is not root
	if (smallest != i) {
		swap(&arr[i], &arr[smallest]);

		// Recursively heapify the affected sub-tree
		heapify(arr, n, smallest);
	}
}

// main function to do heap sort
void heapSort(int arr[], int n)
{
	// Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// One by one extract an element from heap
	printArray(arr,n);
	printf("\n");
	int sum=0;
	int count=0;
	//int finalcount=0;
	int maxsum=0;
	for (int i = n - 1; i >= 0; i--) {
		// Move current root to end
		swap(&arr[0], &arr[i]);
                sum=sum+arr[i];
                count++;
                if(count==2){
                   // finalcount++;
                    maxsum=maxsum+sum;
                    count=0;
                    arr[i]=sum;
                    sum=0;
                    i++;
                }
               // printf("%d\n",arr[i]);
		// call min heapify on the reduced heap
		 heapify(arr, i, 0);
	}
	printf("maxsum%d\n",maxsum);
}

/* A utility function to print array of size n */


// Driver program
int main()
{
	int arr[] = { 15,10,2,5,16};
	int n = sizeof(arr) / sizeof(arr[0]);

	heapSort(arr, n);

	
	
}

