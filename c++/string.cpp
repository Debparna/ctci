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
#include <climits>
#include<list>
using namespace std;

/*
 1) Recursive reverse string
 2) find max char
 3) find if unique
 4)
 */

//Time Complexity: O(n)
void reverseCString(char *deb){
  if(*deb){
    reverseCString(deb + 1);
    cout << *deb << " ";
  }
}

//iterative
void reverse(char* str)
{
  char *ptrEnd = str; //value of str in pointer ptrEnd
  char temp;
  if (str != NULL)
  {
    while (*ptrEnd != '\0')
    {
      ptrEnd++;
    }
    ptrEnd--; //ptrEnd to the end of string

    while (str < ptrEnd) //WHAT???!?!?
    {
      temp = *str;
      *str = *ptrEnd;
      str++;
      *ptrEnd = temp;
      ptrEnd--;
    }
  }
}

//Return maximum occurring character in an input string

//Time Complexity: O(n)
//Space Complexity: O(1) — Because we are using fixed space (Hash array) irrespective of input string size.
char getMax(char* str)
{
  int count[256] = {0};

  int len = strlen(str);
  for (int i = 0; i < len; i++)
    count[str[i]]++;

  int max = -1;
  char result;

  // Traversing through the string and maintaining the count of each character
  for (int i = 0; i < len; i++) {
    if (max < count[str[i]]) {
      max = count[str[i]];
      result = str[i];
    }
  }
  return result;
}

//if char* has unique chars or not
//Time Complexity: O(n)
bool isUnique(char *str){
  bool arr[256];
  for(int i = 0; i < 256; i++){
    arr[i] = false;
  }
  int len = strlen(str);
  for(int i = 0; i < len; i++){
    if(arr[str[i]] == false){
      arr[str[i]] = true;
    }
    else{
      return false;
    }
  }
  return true;
}

//helper function for ^
string result(bool value)
{
  if (value)
  {
    return "True";
  }

  return "False";
}

//strlen using char*
int strlen(char *str){
  int n;
  if(*str){
    while(*str++ != '\0')
      n++;
  }
  return n;

  /*
   for(n = 0; *str != '0'; str++)
   n++;
   return n; */

}

int strlen2(char *str){
  char *p = str;
  while (*p != '\0')
    p++;
  return p - str;
}

//char msg[] = "deb is me"; //individual chars in array might change but msg will always refer to the same storage
//char *msg2 = "deb is me"; //is a pointer initialized to point to a string constant, the pointer may be modified to point elsewhere but result is undefined if you try to modify the string contents

void strcpy(char *s, char *t){
  int i = 0;
  while((s[i] = t[i]) != '\0'){
    i++;
  }
}

void strcpyWithPointers(char *s, char *t){
  while((*s = *t) != '\0'){
    s++;
    t++;
  }
}

void strcpy3(char *s, char* t){
  while(*s++ = *t++);
}

/*
 strcmp
 if Return value < 0 then it indicates str1 is less than str2.
 if Return value > 0 then it indicates str2 is less than str1.
 if Return value = 0 then it indicates str1 is equal to str2.
 */

int strcmp(char *s, char* t){
  int i;
  for(int i = 0; s[i] == t[i]; i++)
    if(s[i] == '\0')
      return 0;
  return s[i] - t[i];
}

int strcmp2(char *s, char* t){
  /*
   bool same = true;
   while (*s++ != *t++)
   {
   same = false;
   break;
   }
   return *s - *t;*/

  for(; *s == *t; s++, t++)
    if(*s == '\0')
      return 0;
  return *s - *t;
}

//add str2 to str1
void strcat(char *str1, char *str2){
  int len1 = strlen(str1);
  int len2 = strlen(str2);
  int len3 = len1 + len2;

  char str3[len3 - 1];

  while(*str1 != '\0'){

  }
}

struct node{
  char data;
  node *next;
};
/*
 class LinkedList{
 public:
 node *head;
 node *tail;
 void insert(char value);
 void printList();
 void reverseList();

 };
 */
/*
 void LinkedList::insert(char value){

 if (head == NULL)
 {
 head = new node;
 tail = head;
 head->next = NULL;
 head->data = value;
 }
 else
 {
 tail->next = new node;
 tail = tail->next;
 tail->data = value;
 tail->next = nullptr;
 }
 }

 void LinkedList::printList(){
 node *temp = head;
 while (temp != NULL) {
 cout << temp->data << endl;
 temp = temp->next;
 }
 }

 void LinkedList::reverseList(){

 node *prev, *cur, *next;
 prev = NULL;
 cur = head;

 while (cur != NULL) {
 next = cur->next;
 cur->next = prev;
 prev = cur;
 cur = next;
 }
 head = prev;

 /*
 node *q, *r, *s;
 q = head;
 r = NULL;
 while (q != NULL) {
 s = r;
 r = q;
 q = q->next;
 r->next = s;
 }
 head = r;

 }
 */

/*
 void insert( node **head, char value){

 node *tail = NULL;

 if( head == NULL){
 *head = new node;
 ->next = NULL;
 head->data = value;
 }
 if(head->next != NULL){
 while (head->next != NULL) {
 head = head->next;
 }
 tail = head;
 tail->next = new node;
 tail = tail->next;
 tail->next = NULL;
 tail->data = value;
 }
 }*/

//fn to count how many times a char appears in a char*
//Count substrings with same first and last characters
//Maximum consecutive repeating character in string
//Print common characters of two Strings in alphabetical order
//How to find all permutations of String?
//Write a program to remove a given characters from String?

int main(){
  char *str1 = "debb";
  char *str2 = "debbs";
  cout << strcmp2(str1, str2);
  //cout << strlen(str1);

  //string str = {"beaceh"};

  //int arr[] = {1, 2, 3, 4, 5, 6};
  //reverseCString(deb);
  //cout << endl;

  //char str[] = "sample string";
  //cout << "Max occurring character is "
  //	<< getMax(str) << endl;

  //cout << " has unique characters: " << result(isUnique(deb)) << endl;

  //cout << strlen(deb) <<endl;



  //char stringLL[] = "HELLO";
  //int len = strlen2(stringLL);

  //LinkedList obj;
  node *head = NULL;

  //for(int i = 0; i < len; i++){
  //insert(&head ,stringLL[i]);
  //}

  //obj.printList();
  //obj.reverseList();
  //obj.printList();

  return 0;
}
