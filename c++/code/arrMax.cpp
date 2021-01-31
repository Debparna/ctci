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

//Simple maximum of an array

int main(){
  
  double values[5] = {2, 4, 8, 1, 6};
  double max = values[0];
  
  for(int i = 0; i < 5; i++){
    if(values[i] > max){
      max = values[i];
    }
  }
  
  cout << max << endl;
  
  return 0;
}