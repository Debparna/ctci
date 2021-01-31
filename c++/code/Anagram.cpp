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
//ANAGRAMS - to check if one word is a different form another. Check if every char of one word belongs to the other word.
//One way is this way,the other way is the quicksort method

bool IsAnagram(std::string str1, std::string str2)
{
  if(str1.length() != str2.length())
    return false;
  for(int i = 0; i < str1.length();i++)
  {
    bool found = false;
    for( int j = 0; !found && j < str2.length(); j++)
    {
      if(str1[i] == str2[j])
      {
        found = true;
        str2[j] = NULL;
      }
    }
    if(!found)
      return false;
  }
  return true;
}

string result(bool value)
{
  if (value)
  {
    return "True";
  }
  
  return "False";
}

int main(){
  
  string string1;
  string string2;
  
  cin >> string1;
  cin >> string2;
  
  cout << result(IsAnagram(string1, string2)) << endl;
  
  
}
