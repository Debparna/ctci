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

//Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column is set to0
/* Mistakes made: for arr[M][N] instead of i and j. Too many loops. Set arr[i][j] == false which I think sets it to 0. */

int main(){
  int N;
  cout << "Enter row ";
  cin >> N;
  cout << endl;
  
  cout << "Enter column ";
  int M;
  cin >> M;
  cout << endl;
  
  int arr[M][N];
  
  cout << "Enter array";
  cout << endl;
  
  for(int i = 0; i < M; i++){
    for(int j = 0; j < N; j++){
      cin >> arr[i][j];
    }
    cout << endl;
  }
  cout << endl;
  
  for(int i = 0; i < M; i++){
    for(int j = 0; j < N; j++){
      cout << arr[i][j];
    }
    cout << endl;
  }
  cout << endl;
  
  /***** SOLUTION ****/
  
  /** My solution **/
  /* Inefficient and wrong, too many loop holes too many loops
   
  for(int i = 0; i < M; i++){
    for(int j = 0; j < N; j++){
      if(arr[i][j] == 0){
        arr[i][j] = true;
        for(int k = 0; k < N; k++){
          arr[i][k] = true;
        }
        for(int l = 0; l < M; l++){
          arr[l][j] = 0;
          arr[l][j] = true;
        }
      }
    }
  }
  
  for(int i = 0; i < M; i++){
    for(int j = 0; j < N; j++){
      if(arr[i][j] == true){
        for(int k = 0; k < N; k++){
          arr[i][k] = 0;
        }
        for(int l = 0; l < M; l++){
          arr[l][j] = 0;
        }
      }
    }
  }
  */
  
  /** CTCI solution **/
  int row [M];
  int col[N];
  
  for(int i = 0; i < M; i++){
    for(int j = 0; j < N; j++){
      if(arr[i][j] == 0){
        row[i] = 1;
        col[j] = 1;
      }
    }
  }
  
  for(int i = 0; i < M; i++){
    for(int j = 0; j < N; j++){
      if((row[i] == 1) || (col[j] == 1)){
        arr[i][j] = 0;
      }
    }
  }

  
  /*** OUTPUT ***/
  
  for(int i = 0; i < M; i++){
    for(int j = 0; j < N; j++){
      cout << arr[i][j];
    }
    cout << endl;
  }
  cout << endl;
  
  return 0;
}
