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

//Implement a MyQueue class which implements a queue using two stacks.
//A queue is FIFO
// pop() pops the last thing from the stack

//Questions to ask, does the order of the numbers you put in matter?
//Are the stacks connected or can one act as a buffer stack instead of actually being connected?

/*
 When you enqueue into the first stack it add numbers from the beginning to the end. Then when you dequeue the first element from stack 1 from the top moves into stack 2. So the last element from the stack will move to the beginning of the next stack. So the first element will be at the end of the second stack, when when we pop the last element of s2 will be returned which is actually the first element of s1.
 */
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

int main(){
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
}


