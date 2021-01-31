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
using namespace std;

//Q1
//Implement a MyQueue class which implements a queue using two stacks.

//Questions to ask, does the order of the numbers you put in matter?
//Are the stacks connected or can one act as a buffer stack instead of actually being connected?

/*
 When you enqueue into the first stack it add numbers from the beginning to the end.
 Then when you dequeue the first element from stack 1 from the top moves into stack 2.
 So the last element from the stack will move to the beginning of the next stack.
 So the first element will be at the end of the second stack, when we pop the last element of s2 will be returned which is actually the first element of s1.
 */

//FIFO
class Queue{
private:
  stack<int> s1, s2;

public:

  void EnQueue(int data){
    while(!s2.empty()){
      s1.push(s2.top());
      s2.pop();
    }
    s2.push(data);
  }

  int DeQueue(){
    if(s1.empty() && s2.empty()){
      return INT_MIN;
    }
    while(!s1.empty()){
      int n = s1.top();
      s1.pop();
      s2.push(n);
    }
    int tmp = s2.top();
    s2.pop();
    return tmp;
  }

  int size(){
    return s1.size() + s2.size();
  }

};

//How would you design a stack which, in addition to push and pop, also has a function min which returns the minimum element?
//Push, pop and min should all operate in O(1) time

//Using an additional stack which keeps track of the mins, s2 keeps track of mins.
//while popping, if the one being popped from s1 is equal to min the pop the top from s2 since if popped it will no longer be min.
//Same with push if the one being pushed is lesser than s2 top then that is the new min so push it in s2.

//Q2
class stackWithMin{
private:
  stack<int> s1, s2;

public:
  void push(int x){
    s1.push(x);
    if(min() >= x){
      s2.push(x);
    }
  }
  void pop(){
    if(min() == s1.top()){
      s2.pop();
    }
    s1.pop();
  }

  int min(){
    if(s2.empty()){
      return INT_MAX;
    }
    return s2.top();
  }
};

//Q3
//SetOfStacks - //create a stack and when it exceeds capacity beyond the threshold,
//create a new stack and place item in it

class newStack{
private:
  stack<int> *myStack;
  int threshold;
  int curStack;

public:
  newStack(){
    threshold = 10;
    //stack<int> *myStack = new stack<int>[STACK_NUM];
    myStack = new stack<int>[100];
    curStack = 0;
  }

  void push(int data){
    if(myStack[curStack].size() >= threshold){
      curStack++;
    }
    myStack[curStack].push(data);
  }

  void pop(){
    if(myStack[curStack].empty()){ //before popping, check if stack is empty.
      if(curStack == 0){ //If it is then check if the first stack is empty, if that is, then there is nothing to pop, return
        cout << "Stack is empty\n";
        return;
      }
      curStack--; //if the curr stack is empty go to the prev stack and then pop
    }
    myStack[curStack].pop(); //if curr stack is not empty then
  }

  int top(){
    if(myStack[curStack].empty()){
      if(curStack == 0){
        return INT_MIN;
      }
      curStack--;
    }
    return myStack[curStack].top();
  }

  bool empty(){
    if(curStack == 0){
      return myStack[curStack].empty();
    }
    else
      return false;
  }

  void popAt(int index){
    if(myStack[index].empty()){
      cout << "sub-stack " << index << " is empty" << '\n';
      return;
    }
    myStack[index].pop();
  }
};

//Q4
/*
 1) Only one disk can be moved at a time.
 2) Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack i.e. a disk can only be moved if it is the uppermost disk on a stack.
 3) No disk may be placed on top of a smaller disk.

 Approach :

 Take an example for 2 disks :
 Let rod 1 = 'A', rod 2 = 'B', rod 3 = 'C'.

 Step 1 : Shift first disk from 'A' to 'B'.
 Step 2 : Shift second disk from 'A' to 'C'.
 Step 3 : Shift first disk from 'B' to 'C'.

 The pattern here is :
 Shift 'n-1' disks from 'A' to 'B'.
 Shift last disk from 'A' to 'C'.
 Shift 'n-1' disks from 'B' to 'C'.
 arg - P B D  1 2 3
       P D B  1 3 2
       B P D  2 1 3

 Image for illustration: http://mathforum.org/dr.math/faq/faq.disk3.gif
 */

void towerOfHanoi(stack<int> *pri, stack<int> *buff, stack<int> *dest, int n){
  if(n == 0){
    return;
  }

  towerOfHanoi(pri, dest, buff, n-1);
  (*dest).push((*pri).top());
  (*pri).pop();
  towerOfHanoi(buff, pri, dest, n-1);
}

//Q5
//Implement a MyQueue class which implements a queue using two stacks.
/*
 When you enqueue into the first stack it add numbers from the beginning to the end. Then when you dequeue the first element from stack 1 from the top moves into stack 2. So the last element from the stack will move to the beginning of the next stack. So the first element will be at the end of the second stack, when when we pop the last element of s2 will be returned which is actually the first element of s1.


class Queue{
private:
  stack<int> s1, s2;
public:
  void EnQueue(int data){
    while(!s2.empty()){
      s1.push(s2.top());
      s2.pop();
    }
    s2.push(data);
  }
  int DeQueue(){
    if(s1.empty() && s2.empty()){
      return INT_MIN;
    }
    while(!s1.empty()){
      s2.push(s1.top());
      s1.pop();
    }
    int tmp = s2.top();
    s2.pop();
    return tmp;
  }
  int size(){
    return s1.size() + s2.size();
  }
};
 */

//Q6
//Write a program to sort a stack in ascending order.
//Use two stacks, pop one from input stack

void sortStack(stack<int> *st){
  stack<int> sorted; //top contains smallest element

  while(!(*st).empty()) {
    int tmp = (*st).top();
    (*st).pop();

    while(!sorted.empty() && tmp > sorted.top()){
      (*st).push(sorted.top());
      sorted.pop();
    } //
    sorted.push(tmp);
  } //

  while(!sorted.empty()){
    (*st).push(sorted.top());
    sorted.pop();
  }
}


int main(){
  /*
  //Q1
  Queue q;
  for(int i = 0; i < 10; i++)
    q.EnQueue(i);

  cout << q.DeQueue() << '\n';
  cout << q.DeQueue() << '\n';
  cout << q.DeQueue() << '\n';
  */

  /*
  //Q2
  stackWithMin myStack;
  int arr[] = {6, 3, 5, 2, 2, 9, 2, 8, 1, 1};
  for(int i = 0; i < 10; i++){
    myStack.push(arr[i]);
    cout << arr[i] << " " << myStack.min() << '\n';
  }
  for(int i = 0; i < 10; i++){
    myStack.pop();
    cout << i << " " << myStack.min() << '\n';
  }*/

  //Q3
  /*
  newStack sta;
  for(int i = 0; i < 100; i++)
    sta.push(i);
  sta.popAt(4);

  for(int i = 0; i < 101; i++){
    cout << sta.top() << '\n';
    sta.pop();
  }
  */

  //Q4
  /*
  stack<int> primary, buffer, destination;

  int n = 10;
  for(int i = n; i > 0; i--)
    primary.push(i); //push numbers in first stack

  towerOfHanoi(&primary, &buffer, &destination, 10);

  while(!destination.empty()){
    cout << destination.top() << " ";
    destination.pop();
  }
  */

  /*
  Queue q;
  for(int i = 0; i < 10; i++)
    q.EnQueue(i);
  cout << q.DeQueue() << '\n';
  cout << q.DeQueue() << '\n';
  for(int i = 10; i < 20; i++){
    q.EnQueue(i);
  }
  cout << q.DeQueue() << " ";
  cout << q.DeQueue() << '\n';
  */

}
