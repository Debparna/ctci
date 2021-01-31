#include <stdio.h>
#include <iostream>
using namespace std;

int my_array[] = {1,23,17,4,-5,100};
int *ptr;

int name(){
  
  
  return 8;
}

int main(void)
{
  int i;
  ptr = &my_array[0];
  cout << ptr << endl;
  cout << &ptr << endl;
   cout << *ptr << endl;
  
  //ptr = *my_array[0]; //no
  //*ptr = &my_array[0]; //no
  //*ptr = my_array[0]; //yes
 //ptr = my_array; //yes
  
  int *s;
  int p = 3;
  s = &p;
  cout << s << " " << p  << endl;
  
  for (i = 0; i < 6; i++)
  {
    //cout << i << my_array[i] << endl;
    //cout << i << *(ptr + i) << endl;
  }
    return 0;
}

/*
int x = 1, y = 2, int *ip;
ip = &x;
y = *ip;
*ip = 0;
ip = &z[0];
z[10];
*/
