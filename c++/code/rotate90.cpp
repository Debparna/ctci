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

/*Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes, write a method to rotate the image by 90 degrees Can you do this in place?

Mistake: Array in the for loop went from 0 to > N but when initializing l I did l = N instead of l = N-1 as the index was going ( if N = 4) from 0 to 3 and N was being 4 instead of 3.

*/


int main(){
  int N;
  cout<<"Enter length of row and col of matrix  ";
  cin >> N;
  cout << endl;
  
  int arr[N][N];
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> arr[i][j];
    }
    cout << endl;
  }
  cout << endl;
  
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cout << arr[i][j];
    }
    cout << endl;
  }
  
  cout << endl;
  int arr2[N][N];
  int l = N-1;
  int k;
  
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      arr2[i][j] = 0;
    }
  }
  
  for(int i = 0; i < N; i++){
    k = 0;
    for (int j = 0; j < N; j++){
      arr2[k][l] = arr[i][j];
      //cout << arr[i][j] << ' ';
      //cout << arr2[k][l] << ' ';

      k = k + 1;
    }
    l = l - 1;
  }
  
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cout << arr2[i][j];
    }
    cout << endl;
  }
  
  return 0;
}