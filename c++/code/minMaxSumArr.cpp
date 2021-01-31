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

//To find the min and maximum sum by not considering one element of the array each time
// Finding out the min sum and max sum by leaving out an element of the array

int main() {
  /*
   My solution but min was not printing out correctly
   
  vector<int> arr(5);
  for(int arr_i = 0; arr_i < 5; arr_i++){
    cin >> arr[arr_i];
  }
  
  int sum1;
  int sum2;
  int sum3;
  int sum4;
  int sum5;
  
  vector<int> sum(5);
  for(int arr_i = 0; arr_i < 5; arr_i++){
    if (arr_i == 0){
      sum1 = arr[arr_i+1]+arr[arr_i+2]+arr[arr_i+3]+arr[arr_i+4];
    }
    if (arr_i == 1){
      sum2 = arr[arr_i-1]+arr[arr_i+1]+arr[arr_i+2]+arr[arr_i+3];
    }
    if (arr_i == 2){
      sum3 = arr[arr_i-2]+arr[arr_i-1]+arr[arr_i+1]+arr[arr_i+2];
    }
    if (arr_i == 3){
      sum4 = arr[arr_i-3]+arr[arr_i-2]+arr[arr_i-1]+arr[arr_i+1];
    }
    if (arr_i == 4){
      sum5 = arr[arr_i-4]+arr[arr_i-3]+arr[arr_i-2]+arr[arr_i-1];
    }
    
  }
  
  sum.insert(sum.end(), sum1);
  sum.insert(sum.end(), sum2);
  sum.insert(sum.end(), sum3);
  sum.insert(sum.end(), sum4);
  sum.insert(sum.end(), sum5);
  
  cout << sum1 << ' ' << sum2 << ' ' << sum3 << ' ' << sum4 << ' ' << sum5;
  
  sort(sum.begin(), sum.end()); // 12 32 45 71(26 33 53 80)


  vector<int>::iterator it1;
  it1 = max_element(sum.begin(),sum.end());
  
  vector<int>::iterator it2;
  it2 = min_element(sum.begin(),sum.end());
  cout<< *it1 << ' ' << it*2;
   
  */
  
  long long a[5];
  long long sum = 0;
  for(int i = 0; i < 5; i++){
    cin >> a[i];
    sum += a[i];
  }
  
  sort(a, a+5);
  cout << sum - a[4] << " " << sum - a[0] << endl;
  return 0;
  
  return 0;
}

