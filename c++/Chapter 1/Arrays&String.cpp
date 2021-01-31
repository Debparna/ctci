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

//Q1
//Implement an algorithm to determine if a string has all unique characters. What if you can not use additional data structures?

//Approach 1 – Brute Force technique: Run 2 loops with variable i and j. Compare str[i] and str[j]. If they become equal at any point, return false.
//Time Complexity: O(n2)

bool isUnique(string deb){
  for(int i = 0; i < deb.length(); i++){
    char temp;
    temp = deb[i];
    for(int j = 0; j < deb.length(); j++ ){
      if( i != j){
        if(temp == deb[j]){
          return false;
        }
      }
    }
  }
  return true;
}
/*
 Other way of doing the same as above
 bool isUnique(string str)
 {
 for (int i = 0; i < str.length(); i++)  // If at any time we encounter 2 same characters, return false
 for (int j = i + 1; j < str.length(); j++)
 if (str[i] == str[j])
 return false;
 
 return true;  // If no duplicate characters encountered, return true
 }
 */

/*
 Approach 2 - Based on ASCII values of characters
 Without Extra Data Structure: The approach is valid for strings having alphabet as a-z. This approach is little tricky. Instead of maintaining a boolean array, we maintain an integer value called checker(32 bits). As we iterate over the string, we find the int value of the character with respect to ‘a’ with the statement int bitAtIndex = str.charAt(i) - ‘a’; Then the bit at that int value is set to 1 with the statement 1 << bitAtIndex. Now, if this bit is already set in the checker, the bit AND operation would make checker > 0. Return false in this case. Else Update checker to make the bit 1 at that index with the statement checker = checker | (1 << bitAtIndex);
 
 Time Complexity: O(n)
 */

bool isUniqueChars(const string& str)
{
  if (str.length() > 256) //then its not ASCII
  {
    return false;
  }
  unsigned int checker = 0; //create a checker var instead of array
  for (int i = 0; i < str.length(); ++i)
  {
    int value = str[i] - 'a'; //finds the int value of the character with respect to ‘a’
    if ((checker & (1 << value)) != 0) //the bit at that int value is set to 1
    {
      return false;
    }
    checker |= (1 << value); //if value not found elsewhere, make it one
  }
  return true;
}

/* IN THIS QUESTION WE ARE NOT ALLOWED TO USE ANOTHER DATA SRTUCTURE, BUT IF WE DO THEN
 Approach 3 – Use of Extra Data Structure: This approach assumes ASCII char set(8 bits). The idea is to maintain a boolean array for the characters. The 256 indices represent 256 characters. All the array elements are initially set to false. As we iterate over the string, set true at the index equal to the int value of the character. If at any time, we encounter that the array value is already true, it means the character with that int value is repeated.
 Time Complexity: O(n)
 */

bool isUniqueChars2(const string& str)
{
  //To check if 1 byte = 8 bits, ascii char array 8 bits
  if (str.length() > 256)
  {
    return false;
  }
  
  bool ascii_set[256] = { false }; //create an array
  for (int i = 0; i < str.length(); ++i)
  {
    int value = str[i]; //stores the ASCII value of i in value
    if (ascii_set[value] == true)
    {
      return false;
    }
    ascii_set[value] = true;
  }
  return true;
}

//Approach 2 – Sorting: Using sorting based on ASCII values of characters
//Time Complexity: O(n log n)

string result(bool value)
{
  if (value)
  {
    return "True";
  }
  
  return "False";
}

//******************************************      Q2     *****************************************************//
//Q2
//Write code to reverse a C-Style String. (C-String means that “abcd” is represented as five characters, including the null character.)

//MY METHOD : swap
//Time Complexity: O(n)
void isReversed(string deb){
  int size = deb.length();
  char arr[size];
  int j = 0;
  for (int i = size - 1; i >= 0;  i--) {
    arr[j] = deb[i];
    j++;
  }
  cout << arr;
  return;
}

/* Function to reverse arr[] from start to end*/
// int arr[] = {1, 2, 3, 4, 5, 6};
void rvereseArray(int arr[], int start, int end)
{
  int temp;
  while (start < end)
  {
    temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    start++;
    end--;
  }
}

// Recursive C program to reverse an array
void rvereseArray(int arr[], int start, int end)
{
  int temp;
  if (start >= end)
    return;
  temp = arr[start];
  arr[start] = arr[end];
  arr[end] = temp;
  rvereseArray(arr, start+1, end-1);
}

//SECOND METHOD TO REVERSE IN PLACE, ACC TO CTCI
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

/*
 Anagram is "a word or phrase spelled by rearranging the letters of another word or phrase". So to be an anagram the arrangement of letters must make a word - that is, an anagram of a word must have a meaning, such as cinema, formed from iceman.
 
 On the other hand, permutation is defined as "the act of changing the arrangement of a given number of elements". So a permutation of a word can be any random assortment of characters, not necessarily having a meaning in the original language.
 
 So every anagram is a permutation of the word, but every permutation is not an anagram. To make it clearer 'cheaters' is an anagram of 'teachers' because both have the same letters, albeit in different positions, and both have some meaning in the English language. But 'eeahcrst' is merely a permutation of 'teachers' because 'eeahcrst' doesn't have any meaning associated with it in the English language.
 */

//Q3
//Find if a string is an anagram/permution of another

/*
 Method 1 (Use Sorting) -
 In the above implementation, quickSort is used which may be O(n^2) in worst case. If we use a O(nLogn) sorting algorithm like merge sort, then the complexity becomes O(nLogn)
 1) Sort both strings
 2) Compare the sorted strings
 */

void quickSort(char *arr, int si, int ei);

/* function to check whether two strings are anagram of each other */
bool anagram1(char *str1, char *str2)
{
  // Get lenghts of both strings
  int n1 = strlen(str1);
  int n2 = strlen(str2);
  
  // If length of both strings is not same, then they cannot be anagram
  if (n1 != n2)
    return false;
  
  // Sort both strings
  quickSort(str1, 0, n1 - 1);
  quickSort(str2, 0, n2 - 1);
  
  // Compare sorted strings
  for (int i = 0; i < n1;  i++)
    if (str1[i] != str2[i])
      return false;
  
  return true;
}

// Following functions (exchange and partition are needed for quickSort)
void exchange(char *a, char *b)
{
  char temp;
  temp = *a;
  *a   = *b;
  *b   = temp;
}

int partition(char A[], int startIndex, int endIndex)
{
  char x = A[endIndex];
  int i = (startIndex - 1);
  int j;
  
  for (j = startIndex; j <= endIndex - 1; j++)
  {
    if(A[j] <= x)
    {
      i++;
      exchange(&A[i], &A[j]);
    }
  }
  exchange (&A[i + 1], &A[endIndex]);
  return (i + 1);
}

/* Implementation of Quick Sort
 A[] --> Array to be sorted
 si  --> Starting index
 ei  --> Ending index
 */
void quickSort(char A[], int startIndex, int endIndex)
{
  int partitionIndex;
  if(startIndex < endIndex)
  {
    partitionIndex = partition(A, startIndex, endIndex);
    quickSort(A, startIndex, partitionIndex - 1);
    quickSort(A, partitionIndex + 1, endIndex);
  }
}

/*
 Method 2 (Count characters)
 This method assumes that the set of possible characters in both strings is small. In the following implementation, it is assumed that the characters are stored using 8 bit and there can be 256 possible characters.
 1) Create count arrays of size 256 for both strings. Initialize all values in count arrays as 0.
 2) Iterate through every character of both strings and increment the count of character in the corresponding count arrays.
 3) Compare count arrays. If both count arrays are same, then return true.
 */

bool anagram2(char *str1, char *str2)
{
  // Create 2 count arrays and initialize all values as 0
  int count1[256] = {0};
  int count2[256] = {0};
  
  // For each character in input strings, increment count in the corresponding count array
  int i;
  for (i = 0; str1[i] && str2[i];  i++)
  {
    count1[str1[i]]++; //increments counts at the particular index for that ascii value, if 4 e's, 97 is incremented by 4
    count2[str2[i]]++;
  }
  
  // If both strings are of different length. Removing this condition will make the program fail for strings like "aaca" and "aca"
  if (str1[i] || str2[i])
    return false;
  
  // Compare count arrays
  for (i = 0; i < 256; i++)
    if (count1[i] != count2[i])
      return false;
  
  return true;
}

/*
 Method 3 (Count characters)
 This implementation can be further to use only one count array instead of two. We can increment the value in count array for characters in str1 and decrement for characters in str2. Finally, if all count values are 0, then the two strings are anagram of each other.
 
 If the possible set of characters contains only English alphabets, then we can reduce the size of arrays to 52 and use str[i] – ‘A’ as an index for count arrays. This will further optimize this method.
 
 Time Complexity: O(n)
 */

bool anagrams3(char *str1, char *str2)
{
  int count[256] = {0};   // Create a count array and initialize all values as 0
  int i;
  
  for (i = 0; str1[i] && str2[i];  i++)//For each character in input strings, increment count in the corresponding count array
  {
    count[str1[i]]++; //increments counts at the particular index for that ascii value, if 4 e's, 97 is incremented by 4
    count[str2[i]]--;
  }
  
  // If both strings are of different length. Removing this condition will make the program fail for strings like "aaca" and "aca"
  if (str1[i] || str2[i])
    return false;
  
  for (i = 0; i < 256; i++)   // See if there is any non-zero value in count array
    if (count[i])
      return false;
  return true;
}

//Q4
//Write a method to replace all spaces in a string with ‘%20’.

void replaceSpaces(char str[], int length) //char str[]
{
  int newLength, spaceCount = 0;
  for (int i = 0; i < length; i++) //count the number of spaces in the given string.
  {
    if (str[i] == ' ')
    {
      spaceCount++;
    }
  }
  
  newLength = length + spaceCount * 2; //calculate new string size.
  str[newLength] = '\0';
  
  for (int i = length - 1; i >= 0; i--)  //copying the characters backwards and inserting %20
  {
    if (str[i] == ' ')
    {
      str[newLength - 1] = '0';
      str[newLength - 2] = '2';
      str[newLength - 3] = '%';
      newLength -= 3;
    }
    else
    {
      str[newLength - 1] = str[i];
      newLength--;
    }
  }
}

int main(){
  //Q1
  //string input = {"abkcde"};
  //cout << input << " has unique characters: " << result(isUnique(input)) << endl;
  //cout << input << " has unique characters: " << result(isUniqueChars(input)) << endl;
  //cout << input << " has unique characters: " << result(isUniqueChars2(input)) << endl;
  
  //Q2
  //char input[10] = { "abcde"};
  //isReversed(input);
  //reverse(input);
  //cout << "reverse of input string is " << input << endl;
  
  //Q3
  char str1[] = "geeksforgeeks";
  char str2[] = "forgeeksgeeks";
  if ( anagram2(str1, str2) ) //areAnagram(str1, str2) //areAnagrams(str1, str2)
    printf("The two strings are anagram of each other");
  else
    printf("The two strings are not anagram of each other");
  
  
  //Q4
  /*  // Increasing length of the string to meet question requirement of 'true' length by using char array. (Note: using a unique_ptr here)
   auto newStr = make_unique<char[]>(str.length() + 3 * 2 + 1);
   
   for (int i = 0; i < str.length(); i++)
   {
   newStr[i] = str[i];
   }
   
   cout << "Original string is " << str << endl;
   replaceSpaces(newStr, str.length());
   cout << "New string with %20 is " << newStr.get() << endl;
   */
  
  
  
  return 0;
  
}



