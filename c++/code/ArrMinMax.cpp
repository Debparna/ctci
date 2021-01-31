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
using namespace std;

/*
 
 Divide and Conquer is one of the famous algorithmic techniques. It works with the philosophy that divide the whole problem into smaller managable chunks of subproblems and work out these small subproblems there by combining the intermediate partial solutions.
 
 There are many famous examples which use the Divide and Conqure strategy, for example Binary search, Merge sort, Insertion sort, Quick sort etc.,
 
 Let us take a small example of finding minimum and maximum elements in a given array. If we adapt a normal methodology it takes atleast 2*(n-1) comparisions. We can decrease the number of comparisions using this technique which results in [ Ceil(3*n/2)-2 ] comparisions.
  
 My Notes:
 When they say divide and conquer they dont mean divide the whole array into two but instead take two at a time starting from the beginning. First and midpoint and then midpoint+1 and last. First the indices are 0 and 9 and then it is divided recursively till 0 = 0(First and midpoint) for the fn. In the first minmax fn with first and midpoint, when first = midpoint which means first index  = last index, min and max are assigned to arr[firstIndex]. Then the second minmax fn is called and executed till midpoint+1 = last. After these two fns are done the comparisions are done in the end
 
 */


//FUNCTION CALL
void MaxMin(int arr[], int first, int last, int &min, int &max);

//MAIN
int main()
{
  const int size = 10;
  int arr[size] = { -99, 34, 15, 17, 19, 26, 18, 783, 14, -6 };
  
  int min;
  int max;
  MaxMin(arr, 0, size - 1, min, max);
  
  cout << "Minimum is: " << min << '\n' << "Maximum is: " << max << "\n\n";
  
  return 0;
}

//FUNCTION
void MaxMin(int arr[], int firstIndex, int lastIndex, int &min, int &max)
{
  //BASE CASE - if lower index of array is equal to upper index, it is on the last element, the size of the list is 1.
  if (firstIndex == lastIndex)
  {
    min = max = arr[firstIndex];
  }
  else
  {
    int midpoint = (firstIndex + lastIndex) / 2;
    
    int leftMin;
    int leftMax;
    int rightMin;
    int rightMax;
    
    MaxMin(arr, firstIndex, midpoint, leftMin, leftMax);
    MaxMin(arr, midpoint + 1, lastIndex, rightMin, rightMax);
    
    if (leftMin < rightMin)
      min = leftMin;
    else
      min = rightMin;
    
    if (leftMax > rightMax)
      max = leftMax;
    else
      max = rightMax;
  }
}
