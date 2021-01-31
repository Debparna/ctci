#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <limits>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <climits>
#include<list>
using namespace std;
//http://www.geeksforgeeks.org/time-complexities-of-all-sorting-algorithms/
//https://www.youtube.com/playlist?list=PL2_aWCzGMAwKedT2KfDMB9YA5DgASZb3U



/* Quick sort
   Time Complexity -
   Best - O(n log(n))
   Average - O(n log(n))
   Worst - O(n^2)

   Select a pivot and then divide and conquer -

 Algorithm:
  Set the pivot to the end and partitionIndex to the beginning. Move through the array and compare each time with the pivot. If the index is lesser than the pivot, swap and increment the partitionIndex. At the end swap the last element with the partition index. This creates two sides of the partition separated by the pivot. In the next round select two pivots in these divided areas and do the same.
 */

// This function takes last element as pivot, places the pivot element at its correct position in sorted array, and places all smaller (smaller than pivot) to left of pivot and all greater elements to right of pivot

void swap(int* a, int* b)
{
  int t = *a;
  *a = *b;
  *b = t;
}

int partition (int arr[], int first, int last)
{
  int pivot = arr[last];    // pivot
  int partitionIndex = (first - 1);  // Index of smaller element

  for (int movingIndex = first; movingIndex <= last - 1; movingIndex++)
  {
    if (arr[movingIndex] <= pivot) // If current element is smaller than or equal to pivot
    {
      partitionIndex++;    // increment index of smaller element
      swap(&arr[partitionIndex], &arr[movingIndex]);
    }
  }
  swap(&arr[partitionIndex + 1], &arr[last]); // switch last with partition
  return (partitionIndex + 1); //return partition index
}

// The main function that implements QuickSort, arr[] --> Array to be sorted, low  --> Starting index, high  --> Ending index
void quickSort(int arr[], int first, int last)
{
  if (first < last)
  {
    int pi = partition(arr, first, last);  /* pi is partitioning index, arr[p] is now at right place */
    quickSort(arr, first, pi - 1);    // Separately sort elements before partition and after partition
    quickSort(arr, pi + 1, last);
  }
}

//******************************************************************//

/* Merge sort

   Best - Omega(n log(n))
   Average - Theta(n log(n))
   Worst - O(n log(n))

 MergeSort(arr[], l,  r)
 If r > l
 1. Find the middle point to divide the array into two halves:
 middle m = (l+r)/2
 2. Call mergeSort for first half:
 Call mergeSort(arr, l, m)
 3. Call mergeSort for second half:
 Call mergeSort(arr, m+1, r)
 4. Merge the two halves sorted in step 2 and 3:
 Call merge(arr, l, m, r)

 Time complexity of Merge Sort is \Theta(nLogn) in all 3 cases (worst, average and best) as merge sort always divides the array in two halves and take linear time to merge two halves.

 Auxiliary Space: O(n)
 */

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
  int i, j, k;
  int n1 = m - l + 1;
  int n2 =  r - m;

  /* create temp arrays */
  int L[n1], R[n2];

  /* Copy data to temp arrays L[] and R[] */
  for (i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (j = 0; j < n2; j++)
    R[j] = arr[m + 1 + j];

  /* Merge the temp arrays back into arr[l..r]*/
  i = 0; // Initial index of first subarray
  j = 0; // Initial index of second subarray
  k = l; // Initial index of merged subarray
  while (i < n1 && j < n2)
  {
    if (L[i] <= R[j])
    {
      arr[k] = L[i];
      i++;
    }
    else
    {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  /* Copy the remaining elements of L[], if there
   are any */
  while (i < n1)
  {
    arr[k] = L[i];
    i++;
    k++;
  }

  /* Copy the remaining elements of R[], if there
   are any */
  while (j < n2)
  {
    arr[k] = R[j];
    j++;
    k++;
  }
}

/* l is for left index and r is right index of the
 sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
  if (l < r)
  {
    // Same as (l+r)/2, but avoids overflow for
    // large l and h
    int m = l+(r-l)/2;

    // Sort first and second halves
    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);

    merge(arr, l, m, r);
  }
}

//******************************************************************//

//INSERTION SORT
/*
 Time Complexity: O(n*n)

 Auxiliary Space: O(1)
*/
void insertionSort(int arr[], int n)
{
  int i, key, j;
  for (i = 1; i < n; i++)
  {
    key = arr[i];
    j = i-1;

    /* Move elements of arr[0..i-1], that are
     greater than key, to one position ahead
     of their current position */
    while (j >= 0 && arr[j] > key)
    {
      arr[j+1] = arr[j];
      j = j-1;
    }
    arr[j+1] = key;
  }
}

/* BUBBLE SORT
   Time Complexity -
   BEST -

 Worst and Average Case Time Complexity: O(n*n). Worst case occurs when array is reverse sorted.

 Best Case Time Complexity: O(n). Best case occurs when array is already sorted.
 Algorithm:
 The swapping by bubbling occurs in passes. For each one outer loop pass, the inner loop compares and switches two elements till the end of the array. In each pass the largest element bubbles up to the end. This is why for each one outer loop pass, the innner loop comparisions decrese by one because the the last element already finds its place.
 https://www.youtube.com/watch?v=Jdtq5uKz-w4
 */

void swap(int *xp, int *yp)
{
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}


void bubbleSort(int arr[], int n)
{
  bool swapped; // this variable adds an optimization
  for (int i = 0; i < n - 1; i++){ //out of bounds
    swapped = false;
    for (int j = 0; j < n - i - 1; j++){ // n - i - 1 because we dont need to go over the whole array, we can leave out the sorted part, each iteration will sort and bubble the greatest to the end, to avoid this part we do n - i -1
      if (arr[j] > arr[j+1]){
        swap(&arr[j], &arr[j+1]);
        swapped = true;
      }
    }
    if (swapped == false) //if the array is already sorted there is no point in doing more passes so break out
      break;
  }
  //To print
  for (int k = 0; k < n; k++)
    cout <<  arr[k] << ' ';

}

int main()
{
  int arr[] = {64, 34, 25, 12, 22, 11, 90};
  int n = 7;

  //1
  //cout << "Sorted array: \n";
  //bubbleSort(arr, n);

  //2
  //printf("Sorted array: ");
  //quickSort(arr, 0, n-1);
  //for (int k = 0; k < n; k++)
  //  cout <<  arr[k] << ' ';

  //3
  //mergeSort(arr, 0, n - 1);
  //printf("\nSorted array is \n");
  //for (int k = 0; k < n; k++)
  //  cout <<  arr[k] << ' ';

  //4
  //insertionSort(arr, n);
  //for (int k = 0; k < n; k++)
  //  cout <<  arr[k] << ' ';

  return 0;
}
