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

void reverse(char* str)
{
  char *ptrEnd = str;
  char temp;
  if (str != NULL)
  {
    while (*ptrEnd != '\0')
    {
      ptrEnd++;
    }
    ptrEnd--;
    
    while (str < ptrEnd)
    {
      temp = *str;
      *str++ = *ptrEnd;
      
      *ptrEnd-- = temp;
    }
  }
}


int main()
{
  char input[10] = { "abcde"};
  
  
  cout << "reversing the string: " << input << endl;
  reverse(input);
  cout << "reverse of input string is " << input << endl;
  
  
  return 0;
}
