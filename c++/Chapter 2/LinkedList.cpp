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
#include <unordered_map>


using namespace std;

struct Node
{
  int data;
  Node* next;
};

struct DNode
{
  int data;
  Node* next;
};

/* IF NOT CLASS
 struct Node *newNode(int data) //WHAT
 {
 Node *temp = new Node;
 temp->data = data;
 temp->next = NULL;
 return temp;
 }
 */

class LinkedList
{
private:
  Node* tail;   // added this so insertion is O(1) time
  
public:
  Node* head;
  LinkedList();
  ~LinkedList();
  
  void insert(int value);
  void Delete(int value);
  bool find(int value);
  void createCycle();
  void display();
  int run();
  
  //Q1
  void removeDuplicates_1(Node* head);
  void removeDuplicates_2(Node* head);
  //Q2
  int findNthFromEnd(Node* head, int n);
  //Q3
  bool removeNode(Node* node);
  //Q4
  void sumLinks(Node* list1, Node* list2);
  //Q5
  bool hasCycle(Node *head );
  //Q6
  Node* findCycleBegin(Node* head);
};

class DLinkedList{
protected:
  DNode *head;
  DNode *tail;
  DNode *curr;
public:
  DLinkedList(); //The constructor sets the three members to NULL.
  ~DLinkedList(); //The destructor removes all of the ListNodes
  virtual int* erase(int num);
  virtual int* find(int num);
  virtual int* insert(int num);
};


LinkedList::LinkedList()
{
  this->head = nullptr;
}

LinkedList::~LinkedList()
{
  Node *temp = nullptr;
  while( head != NULL){
    head = head->next;
    delete temp;
  }
  tail = NULL;
  //std::cout << "List successfully deleted from memory" << std::endl;
}

//HOW WILL PROGRAM KNOW TAIL POINTS TO LAST NODE?
void LinkedList::insert(int value) //insertion in O(1) time with tail pointer
{
  if (head == NULL)
  {
    head = new Node();
    tail = head;
    head->next = nullptr;
    head->data = value;
  }
  else
  {
    tail->next = new Node();
    tail = tail->next;
    tail->data = value;
    tail->next = nullptr;
  }
}

bool LinkedList::find(int value){
  while(head != NULL)
    if(head->data == value) //item found
      return true;
    else
      head = head->next; //continue traversing
  return false; //list is empty
}

void LinkedList::createCycle()
{
  tail->next = head->next;
}

void LinkedList::display()
{
  Node* temp;
  if (head == NULL)
  {
    return;
  }
  
  temp = head;
  while (temp != NULL)
  {
    cout << temp->data << ' ';
    temp = temp->next;
  }
  cout << endl;
}

void LinkedList::Delete(int value){
  /*
   //To delete curr
   Node* curr = head;
   Node* temp;
   if(head == NULL){
   return;
   }
   else{
   if(curr != NULL && curr->data == value){
   delete curr;
   }
   else{
   curr = curr->next;
   while(curr != NULL){
   if(curr->data == value){
   temp = curr;
   curr = curr->next;
   delete temp;
   cout << " found and deleted";
   }
   else if(curr->data != value) {
   curr = curr->next;
   }
   else{
   cout << "not in list";
   }
   }
   }
   }
   */
  
}

/************************ QUESTION 1 *********************************/

//To remove duplicates from an unsorted linked list

// First implementation uses undordered_map run time is O(n) with O(n) space, should be a hash map
void LinkedList::removeDuplicates_1(Node* head)
{
  if (head == NULL) //check if head is null
  {
    return;
  }
  
  //create a map of node value and a bool associated with it - true or false
  unordered_map<int,bool> map; //typedef pair<key_type, data_type> value_type;
  Node* current = head; //start at head
  map[current->data] = 1; //set first one to true
  
  while (current->next) //while the node after head exists
  {
    if (map[current->next->data] == 0) //if the next data is false
    {
      map[current->next->data] = 1; //it is not the same therefore no duplicate
      current = current->next; //move to next
    }
    else //else the next node is true
    {
      Node* temp = current->next; //save the next duplicate node in temp
      cout << "Duplicate Found: " << temp->data << " removed" << endl; //display data of duplicate node
      delete temp; //delete duplicate node
      current->next = current->next->next; //set next to node after duplicate/deleted node
    }
  }
}

//Without a buffer, we can iterate with two pointers: “current” does a normal iteration, while “runner” iterates through all prior nodes to check for dups Runner will only see one dup per node, because if there were multiple duplicates they would have been removed already

// This implementation uses no additional data structure run time is O(n^2) with O(1) space
void LinkedList::removeDuplicates_2(Node* head)
{
  if (head == NULL)
  {
    return;
  }
  
  Node* current = head;
  Node* runner;
  while (current) //while current which starts at head exists
  {
    runner = current; //set current to runner
    while (runner->next) //while runner next exists
    {
      //runner starts with the curr node then goes next till the end and compares each node to curr node to find duplicate
      if (current->data == runner->next->data)// if  duplicate then
      {
        Node* temp = runner->next;
        cout << "Duplicate Found: " << temp->data << " removed" << endl;
        delete temp;
        runner->next = runner->next->next; //assign the node after the  deleted node to the runner node so it can continue
      }
      else
      {
        runner = runner->next; // if no duplicate then continue
      }
    }//end of while2
    current = current->next; // move on  to next node to check if it has a duplicate in the whole list
  }//end of while1
}

/************************ QUESTION 2 *********************************/
//Implement an algorithm to find the nth to last element of a singly linked list
int LinkedList::findNthFromEnd( Node* head, int n)
{
  Node *p1, *p2;
  if (head == NULL && n-1 < 1){
    return NULL;
  }
  p1 = head;
  p2 = head;
  for(int i = 0; i < n; i++){
    if(p2 == NULL){
      return NULL;
    }
    p2 = p2->next;
  }
  while(p2->next != NULL){
    p1 = p1->next;
    p2 = p2->next;
  }
  return p1->data;
}

/************************ QUESTION 3 *********************************/
//Implement an algorithm to delete a node in the middle of a single linked list, given only access to that node
// Copy data from next node into current node and then delete the next node. Runs in O(1) time with O(1) space (note: this is only true if you are not iterating through the list)
bool LinkedList::removeNode(Node* node){
  if(node == NULL && node->next == NULL){
    return false;
  }
  else{
    // copy the next nodes information to the current node and then delete the next node updating the pointers
    Node* nextNode;
    nextNode = node->next;
    node->data = nextNode->data;
    node->next = nextNode->next;
    delete nextNode;
  }
  return true;
}

/************************ QUESTION 4 *********************************/
//You have two numbers represented by a linked list, where each node contains a single digit The digits are stored in reverse order, such that the 1’s digit is at the head of the list Write a function that adds the two numbers and returns the sum as a linked list

/*implementation runs in O(n) time with O(1) space by overwriting one of the
 original lists. It is an iterative implementation that handles numbers of
 different lengths.
 for part B (if the lists are in forward order) simply reversing the list
 in O(n) time and running the same algorithm does the trick
 */

int lenList(Node* head);
void padList(Node* head, int pad);

void LinkedList::sumLinks(Node* list1, Node* list2)
{
  if (list1 == NULL && list2 == NULL)
  {
    return;
  }
  
  int carry = 0;
  int val = 0;
  Node* l1 = list1;
  Node* l2 = list2;
  
  // determine if a list is longer and if so, pad that list
  int l1Len = lenList(l1);
  int l2Len = lenList(l2);
  
  if (l1Len > l2Len)
  {
    padList(l2, l1Len - l2Len);
  }
  
  if (l2Len > l1Len)
  {
    padList(l1, l2Len - l1Len);
  }
  
  
  while (l1 || l2)
  {
    l1->data += carry;
    
    val = l1->data + l2->data;
    
    if (val > 9)
    {
      carry = 1;
      val = val - 10;
    }
    else
    {
      carry = 0;
    }
    
    l1->data = val;
    
    l1 = l1->next;
    l2 = l2->next;
  }
  
  // if the final digit had a carry we need to add one to the end
  if (carry)
  {
    // reset the head and find the last element
    l1 = list1;
    while (l1->next)
    {
      l1 = l1->next;
    }
    
    l1->next = new Node();
    l1->next->data = 1;
    l1->next->next = nullptr;
  }
}

// helper function to display to list value normally
int listValue(Node* head)
{
  int value = 0;
  double digit = 0;
  Node* temp = head;
  
  // I did this implementation because I wanted to avoid O(n) space
  while (temp)
  {
    value += pow(10.0,digit) * temp->data;
    digit++;
    temp = temp->next;
  }
  
  return value;
}

// helper function to determine the length of a list
int lenList(Node* head)
{
  Node* temp = head;
  int len = 0;
  
  while (temp)
  {
    temp = temp->next;
    len++;
  }
  
  return len;
}

// helper function to pad the list with a different length with 0 zeros
void padList(Node* list, int pad)
{
  int count = 0;
  Node* temp = list;
  
  // get to the end of the list
  while (temp->next)
  {
    temp = temp->next;
  }
  
  while (count != pad)
  {
    temp->next = new Node();
    temp = temp->next;
    temp->data = 0;
    temp->next = nullptr;
    count++;
  }
}

/************************ QUESTION 5 *********************************/
//To find if linked list is circular or not.
//imagine two pointer, if they move at different speeds, they will collide. We can do this on a linked list, one moves two nodes for every time the other moves one node. If there is a loop they will collide, otherwise they will get to the end of the list.

bool LinkedList::hasCycle(Node *head ){
  if(head == NULL){
    return false;
  }
  Node *slow;
  Node *fast;
  slow = head; //set slow to first node
  fast = head->next; //set first to second node since they move at diff speeds they need to start off at different positions.
  while(slow != NULL && fast != NULL && fast->next != NULL){
    if(fast == slow){
      return true;
    }
    slow = slow->next;
    fast = fast->next->next;
  }
  return false;
}

/************************ QUESTION 6 *********************************/
//Given a circular linked list, implement an algorithm which returns node at the beginning of the loop
Node* LinkedList::findCycleBegin(Node* head){
  //First find if linked list is a cycle or not
  if(head == NULL){
    return nullptr;
  }
  Node *slow;
  Node *fast;
  slow = head; //set slow to first node
  fast = head->next; //set first to second node since they move at diff speeds they need to start off at different positions.
  while(slow != NULL && fast != NULL && fast->next != NULL){
    if(fast == slow){
      break;
    }
    slow = slow->next;
    fast = fast->next->next;
  }
  
  if (fast == NULL || fast->next == NULL)   // a check to make sure that there was in fact a loop
  {
    return nullptr;
  }
  
  //Now if the linked list is in fact a circular linked list then leave the fast pointer on the node where the two pointers met but move the slow pointer to the head of the list.
  slow = head;// slow is set to the head and then both are moved at the same pace
  while (slow != fast)
  {
    slow = slow->next;
    fast = fast->next;
  }
  
  // once they meet, they are at the start of the loop
  return slow;
}

/************************ QUESTION 7 *********************************/
//Function to check if a singly linked list is palindrome

/*
 METHOD 1 (Use a Stack)
 A simple solution is to use a stack of list nodes. This mainly involves three steps.
 1) Traverse the given list from head to tail and push every visited node to stack.
 2) Traverse the list again. For every visited node, pop a node from stack and compare data of popped node with currently visited node.
 3) If all nodes matched, then return true, else false.
 
 Time complexity of above method is O(n), but it requires O(n) extra space. Following methods solve this with constant extra space.
 
 SINCE STACK IS FILO
 */

bool isPalindrome(Node* head){
  stack<char> Stack;
  if(head == NULL){
    return false;
  }
  Node *temp = new Node;
  temp = head;
  while (temp != NULL) {
    Stack.push(temp->data);
    temp = temp->next;
  }
  while(temp != NULL){
    if(temp->data == Stack.top()) {
      temp = temp->next;
      Stack.pop();
    } else{
      return false;
    }
  }
  return true;
}
/*
 METHOD 2 (By reversing the list)
 This method takes O(n) time and O(1) extra space.
 1) Get the middle of the linked list.
 2) Reverse the second half of the linked list.
 3) Check if the first half and second half are identical.
 4) Construct the original linked list by reversing the second half again and attaching it back to the first half
 
 To divide the list in two halves, method 2 of this post is used.
 When number of nodes are even, the first and second half contain exactly half nodes. The challenging thing in this method is to handle the case when number of nodes are odd. We don’t want the middle node as part of any of the lists as we are going to compare them for equality. For odd case, we use a separate variable ‘midnode’.
 Time Complexity O(n)
 Auxiliary Space: O(1) http://yucoding.blogspot.com/2016/01/leetcode-question-palindrome-linked-list.html
 */

/*
 METHOD 3 (Using Recursion)
 Use two pointers left and right. Move right and left using recursion and check for following in each recursive call.
 1) Sub-list is palindrome.
 2) Value at current left and right are matching.
 
 If both above conditions are true then return true.
 
 The idea is to use function call stack as container. Recursively traverse till the end of list. When we return from last NULL, we will be at last node. The last node to be compared with first node of list.
 
 In order to access first node of list, we need list head to be available in the last call of recursion. Hence we pass head also to the recursive function. If they both match we need to compare (2, n-2) nodes. Again when recursion falls back to (n-2)nd node, we need reference to 2nd node from head. We advance the head pointer in previous call, to refer to next node in the list.
 
 However, the trick in identifying double pointer. Passing single pointer is as good as pass-by-value, and we will pass the same pointer again and again. We need to pass the address of head pointer for reflecting the changes in parent recursive calls.
 
 Time Complexity: O(n)
 Auxiliary Space: O(n) if Function Call Stack size is considered, otherwise O(1).
 */

/************************ QUESTION 7 *********************************/
/*Given pointer to the head node of a linked list, the task is to reverse the linked list.

 Recursive Method:
 
 1) Divide the list in two parts - first node and rest of the linked list.
 2) Call reverse for the rest of the linked list.
 3) Link rest to first.
 4) Fix head pointer
 
 Time Complexity: O(n)
 Space Complexity: O(1)
 */

void recursiveReverse( Node** head_ref)
{
  struct Node* first;
  struct Node* rest;
  
  /* empty list */
  if (*head_ref == NULL)
    return;
  
  /* suppose first = {1, 2, 3}, rest = {2, 3} */
  first = *head_ref;
  rest  = first->next;
  
  /* List has only one node */
  if (rest == NULL)
    return;
  
  /* reverse the rest list and put the first element at the end */
  recursiveReverse(&rest);
  first->next->next  = first;
  
  /* tricky step -- see the diagram */
  first->next  = NULL;
  
  /* fix the head pointer */
  *head_ref = rest;
}

int LinkedList::run()
{
  LinkedList *myList = new LinkedList();
  myList->insert(5);
  myList->insert(7);
  myList->insert(12);
  myList->insert(7);
  myList->insert(16);
  myList->insert(16);
  myList->insert(25);
  myList->insert(11);
  myList->insert(5);
  
  
  //cout << "The original list is: ";
  //myList->display();
  
  // change to removeDuplicates_2 to run that implementation
  //removeDuplicates_1(myList->head);
  //cout << "The list with duplicated removed is: ";
  //myList->display();
  //cout << "Nth to end node is " << findNthFromEnd(myList->head, 3) << endl;
  
  //Question 3
  // just get a node in the list
  //Node* temp = myList->head->next->next->next->next;
  //cout << "Removing node with value: " << temp->data << endl;
  //removeNode(temp);
  
  //Question 4
  //LinkedList* list1 = new LinkedList();
  //list1->insert(5);
  //list1->insert(3);
  //list1->insert(6);
  
  //LinkedList* list2 = new LinkedList();
  //list2->insert(2);
  //list2->insert(1);
  //list2->insert(6);
  
  //cout << listValue(list1->head) << " + " << listValue(list2->head) << " = ";
  //sumLinks(list1->head, list2->head);
  //cout << listValue(list1->head) << endl;
  //delete list1;
  //delete list2;
  //cout << endl;
  
  //Question 6
  //cout << "For the list: ";
  //list1->display();
  //cout << "A cycle begins at value: ";
  
  // create a cycle in the list
  //list1->createCycle();
  
  //Node* beginCycle = findCycleBegin(list1->head);
  //cout << beginCycle->data << std::endl;
  
  //cout << "The original list is: ";
  //myList->display();
  //delete myList;
  
  //Palindrome
  
  return 0;
}

int main()
{
  LinkedList list;
  list.run();
  return 0;
}
