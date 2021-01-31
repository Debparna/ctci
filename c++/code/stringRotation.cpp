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
 Assume you have a method isSubstring which checks if one word is a substring of another Given two strings,s1 and s2,write code to check if s2 is a rotation of s1 using only one call to isSubstring (i e , “waterbottle” is a rotation of “erbottlewat”)
 
 Solution:
 Concatenate both strings, thens find srting 2 in the concatenated string. 
*/


using std::string;

class Question1_8
{
public:
  string result(bool value);
  bool isRotation(const string& s1, const string& s2);
  int run();
};

bool Question1_8::isRotation(const string& s1, const string& s2)
{
  int len = s1.length();
  
  if(len == s2.length() && len > 0)
  {
    string s1s1 = s1 + s1;
    return s1s1.find(s2) != string::npos;
  }
  
  return false;
}

string Question1_8::result(bool value)
{
  if (value)
  {
    return "True";
  }
  
  return "False";
}

int Question1_8::run()
{
  string a = "apple";
  string b = "leapp";
  cout << "Checking if string: " << a << " is a rotation of string: " << b << ": "
  << result(isRotation(a, b)) << endl;
  
  a = "james";
  b = "masje";
  cout << "Checking if string: " << a << " is a rotation of string: " << b << ": "
  << result(isRotation(a, b)) << endl;
  
  return 0;
}

int main(){
  Question1_8 obj;
  obj.run();
  return 0;
}
