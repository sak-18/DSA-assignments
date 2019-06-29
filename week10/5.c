#include<stdio.h>

void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
		
}

// to heapify a subtree with root at given index 
void MaxHeapify(int arr[], int i, int n) 
{ 
    int l = 2*i + 1; 
    int r = 2*i + 2; 
    int largest = i; 
    if (l < n && arr[l] > arr[i]) 
        largest = l; 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
    if (largest != i) 
    { 
        swap(&arr[i], &arr[largest]); 
        MaxHeapify(arr, largest, n); 
    } 
} 
  
void convertMaxHeap(int arr[], int n) 
{ 
    // Start from bottommost and rightmost 
    // internal mode and heapify all internal 
    // modes in bottom up way 
    for (int i = (n-2)/2; i >= 0; --i) 
        MaxHeapify(arr, i, n); 
} 
  
void printArray(int* arr, int size) 
{ 
    for (int i = 0; i < size; ++i) 
        printf("%d ", arr[i]); 
} 
  
 
int main() 
{ 

   	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}

    printf("\nMin Heap array : "); 
    printArray(arr, n); 
  
    convertMaxHeap(arr, n); 
  
    printf("\nMax Heap array : "); 
    printArray(arr, n); 
  
    return 0; 
} 
