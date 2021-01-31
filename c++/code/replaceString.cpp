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

//1 5 Write a method to replace all spaces in a string with ‘%20’

//String method
string stringReplace(string string1){
  
  int length = string1.length();
  string string2;
  
  int counter = 0;
  for(int i = 0; i < length; i++){
    if (string1[i] != ' '){
      cout << string1[i];
      string2[counter++] = string1[i];
      cout << string2[counter++];
    }
    else{
      string2[counter] = '%';
      string2[counter+1] = '2';
      string2[counter+2] = '0';
    }
  }
  string2[counter]='\0';
  
  return string2;
  
}

//Char array method
char * charReplace(char *s)
{
  if(!s)
    throw("wrong input\n");
  int len = strlen(s);
  char* t = new char[3*len];//incase all are spaces
  int k=0;
  for(int i=0;i<len;i++){
    if(s[i]!=' ')
      t[k++]= s[i];
    else{
      t[k]='%';
      t[k+1]='2';
      t[k+2] = '0';
      k=k+3;
    }
  }
  t[k]='\0';
  return t;
}


int main(){
  /*
  string string1;
  getline(cin, string1);
  
  int newLength = 0;
  int length = string1.length();
  string string2[3*length];
  
  int counter = 0;
  for(int i = 0; i < length; i++){
    if (string1[i] != ' '){
      string2[counter++] = string1[i];
    }
    else{
      string2[counter] = '%';
      string2[counter+1] = '2';
      string2[counter+2] = '0';
    }
  }
  string2[counter]='\0';
  
  cout << string2;
  
  */
  
  string string1;
  getline(cin, string1);

  char string[256];
  cin.getline ( string, 256, '\n' );
  
  cout << stringReplace(string) << endl;
  cout << charReplace(string) << endl;
  
  return 0;
}