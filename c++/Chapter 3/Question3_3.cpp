#include<iostream>
#include<stack>
#include<climits>
using namespace std;
#define STACK_NUM 100

/*Imagine a (literal) stack of plates If the stack gets too high, it might topple There- fore, in real life, we would likely start a new stack when the previous stack exceeds some threshold. Implement a data structure SetOfStacks that mimics this SetOfStacks should be composed of several stacks, and should create a new stack once the previous one exceeds capacity SetOfStacks push() and SetOfStacks pop() should behave identically to a single stack (that is, pop() should return the same values as it would if there were just a single stack)
 FOLLOW UP
 Implement a function popAt(int index) which performs a pop operation on a speci c sub-stack\\
 */

//create a stack and when it exceeds capacity beyond the threshold, create a new stack and place item in it

class newStack{
private:
    stack<int> *myStack;
    int threshold;
    int curStack;
  
public:
    newStack(){
        threshold = 10;
        //stack<int> *myStack = new stack<int>[STACK_NUM];
        myStack = new stack<int>[STACK_NUM];
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

int main(){
    newStack sta;
    for(int i = 0; i < 100; i++)
        sta.push(i);
        sta.popAt(4);
  
    for(int i = 0; i < 101; i++){
        cout << sta.top() << '\n';
        sta.pop();
    }
  
    return 0;
}
