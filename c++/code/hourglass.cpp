#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
Hour Glass sum:
 Given a matrix of numbers calculate the hourglass sum of each element in the hourglass and find the max and min sums. The housrglass looks like this 
   1 2 3
     4
   5 6 7
*/
 
int main(){
    vector< vector<int> > arr(6,vector<int>(6));
    
    for(int arr_i = 0;arr_i < 6;arr_i++){
       for(int arr_j = 0;arr_j < 6;arr_j++){
          cin >> arr[arr_i][arr_j];
       }
    }
    
    vector<int> sum(20);
    vector<int>::iterator it;

      int sum1;  
      int sum2;
      int sum3;
      int sumFinal;
    
    for(int arr_i = 0; arr_i <= 3; arr_i++){
       for( int arr_j = 0; arr_j <= 3; arr_j++){
         sum1 = arr[arr_i][arr_j] + arr[arr_i][arr_j+1]+ arr[arr_i][arr_j+2];
         sum2 = arr[arr_i+1][arr_j+1];
         sum3 = arr[arr_i+2][arr_j] + arr[arr_i+2][arr_j+1] + arr[arr_i+2][arr_j+2];
         sumFinal = sum1 + sum2 + sum3;
         sum.insert(sum.end(), sumFinal);
       }
    }  
    
    it = max_element(sum.begin(),sum.end());
    cout<<*it;
    
    return 0;
}
