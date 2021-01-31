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
 when n = 4
    #
   ##
  ###
 ####
*/

int main() {
  int n,w = 1,k;
  cin >> n;
  k = n-1;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < k; j++)cout << " ";
    for(int m = 0; m < w; m++)cout << "#";
    cout << endl;
    k--;
    w++;
  }
  return 0;
}