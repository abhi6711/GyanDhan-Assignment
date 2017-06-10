#include <stdio.h>
 
//Swap array element at index left and right 
void swap(int array[], int left, int right) {
    int temp;
    //Swapping using a temp variable 
    temp = array[left];
    array[left]=array[right];
    array[right]=temp; 
}
  
void quickSort(int array[], int left, int right) {
    int pivot; 
    if (right > left) {
        /* Partition the given array into 
        two segment by calling partion function */
        pivot = partition(array, left, right);
      
        //Recursively sort left and right sub array
        quickSort(array, left, pivot-1);
        quickSort(array, pivot+1, right);
    }
}
  
int partition(int array[], int left, int right) {
    int temp = left;
    int pivot = array[left];
     
    while(left < right) {
        /* From left side, search for a number
  greater than pivot element */
        while(array[left] <= pivot) 
            left++;
        /* From right side, search for a number 
  less than pivot element */
        while(array[right] > pivot) 
            right--;
     
        if(left < right) 
            swap(array, left, right);
    }
   // Put pivot element in it's currect position 
   array[temp] = array[right];
   array[right] = pivot;
   return right;
}
 

//This function prints triplet whose sum is equal to K
int isTripletSum(int *array, int size, int K) 
{
    int first, second, third, currentSum, sum;
 
    //Sort elements of array using quick sort algorithm  
    quickSort(array, 0, size-1);   // sorting the array to reduce comparision time sorting time= O(n*logn)
     
    // Fix first element 
    for(first = 0; first < size-2; first++) {
      /* Initialize second and third to next element of first and 
   last index of array respectively */
      second = first+1;
      third = size-1; 
      /* sum id the remianing value of K to be found */
      sum = K - array[first];
      while(second < third)   // time complexicity of this loop is O(n)
	  {
         currentSum = array[second] + array[third];
          /*Check if sun of array[second] and array[third] 
   is equal to sum */
          if(currentSum == sum) {
             printf("Triplet found : %d, %d, %d\n", array[first], 
       array[second], array[third]);
             return 1;
          } else if(currentSum < sum) {
              /* If currentSum < sum, then increase the value 
               of currentSum by incrementing left index */
			   
              second++;
          } else {
              /* currentSum is greater than sum, decrease 
              value of currentsum by decrementing right index */
			  
              third--; 
   } 
      }    
    }
    return 0;
}

int main()
{
int arr[MAX_SIZE]; 
    int i, n,sum;
    printf("Enter size of array: ");
    scanf("%d", &n);
	if(size<3) //atleast three elements are required for the problem
		{
			printf("This program requires 3 or more than 3 numbers to be tested.");
		   getchar();
		}
    printf("Enter %d elements in the array : ", n);
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
 
    //Prints all elements of array
    printf("\nElements in array are: ");
    for(i=0; i<n; i++)
    {
        printf("%d, ", arr[i]);
    }
	printf("Enter the number you want the sum of 3 elements of input array to be \n");
	scanf("%d",&sum);
	if(!isTripletSum(arr,n,sum)){
     printf("No Triplet Found");
}